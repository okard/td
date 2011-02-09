#########################################
# CMake File for td editor
######################################### 
cmake_minimum_required(VERSION 2.8)
project(editor)

find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL TRUE)

# include dirs
include(${QT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR}/engine/include)

# src
set(editor_src
    src/main.cpp
    src/MainWindow.cpp
    src/EngineWidget.cpp
)

# uis
set(editor_ui
    src/ui/MainWindow.ui
)

#qt resources
set(editor_qrc
    src/editor.qrc
)

# auto moc
qt4_automoc(${editor_src})
# generate ui header
qt4_wrap_ui(editor_ui_h ${editor_ui})
# generate resources
qt4_add_resources(editor_qrc_gen ${editor_qrc})

# include generated ui header
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# the editor application
add_executable(editor ${editor_src} ${editor_ui_h} ${editor_qrc_gen})
target_link_libraries(editor engine ${QT_LIBRARIES})






