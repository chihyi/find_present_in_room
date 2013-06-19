#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <tf/transform_broadcaster.h>

#include "find_present_in_room/Tag.h"
#include "find_present_in_room/Tags.h"
#include "find_present_in_room/marker.h"
#include "tf/tf.h"
#include "tf/tfMessage.h"

using namespace std;

struct Marker_localizer {

	// communication
	ros::NodeHandle nh_;
	ros::Subscriber sub_tf;



 void tfCB(const tf::tfMessageConstPtr msg)
 {

	 // get observations and correct
	 for(int i=0;i<msg->transforms.size();i++)
	 {
		 if(msg->transforms[i].header.frame_id == "/image_raw" &&
				 (msg->transforms[i].child_frame_id == "/4x4_1" || msg->transforms[i].child_frame_id == "/4x4_95"))
		 {

//			 // make rotation matrix
//			 tf::Matrix3x3 R;
//			 R.setRotation(tf::Quaternion(msg->transforms[i].transform.rotation.x,
//					 msg->transforms[i].transform.rotation.y,
//					 msg->transforms[i].transform.rotation.z,
//					 msg->transforms[i].transform.rotation.w));
//			 tf::Vector3 t = tf::Vector3(
//					 msg->transforms[i].transform.translation.x,
//					 msg->transforms[i].transform.translation.y,
//					 msg->transforms[i].transform.translation.z);

			 // add measurement
			 if(msg->transforms[i].child_frame_id == "/4x4_1")
			 {
				 cout << "detect Marker /4x4_1";
			 }
			 else
			 {
				 cout<<"detect Marker /4x4_95";
		 	 }
		 }
	 }

 }


 Marker_localizer(){

  sub_tf = nh_.subscribe("/tf",100,&Marker_localizer::tfCB, this);

 }
};

int main(int argc, char **argv)
{
 ros::init(argc, argv, "find_present");

 Marker_localizer localizer;

 return 0;
}
