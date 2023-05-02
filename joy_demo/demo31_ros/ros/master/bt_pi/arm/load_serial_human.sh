#!/usr/bin/env bash
path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $path
cd ..
path=$(pwd)
source $path/environment.sh

roslaunch rosserial_python human_ir.launch

