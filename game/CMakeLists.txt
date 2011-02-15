#########################################
# CMake File for td game
######################################### 
cmake_minimum_required(VERSION 2.8)
project(engine)

if(WIN32)
    add_definitions(-DGLUL_WIN32)
elseif(GLUL_XCB)
    add_definitions(-DGLUL_XCB)
else()
    add_definitions(-DGLUL_XLIB)
endif()

#set up includes
include_directories(${CMAKE_SOURCE_DIR}/lib/glul/include)
include_directories(${CMAKE_SOURCE_DIR}/engine/include)

#source files for engine
set( GAME_SRC
     src/GameWindow.cpp
     src/main.cpp
)

#library
add_executable(game ${GAME_SRC})
target_link_libraries(game engine glul)

