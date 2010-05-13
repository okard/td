
cmake_minimum_required(VERSION 2.8)

PROJECT(td)

include_directories(src)

find_library(SFML_SYSTEM sfml-system)
find_library(SFML_WINDOW sfml-window)
find_library(SFML_GRAPHICS sfml-graphics)
find_library(LUA_LIB lua)

ADD_EXECUTABLE(td src/data/lua/LuaInterface.cpp src/data/lua/LuaState.cpp src/common/Log.cpp src/state/InGameMenuState.cpp src/state/GameState.cpp src/state/MenuState.cpp src/data/Creature.cpp src/data/Map.cpp src/data/Bullet.cpp src/data/Building.cpp src/engine/Window.cpp src/main.cpp)

target_link_libraries(td ${SFML_SYSTEM} ${SFML_WINDOW} ${SFML_GRAPHICS} ${LUA_LIB})
