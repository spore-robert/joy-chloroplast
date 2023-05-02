

echo "kill all screen"
screen -d -m -S load_kill bash -c '/home/sporev/bluetooth/arm/load_kill.sh'
sleep 15
echo "Load roscore"
screen -d -m -S load_roscore bash -c '/home/sporev/bluetooth/arm/load_roscore.sh'
sleep 2
echo "Load connectBT Human"
screen -d -m -S load_connectBTHuman bash -c '/home/sporev/bluetooth/arm/bt_shell/connectHuman.sh'
sleep 1
echo "Load connectBT Car"
screen -d -m -S load_connectBTCar bash -c '/home/sporev/bluetooth/arm/bt_shell/connectCar.sh'
sleep 5
echo "Load rosserial car"
screen -d -m -S load_rosserialcar bash -c '/home/sporev/bluetooth/arm/load_serial_car.sh'
sleep 1
echo "Load rosserial human detect"
screen -d -m -S load_rosserialHuman bash -c '/home/sporev/bluetooth/arm/load_serial_human.sh'
sleep 1
echo "Load load_pyPose"
screen -d -m -S load_pyPose bash -c '/home/sporev/bluetooth/arm/load_pyPose.sh'
sleep 1
##echo "Load Nav"
##screen -d -m -S load_nav bash -c '/home/lidar/demo_0120/load_nav.sh'
##sleep 3


