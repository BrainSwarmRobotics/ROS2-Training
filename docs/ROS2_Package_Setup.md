# 📦 ROS2 Package Setup Guide

This guide walks you through how to properly set up a ROS 2 package using both **Python** and **C++** nodes. It includes the directory structure, CMakeLists configurations, and install directives essential for building and installing packages correctly.

------

## 🗂️ Recommended Folder Structure

```
ros2_ws/
└── src/
    └── my_package/
        ├── CMakeLists.txt
        ├── package.xml
        ├── launch/
        ├── scripts/          # For Python nodes (ensure they are executable)
        │   └── my_node.py
        └── src/              # For C++ source files
            └── my_node.cpp
```

------

## 🐍 Setting Up Python-Based ROS 2 Package

### ➕ CMakeLists.txt (Python)

```
cmake_minimum_required(VERSION 3.5)
project(my_python_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

install(PROGRAMS
  scripts/my_node.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  scripts
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
```

> ✅ Make sure your Python scripts are executable:

```
chmod +x scripts/my_node.py
```

------

## ⚙️ Setting Up C++-Based ROS 2 Package

### ➕ CMakeLists.txt (C++)

```
cmake_minimum_required(VERSION 3.5)
project(my_cpp_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(hello_publisher src/hello_publisher.cpp)

ament_target_dependencies(hello_publisher
  rclcpp
  std_msgs
)

install(TARGETS
  hello_publisher
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
```

------

## 📦 package.xml (common for both)

```
<?xml version="1.0"?>
<package format="3">
  <name>my_package</name>
  <version>0.0.1</version>
  <description>Sample ROS2 package</description>
  <maintainer email="you@example.com">Your Name</maintainer>
  <license>MIT</license>

  <buildtool_depend>ament_cmake</buildtool_depend>

  <!-- For Python -->
  <exec_depend>rclpy</exec_depend>

  <!-- For C++ -->
  <build_depend>rclcpp</build_depend>
  <exec_depend>rclcpp</exec_depend>

  <exec_depend>std_msgs</exec_depend>
</package>
```

------

## ⚙️ Custom Service Interfaces in CMAKESLIST File

These additional lines are added to `CMAKESLIST.txt` file for custom service interfaces

```
find_package(rosidl_default_generators REQUIRED)
find_package(${PROJECT_NAME} REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "srv/AddThreeInts.srv"
 )
```

Add these additional lines in `package.xml` file

```
<build_depend>rosidl_default_generators</build_depend>

<exec_depend>rosidl_default_runtime</exec_depend>

<member_of_group>rosidl_interface_packages</member_of_group>
```

## ⚙️ Example `CMAKESLIST.TXT` File with Service Interface

```
cmake_minimum_required(VERSION 3.8)
project(add_two_ints)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(add_two_ints REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/AddTwoInts.srv"
 )

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
ament_target_dependencies(add_two_ints_client
  rclcpp
  std_msgs
  add_two_ints
)

add_executable(add_two_ints_server src/add_two_ints_server.cpp)
ament_target_dependencies(add_two_ints_server
  rclcpp
  std_msgs
  add_two_ints
)

install(TARGETS
  add_two_ints_client
  add_two_ints_server
  DESTINATION lib/${PROJECT_NAME}
)

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
```



## 🚀 Building the Package

```
cd ~/ros2_ws
colcon build --packages-select my_package
source install/setup.bash
```

------

## 🧪 Running the Nodes

### Python Node

```
ros2 run my_python_pkg my_node
```

### C++ Node

```
ros2 run my_cpp_pkg hello_publisher
```

------

## 📌 Notes

- Python files must be in the `scripts/` folder and be marked as executable.
- All launch files and other resources can be placed under `launch/` and installed via `install(DIRECTORY...)`.
- Python scripts are installed using `install(PROGRAMS ...)`.
- C++ executables require `add_executable(...)` and `ament_target_dependencies(...)`.