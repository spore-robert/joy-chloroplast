#source /home/lidar/.bashrc
source /home/sporev/workspace/devel/setup.bash
export ROS_MASTER_URI=http://192.168.1.201:11311/
#export ROS_MASTER_URI=http://127.0.0.1:11311/
#export ROS_MASTER_URI=http://192.168.168.20:11311/
export ROS_HOSTNAME=192.168.1.202

roslaunch robot_launch_controller r2d2_waypoints_rviz.launch --screen
