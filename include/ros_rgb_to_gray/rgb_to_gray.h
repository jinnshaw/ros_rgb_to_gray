
#ifndef ROS_RGB_TO_GRAY_H_
#define ROS_RGB_TO_GRAY_H_

#include <ros/ros.h>
#include <iostream>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class RGBToGray
{
private:
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;
	//image_transport::Publisher image_pub_;

public:
	RGBToGray();

	~RGBToGray();

	void convertCallBack(const sensor_msgs::ImageConstPtr& msg);

	void imageProcess(cv::Mat img);

};

#endif //ROS_RGB_TO_GRAY_H_
