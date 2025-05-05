# Navigation-system
Multi-map navigation system for a robot
# Navigation System

## Overview

This project implements a **multi-map navigation system** for robots, where robots can navigate between mapped rooms using a **'wormhole' mechanism**. It is built using **ROS 2**, **C++**, and **SQLite** for managing wormhole positions. The system aims to improve the efficiency of robots by enabling seamless navigation between different environments, helping robots switch between various maps easily.

## Features

- Multi-map navigation with wormhole-based transitions.
- SQLite database for storing wormhole positions.
- ROS 2 integration for seamless communication with robots.
- Custom action server for handling navigation goals.
- Ability to reset the Adaptive Monte Carlo Localization (AMCL) after switching maps.
- Easy configuration for new maps and wormhole data.

## Prerequisites

Before running this project, ensure you have the following:

- **ROS 2** (Foxy, Galactic, or any other supported version).
- **C++** compiler.
- **SQLite** for managing the database.
- **Git** for version control.
- **Python** (for any Python-based components or tools).
- A **working robot** with ROS 2 set up.

### Installing Dependencies

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Darshi18/Navigation-system.git
   
   
2. Install ROS 2 (if you don't have it installed):
  Follow the installation guide for your specific version of ROS 2:

    ROS 2 Installation Guide
    https://docs.ros.org/en/humble/Installation.html

3. Install C++ dependencies:
   If there are any system dependencies required by C++ packages, install them using:

   sudo apt install <dependency-name>

4. Set up the SQLite database:
   The project uses an SQLite database (wormholes.db) to store the positions of the wormholes. Make sure to modify or create your database if needed. The structure of the database is simple and can be expanded as per requirements.

5. Install any Python dependencies (if applicable):

    pip install -r requirements.txt

**Usage**

After installing the necessary dependencies and setting up the environment, follow the steps below to use the navigation system:

   1. Launch the system:
    Use the following command to launch the robot’s navigation system. Modify the command based on your specific launch files:

     ros2 launch multi_map_nav bringup.launch.py

   2. Send navigation goals:
      You can send navigation goals to the robot via the MultiMapNavigate action server. For example, to navigate to a specific location in room2:

     ros2 action send_goal /multi_map_navigator MultiMapNavigate "x: 5.0, y: 10.0, theta: 1.57, target_map: 'room2'"

   3. Configure maps:
    Ensure that you have the necessary .yaml files and .pgm image files for the rooms/maps you are using in the project. These configuration files specify the layout of the rooms and the parameters for navigation.

    Example:

        room1.yaml

        room2.yaml

        room1.pgm

        room2.pgm

**Configuration**

    Maps Configuration:
    The .yaml files (e.g., room1.yaml, room2.yaml) define the map layout and navigation parameters. Modify these files as needed for new rooms or changes in the environment.

    Wormhole Database:
    The wormholes.db file contains the wormhole positions between different maps. You can modify this SQLite database to add or update wormhole entries. For example:

        Add a new wormhole between room1 and room2.

**Example**

Here’s an example of how to send a goal to navigate to a specific position using the action server:

ros2 action send_goal /multi_map_navigator MultiMapNavigate "x: 10.0, y: 15.0, theta: 0.0, target_map: 'room1'"

**Troubleshooting**
Common Issues

    Issue: Robot is not transitioning between maps.

        Solution: Ensure that the wormholes.db database is properly set up and contains valid entries for wormhole positions.

    Issue: AMCL localization is lost after map transition.

        Solution: Make sure to reset the AMCL after switching maps. You can do this by implementing an AMCL reset in the multi_map_navigator.cpp file.   
