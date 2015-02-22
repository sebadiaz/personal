include_directories(.)
add_library(eureumillion STATIC  abstractstrategy.cpp core.cpp maxmincounter.cpp Mixer.cpp)


set_property(TARGET eureumillion PROPERTY VERSION ${EUREU_VERSION})
set_property(TARGET eureumillion PROPERTY SOVERSION 3)
set_property(TARGET eureumillion PROPERTY  INTERFACE_Eureumillion_MAJOR_VERSION 3)
set_property(TARGET eureumillion APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING ClimbingStats_MAJOR_VERSION
)

install(TARGETS eureumillion EXPORT eureumillionTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
#  INCLUDES DESTINATION include
)
install(
  FILES
    abstractstrategy.h
    core.h
    maxmincounter.h
  DESTINATION
    include
  COMPONENT
    Devel
)