#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Float32MultiArray
from sensor_msgs.msg import Joy
import pigpio
import time

class Flight_Planner_node(Node):

    def __init__(self):
        super().__init__("Flight_Planner_node")

        self.lastButtons = [0]*13
        self.mode = Int32()
        self.mode.data = 1
        self.FFWservo = Float32MultiArray()

        self.GroundCommands_sub = self.create_subscription(Joy, "/joy", self.Commands_callback, 10)
        self.PlannerMode_pub = self.create_publisher(Int32,"/Planner/Mode",10)
        # self.HoverRef_pub = self.create_publisher(int,"/Hover_Control/Reference",10)
        # self.CruiseRef_pub = self.create_publisher(int,"/Cruise_Control/Reference",10)
        self.FFWservo_pub = self.create_publisher(Float32MultiArray,"/Feed_Forward/Servo",10)
        # self.FFWmotor_pub = self.create_publisher(int,"/Feed_Forward/Motor",10)

        self.get_logger().info("Flight Planner node initialized")
        self.Buzzer_Initialize()

    def Commands_callback(self, msg: Joy):
        if self.lastButtons[9] == 0 and msg.buttons[9] == 1:
            if self.mode.data != 3:
                self.mode.data += 1
            else:
                self.mode.data = 1

            self.PlannerMode_pub.publish(self.mode)

        if self.mode.data == 3:
            self.FFWservo.data = [msg.axes[0], msg.axes[3]]
            self.FFWservo_pub.publish(self.FFWservo)

        self.lastButtons = msg.buttons

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
    node = Flight_Planner_node()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()