set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

set(SOURCE_FILES
        cell-tests.cpp
        main.cpp
        main.cpp
        board-updater-tests.cpp)

add_executable (GameOfLifeTests ${SOURCE_FILES})
target_link_libraries (GameOfLifeTests ${Boost_LIBRARIES})
target_link_libraries (GameOfLifeTests GameOfLifeLib)