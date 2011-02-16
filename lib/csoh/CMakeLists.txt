#########################################
# CMake File for csoh
######################################### 
cmake_minimum_required(VERSION 2.8)
project(csoh)


include_directories(include)


set(CSOH_SRC
    src/Math.cpp
    src/Renderer.cpp
    src/gl/glTexture.cpp
    src/gl/glShader.cpp
    src/gl/glRenderer.cpp
    )


add_library(csoh ${CSOH_SRC})
target_link_libraries(csoh)