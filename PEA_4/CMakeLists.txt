cmake_minimum_required(VERSION 3.27)
project(PEA_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(PEA_4 main.cpp
        Utils/Presentation/Menu.cpp
        Utils/Presentation/Menu.h
        Utils/Reader/FileReader.cpp
        Utils/Reader/FileReader.h
        Algorithm/Ant.cpp
        Algorithm/Ant.h
        Algorithm/Colony.cpp
        Algorithm/Colony.h
)
