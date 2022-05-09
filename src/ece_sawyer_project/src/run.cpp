#include <planning.h>

int main(int argc, char **argv)
{
    double zero_pose [7] = {0.1396,-0.9076,1.0996,-0.2269,-1.3439,2.2689,1.2392};
    double block1 [7] = {0.3316,-0.1745,0.9599,-0.7505,-1.2217,1.9373,0.5236};
    double discblock1 [7] = {0.7854,-0.5236,0.9599,-0.7505,-1.2217,1.9373,0.6458};

    double zero_block3 [7] = {-0.2094,-0.4363,0.9076,-1.1868,-1.1868,1.8675,0.3316};
    double block3 [7] = {-0.2094,-0.1745,0.9076,-1.1868,-1.1868,1.8675,0.3316};

    double zero_block2 [7] = {-0.4189,-0.4363,2.0246,0.0349,-1.9373,1.7802,0.7330};    
    double block2 [7] = {-0.4189,-0.1745,2.0246,0.0349,-1.9373,1.7802,0.7330};
    ros::init(argc, argv, "custom_interfacing");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(2);
    spinner.start();

    if (argc != 2)
    {
        ROS_INFO(" ");
        ROS_INFO("\tUsage:");
        ROS_INFO(" ");
        ROS_INFO("\trosrun planning run  n");
        return 1;
    }

    my_planning::MyPlanningClass my_planning_(&node_handle);

    int selection = atoi(argv[1]);
    switch (selection)
    {
        my_planning_.resetValues();

    case 1:
        my_planning_.goToPoseGoal();
        break;
    case 2:
        my_planning_.goToJointState(zero_pose);
        my_planning_.openGripper();
        my_planning_.resetValues();
        my_planning_.goToJointState(block1);
        my_planning_.closeGripper();
        my_planning_.resetValues();
        my_planning_.goToJointState(discblock1);
        my_planning_.openGripper();
        my_planning_.resetValues();
        my_planning_.goToJointState(block3);
        my_planning_.resetValues();
        my_planning_.closeGripper();
        my_planning_.resetValues();        
        my_planning_.goToJointState(zero_block3);
        my_planning_.resetValues();        
        my_planning_.goToJointState(block1);
        my_planning_.openGripper();
        my_planning_.goToJointState(discblock1);
        my_planning_.resetValues();
        my_planning_.goToJointState(block2);
        my_planning_.closeGripper();
        my_planning_.resetValues();
        my_planning_.goToJointState(zero_block2);
        my_planning_.resetValues();        
        my_planning_.goToJointState(block3);
        my_planning_.openGripper();
        break;
    case 3:
        my_planning_.cartesianPath();
        break;
    case 4:
        my_planning_.addObjects();
        break;
    case 5:
        my_planning_.removeObjects();
        break;
    case 6:
        my_planning_.printRobotInfo();
        break;
    case 7:
        my_planning_.openGripper();
        break;
    case 8:
        my_planning_.closeGripper();
        break;
    }

    spinner.stop();
    return 0;
}
