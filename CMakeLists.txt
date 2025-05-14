cmake_minimum_required(VERSION 3.8)
project(video_capture)

# Required to find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(image_transport REQUIRED)

# Create executable
add_executable(video_publisher src/video.cpp)

# Include directories
target_include_directories(video_publisher PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${OpenCV_INCLUDE_DIRS}
)

# Link libraries
ament_target_dependencies(video_publisher
  rclcpp
  sensor_msgs
  cv_bridge
  OpenCV
  image_transport
)

# Install
install(TARGETS video_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
