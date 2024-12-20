cmake_minimum_required(VERSION 3.0.2)
project(husky_isa4_init)
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  sensor_msgs
  roscpp
  tf
)
catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


## Declare a C++ executable
add_executable(tf2_static_lidar src/tf2_static_lidar.cpp)
add_executable(tf2_traversable_lidar src/tf2_traversable_lidar.cpp)
add_executable(tf2_kams_cam1r src/tf2_kams_cam1R.cpp)
add_executable(tf2_lidar_cam src/tf2_lidar_cam.cpp)


## Specify libraries to link a library or executable target against
target_link_libraries(tf2_static_lidar ${catkin_LIBRARIES})
target_link_libraries(tf2_traversable_lidar ${catkin_LIBRARIES})
target_link_libraries(tf2_kams_cam1r ${catkin_LIBRARIES})
target_link_libraries(tf2_lidar_cam ${catkin_LIBRARIES})



