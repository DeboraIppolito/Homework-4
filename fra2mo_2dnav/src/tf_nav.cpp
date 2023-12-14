#include "../include/tf_nav.h"
 
TF_NAV::TF_NAV() {
 
    _position_pub = _nh.advertise<geometry_msgs::PoseStamped>( "/fra2mo/pose", 1 );
    _cur_pos << 0.0, 0.0, 0.0;
    _cur_or << 0.0, 0.0, 0.0, 1.0;
 
    _goal1_pos << 0.0, 0.0, 0.0;
    _goal1_or << 0.0, 0.0, 0.0, 1.0;
 
    _goal2_pos << 0.0, 0.0, 0.0;
    _goal2_or << 0.0, 0.0, 0.0, 1.0;
 
    _goal3_pos << 0.0, 0.0, 0.0;
    _goal3_or << 0.0, 0.0, 0.0, 1.0;
 
    _goal4_pos << 0.0, 0.0, 0.0;
    _goal4_or << 0.0, 0.0, 0.0, 1.0;
 
    _home_pos << -18.0, 2.0, 0.0;
}
 
void TF_NAV::tf_listener_fun() {
    ros::Rate r( 5 );
    tf::TransformListener listener;
    tf::StampedTransform transform;
    
    while ( ros::ok() )
    {
        try {
            listener.waitForTransform( "map", "base_footprint", ros::Time(0), ros::Duration(10.0) );
            listener.lookupTransform( "map", "base_footprint", ros::Time(0), transform );
 
        }
        catch( tf::TransformException &ex ) {
            ROS_ERROR("%s", ex.what());
            r.sleep();
            continue;
        }
        
        _cur_pos << transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z();
        _cur_or << transform.getRotation().w(),  transform.getRotation().x(), transform.getRotation().y(), transform.getRotation().z();
        position_pub();
        r.sleep();
    }
 
}
 
void TF_NAV::position_pub() {
 
    geometry_msgs::PoseStamped pose;
 
    pose.header.stamp = ros::Time::now();
    pose.header.frame_id = "map";
 
    pose.pose.position.x = _cur_pos[0];
    pose.pose.position.y = _cur_pos[1];
    pose.pose.position.z = _cur_pos[2];
 
    pose.pose.orientation.w = _cur_or[0];
    pose.pose.orientation.x = _cur_or[1];
    pose.pose.orientation.y = _cur_or[2];
    pose.pose.orientation.z = _cur_or[3];
 
    _position_pub.publish(pose);
}
 
 
// GOAL LISTENERS
 
void TF_NAV::goal_listener_1() {
    ros::Rate r( 1 );
    tf::TransformListener listener;
    tf::StampedTransform transform;
 
    while ( ros::ok() )
    {
        try
        {
            listener.waitForTransform( "map", "goal1", ros::Time( 0 ), ros::Duration( 10.0 ) );
            listener.lookupTransform( "map", "goal1", ros::Time( 0 ), transform );
        }
        catch( tf::TransformException &ex )
        {
            ROS_ERROR("%s", ex.what());
            r.sleep();
            continue;
        }
 
        _goal1_pos << transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z();
        _goal1_or << transform.getRotation().w(),  transform.getRotation().x(), transform.getRotation().y(), transform.getRotation().z();
 
        // Debug Print
       // ROS_INFO("Goal Position: %f %f %f", _goal1_pos[0], _goal1_pos[1], _goal1_pos[2]);
        //ROS_INFO("Goal Orientation: %f %f %f %f", _goal1_or[0], _goal1_or[1], _goal1_or[2], _goal1_or[3]);
 
        r.sleep();
    }    
}
 
void TF_NAV::goal_listener_2() {
    ros::Rate r( 1 );
    tf::TransformListener listener;
    tf::StampedTransform transform;
 
    while ( ros::ok() )
    {
        try
        {
            listener.waitForTransform( "map", "goal2", ros::Time( 0 ), ros::Duration( 10.0 ) );
            listener.lookupTransform( "map", "goal2", ros::Time( 0 ), transform );
        }
        catch( tf::TransformException &ex )
        {
            ROS_ERROR("%s", ex.what());
            r.sleep();
            continue;
        }
 
        _goal2_pos << transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z();
        _goal2_or << transform.getRotation().w(),  transform.getRotation().x(), transform.getRotation().y(), transform.getRotation().z();
 
        // Debug Print
        //ROS_INFO("Goal Position: %f %f %f", _goal2_pos[0], _goal2_pos[1], _goal2_pos[2]);
        //ROS_INFO("Goal Orientation: %f %f %f %f", _goal2_or[0], _goal2_or[1], _goal2_or[2], _goal2_or[3]);
 
        r.sleep();
    }    
}
 
