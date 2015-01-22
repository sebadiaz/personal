cmake_minimum_required(VERSION 2.6)
project(calculation)

add_executable(calculation main.cpp abstractstrategy.cpp)

install(TARGETS calculation RUNTIME DESTINATION bin)
