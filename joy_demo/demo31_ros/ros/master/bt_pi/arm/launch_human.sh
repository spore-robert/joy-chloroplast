#!/usr/bin/env bash

x=0

_delay=0.5
_count=600
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

path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $path
cd ..
path=$(pwd)
source $path/environment.sh

roslaunch alert_pi human_node.launch

