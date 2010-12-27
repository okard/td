#########################################
# CMake File for td editor
######################################### 
cmake_minimum_required(VERSION 2.8)
project(editor)

find_package(Qt4 REQUIRED)

# include dirs
include(${QT_USE_FILE})

# src
set(editor_src
    src/main.cpp
    src/MainWindow.cpp
)

# auto moc
qt4_automoc(${editor_src})

# uis
SET(editor_ui
    src/ui/MainWindow.ui
)

# generate ui header
QT4_WRAP_UI(editor_ui_h ${editor_ui})

# include generated ui header
include_directories(${CMAKE_CURRENT_BINARY_DIR})


# the editor application
add_executable(editor ${editor_src} ${editor_ui_h})
target_link_libraries(editor ${QT_LIBRARIES})






