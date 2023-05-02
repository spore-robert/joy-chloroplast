#!/usr/bin/env bash
x=0

_delay=0.5
_count=600
echo "check network status.."
while ! ifconfig | grep "192.168*" > /dev/null ; do
#while ! ifconfig | grep "127.0.0.1" > /dev/null ; do
    echo "no nework"
    if [ "$x" -gt $_count ]; then
        #Time out here
        exit 1
    fi
    x=$((x+1))
    sleep $_delay

done



echo "start launch screen"


path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

#echo "kill all screen"
#screen -d -m -S load_kill bash -c $path/load_kill.sh
#echo "release bluetooth need wait 5 second"
#sleep 3

#echo "Load roscore"
#screen -d -m -S roscore bash -c $path/load_roscore.sh
#sleep 2
#echo "Load connectBT Human"
#echo $path/bt_shell/connectHuman.sh
#screen -d -m -S connectBTHuman bash -c $path/bt_shell/connectHuman.sh
#sleep 1
#echo "Load connectBT Car"
#screen -d -m -S load_connectBTCar bash -c '/home/sporev/bluetooth/arm/bt_shell/connectCar.sh'
#sleep 5
#echo "Load rosserial car"
#screen -d -m -S load_rosserialcar bash -c '/home/sporev/bluetooth/arm/load_serial_car.sh'
sleep 1
echo "Load rosserial human detect"
/usr/bin/screen -d -m -S rosserialHuman  $path/launch_human.sh
sleep 1
#echo "Load load_pyPose"
#screen -d -m -S load_pyPose bash -c '/home/sporev/bluetooth/arm/load_pyPose.sh'
#sleep 1
##echo "Load Nav"
##screen -d -m -S load_nav bash -c '/home/lidar/demo_0120/load_nav.sh'
##sleep 3


