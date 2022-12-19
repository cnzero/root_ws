// Generated by gencpp from file xf_mic_asr_offline_line/Get_Awake_Angle_srvRequest.msg
// DO NOT EDIT!


#ifndef XF_MIC_ASR_OFFLINE_LINE_MESSAGE_GET_AWAKE_ANGLE_SRVREQUEST_H
#define XF_MIC_ASR_OFFLINE_LINE_MESSAGE_GET_AWAKE_ANGLE_SRVREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace xf_mic_asr_offline_line
{
template <class ContainerAllocator>
struct Get_Awake_Angle_srvRequest_
{
  typedef Get_Awake_Angle_srvRequest_<ContainerAllocator> Type;

  Get_Awake_Angle_srvRequest_()
    : get_awake_angle(0)  {
    }
  Get_Awake_Angle_srvRequest_(const ContainerAllocator& _alloc)
    : get_awake_angle(0)  {
  (void)_alloc;
    }



   typedef int8_t _get_awake_angle_type;
  _get_awake_angle_type get_awake_angle;





  typedef boost::shared_ptr< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct Get_Awake_Angle_srvRequest_

typedef ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<std::allocator<void> > Get_Awake_Angle_srvRequest;

typedef boost::shared_ptr< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest > Get_Awake_Angle_srvRequestPtr;
typedef boost::shared_ptr< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest const> Get_Awake_Angle_srvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator1> & lhs, const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.get_awake_angle == rhs.get_awake_angle;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator1> & lhs, const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace xf_mic_asr_offline_line

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7f4c060de1fcfcddc29c07ae9e375a53";
  }

  static const char* value(const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7f4c060de1fcfcddULL;
  static const uint64_t static_value2 = 0xc29c07ae9e375a53ULL;
};

template<class ContainerAllocator>
struct DataType< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "xf_mic_asr_offline_line/Get_Awake_Angle_srvRequest";
  }

  static const char* value(const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 get_awake_angle #1,0\n"
;
  }

  static const char* value(const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.get_awake_angle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Get_Awake_Angle_srvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::xf_mic_asr_offline_line::Get_Awake_Angle_srvRequest_<ContainerAllocator>& v)
  {
    s << indent << "get_awake_angle: ";
    Printer<int8_t>::stream(s, indent + "  ", v.get_awake_angle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // XF_MIC_ASR_OFFLINE_LINE_MESSAGE_GET_AWAKE_ANGLE_SRVREQUEST_H
