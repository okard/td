PROJECT(td)


find_library(SFML_SYSTEM sfml-system)
find_library(SFML_WINDOW sfml-window)
find_library(SFML_GRAPHICS sfml-graphics)

ADD_EXECUTABLE(td src/engine/Window.cpp src/main.cpp)

target_link_libraries(td ${SFML_SYSTEM} ${SFML_WINDOW} ${SFML_GRAPHICS})

