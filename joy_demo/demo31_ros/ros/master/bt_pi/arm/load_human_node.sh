#!/usr/bin/env bash
bash_path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
evn_path=$(cd $bash_path && cd .. && pwd)
source $evn_path/environment.sh

wait_t=3
echo "kill all screen"
screen -d -m -S load_kill bash -c $bash_path/load_kill.sh
echo "release bluetooth need wait" $wait_t " second"
sleep $wait_t




_delay=0.5
while ! rosnode list | grep "/rosout"  >/home/pi/tmp/log.txt ; do
    echo "master "$master_ip" is not wakeup"
    sleep $_delay
done

echo "Load rosserial human detect"
screen -d -m -S Human_node  bash -c $bash_path/load_human_node.sh
sleep 3

