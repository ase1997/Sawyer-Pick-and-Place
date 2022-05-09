#include <planning.h>

namespace my_planning
{
    MyPlanningClass::MyPlanningClass(ros::NodeHandle *nh) : move_group(PLANNING_GROUP)
    {
        target_pose1.orientation.w = 1; // unit quaternion
        target_pose1.orientation.x = 0;
        target_pose1.orientation.y = 0;
        target_pose1.orientation.z = 0;
        target_pose1.position.x = 0.75;
        target_pose1.position.y = -0.35;
        target_pose1.position.z = 1.1;

        move_group.allowReplanning(true);
        move_group.setNumPlanningAttempts(10);

        joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

        gripper_pub = nh->advertise<intera_core_msgs::IOComponentCommand>
        ("/io/end_effector/right_gripper/command", 10);
    }

    void MyPlanningClass::goToPoseGoal()
    {
        move_group.setPoseTarget(target_pose1);
        bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
        if (!success) // execute
            throw std::runtime_error("No plan found");

        move_group.move(); // blocking
    }

    void MyPlanningClass::goToPoseGoal(geometry_msgs::Pose &pose)
    {
        move_group.setPoseTarget(pose);
        ros::Duration(0.5).sleep();
        bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
        /*while (!success) //keep trying until a plan is found
        {

            success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
        }*/

        if (!success) // execute
            throw std::runtime_error("No plan found");

        move_group.move(); // blocking
    }

    void MyPlanningClass::goToJointState(double jsarray [7])
    {
        std::vector<double> joint_positions;
        joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
        moveit::core::RobotStatePtr current_state = move_group.getCurrentState();
        current_state->copyJointGroupPositions(joint_model_group, joint_positions);

        joint_positions[0] = jsarray[0]; // radians
        joint_positions[1] = jsarray[1]; // radians
        joint_positions[2] = jsarray[2]; // radians
        joint_positions[3] = jsarray[3]; // radians
        joint_positions[4] = jsarray[4]; // radians
        joint_positions[5] = jsarray[5]; // radians
        joint_positions[6] = jsarray[6]; // radians

        move_group.setJointValueTarget(joint_positions);
        bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
        if (!success)
            throw std::runtime_error("No plan found");

        move_group.move(); // blocking
    }

    void MyPlanningClass::cartesianPath()
    {
        std::vector<geometry_msgs::Pose> waypoints;
        waypoints.push_back(target_pose1);

        geometry_msgs::Pose target_pose2 = target_pose1;

        target_pose2.position.z -= 0.2;
        waypoints.push_back(target_pose2);

        target_pose2.position.y -= 0.2;
        waypoints.push_back(target_pose2);

        target_pose2.position.z += 0.2;
        target_pose2.position.y += 0.2;
        target_pose2.position.x -= 0.2;
        waypoints.push_back(target_pose2);

        move_group.setMaxVelocityScalingFactor(0.1);

        // We want the Cartesian path to be interpolated at a resolution of 1 cm
        // which is why we will specify 0.01 as the max step in Cartesian
        // translation.  We will specify the jump threshold as 0.0, effectively disabling it.
        // Warning - disabling the jump threshold while operating real hardware can cause
        // large unpredictable motions of redundant joints and could be a safety issue
        moveit_msgs::RobotTrajectory trajectory;
        const double jump_threshold = 0.0;
        const double eef_step = 0.01;
        double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);

