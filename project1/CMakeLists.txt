cmake_minimum_required(VERSION 3.28)
project(project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(project1 main.cpp
        user.cpp
        games.cpp
        main.h
        beg.cpp)