void TF_NAV::goal_listener_3() {
    ros::Rate r( 1 );
    tf::TransformListener listener;
    tf::StampedTransform transform;
 
    while ( ros::ok() )
    {
        try
        {
            listener.waitForTransform( "map", "goal3", ros::Time( 0 ), ros::Duration( 10.0 ) );
            listener.lookupTransform( "map", "goal3", ros::Time( 0 ), transform );
        }
        catch( tf::TransformException &ex )
        {
            ROS_ERROR("%s", ex.what());
            r.sleep();
            continue;
        }
 
        _goal3_pos << transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z();
        _goal3_or << transform.getRotation().w(),  transform.getRotation().x(), transform.getRotation().y(), transform.getRotation().z();
 
        // Debug Print
        //ROS_INFO("Goal Position: %f %f %f", _goal3_pos[0], _goal3_pos[1], _goal3_pos[2]);
        //ROS_INFO("Goal Orientation: %f %f %f %f", _goal3_or[0], _goal3_or[1], _goal3_or[2], _goal3_or[3]);
 
        r.sleep();
    }    
}
 
void TF_NAV::goal_listener_4() {
    ros::Rate r( 1 );
    tf::TransformListener listener;
    tf::StampedTransform transform;
 
    while ( ros::ok() )
    {
        try
        {
            listener.waitForTransform( "map", "goal4", ros::Time( 0 ), ros::Duration( 10.0 ) );
            listener.lookupTransform( "map", "goal4", ros::Time( 0 ), transform );
        }
        catch( tf::TransformException &ex )
        {
            ROS_ERROR("%s", ex.what());
            r.sleep();
            continue;
        }
 
        _goal4_pos << transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z();
        _goal4_or << transform.getRotation().w(),  transform.getRotation().x(), transform.getRotation().y(), transform.getRotation().z();
 
        // Debug Print
        //ROS_INFO("Goal Position: %f %f %f", _goal4_pos[0], _goal4_pos[1], _goal4_pos[2]);
        //ROS_INFO("Goal Orientation: %f %f %f %f", _goal4_or[0], _goal4_or[1], _goal4_or[2], _goal4_or[3]);
 
        r.sleep();
    }    
}
 
 
void TF_NAV::send_goal() {
    ros::Rate r( 5 );
    int cmd;
    move_base_msgs::MoveBaseGoal goal;
 
    while ( ros::ok() )
    {
        std::cout<<"\nInsert 1 to send goal from TF "<<std::endl;
        std::cout<<"Insert 2 to send home position goal "<<std::endl;
        std::cout<<"Inser your choice"<<std::endl;
        std::cin>>cmd;
 
        if ( cmd == 1) {
            MoveBaseClient ac("move_base", true);
            while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
            }
            goal.target_pose.header.frame_id = "map";
            goal.target_pose.header.stamp = ros::Time::now();
            
 
            //GOAL 3
            goal.target_pose.pose.position.x = _goal3_pos[0];
            goal.target_pose.pose.position.y = _goal3_pos[1];
            goal.target_pose.pose.position.z = _goal3_pos[2];
 
            goal.target_pose.pose.orientation.w = _goal3_or[0];
            goal.target_pose.pose.orientation.x = _goal3_or[1];
            goal.target_pose.pose.orientation.y = _goal3_or[2];
            goal.target_pose.pose.orientation.z = _goal3_or[3];
 
            ROS_INFO("Sending goal 3");
            ac.sendGoal(goal);
 
            ac.waitForResult();
 
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("The mobile robot arrived in the TF goal 3");
                ac.cancelGoal();
            }
            else
                ROS_INFO("The base failed to move for some reason");
 
 
           //GOAL 4
            goal.target_pose.pose.position.x = _goal4_pos[0];
            goal.target_pose.pose.position.y = _goal4_pos[1];
            goal.target_pose.pose.position.z = _goal4_pos[2];
 
            goal.target_pose.pose.orientation.w = _goal4_or[0];
            goal.target_pose.pose.orientation.x = _goal4_or[1];
            goal.target_pose.pose.orientation.y = _goal4_or[2];
            goal.target_pose.pose.orientation.z = _goal4_or[3];
 
            ROS_INFO("Sending goal 4");
            ac.sendGoal(goal);
 
            ac.waitForResult();
 
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("The mobile robot arrived in the TF goal 4");
                ac.cancelGoal();
            }
            else
                ROS_INFO("The base failed to move for some reason");
 
           //GOAL 2
            goal.target_pose.pose.position.x = _goal2_pos[0];
            goal.target_pose.pose.position.y = _goal2_pos[1];
            goal.target_pose.pose.position.z = _goal2_pos[2];
 
            goal.target_pose.pose.orientation.w = _goal2_or[0];
            goal.target_pose.pose.orientation.x = _goal2_or[1];
            goal.target_pose.pose.orientation.y = _goal2_or[2];
            goal.target_pose.pose.orientation.z = _goal2_or[3];
 
            ROS_INFO("Sending goal 2");
            ac.sendGoal(goal);
 
            ac.waitForResult();
 
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("The mobile robot arrived in the TF goal 2");
                ac.cancelGoal();
            }
            else
                ROS_INFO("The base failed to move for some reason");
 
            //GOAL 1
            goal.target_pose.pose.position.x = _goal1_pos[0];
            goal.target_pose.pose.position.y = _goal1_pos[1];
            goal.target_pose.pose.position.z = _goal1_pos[2];
 
            goal.target_pose.pose.orientation.w = _goal1_or[0];
            goal.target_pose.pose.orientation.x = _goal1_or[1];
            goal.target_pose.pose.orientation.y = _goal1_or[2];
            goal.target_pose.pose.orientation.z = _goal1_or[3];
 
            ROS_INFO("Sending goal 1");
            ac.sendGoal(goal);
 
            ac.waitForResult();
 
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
                ROS_INFO("The mobile robot arrived in the TF goal 1");
                ac.cancelGoal();
            }
            else
                ROS_INFO("The base failed to move for some reason");
 
        }
        else if ( cmd == 2 ) {
            MoveBaseClient ac("move_base", true);
            while(!ac.waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
            }
            goal.target_pose.header.frame_id = "map";
            goal.target_pose.header.stamp = ros::Time::now();
            
            goal.target_pose.pose.position.x = _home_pos[0];
            goal.target_pose.pose.position.y = _home_pos[1];
            goal.target_pose.pose.position.z = _home_pos[2];
 
            goal.target_pose.pose.orientation.w = 1.0;
            goal.target_pose.pose.orientation.x = 0.0;
            goal.target_pose.pose.orientation.y = 0.0;
            goal.target_pose.pose.orientation.z = 0.0;
 
            ROS_INFO("Sending HOME position as goal");
            ac.sendGoal(goal);
 
            ac.waitForResult();
 
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
            ROS_INFO("The mobile robot arrived in the TF goal 3");
            ac.cancelGoal();
            }
            else
                ROS_INFO("The base failed to move for some reason");
        }
         else {
            ROS_INFO("Wrong input!");
        }
        r.sleep();
    }
    
}
 
void TF_NAV::run() {
    boost::thread tf_listener_fun_t( &TF_NAV::tf_listener_fun, this );
    boost::thread tf_listener_goal1_t( &TF_NAV::goal_listener_1, this );
    boost::thread tf_listener_goal2_t( &TF_NAV::goal_listener_2, this );
    boost::thread tf_listener_goal3_t( &TF_NAV::goal_listener_3, this );
    boost::thread tf_listener_goal4_t( &TF_NAV::goal_listener_4, this );
    boost::thread send_goal_t( &TF_NAV::send_goal, this );
    ros::spin();
}
 
 
 
int main( int argc, char** argv ) {
    ros::init(argc, argv, "tf_navigation");
    TF_NAV tfnav;
    tfnav.run();
 
    return 0;
}