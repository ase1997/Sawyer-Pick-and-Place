// Generated by gencpp from file intera_core_msgs/CalibrationCommandAction.msg
// DO NOT EDIT!


#ifndef INTERA_CORE_MSGS_MESSAGE_CALIBRATIONCOMMANDACTION_H
#define INTERA_CORE_MSGS_MESSAGE_CALIBRATIONCOMMANDACTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <intera_core_msgs/CalibrationCommandActionGoal.h>
#include <intera_core_msgs/CalibrationCommandActionResult.h>
#include <intera_core_msgs/CalibrationCommandActionFeedback.h>

namespace intera_core_msgs
{
template <class ContainerAllocator>
struct CalibrationCommandAction_
{
  typedef CalibrationCommandAction_<ContainerAllocator> Type;

  CalibrationCommandAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  CalibrationCommandAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::intera_core_msgs::CalibrationCommandActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::intera_core_msgs::CalibrationCommandActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::intera_core_msgs::CalibrationCommandActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> const> ConstPtr;

}; // struct CalibrationCommandAction_

typedef ::intera_core_msgs::CalibrationCommandAction_<std::allocator<void> > CalibrationCommandAction;

typedef boost::shared_ptr< ::intera_core_msgs::CalibrationCommandAction > CalibrationCommandActionPtr;
typedef boost::shared_ptr< ::intera_core_msgs::CalibrationCommandAction const> CalibrationCommandActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator1> & lhs, const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator2> & rhs)
{
  return lhs.action_goal == rhs.action_goal &&
    lhs.action_result == rhs.action_result &&
    lhs.action_feedback == rhs.action_feedback;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator1> & lhs, const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace intera_core_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4918e674f484b978148ca2521979946d";
  }

  static const char* value(const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4918e674f484b978ULL;
  static const uint64_t static_value2 = 0x148ca2521979946dULL;
};

template<class ContainerAllocator>
struct DataType< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "intera_core_msgs/CalibrationCommandAction";
  }

  static const char* value(const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"CalibrationCommandActionGoal action_goal\n"
"CalibrationCommandActionResult action_result\n"
"CalibrationCommandActionFeedback action_feedback\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/CalibrationCommandActionGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"CalibrationCommandGoal goal\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalID\n"
"# The stamp should store the time at which this goal was requested.\n"
"# It is used by an action server when it tries to preempt all\n"
"# goals that were requested before a certain time\n"
"time stamp\n"
"\n"
"# The id provides a way to associate feedback and\n"
"# result message with specific goal requests. The id\n"
"# specified must be unique.\n"
"string id\n"
"\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/CalibrationCommandGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Engine command goal\n"
"string command\n"
"string CALIBRATION_START=start\n"
"string CALIBRATION_STOP=stop\n"
"\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/CalibrationCommandActionResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"CalibrationCommandResult result\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalStatus\n"
"GoalID goal_id\n"
"uint8 status\n"
"uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n"
"uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n"
"uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n"
"                            #   and has since completed its execution (Terminal State)\n"
"uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n"
"uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n"
"                            #    to some failure (Terminal State)\n"
"uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n"
"                            #    because the goal was unattainable or invalid (Terminal State)\n"
"uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n"
"                            #    and has not yet completed execution\n"
"uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n"
"                            #    but the action server has not yet confirmed that the goal is canceled\n"
"uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n"
"                            #    and was successfully cancelled (Terminal State)\n"
"uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n"
"                            #    sent over the wire by an action server\n"
"\n"
"#Allow for the user to associate a string with GoalStatus for debugging\n"
"string text\n"
"\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/CalibrationCommandResult\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# result\n"
"bool result\n"
"string statusId\n"
"# possible values for statusId are:\n"
"string SUCCESS=Success\n"
"string STOPPED=Stopped\n"
"string GENERIC_FAILURE=calibrationFailure\n"
"string INCOMPLETE=incomplete\n"
"string GRIPPER_ON=cannotCalibrateWithGripper\n"
"string TORQUES_EXCEEDED_THRESHOLD=torquesExceededThreshold\n"
"string PLANNER_FAILURE=plannerFailure\n"
"\n"
"\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/CalibrationCommandActionFeedback\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalStatus status\n"
"CalibrationCommandFeedback feedback\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/CalibrationCommandFeedback\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# feedback\n"
"string currentState\n"
"uint32 numberOfPoses\n"
"uint32 currentPoseNumber\n"
"\n"
;
  }

  static const char* value(const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CalibrationCommandAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::intera_core_msgs::CalibrationCommandAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::intera_core_msgs::CalibrationCommandActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::intera_core_msgs::CalibrationCommandActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::intera_core_msgs::CalibrationCommandActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // INTERA_CORE_MSGS_MESSAGE_CALIBRATIONCOMMANDACTION_H
