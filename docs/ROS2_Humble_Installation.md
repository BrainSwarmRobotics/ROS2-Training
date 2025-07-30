# 🚀 Getting Started with ROS 2 Humble on Ubuntu 22.04 in VMware

Welcome! This guide will help **absolute beginners** install **Ubuntu 22.04** in **VMware Workstation** and set up **ROS 2 Humble Hawksbill**, the Robot Operating System for robotics development.

---

## 📦 What You'll Need

- VMware Workstation or VMware Player (Windows/Linux)
- Ubuntu 22.04 ISO image
- At least 4 GB RAM (recommended: 8 GB)
- At least 25 GB of free disk space

---

## 🧰 Step 1: Download Required Software

1. **Download VMware:**
   - [VMware Workstation Player](https://www.vmware.com/products/workstation-player.html)

2. **Download Ubuntu 22.04 ISO:**
   - [Ubuntu 22.04 LTS](https://releases.ubuntu.com/22.04/)

---

## 🛠️ Step 2: Install Ubuntu 22.04 in VMware

1. Open VMware and create a **new virtual machine**.
2. Select **"Installer disc image file (iso)"** and browse to the Ubuntu 22.04 ISO.
3. Set name: `Ubuntu_22.04_ROS2`.
4. Allocate at least **25 GB of disk space**.
5. Set **memory to 4096 MB** (or more).
6. Finish setup and start the VM.
7. Follow on-screen instructions to install Ubuntu.

---

## 🤖 Step 3: Installing ROS 2 Humble on Ubuntu 22.04

### 🔧 1. Set Locale

```bash
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```

### 🧾 2. Add ROS 2 GPG Key and Repository

```

sudo apt install software-properties-common
sudo add-apt-repository universe
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo tee /etc/apt/trusted.gpg.d/ros.asc > /dev/null
```

Then add the ROS 2 repository:

```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/trusted.gpg.d/ros.asc] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```

### 📥 3. Install ROS 2 Humble

```
sudo apt update
sudo apt install ros-humble-desktop
```

```
sudo apt install ros-dev-tools
```

```
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
```

