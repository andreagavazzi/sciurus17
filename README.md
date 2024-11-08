sciurus17_ros
====

[![industrial_ci](https://github.com/rt-net/sciurus17_ros/workflows/industrial_ci/badge.svg?branch=master)](https://github.com/rt-net/sciurus17_ros/actions?query=workflow%3Aindustrial_ci+branch%3Amaster)

![sciurus17_gazebo](https://rt-net.github.io/images/sciurus17/sciurus17_gazebo.png "sciurus17_gazebo")

ROS Packages for Sciurus17.

Product page:  
[https://www.rt-net.jp/products/sciurus17](https://www.rt-net.jp/products/sciurus17?lang=en)

ROS Wiki:  
[https://wiki.ros.org/sciurus17](https://wiki.ros.org/sciurus17)

Examples:  
[sciurus17_examples](./sciurus17_examples/README.en.md).

## System Requirements

These packages have been developed and tested on ROS Noetic.
Please see below for details.

- ROS
  - Noetic on Ubuntu 20.04.3 LTS

- ROS 2
  - [Humble](https://github.com/rt-net/sciurus17_ros/tree/humble-devel)

## Installation

### Build from source

- Install ROS environments.

- Download the packages for Sciurus17

  ```bash
  cd ~/catkin_ws/src
  git clone https://github.com/rt-net/sciurus17_ros.git
  ```

- Download [sciurus17_description](https://github.com/rt-net/sciurus17_description) package.

  ```bash
  cd ~/catkin_ws/src
  git clone https://github.com/rt-net/sciurus17_description.git
  ```

- Install package dependencies.

  ```bash
  cd ~/catkin_ws/src

  rosdep install -r -y --from-paths . --ignore-src
  ```

- Build packages using `catkin_make`.

  ```bash
  cd ~/catkin_ws && catkin_make
  source ~/catkin_ws/devel/setup.bash
  ```

### Setup

Apply udev rules with the following commands to enable communication between `sciurus17_control` and Sciurus17.

```bash
roscd sciurus17_tools/scripts/
./create_udev_rules
```
Reboot the PC to update the udev rules.
The new device will be crea `/dev/sciurus17spine`

## Sciurus17 packages

### sciurus17_control

This package controls Sciurus17 using `Dynamixel SDK C++ Library`
which can install by `rosdep install` command.
Read and write permissions on `/dev/sciurus17spine` 
are required for communication between the package and Sciurus17.

The device name of serial port and parameters of Dynamixel servo motors are listed in:

- `config/sciurus17_control1.yaml`
- `config/sciurus17_control2.yaml`
- `config/sciurus17_control3.yaml`

If this package did not find the serial port, the package switches its control mode to Dummy Joint Mode from Normal Mode
and republishes target joint values as servo angle values.
This is useful for debugging of motion control without Sciurus17 hardware.

At startup, this package moves the Sciurus17 to Home Position in 5 seconds.
At shutdown, this package decreases PID gains of the servo motors to stop motion safely.

### sciurus17_moveit_config

This package includes configuration files for MoveIt.

To launch the MoveIt demonstration with Rviz:

```bash
roslaunch sciurus17_moveit_config demo.launch
```

### sciurus17_msgs

This package defines ROS message types for Sciurus17.

### sciurus17_vision

This package includes launch files for camera nodes.

### sciurus17_bringup

This package includes launch files for startup of Sciurus17.

### sciurus17_tools

This package includes option tools for Sciurus17.

If the head camera (RealSense) is unstable, please run the following command before startup.

```bash
rosrun sciurus17_tools realsense_hwreset
```

### sciurus17_gazebo

This package includes Gazebo simulation environments for Sciurus17.

```bash
roslaunch sciurus17_gazebo sciurus17_with_table.launch
```

**NOTE:** First launch will take long time to download gazebo models. Please wait until Gazebo screen is displayed.

### sciurus17_examples

This package includes example codes for Sciurus17.
Please refer to [./sciurus17_examples/README.en.md](./sciurus17_examples/README.en.md).


