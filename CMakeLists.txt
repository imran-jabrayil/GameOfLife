cmake_minimum_required(VERSION 3.27)
project(GameOfLifeQt)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp)
add_executable(GameOfLifeQt ${SOURCE_FILES})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(GameOfLifeQt
        Qt::Core
        Qt::Gui
        Qt::Widgets)

include_directories(lib)
add_subdirectory(lib)

target_link_libraries(GameOfLifeQt GameOfLifeLib)
add_subdirectory(tests)