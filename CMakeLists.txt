cmake_minimum_required(VERSION 2.8.3)
project(ros_rgb_to_gray)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)

catkin_package(
	#INCLUDE_DIRS include
	#LIBRARIES ros_rgb_to_gray
	#CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
	include
	${catkin_INCLUDE_DIRS}
)

#add_library(${PROJECT_NAME}
#	src/rgb_to_gray.cc
#)

add_executable(${PROJECT_NAME}_node 
	src/rgb_to_gray.cc
	src/ros_rgb_to_gray_node.cc
)

#add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
	${catkin_LIBRARIES}
	#	${PROJECT_NAME}
)

