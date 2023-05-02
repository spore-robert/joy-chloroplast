x=0
while ! ifconfig | grep "192.168.0.192" > /dev/null ; do
#while ! ifconfig | grep "127.0.0.1" > /dev/null ; do
    echo "no nework"
    if [ "$x" -gt 200 ]; then
        #Time out here
        exit 1
    x=$((x+1))
    sleep .1
    fi
done

echo "Load core"
screen -d -m -S load_core bash -c '/home/sporev/spore_turtlebot/load_core.sh'
sleep 3

echo "Load arm"
screen -d -m -S load_arm bash -c '/home/sporev/spore_turtlebot/load_arm.sh'
sleep 5

echo "Load moveit"
screen -d -m -S load_moveit bash -c '/home/sporev/spore_turtlebot/load_moveit.sh'
sleep 5

##echo "Load ICP"
##screen -d -m -S load_icp bash -c '/home/lidar/demo_0120/load_icp.sh'
##sleep 5
##echo "Load Nav"
##screen -d -m -S load_nav bash -c '/home/lidar/demo_0120/load_nav.sh'
##sleep 3


