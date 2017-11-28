cmake_minimum_required(VERSION 3.8)
project(snippets)

set(CMAKE_CXX_STANDARD 11)

configure_file(rot13.txt rot13.txt COPYONLY)

set(SOURCE_FILES
        main.cpp
        README.md main.h)

add_executable(rot13 ${SOURCE_FILES})