#!/usr/bin/env bash
path=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $path
cd ..
path=$(pwd)
source $path/environment.sh

roslaunch alert_pi human_node.launch

