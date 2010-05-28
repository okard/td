
cmake_minimum_required(VERSION 2.8)

PROJECT(td)

include_directories(src)

find_library(SFML_SYSTEM sfml-system)
find_library(SFML_WINDOW sfml-window)
find_library(SFML_GRAPHICS sfml-graphics)
#find_library(LUA_LIB lua)
find_library(LUA_LIB luajit-5.1)

ADD_EXECUTABLE(td src/engine/Sprite.cpp src/engine/ResourceManager.cpp src/state/LoadingState.cpp src/lua/LuaBuilding.cpp src/lua/LuaBuildingType.cpp src/lua/LuaInterface.cpp src/lua/LuaState.cpp src/common/Log.cpp src/state/InGameMenuState.cpp src/state/GameState.cpp src/state/MenuState.cpp src/model/Map.cpp src/engine/Window.cpp src/main.cpp)

target_link_libraries(td ${SFML_SYSTEM} ${SFML_WINDOW} ${SFML_GRAPHICS} ${LUA_LIB})