        move_group.move();
        ROS_INFO_STREAM("Percentage of path followed: " << fraction);
    }

    void MyPlanningClass::printRobotInfo()
    {
        // print reference frame of the robot
        ROS_INFO("Reference frame: %s", move_group.getPlanningFrame().c_str());

        // print the name of the end-effector link for this group
        std::string end_effector_link_str = move_group.getEndEffectorLink();
        ROS_INFO("End effector link: %s", end_effector_link_str.c_str());

        // print the robot state
        geometry_msgs::PoseStamped pose_stamped = move_group.getCurrentPose(end_effector_link_str);
        std::vector<double> rpy = move_group.getCurrentRPY(end_effector_link_str);

        ROS_INFO("gripper position [x,y,z]:  %f, %f, %f", pose_stamped.pose.position.x, 
                 pose_stamped.pose.position.y,
                 pose_stamped.pose.position.z);
        ROS_INFO("gripper orientation [w,x,y,z]: %f, %f, %f, %f", pose_stamped.pose.orientation.w,
                 pose_stamped.pose.orientation.x, pose_stamped.pose.orientation.y,
                 pose_stamped.pose.orientation.z);
        ROS_INFO("gripper orientation [roll,pitch,yaw]: %f, %f, %f", rpy[0], rpy[1], rpy[2]);

        ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
        std::copy(move_group.getJointModelGroupNames().begin(),
                  move_group.getJointModelGroupNames().end(), 
                  std::ostream_iterator<std::string>(std::cout, ", "));
    }

    void MyPlanningClass::openGripper()
    {
        // Open the gripper (MAX_POSITION = 0.041667)
        intera_core_msgs::IOComponentCommand gripper_cmd;
        gripper_cmd.time = ros::Time::now(); // time the message was created
        gripper_cmd.op = "set";              // operation to perform
        gripper_cmd.args = "{\"signals\": {\"position_m\": \
          {\"format\": {\"type\": \"float\"}, \"data\": [0.041667]}}}";

        // Publish Command to /io/end_effector/right_gripper/command
        // ROS_INFO_STREAM( "openGripper : " << gripper_cmd);

        for (int i = 0; i < 20; i++) // try for 2 sec
        {
            gripper_pub.publish(gripper_cmd);
            ros::Duration(0.1).sleep();
        }
    }

    void MyPlanningClass::closeGripper()
    {
        // Close the gripper (MIN_POSITION = 0.0)

        intera_core_msgs::IOComponentCommand gripper_cmd;
        gripper_cmd.time = ros::Time::now();
        gripper_cmd.op = "set";                                    // operation to perform
        gripper_cmd.args = "{\"signals\": {\"position_m\": \
          {\"format\": {\"type\": \"float\"}, \"data\": [0.0]}}}"; // JSON arguments

        // Publish Command to /io/end_effector/right_gripper/command
        // ROS_INFO_STREAM( "closeGripper : " << gripper_cmd);

        for (int i = 0; i < 20; i++) // try for 2 sec
        {
            gripper_pub.publish(gripper_cmd);
            ros::Duration(0.1).sleep();
        }
    }

    void MyPlanningClass::resetValues()
    {
        // set the start state and operational speed
        move_group.setStartStateToCurrentState();
        move_group.setMaxVelocityScalingFactor(1.0);
    }

    void MyPlanningClass::makeBox(std::string blk_name, double *pose)
    {
        moveit_msgs::CollisionObject box;
        // set the relative frame
        box.header.frame_id = move_group.getPlanningFrame();
        box.id = blk_name;

        shape_msgs::SolidPrimitive primitive;
        primitive.type = primitive.BOX;
        primitive.dimensions.resize(3);
        primitive.dimensions[0] = pose[7];
        primitive.dimensions[1] = pose[8];
        primitive.dimensions[2] = pose[9];

        geometry_msgs::Pose box_pose;
        box_pose.orientation.w = pose[6];
        box_pose.position.x = pose[0];
        box_pose.position.y = pose[1];
        box_pose.position.z = pose[2];

        box.primitives.push_back(primitive);
        box.primitive_poses.push_back(box_pose);
        box.operation = box.ADD;

        std::vector<moveit_msgs::CollisionObject> collisionObjects;
        collisionObjects.push_back(box);
        ros::Duration(2).sleep();
        virtual_world.addCollisionObjects(collisionObjects);
        ROS_INFO_STREAM("Added: " << blk_name);
    }

    void MyPlanningClass::addObjects()
    {
        double box_pose1[10] = {1.0,0.0,0.0,0.9999,0.0,0.0,0.0137,0.8,3.0,0.1};
        makeBox("block_1", box_pose1);

        double box_pose2[10] = {0.75,-0.35,0.075,1.0,0.0,0.0,0.0,0.5,0.5,0.5};
        makeBox("block_2", box_pose2);
		
		double box_pose3[10] = {1.0,0.0,0.075,1.0,0.0,0.0,-0.0069,0.5,0.5,0.5};
        makeBox("block_3", box_pose3);
		
		double box_pose4[10] = {0.85,0.25,0.075,1.0,0.0,0.0,0.0069,0.5,0.5,0.5};
        makeBox("block_4", box_pose4);

    }

    void MyPlanningClass::removeObjects()
    {
        std::vector<std::string> object_ids;
        object_ids.push_back("block_1");
        object_ids.push_back("block_2");
		object_ids.push_back("block_3");
		object_ids.push_back("block_4");
        virtual_world.removeCollisionObjects(object_ids);
    }
}
