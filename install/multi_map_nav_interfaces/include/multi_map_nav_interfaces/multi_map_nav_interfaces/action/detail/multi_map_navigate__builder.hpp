// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_map_nav_interfaces:action/MultiMapNavigate.idl
// generated code does not contain a copyright notice

#ifndef MULTI_MAP_NAV_INTERFACES__ACTION__DETAIL__MULTI_MAP_NAVIGATE__BUILDER_HPP_
#define MULTI_MAP_NAV_INTERFACES__ACTION__DETAIL__MULTI_MAP_NAVIGATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_map_nav_interfaces/action/detail/multi_map_navigate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_Goal_target_map
{
public:
  explicit Init_MultiMapNavigate_Goal_target_map(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal & msg)
  : msg_(msg)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Goal target_map(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal::_target_map_type arg)
  {
    msg_.target_map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Goal msg_;
};

class Init_MultiMapNavigate_Goal_theta
{
public:
  explicit Init_MultiMapNavigate_Goal_theta(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal & msg)
  : msg_(msg)
  {}
  Init_MultiMapNavigate_Goal_target_map theta(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_MultiMapNavigate_Goal_target_map(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Goal msg_;
};

class Init_MultiMapNavigate_Goal_y
{
public:
  explicit Init_MultiMapNavigate_Goal_y(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal & msg)
  : msg_(msg)
  {}
  Init_MultiMapNavigate_Goal_theta y(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MultiMapNavigate_Goal_theta(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Goal msg_;
};

class Init_MultiMapNavigate_Goal_x
{
public:
  Init_MultiMapNavigate_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiMapNavigate_Goal_y x(::multi_map_nav_interfaces::action::MultiMapNavigate_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MultiMapNavigate_Goal_y(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_Goal>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_Goal_x();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_Result_success
{
public:
  Init_MultiMapNavigate_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Result success(::multi_map_nav_interfaces::action::MultiMapNavigate_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_Result>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_Result_success();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_Feedback_current_status
{
public:
  Init_MultiMapNavigate_Feedback_current_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Feedback current_status(::multi_map_nav_interfaces::action::MultiMapNavigate_Feedback::_current_status_type arg)
  {
    msg_.current_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_Feedback>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_Feedback_current_status();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_SendGoal_Request_goal
{
public:
  explicit Init_MultiMapNavigate_SendGoal_Request_goal(::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request goal(::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request msg_;
};

class Init_MultiMapNavigate_SendGoal_Request_goal_id
{
public:
  Init_MultiMapNavigate_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiMapNavigate_SendGoal_Request_goal goal_id(::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MultiMapNavigate_SendGoal_Request_goal(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Request>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_SendGoal_Request_goal_id();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_SendGoal_Response_stamp
{
public:
  explicit Init_MultiMapNavigate_SendGoal_Response_stamp(::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response stamp(::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response msg_;
};

class Init_MultiMapNavigate_SendGoal_Response_accepted
{
public:
  Init_MultiMapNavigate_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiMapNavigate_SendGoal_Response_stamp accepted(::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MultiMapNavigate_SendGoal_Response_stamp(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_SendGoal_Response>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_SendGoal_Response_accepted();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_GetResult_Request_goal_id
{
public:
  Init_MultiMapNavigate_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Request goal_id(::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Request>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_GetResult_Request_goal_id();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_GetResult_Response_result
{
public:
  explicit Init_MultiMapNavigate_GetResult_Response_result(::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response result(::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response msg_;
};

class Init_MultiMapNavigate_GetResult_Response_status
{
public:
  Init_MultiMapNavigate_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiMapNavigate_GetResult_Response_result status(::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MultiMapNavigate_GetResult_Response_result(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_GetResult_Response>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_GetResult_Response_status();
}

}  // namespace multi_map_nav_interfaces


namespace multi_map_nav_interfaces
{

namespace action
{

namespace builder
{

class Init_MultiMapNavigate_FeedbackMessage_feedback
{
public:
  explicit Init_MultiMapNavigate_FeedbackMessage_feedback(::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage feedback(::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage msg_;
};

class Init_MultiMapNavigate_FeedbackMessage_goal_id
{
public:
  Init_MultiMapNavigate_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiMapNavigate_FeedbackMessage_feedback goal_id(::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MultiMapNavigate_FeedbackMessage_feedback(msg_);
  }

private:
  ::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_map_nav_interfaces::action::MultiMapNavigate_FeedbackMessage>()
{
  return multi_map_nav_interfaces::action::builder::Init_MultiMapNavigate_FeedbackMessage_goal_id();
}

}  // namespace multi_map_nav_interfaces

#endif  // MULTI_MAP_NAV_INTERFACES__ACTION__DETAIL__MULTI_MAP_NAVIGATE__BUILDER_HPP_
