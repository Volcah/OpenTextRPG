cmake_minimum_required(VERSION 3.8)
project(OpenTextRpg)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(OpenTextRpg ${SOURCE_FILES})

if (NOT WIN32)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries(OpenTextRpg ${CURSES_LIBRARIES})
endif (NOT WIN32)