#source /home/lidar/.bashrc
source /home/sporev/bluetooth/catkin_ws/devel/setup.bash
export ROS_MASTER_URI=http://localhost:11311/
#export ROS_MASTER_URI=http://127.0.0.1:11311/
#export ROS_MASTER_URI=http://192.168.168.20:11311/
#export ROS_HOSTNAME=192.168.1.202

#roslaunch robot_launch_controller r2d2_waypoints_rviz.launch --screen

#rosrun rosserial_python serial_node.py /dev/ttyACM0
#rosrun rosserial_python serial_node.py /dev/rfcomm0
roslaunch rosserial_python car.launch
