cmake_minimum_required(VERSION 3.5)

project(03.homework)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GuessTheNumber
	src/main.cpp
	src/game.cpp
	src/scores_helper.cpp
)