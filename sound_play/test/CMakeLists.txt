find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  roslib
)


add_executable(test_sound_play test.cpp)
target_link_libraries(test_sound_play ${catkin_LIBRARIES})
add_dependencies(test_sound_play sound_play_gencpp)
#set_target_properties(test_sound_play PROPERTIES OUTPUT_NAME test)


add_executable(wavfilesub wavfilesub.cpp)
target_link_libraries(wavfilesub ${catkin_LIBRARIES})
add_dependencies(wavfilesub sound_play_gencpp)
#set_target_properties(wavfilesub PROPERTIES OUTPUT_NAME wavfilesub)
