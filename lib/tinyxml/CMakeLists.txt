# CMake File TinyXML Lib
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(tinyxml) 

ADD_DEFINITIONS(-DTIXML_USE_STL)
ADD_LIBRARY(TINYXML tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp)
