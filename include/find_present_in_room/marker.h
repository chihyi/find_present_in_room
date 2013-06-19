/*
 * marker.h
 *
 *  Created on: Apr 18, 2012
 *      Author: Nikolas Engelhard
 */

#ifndef MARKER_H_
#define MARKER_H_


#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <tf/transform_broadcaster.h>
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

struct marker {

 void publish_markers();

 marker(){
  pub_markers = nh_.advertise<visualization_msgs::MarkerArray>( "poses_array", 0 );
 }


 void addMarkerPose(const tf::StampedTransform& trafo){
  trafos.push_back(trafo);
 }

 void init(){trafos.clear();}

 std::vector<tf::StampedTransform> trafos;

 ros::NodeHandle nh_;
 ros::Publisher pub_markers;
 tf::TransformBroadcaster br;

};

#endif /* MARKER_H_ */
