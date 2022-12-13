// Generated by gencpp from file xf_mic_asr_offline/Get_Offline_Result_srvResponse.msg
// DO NOT EDIT!


#ifndef XF_MIC_ASR_OFFLINE_MESSAGE_GET_OFFLINE_RESULT_SRVRESPONSE_H
#define XF_MIC_ASR_OFFLINE_MESSAGE_GET_OFFLINE_RESULT_SRVRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace xf_mic_asr_offline
{
template <class ContainerAllocator>
struct Get_Offline_Result_srvResponse_
{
  typedef Get_Offline_Result_srvResponse_<ContainerAllocator> Type;

  Get_Offline_Result_srvResponse_()
    : result()
    , fail_reason()
    , text()  {
    }
  Get_Offline_Result_srvResponse_(const ContainerAllocator& _alloc)
    : result(_alloc)
    , fail_reason(_alloc)
    , text(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _result_type;
  _result_type result;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _fail_reason_type;
  _fail_reason_type fail_reason;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _text_type;
  _text_type text;





  typedef boost::shared_ptr< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct Get_Offline_Result_srvResponse_

typedef ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<std::allocator<void> > Get_Offline_Result_srvResponse;

typedef boost::shared_ptr< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse > Get_Offline_Result_srvResponsePtr;
typedef boost::shared_ptr< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse const> Get_Offline_Result_srvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator1> & lhs, const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result &&
    lhs.fail_reason == rhs.fail_reason &&
    lhs.text == rhs.text;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator1> & lhs, const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace xf_mic_asr_offline

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3d345f7c38cbf099d9598b4c8bbccd33";
  }

  static const char* value(const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3d345f7c38cbf099ULL;
  static const uint64_t static_value2 = 0xd9598b4c8bbccd33ULL;
};

template<class ContainerAllocator>
struct DataType< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "xf_mic_asr_offline/Get_Offline_Result_srvResponse";
  }

  static const char* value(const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string result\n"
"string fail_reason \n"
"string text\n"
"\n"
;
  }

  static const char* value(const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.fail_reason);
      stream.next(m.text);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Get_Offline_Result_srvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::xf_mic_asr_offline::Get_Offline_Result_srvResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.result);
    s << indent << "fail_reason: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.fail_reason);
    s << indent << "text: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.text);
  }
};

} // namespace message_operations
} // namespace ros

#endif // XF_MIC_ASR_OFFLINE_MESSAGE_GET_OFFLINE_RESULT_SRVRESPONSE_H
