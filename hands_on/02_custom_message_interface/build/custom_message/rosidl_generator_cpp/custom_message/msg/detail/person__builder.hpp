// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_message:msg/Person.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGE__MSG__DETAIL__PERSON__BUILDER_HPP_
#define CUSTOM_MESSAGE__MSG__DETAIL__PERSON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_message/msg/detail/person__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_message
{

namespace msg
{

namespace builder
{

class Init_Person_age
{
public:
  explicit Init_Person_age(::custom_message::msg::Person & msg)
  : msg_(msg)
  {}
  ::custom_message::msg::Person age(::custom_message::msg::Person::_age_type arg)
  {
    msg_.age = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_message::msg::Person msg_;
};

class Init_Person_name
{
public:
  Init_Person_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Person_age name(::custom_message::msg::Person::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Person_age(msg_);
  }

private:
  ::custom_message::msg::Person msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_message::msg::Person>()
{
  return custom_message::msg::builder::Init_Person_name();
}

}  // namespace custom_message

#endif  // CUSTOM_MESSAGE__MSG__DETAIL__PERSON__BUILDER_HPP_
