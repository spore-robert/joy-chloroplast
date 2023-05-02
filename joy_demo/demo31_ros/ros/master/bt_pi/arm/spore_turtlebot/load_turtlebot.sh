#source /home/lidar/.bashrc
source /home/sporet/turtlebot/devel/setup.bash
export ROS_MASTER_URI=http://192.168.1.190:11311/
#export ROS_MASTER_URI=http://127.0.0.1:11311/
#export ROS_MASTER_URI=http://192.168.168.20:11311/
export ROS_HOSTNAME=192.168.1.190


roslaunch turtlebot_bringup minimal.launch
