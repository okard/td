#########################################
# CMake File for td game
######################################### 
cmake_minimum_required(VERSION 2.8)
project(engine)

#source files for engine
set( GAME_SRC
     src/GameWindow.cpp
     src/main.cpp
)

#library
add_executable(game ${GAME_SRC})
target_link_libraries(game engine glul)

