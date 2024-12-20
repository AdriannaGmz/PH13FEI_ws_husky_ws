/*    Static tf2 Broadcaster
publishes transform:      os_sensor → cam_1_optical_frame
cam1R is the Right camera, ip 29

*/

#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "tf2_static_lidar_cam");

  static tf2_ros::StaticTransformBroadcaster st_br;
  geometry_msgs::TransformStamped transformStamped;

  transformStamped.header.stamp = ros::Time::now();
  transformStamped.header.frame_id = "os_sensor";
  transformStamped.child_frame_id = "cam_0_optical_frame";

  // transformStamped.transform.translation.x = 0.260;    #m
  // transformStamped.transform.translation.y = -0.05;
  // transformStamped.transform.translation.z = 0.77;

  // tf2::Quaternion q;
  // q.setRPY(-1.571, 0, -1.571);    //  roll pitch yaw in radians
  // transformStamped.transform.rotation.x = q.x();
  // transformStamped.transform.rotation.y = q.y();
  // transformStamped.transform.rotation.z = q.z();
  // transformStamped.transform.rotation.w = q.w();            






  /*    meters???
  "T_lidar_camera": [
      52.57411305035366,       -55.35585680816991,        110.27387886777055,
      0.8824494513460811,
      0.2852066398952406,
      0.32753485826838086,
      -0.18072369794185453
    ],
    */
  // transformStamped.transform.translation.x =  0.052;   //m??
  // transformStamped.transform.translation.y = -0.055;
  // transformStamped.transform.translation.z =  0.0110;





// Dirty calibration (manual)
// - Translation: [0.050, 0.000, 0.000]
// - Rotation: in Quaternion [-0.707, 0.000, 0.000, 0.707]
//             in RPY (radian) [-1.571, 0.000, 0.000]
//             in RPY (degree) [-90.012, 0.000, 0.000]

  transformStamped.transform.translation.x =  0.025;   //m??
  transformStamped.transform.translation.y =  0;
  transformStamped.transform.translation.z =  0.025;

  tf2::Quaternion q;
  q.setRPY(-1.571, 0, 0);    //  roll pitch yaw in radians
  transformStamped.transform.rotation.x = q.x();
  transformStamped.transform.rotation.y = q.y();
  transformStamped.transform.rotation.z = q.z();
  transformStamped.transform.rotation.w = q.w();            


  st_br.sendTransform(transformStamped);

  ros::spin();
  return 0;
};
