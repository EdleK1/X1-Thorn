cmake_minimum_required(VERSION 3.8)
project(thorn_drivers)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# ChatGPTXD v

# Locate the pigpio include directory and libraries
find_path(PIGPIO_INCLUDE_DIR NAMES pigpiod_if2.h pigpio.h)
find_library(PIGPIOD_IF2_LIBRARY NAMES pigpiod_if2 HINTS /usr/local/lib /usr/lib)
find_library(PIGPIO_LIBRARY NAMES pigpio HINTS /usr/local/lib /usr/lib)
find_library(RT_LIBRARY NAMES rt HINTS /usr/local/lib /usr/lib)
find_library(PTHREAD_LIBRARY NAMES pthread HINTS /usr/local/lib /usr/lib)

# ChatGPTXD ^

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(Servo_Driver_node src/Servo_Driver_node.cpp)
ament_target_dependencies(Servo_Driver_node rclcpp std_msgs)

target_include_directories(Servo_Driver_node PRIVATE ${PIGPIO_INCLUDE_DIR})

target_link_libraries(Servo_Driver_node ${PIGPIOD_IF2_LIBRARY} ${PIGPIO_LIBRARY} ${PTHREAD_LIBRARY} ${RT_LIBRARY})


install(TARGETS
  Servo_Driver_node
  DESTINATION lib/${PROJECT_NAME})



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()