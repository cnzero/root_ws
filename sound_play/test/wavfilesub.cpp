#include "ros/ros.h"
#include <std_msgs/String.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <std_msgs/ByteMultiArray.h>
#include <sound_play/sound_play.h>
#include <ros/package.h>

using namespace std;
bool wavflag = false;
std::string wavpath;

void subCallback(const std_msgs::ByteMultiArray::ConstPtr& msg)
{
    //"/home/jetson/transbot_ws/src/sound_play/sounds/123.wav"
    std::ofstream out(wavpath.c_str(), ios::trunc);
//    out << msg->data.c_str() << std::endl; 
//    out.close();
    std_msgs::ByteMultiArray btmly;
    btmly.data = msg->data;
    for (int i = 0; i < btmly.data.size(); i++)
    {
        //ROS_INFO("%c", btmly.data[i]);
        out << btmly.data[i];
    }
    out.close();
    wavflag = true;
    ROS_INFO("wav File received successful!\r\n");
    //ROS_INFO("%s\r\n", msg->data.c_str());
}
 
int main(int argc, char **argv){

    ros::init(argc,argv,"sound_play_test"); //初始化节点
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("tts_file", 1, subCallback);
    
    // path
    wavpath = ros::package::getPath("sound_play");
    wavpath += "/sounds/123.wav";
    // sound_play
    sound_play::SoundClient sc;
    ros::Duration(1).sleep();
    //sc.say("Hello world!");
    ros::Rate r(10);
    while(nh.ok())
    {
        if (wavflag)
        {
            sc.playWave(wavpath.c_str());
            wavflag = false;
        }
    
        ros::spinOnce();
        r.sleep();
    }
    
    return 0;
}
