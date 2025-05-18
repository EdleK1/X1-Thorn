#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Float32MultiArray
import pigpio
import time


class Test_Stand_Planner_node(Node):

    def __init__(self):
        super().__init__("Test_Stand_Planner_node")

        self.motor_pub = self.create_publisher(Float32MultiArray, "/Feed_Forward/Motor", 10)
        self.servo_pub = self.create_publisher(Float32MultiArray, "/Feed_Forward/Servo", 10)
        self.write_csv_pub = self.create_publisher(Int32, "/Write_csv", 10)
        self.PlannerMode_pub = self.create_publisher(Int32,"/Planner/Mode",10)
        self.get_logger().info("Test Stand Planner node initialized")


        motor_thrust = [0.1,0.25,0.4,0.55,0.7,0.85,1] # levels of thrust to be tested
        servo_orientations = [-1,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1] # orientations to be tested
        self.reference_index = 0
        self.write_csv = Int32()
        self.FFWservo = Float32MultiArray()
        self.FFWmotor = Float32MultiArray()
        self.mode = Int32()
        self.mode.data = 3

        self.reference_commands = []
        for i in range(len(motor_thrust)):
            for j in range(len(servo_orientations)):

                if i%2 == 0:
                    self.reference_commands.append([motor_thrust[i],servo_orientations[j]])
                else:
                    self.reference_commands.append([motor_thrust[i],servo_orientations[-j-1]])

        
        self.PlannerMode_pub.publish(self.mode)

        self.Buzzer_Initialize()


        self.timer = self.create_timer(0.5, self.command_callback)

    def command_callback(self):

        if self.reference_index <= len(self.reference_commands) - 1:


            self.FFWservo.data = [self.reference_commands[self.reference_index][1], self.reference_commands[self.reference_index][1]]
            self.FFWmotor.data = [self.reference_commands[self.reference_index][0], self.reference_commands[self.reference_index][0]]

            self.get_logger().info(f"Setting new references: Servo = {self.FFWservo.data[0]:.2f}, Motor = {self.FFWmotor.data[0]:.2f}")

            self.servo_pub.publish(self.FFWservo) # publish servo reference
            self.motor_pub.publish(self.FFWmotor) # publish servo reference

            self.reference_index += 1

        elif self.write_csv.data != 1:

            self.get_logger().info("Sending write command")
            self.write_csv.data = 1
            self.write_csv_pub.publish(self.write_csv)

        else:
            pass


    def Buzzer_Initialize(self):
        GPIO_PIN = 19

        sequence = [
            (1700, 0.5),
            (1800, 0.5),
            (1700, 0.5),
            (1800, 0.5),
            (1700, 0.5),
            (1800, 0.5),
        ]

        pi = pigpio.pi()

        if not pi.connected:
            self.get_logger().error("Failed to connect to pigpio daemon")
            self.destroy_node()
            return

        try:
            for frequency, duration in sequence:
                
                pi.set_PWM_frequency(GPIO_PIN, frequency)  # Set the frequency of the buzzer
                pi.set_PWM_dutycycle(GPIO_PIN, 128)        # 50% duty cycle (buzzing)

                time.sleep(duration)                       # Sleep for the specified duration

                pi.set_PWM_dutycycle(GPIO_PIN, 0)          # Turn the buzzer off

        finally:
            pi.stop()  # Ensure pigpio connection is closed properly





def main(args=None):

    rclpy.init(args=args)
    node = Test_Stand_Planner_node()
    rclpy.spin(node)
    rclpy.shutdown()