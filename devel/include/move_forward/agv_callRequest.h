// Generated by gencpp from file move_forward/agv_callRequest.msg
// DO NOT EDIT!


#ifndef MOVE_FORWARD_MESSAGE_AGV_CALLREQUEST_H
#define MOVE_FORWARD_MESSAGE_AGV_CALLREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace move_forward
{
template <class ContainerAllocator>
struct agv_callRequest_
{
  typedef agv_callRequest_<ContainerAllocator> Type;

  agv_callRequest_()
    : action(0)  {
    }
  agv_callRequest_(const ContainerAllocator& _alloc)
    : action(0)  {
  (void)_alloc;
    }



   typedef int64_t _action_type;
  _action_type action;





  typedef boost::shared_ptr< ::move_forward::agv_callRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::move_forward::agv_callRequest_<ContainerAllocator> const> ConstPtr;

}; // struct agv_callRequest_

typedef ::move_forward::agv_callRequest_<std::allocator<void> > agv_callRequest;

typedef boost::shared_ptr< ::move_forward::agv_callRequest > agv_callRequestPtr;
typedef boost::shared_ptr< ::move_forward::agv_callRequest const> agv_callRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::move_forward::agv_callRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::move_forward::agv_callRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace move_forward

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::move_forward::agv_callRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::move_forward::agv_callRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::move_forward::agv_callRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::move_forward::agv_callRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::move_forward::agv_callRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::move_forward::agv_callRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::move_forward::agv_callRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b460309c977f7566468f25ecee904c29";
  }

  static const char* value(const ::move_forward::agv_callRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb460309c977f7566ULL;
  static const uint64_t static_value2 = 0x468f25ecee904c29ULL;
};

template<class ContainerAllocator>
struct DataType< ::move_forward::agv_callRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "move_forward/agv_callRequest";
  }

  static const char* value(const ::move_forward::agv_callRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::move_forward::agv_callRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 action\n"
;
  }

  static const char* value(const ::move_forward::agv_callRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::move_forward::agv_callRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct agv_callRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::move_forward::agv_callRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::move_forward::agv_callRequest_<ContainerAllocator>& v)
  {
    s << indent << "action: ";
    Printer<int64_t>::stream(s, indent + "  ", v.action);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOVE_FORWARD_MESSAGE_AGV_CALLREQUEST_H
