#!/usr/bin/env bash
path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
echo $path
#release bluetooth connect
#echo $home
#disconnect=$path/bt_shell/disconnectCar.sh
#echo $disconnect
#$disconnect

#disconnect==$path/bt_shell/disconnectAudio.sh
#echo $disconnect
#$disconnect

disconnect=$path/bt_shell/disconnectHuman.sh
echo $disconnect
$disconnect

echo "release bluetooth need wait 5 second"
sleep 1

killall screen


