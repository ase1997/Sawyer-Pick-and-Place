cmake_minimum_required(VERSION 3.0.2)
project(ece_sawyer_project)


## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp moveit_ros_planning_interface intera_core_msgs
)

## catkin specific configuration ##
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp intera_core_msgs
)

## Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Build ##
add_executable(sawyer_pick_and_place src/run.cpp src/planning.cpp include/planning.h)
add_dependencies(sawyer_pick_and_place ${catkin_EXPORTED_TARGETS})
target_link_libraries(sawyer_pick_and_place ${catkin_LIBRARIES})


