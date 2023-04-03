cmake_minimum_required(VERSION 3.23)
project(Assignment2COEN244)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment2COEN244 main.cpp Game.cpp Game.h Player.cpp Player.h Board.cpp Board.h Position.cpp Position.h UnPlayablePosition.cpp UnPlayablePosition.h)
