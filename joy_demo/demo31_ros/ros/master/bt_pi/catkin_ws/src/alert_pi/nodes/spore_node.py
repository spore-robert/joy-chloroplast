#!/usr/bin/env python


import rospy
import subprocess
from std_msgs.msg import String


def callback(data):
    #rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)
    if  data.data=="shutdown":
        command="echo sporefun | sudo -S shutdown now" 
        subprocess.call(command, shell=True)

def listener():

    rospy.init_node('sporez', anonymous=True)

    rospy.Subscriber('spore_cmd', String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
