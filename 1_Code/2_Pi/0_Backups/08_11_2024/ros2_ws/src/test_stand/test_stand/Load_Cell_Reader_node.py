#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Float32MultiArray
import pigpio
import os

class HX711:
    def __init__(self, pi, data_pin, clock_pin, gain=128):
        self.pi = pi
        self.data_pin = data_pin
        self.clock_pin = clock_pin
        self.gain = gain
        self.setup_pins()
        self.set_gain(gain)

    def setup_pins(self):
        self.pi.set_mode(self.data_pin, pigpio.INPUT)
        self.pi.set_mode(self.clock_pin, pigpio.OUTPUT)

    def set_gain(self, gain=128):
        if gain == 128:
            self.gain_bits = 1
        elif gain == 64:
            self.gain_bits = 3
        elif gain == 32:
            self.gain_bits = 2
        else:
            raise ValueError("Gain should be 128, 64, or 32.")
        self.read_raw()

    def read_raw(self):
        while self.pi.read(self.data_pin) == 1:
            pass
        count = 0
        for i in range(24):
            self.pi.write(self.clock_pin, 1)
            count = (count << 1) | self.pi.read(self.data_pin)
            self.pi.write(self.clock_pin, 0)
        for i in range(self.gain_bits):
            self.pi.write(self.clock_pin, 1)
            self.pi.write(self.clock_pin, 0)
        if count & 0x800000:
            count -= 0x1000000
        return count

    def read(self, samples=5, delay=0.1):
        readings = []
        for i in range(samples):
            readings.append(self.read_raw())
            time.sleep(delay)
        return sum(readings) / len(readings)

    def cleanup(self):
        self.pi.write(self.clock_pin, 0)
        self.pi.stop()



class Load_Cell_Reader_node(Node):

    def __init__(self):
        super().__init__("Load_Cell_Reader_node")
        self.pi = pigpio.pi()
        # self.load_cell_1 = HX711(self.pi, data_pin=5, clock_pin=6)
        # self.load_cell_3 = HX711(self.pi, data_pin=5, clock_pin=6)
        # self.load_cell_2 = HX711(self.pi, data_pin=5, clock_pin=6)

        self.motor_subscriber = self.create_subscription(Float32MultiArray, "/Feed_Forward/Motor", self.motor_command_callback, 10)
        self.servo_subscriber = self.create_subscription(Float32MultiArray, "/Feed_Forward/Servo", self.servo_command_callback, 10)
        self.write_csv_subscriber = self.create_subscription(Int32, "/Write_csv", self.write_csv_callback, 10)
        self.get_logger().info("Load Cell Reader node initialized")

        self.last_servo_command = 0
        self.last_motor_command = 0
        self.total_data_list = []
        self.stop_logging = False

        self.timer = self.create_timer(0.1, self.log_callback)

    def log_callback(self):

        if self.stop_logging != True:

            current_time = float(self.get_clock().now().nanoseconds) / 1e9
            weight = 1.23 # [self.load_cell_1.read(),self.load_cell_2.read(),self.load_cell_3.read()]
            data = [current_time, weight, self.last_servo_command, self.last_motor_command]
            self.total_data_list.append(data)
        else:
            pass

    def servo_command_callback(self, msg: Float32MultiArray):

        self.last_servo_command = msg.data[0]

    def motor_command_callback(self, msg: Float32MultiArray):

        self.last_motor_command = msg.data[0]

    def write_csv_callback(self, msg: Int32):

        if msg.data == 1:

            self.stop_logging = True

            file_path = os.path.expanduser('~/ros2_ws/src/test_stand/test_stand_csv/test_stand_results.csv')
            self.get_logger().info(f"CSV will be written to: {file_path}")

            with open(file_path, "a") as log:
            
                for i in self.total_data_list:

                    log.write(str(i)[1:-1] + "\n")

            self.get_logger().info("csv written")

            self.pi.stop()

        else:
            pass




def main(args=None):

    rclpy.init(args=args)
    node = Load_Cell_Reader_node()
    rclpy.spin(node)
    rclpy.shutdown()