#source /home/lidar/.bashrc
source /home/sporev/turtlebot_arm/devel/setup.bash
export ROS_MASTER_URI=http://192.168.0.192:11311/
#export ROS_MASTER_URI=http://127.0.0.1:11311/
#export ROS_MASTER_URI=http://192.168.168.20:11311/
export ROS_HOSTNAME=192.168.0.192



roslaunch turtlebot_arm_bringup arm.launch --screen
