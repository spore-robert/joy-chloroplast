#!/usr/bin/env bash
bash_path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
evn_path=$(cd $bash_path && cd .. && pwd)
source $evn_path/environment.sh

wait_t=5
echo "kill all screen"
screen -d -m -S load_kill bash -c $bash_path/load_kill.sh
echo "release bluetooth need wait" $wait_t " second"
sleep $wait_t

echo "Load connectBT Human"
echo $path/bt_shell/connectHuman.sh
screen -d -m -S connectBTHuman bash -c $bash_path/bt_shell/connectHuman.sh
sleep 2

echo "Load roscore"
screen -d -m -S roscore bash -c $bash_path/load_roscore.sh
sleep 2

_delay=0.5
#while ! rosnode list | grep "/rosout"  >/home/spore/tmp/log.txt ; do
while ! rosnode list | grep "/rosout"   ; do
    echo "master "$master_ip" is not wakeup"
    sleep $_delay
done


echo "Load rosserial human detect"
screen -d -m -S rosserialHuman  bash -c $bash_path/load_human.sh
sleep 3
#echo "Load load_pyPose"
#screen -d -m -S load_pyPose bash -c '/home/sporev/bluetooth/arm/load_pyPose.sh'
#sleep 1
##echo "Load Nav"
##screen -d -m -S load_nav bash -c '/home/lidar/demo_0120/load_nav.sh'
##sleep 3


