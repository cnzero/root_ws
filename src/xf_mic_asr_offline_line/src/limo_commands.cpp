/**************************************************************************
作者：caidx1
功能：录音调用控制器，包含休眠功能
**************************************************************************/
#include <user_interface.h>
#include <string>
#include <locale>
#include <codecvt>
#include <ctime>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <xf_mic_asr_offline_line/Get_Offline_Result_srv.h>
#include <xf_mic_asr_offline_line/Pcm_Msg.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int32.h>
#include <sys/stat.h>
#include <iostream>
#include <geometry_msgs/Twist.h>

using namespace std;
int awake_flag = 0;    //唤醒标志位
int confidence_threshold ;
int seconds_per_order ;
int recognize_fail_count = 0;  //被动休眠相关变量


/**************************************************************************
函数功能：唤醒标志subscribe回调函数
入口参数：唤醒标志位awake_flag_msg  voice_control.cpp
返回  值：无
**************************************************************************/
void awake_flag_callback(std_msgs::Int8 msg)
{
	awake_flag = msg.data;
	printf("awake_flag=%d\n",awake_flag);
	recognize_fail_count = 0;
}


/**************************************************************************
函数功能：主函数
入口参数：无
返回  值：无
**************************************************************************/
int main(int argc, char *argv[])
{
	//int temp=0;
	   
	int recognize_fail_count_threshold = 15;    //识别失败次数阈值
	
	string str1 = "ok";				//语音识别相关字符串
	string str2 = "fail";				//语音识别相关字符串
	string str3 = "小车休眠";				//语音识别相关字符串
	string str4 = "失败5次";				//语音识别相关字符串
	string str5 = "失败10次";				//语音识别相关字符串

	// IoT commands words
	string str_cmd = "";
	string str_cmd_words = "";
	string str_IoT_word_L0 = "关闭左灯";
	string str_IoT_word_L1 = "打开左灯";
	string str_IoT_word_R0 = "关闭右灯";
	string str_IoT_word_R1 = "打开右灯";

    std_msgs::String emoji_flag_msg;
	string str_emoji_0 = "";  // 唤醒
	string str_emoji_1 = "我很不屑";
	string str_emoji_2 = "我很兴奋";
	string str_emoji_3 = "我很惊恐";
	string str_emoji_4 = "我很愤怒";
	string str_emoji_5 = "我很难过";

	ros::init(argc, argv, "limo_voice_recognize_commands_publish");    //初始化ROS节点
	ros::NodeHandle nh;    //创建句柄
 
	/***离线命令词识别服务客户端创建***/
	ros::ServiceClient get_offline_recognise_result_client = 
	nh.serviceClient<xf_mic_asr_offline_line::Get_Offline_Result_srv>("xf_asr_offline_node/get_offline_recognise_result_srv");
	
	/***修改唤醒词服务客户端创建***/
	//ros::ServiceClient Set_Awake_Word_client =
	//nh.serviceClient<xf_mic_asr_offline_line::Set_Awake_Word_srv>("xf_asr_offline_node/set_awake_word_srv");

	/***唤醒标志位话题订阅者创建***/
	ros::Subscriber awake_flag_sub = nh.subscribe("awake_flag", 1, awake_flag_callback);

	/***唤醒标志位话题发布者创建***/
	ros::Publisher awake_flag_pub = nh.advertise<std_msgs::Int8>("awake_flag", 1);
	ros::Publisher emoji_flag_pub = nh.advertise<std_msgs::String>("emoji", 1);

	/***离线命令词识别结果话题发布者创建***/
	ros::Publisher control = nh.advertise<std_msgs::String>("voice_words", 1);

	/***IoT控制命令字符串发布***/
	ros::Publisher IoT_commands_pub = nh.advertise<std_msgs::String>("IoT_commands", 1);

	ros::Rate loop_rate(10);    //循环频率10Hz


	nh.param("/confidence", confidence_threshold, 18);
	nh.param("/seconds_per_order", seconds_per_order, 3);

  /***请求修改唤醒词服务***/
	//xf_mic_asr_offline_line::Set_Awake_Word_srv SetAwakeWord_srv;
	//SetAwakeWord_srv.request.awake_word="小车小车";
	//Set_Awake_Word_client.call(SetAwakeWord_srv);
  /***等待服务应答***/
	//std::cout << "Set_Awake_Word: " << SetAwakeWord_srv.response.result << endl;

  /***离线命令词识别服务参数设置***/
	xf_mic_asr_offline_line::Get_Offline_Result_srv GetOfflineResult_srv;
	GetOfflineResult_srv.request.offline_recognise_start = 1;
	GetOfflineResult_srv.request.confidence_threshold = confidence_threshold;
	GetOfflineResult_srv.request.time_per_order = seconds_per_order;


	while(ros::ok())
	{
		if(awake_flag)    //判断休眠状态还是唤醒状态
		{

			if(get_offline_recognise_result_client.call(GetOfflineResult_srv))    //请求离线命令词识别服务并返回应答为调用成功
			{
				//ROS_INFO("succeed to call service \"get_offline_recognise_result_srv\"!");    //打印识别结果、置信度、识别命令词等信息
				std::cout << "\niFLYTEK offline ASR inference:" << endl;
				std::cout << "result: " << GetOfflineResult_srv.response.result << endl;
				std::cout << "fail reason: " << GetOfflineResult_srv.response.fail_reason << endl;
				std::cout << "text: " << GetOfflineResult_srv.response.text << endl;

				// voice words compare and publish to later Android
				std_msgs::String command;
				if(str_IoT_word_L0 == GetOfflineResult_srv.response.text)
				{
					str_cmd = "L0";
					str_cmd_words = str_IoT_word_L0;
				}

				else if(str_IoT_word_L1 == GetOfflineResult_srv.response.text)
				{
					str_cmd = "L1";
					str_cmd_words = str_IoT_word_L1;
				}

				else if(str_IoT_word_R0 == GetOfflineResult_srv.response.text)
				{
					str_cmd = "R0";
					str_cmd_words = str_IoT_word_R0;
				}

				else if(str_IoT_word_R1 == GetOfflineResult_srv.response.text)
				{
					str_cmd = "R1";
					str_cmd_words = str_IoT_word_R1;
				}

				else if(str_emoji_1 == GetOfflineResult_srv.response.text)
				{
					emoji_flag_msg.data = "1";
				}

				else if(str_emoji_2 == GetOfflineResult_srv.response.text)
				{
					emoji_flag_msg.data = "2";
				}

				else if(str_emoji_3 == GetOfflineResult_srv.response.text)
				{
					emoji_flag_msg.data = "3";
				}

				else if(str_emoji_4 == GetOfflineResult_srv.response.text)
				{
					emoji_flag_msg.data = "4";
				}

				else if(str_emoji_5 == GetOfflineResult_srv.response.text)
				{
					emoji_flag_msg.data = "5";
				}

				else
				{
					str_cmd = "NULL";
					str_cmd_words = "没听懂";
					printf("voice words command not recognized or pre-set.");

					emoji_flag_msg.data = "NULL";
				}
				command.data = str_cmd;
				IoT_commands_pub.publish(command);
				std::cout << "\nPublish command --->>> " << str_cmd << str_cmd_words << "\n" << endl;

				emoji_flag_pub.publish(emoji_flag_msg);
				std::cout << "\nPublish emoji--->>> " << emoji_flag_msg.data << "\n" << endl;

			}

			else        //请求离线命令词识别服务并返回应答为调用失败
			{
				ROS_INFO("failed to call service \"get_offline_recognise_result_srv\"!");
				//awake_flag=0;
				continue;
			}
			
		}		
		//printf("awake_flag=%d\n",awake_flag);
		//printf("-----confidence_threshold =%d\n",confidence_threshold);
		//printf("seconds_per_order =%d\n",seconds_per_order); 
		ros::spinOnce();    
		loop_rate.sleep();    //10Hz循环
		
	}

}
