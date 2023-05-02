#!/usr/bin/env python
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of Willow Garage, Inc. nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Revision $Id$

## Simple talker demo that listens to std_msgs/Strings published 
## to the 'chatter' topic

import rospy
import pygame
import subprocess
from std_msgs.msg import String
from datetime import date

play_state = 0
minVolume = 50
maxVolume = 100
curVolume = minVolume
def play_init(media_file):
    #filepath = r"output.mp3";
    today = date.today()
    endweek = today.strftime('%w')
    print "endweek",endweek
    #filepath = media_file+"demo"+endweek+".mp3"
    filepath = media_file+"demo1.mp3"
    print "filepath",filepath
    pygame.mixer.init()
    pygame.mixer.music.load(filepath)
    pygame.mixer.music.set_volume(minVolume)
    

def play_music():
    Volume = pygame.mixer.music.get_volume()
    print "volume = ",Volume
    if not pygame.mixer.music.get_busy():
       command="DISPLAY=:0 xset dpms force on"
       subprocess.call(command, shell=True)

       pygame.mixer.music.play()
    else:
       if Volume <= maxVolume:
         Volume+=10
         pygame.mixer.music.set_volume(Volume) 


def callback(data):
    #rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)
    if  data.data=="on":
        play_music()
    

def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('sporev_pi_alert', anonymous=True)
    media_file = rospy.get_param('~media_file','/home/sporev/bt_pi/catkin_ws/src/alert_pi/nodes/')

    rospy.Subscriber('sensor_pressure', String, callback)
    play_init(media_file)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
