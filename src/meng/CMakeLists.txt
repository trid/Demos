cmake_minimum_required(VERSION 3.5)
project(meng)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_definitions(-DSFML_STATIC)

file(GLOB SOURCE_FILES *.cpp)
file(GLOB VIEW_SOURCE_FILES view/*.cpp)
file(GLOB GUI_SOURCE_FILES view/GUI/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${VIEW_SOURCE_FILES} ${GUI_SOURCE_FILES} ../arena/main.cpp ../arena/main.h)
