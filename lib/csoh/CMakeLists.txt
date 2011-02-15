#########################################
# CMake File for csoh
######################################### 
cmake_minimum_required(VERSION 2.8)
project(csoh)


include_directories(include)


set(CSOH_SRC
   src/Math.cpp
   )


add_library(csoh ${CSOH_SRC})
target_link_libraries(csoh)