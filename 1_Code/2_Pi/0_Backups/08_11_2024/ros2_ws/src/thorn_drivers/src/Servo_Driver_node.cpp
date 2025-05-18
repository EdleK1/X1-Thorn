#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <pigpiod_if2.h>

const int PWM_pin1 = 18;  // GPIO18 (BCM numbering) for Servo 1
const int PWM_pin2 = 25;  // GPIO25 (BCM numbering) for Servo 2

class Servo_Driver_node : public rclcpp::Node {
public:
    int gpioHandle;

    Servo_Driver_node() : Node("Servo_Driver_node") {

        RCLCPP_INFO(this->get_logger(), "Servo Driver node initialized");

        subscription_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(
            "/Feed_Forward/Servo", 10,
            std::bind(&Servo_Driver_node::topic_callback, this, std::placeholders::_1)
        );

        // Initialize pigpio and set gpioHandle
        gpioHandle = pigpio_start(NULL, NULL);

        if (gpioHandle < 0) {
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize pigpio");
            return;
        }

        int set_mode_response_servo1 = set_mode(gpioHandle, PWM_pin1, PI_OUTPUT);
        int set_mode_response_servo2 = set_mode(gpioHandle, PWM_pin2, PI_OUTPUT);

        if (gpioHandle >= 0 && set_mode_response_servo1 == 0 && set_mode_response_servo2 == 0) {
            RCLCPP_INFO(this->get_logger(), "pigpio succesfully initialized");
            return;
        }
        
    }

    ~Servo_Driver_node() {
        if (gpioHandle >= 0) {
            pigpio_stop(gpioHandle); // Terminate pigpio when the node is destroyed
        }
    }

private:
    void topic_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg) {
        if (msg->data.size() != 2) {
            RCLCPP_ERROR(this->get_logger(), "Received invalid data size. Expected 2 floats.");
            return;
        }

        // Read the two floats from the message
        float servo1_value = msg->data[0];
        float servo2_value = msg->data[1]; 

        // Convert the float values (assumed to be in the range -1 to 1) to PWM duty cycle (500-2500)
        int pwm_value1 = static_cast<int>(1520 + 330 * servo1_value); // a bit of safety factor
        int pwm_value2 = static_cast<int>(1520 + 330 * servo2_value);

        RCLCPP_INFO(this->get_logger(), "pwm received: Servo1 = %d, Servo2 = %d", pwm_value1, pwm_value2);

        // Set the PWM output for the servos
        set_servo_pulsewidth(gpioHandle, PWM_pin1, pwm_value1);  // Set PWM for Servo 1
        set_servo_pulsewidth(gpioHandle, PWM_pin2, pwm_value2);  // Set PWM for Servo 2

        // Get the PWM output for the servos (to validate)
        int actual_pwm_value1 = get_servo_pulsewidth(gpioHandle, PWM_pin1);
        int actual_pwm_value2 = get_servo_pulsewidth(gpioHandle, PWM_pin2);

        RCLCPP_INFO(this->get_logger(), "pwm set to: Servo1 = %d, Servo2 = %d", actual_pwm_value1, actual_pwm_value2);
    }

    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Servo_Driver_node>());
    rclcpp::shutdown();
    return 0;
}