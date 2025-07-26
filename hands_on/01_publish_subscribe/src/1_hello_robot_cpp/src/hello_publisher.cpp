#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class HelloRobotPublisher : public rclcpp::Node
{
public:
    HelloRobotPublisher()
    : Node("hello_robot_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("hello_robot_topic", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&HelloRobotPublisher::timer_callback, this)
        );
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello Robot! Count: " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HelloRobotPublisher>());
    rclcpp::shutdown();
    return 0;
}
