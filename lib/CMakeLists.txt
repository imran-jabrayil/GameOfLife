cmake_minimum_required(VERSION 3.27)
project(GameOfLifeLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${PROJECT_SOURCE_DIR})

set(HEADER_FILES
        settings.hpp
        game/cells/Cell.hpp)

set(SOURCE_FILES
        game/cells/Cell.cpp)

add_library(GameOfLifeLib STATIC
        ${HEADER_FILES}
        ${SOURCE_FILES})
