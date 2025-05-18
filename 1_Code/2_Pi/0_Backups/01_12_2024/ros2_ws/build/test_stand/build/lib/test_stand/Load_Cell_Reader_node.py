#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Float32MultiArray
import numpy as np
import pigpio
import os
import time
import sys
from test_stand import HX711


class Load_Cell_Reader_node(Node):

    def __init__(self):
        super().__init__("Load_Cell_Reader_node")
        self.pi = pigpio.pi()

        self.motor_subscriber = self.create_subscription(Float32MultiArray, "/Feed_Forward/Motor", self.motor_command_callback, 10)
        self.servo_subscriber = self.create_subscription(Float32MultiArray, "/Feed_Forward/Servo", self.servo_command_callback, 10)
        self.write_csv_subscriber = self.create_subscription(Int32, "/Write_csv", self.write_csv_callback, 10)
        self.get_logger().info("Load Cell Reader node initialized")

        self.last_servo_command = 0
        self.last_motor_command = 0
        self.total_data_list = []
        self.stop_logging = False

        # Initialize the load cells
        
        self.load_cell_1 = HX711.sensor(self.pi, DATA=2, CLOCK=3,offset=0,gain=1)
        self.load_cell_2 = HX711.sensor(self.pi, DATA=9, CLOCK=11,offset=0,gain=1)
        self.load_cell_3 = HX711.sensor(self.pi, DATA=20, CLOCK=21,offset=0,gain=1)

        stop_initialize = time.time() + 3
        while time.time() < stop_initialize: # First readings were usually inaccurate
            c_1, mode_1, reading_1 = self.load_cell_1.get_reading()
            c_2, mode_2, reading_2 = self.load_cell_2.get_reading()
            c_3, mode_3, reading_3 = self.load_cell_3.get_reading()
            self.get_logger().info(f"Load Cell 1 reading = {reading_1:.2f}, Load Cell 2 reading = {reading_2:.2f}, Load Cell 3 reading = {reading_3:.2f}")
            time.sleep(0.1)

        self.get_logger().info("Load Cells initialized")

        ## Calibrate the load cells

        stop_tare = time.time() + 5

        load_cell_1_readings = np.array([])
        load_cell_2_readings = np.array([])
        load_cell_3_readings = np.array([])

        while time.time() < stop_tare:

            count_1, mode_1, reading_1 = self.load_cell_1.get_reading()
            count_2, mode_2, reading_2 = self.load_cell_2.get_reading()
            count_3, mode_3, reading_3 = self.load_cell_3.get_reading()

            if count_1 != c_1:
                c_1 = count_1
                load_cell_1_readings = np.append(load_cell_1_readings,reading_1)


            if count_2 != c_2:
                c_2 = count_2
                load_cell_2_readings = np.append(load_cell_2_readings,reading_2)

            if count_3 != c_3:
                c_3 = count_3
                load_cell_3_readings = np.append(load_cell_3_readings,reading_3)


        ## calculate thresholds for Load Cell 1 to detect outliers using the IQR

        # self.get_logger().info(f"Taring Load Cell 1 with {len(load_cell_1_readings)} values")
        # iqr_1 = np.percentile(load_cell_1_readings, 75) - np.percentile(load_cell_1_readings, 25)
        # outlier_thresh_low_1 = np.percentile(load_cell_1_readings, 25) - 1.5 * iqr_1
        # outlier_thresh_high_1 = np.percentile(load_cell_1_readings, 75) + 1.5 * iqr_1

        # load_cell_1_readings_cleaned = np.where((load_cell_1_readings < outlier_thresh_low_1) | (load_cell_1_readings > outlier_thresh_high_1), np.nan, load_cell_1_readings)

        # offset_1 = np.nanmean(load_cell_1_readings_cleaned)
        # self.get_logger().info(f"Taring Load Cell 1 with {len(load_cell_1_readings)} values")

        ## calculate thresholds for Load Cell 2 to detect outliers using the IQR

        # self.get_logger().info(f"Taring Load Cell 2 with {len(load_cell_2_readings)} values")
        # iqr_2 = np.percentile(load_cell_2_readings, 75) - np.percentile(load_cell_2_readings, 25)
        # outlier_thresh_low_2 = np.percentile(load_cell_2_readings, 25) - 1.5 * iqr_2
        # outlier_thresh_high_2 = np.percentile(load_cell_2_readings, 75) + 1.5 * iqr_2

        # load_cell_2_readings_cleaned = np.where((load_cell_2_readings < outlier_thresh_low_2) | (load_cell_2_readings > outlier_thresh_high_2), np.nan, load_cell_2_readings)

        # offset_2 = np.nanmean(load_cell_2_readings_cleaned)

        # calculate thresholds for Load Cell 3 to detect outliers using the IQR

        self.get_logger().info(f"Taring Load Cell 3 with {len(load_cell_3_readings)} values")
        iqr_3 = np.percentile(load_cell_3_readings, 75) - np.percentile(load_cell_3_readings, 25)
        outlier_thresh_low_3 = np.percentile(load_cell_3_readings, 25) - 1.5 * iqr_3
        outlier_thresh_high_3 = np.percentile(load_cell_3_readings, 75) + 1.5 * iqr_3

        load_cell_3_readings_cleaned = np.where((load_cell_3_readings < outlier_thresh_low_3) | (load_cell_3_readings > outlier_thresh_high_3), np.nan, load_cell_3_readings)

        offset_3 = np.nanmean(load_cell_3_readings_cleaned)


        self.load_cell_1 = HX711.sensor(self.pi, DATA=2, CLOCK=3,offset=0,gain=1)
        self.load_cell_2 = HX711.sensor(self.pi, DATA=9, CLOCK=11,offset=0,gain=1)
        self.load_cell_3 = HX711.sensor(self.pi, DATA=20, CLOCK=21,offset=offset_3,gain=1)

        # self.get_logger().info(f"Load Cell 1 Tared with offset {offset_1:.2f} values")
        # self.get_logger().info(f"Load Cell 2 Tared with offset {offset_2:.2f} values")
        self.get_logger().info(f"Load Cell 3 Tared with offset {offset_3:.2f} values")

        time.sleep(2) # allow to read offsets

        stop_tare_initialize = time.time() + 3
        while time.time() < stop_tare_initialize: # First readings were usually inaccurate
            c_1, mode_1, reading_1 = self.load_cell_1.get_reading()
            c_2, mode_2, reading_2 = self.load_cell_2.get_reading()
            c_3, mode_3, reading_3 = self.load_cell_3.get_reading()
            self.get_logger().info(f"Load Cell 1 reading = {reading_1:.2f}, Load Cell 2 reading = {reading_2:.2f}, Load Cell 3 reading = {reading_3:.2f}")
            time.sleep(0.1)


        self.get_logger().info(f"Test Stand Planner node can be launched")

        self.timer = self.create_timer(0.1, self.log_callback)

    def log_callback(self):

        if self.stop_logging != True:

            current_time = float(self.get_clock().now().nanoseconds) / 1e9

            c_1, mode_1, reading_1 = self.load_cell_1.get_reading()
            c_2, mode_2, reading_2 = self.load_cell_2.get_reading()
            c_3, mode_3, reading_3 = self.load_cell_3.get_reading()

            self.get_logger().info(f"Load Cell 1 reading = {reading_1:.2f}, Load Cell 2 reading = {reading_2:.2f}, Load Cell 3 reading = {reading_3:.2f}")

            load_cell_data =[c_1, reading_1, c_2, reading_2, c_3, reading_3]

            data = [current_time, self.last_servo_command, self.last_motor_command] + load_cell_data 
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