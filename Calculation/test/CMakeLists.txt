enable_testing()
#find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O3")        ## Optimize
    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()
set(LIBS ${LIBS} ${CHECK_LIBRARIES} eureumillion)
include_directories(. ../src)
add_executable(test_mill test1.cpp)
target_link_libraries(test_mill ${LIBS})
add_test(test_mill ${CMAKE_CURRENT_BINARY_DIR}/test_mill)