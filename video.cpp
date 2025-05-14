#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

class SimpleVideoNode : public rclcpp::Node {
public:
    SimpleVideoNode() : Node("simple_video_node") {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("video_frames", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(33),  // ~30fps
            [this]() { this->publish_frame(); });
    }

private:
    void publish_frame() {
        cv::Mat frame;
        cap_ >> frame;
        if(!frame.empty()) {
            auto msg = cv_bridge::CvImage(
                std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
            publisher_->publish(*msg);
        }
    }

    cv::VideoCapture cap_{0};  // Default camera
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleVideoNode>());
    rclcpp::shutdown();
    return 0;
}
