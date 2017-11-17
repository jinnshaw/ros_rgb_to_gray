
#include "ros_rgb_to_gray/rgb_to_gray.h"

static const std::string INPUT = "Input"; //
static const std::string OUTPUT = "Output"; //

RGBToGray::RGBToGray() :
	it_(nh_)
{

	image_sub_ = it_.subscribe("/usb_cam/image_raw", 1, &RGBToGray::convertCallBack, this);
	cv::namedWindow(INPUT);
	cv::namedWindow(OUTPUT);
	//destroyAllWindows();
}

RGBToGray::~RGBToGray()
{
	cv::destroyWindow(INPUT);
	cv::destroyWindow(OUTPUT);
}

void RGBToGray::convertCallBack(const sensor_msgs::ImageConstPtr& msg)
{
	cv_bridge::CvImagePtr cv_ptr;

	try {
		cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::RGB8);
	} catch (cv_bridge::Exception& e) {
		ROS_ERROR("cv_bridge exception: %s", e.what()); 
		return;
	}
	imageProcess(cv_ptr->image);
}

void RGBToGray::imageProcess(cv::Mat img)
{
	cv::Mat img_out;
	cv::cvtColor(img, img_out, CV_RGB2GRAY);
	cv::imshow(INPUT, img);
	cv::imshow(OUTPUT, img_out);
	cv::waitKey(5);
}

