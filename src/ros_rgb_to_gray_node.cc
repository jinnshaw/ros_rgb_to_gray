
#include "ros_rgb_to_gray/rgb_to_gray.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "rgb_to_gray");
	RGBToGray rtg;
	ros::spin();
	return 0;
}
