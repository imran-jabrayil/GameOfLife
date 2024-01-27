cmake_minimum_required(VERSION 3.27)
project(GameOfLife_Qt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(GameOfLife_Qt main.cpp)
target_link_libraries(GameOfLife_Qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

