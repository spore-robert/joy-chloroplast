x=0
while ! ifconfig | grep "192.168.0.192" > /dev/null ; do
#while ! ifconfig | grep "127.0.0.1" > /dev/null ; do
    echo "no nework"
    if "$x" -gt 200; then
        #Time out here
        exit 1
    x=$((x+1))
    sleep .1
    fi
done

source /home/sporev/turtlebot_arm/devel/setup.bash
#source /home/lidar/.bashrc
export ROS_MASTER_URI=http://192.168.0.192:11311/
#export ROS_MASTER_URI=http://127.0.0.1:11311/
#export ROS_MASTER_URI=http://192.168.168.20:11311/
export ROS_HOSTNAME=192.168.0.192

roscore
