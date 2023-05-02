x=0
while ! ifconfig | grep "192.168.1.202" > /dev/null ; do
#while ! ifconfig | grep "127.0.0.1" > /dev/null ; do
    echo "no nework"
    if [ "$x" -gt 200 ]; then
        #Time out here
        exit 1
    fi
    x=$((x+1))
    sleep .1
    
done


echo "Load rviz"
screen -d -m -S load_rviz bash -c '/home/sporev/spore_turtlebot/load_rviz.sh'
sleep 10
##echo "Load ICP"
##screen -d -m -S load_icp bash -c '/home/lidar/demo_0120/load_icp.sh'
##sleep 5
##echo "Load Nav"
##screen -d -m -S load_nav bash -c '/home/lidar/demo_0120/load_nav.sh'
##sleep 3


