# 🤖 ROS 2 Training Workshop: From Foundations to Deployment

Welcome to the **ROS 2 Training Workshop** GitHub repository! This hands-on, self-paced resource is designed to guide you through the fundamentals and real-world applications of the Robot Operating System 2 (ROS 2).

Whether you're a beginner, intermediate, or aspiring roboticist, this course provides you with:
- 🌐 Self-paced learning resources
- 🧠 Real-world use cases
- 🛠️ Simulations & robot demonstrations
- 📦 All files and simulation assets included
- 🏅 Certificate of Completion upon submission

---

## 📌 Table of Contents

1. [Why ROS 2?](#why-ros-2)
2. [Workshop Structure](#workshop-structure)
3. [System Requirements](#system-requirements)
4. [Getting Started](#getting-started)
5. [Training Modules](#training-modules)
6. [Capstone Projects](#capstone-projects)
7. [Contribution Guidelines](#contribution-guidelines)
8. [License](#license)

---

## 🚀 Why ROS 2?

Modern robotics needs a middleware that can scale across platforms, languages, and use cases.

> ⚠️ The Challenge: Low-level control (e.g. microcontrollers in C++) needs to interoperate with high-level modules like perception (often in Python). Bridging the gap is complex.

**✅ ROS 2 solves this by acting as a communication middleware**, seamlessly integrating distributed robotic components.

---

## 📚 Workshop Structure

This repository contains the following major components:

- 📁 `assets/`: Images and other illustrations used in Repository
- 📁 `docs/`: ROS 2 core concepts (nodes, topics, services, actions, parameters)
- 📁 `ros2_simulation/`: Gazebo simulations, RViz visualization, robot model files (URDF/Xacro)
- 📁 `capstone_project/`: Self-paced real-world project instructions with source code
- 📁 `hardware_interface/`: Real robot interface and launch configuration
- 📁 `presentations/`: Ready-to-use `.pptx` and PDFs for workshop delivery

---

## 🖥️ System Requirements

- OS: Ubuntu 22.04 (recommended)
- ROS Version: **Humble Hawksbill** or **Jazzy **
- Python 3.10+
- Gazebo Fortress or Ignition Edifice (optional)
- colcon build system
- git, vcs, and rosdep

---

## 🛠️ Getting Started

1. Clone the repo:
```bash
git clone https://github.com/your-org/ros2-training-workshop.git
cd ros2-training-workshop
```

## 🧱 Training Modules

| Module                   | Description                                        |
| ------------------------ | -------------------------------------------------- |
| 01. ROS 2 Architecture   | Understand nodes, DDS, topics, services, executors |
| 02. Launch System        | Python launch files, namespaces, remapping         |
| 03. Simulation Setup     | Gazebo + RViz with ROS 2                           |
| 04. Real Robot Interface | Hardware abstraction using ROS 2 Control           |
| 05. Perception & Mapping | Integrate sensors like camera, lidar, IMU          |
| 06. Navigation           | Path planning, localization, controller tuning     |
| 07. Capstone Project     | Full robotic product development from scratch      |