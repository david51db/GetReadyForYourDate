cmake_minimum_required(VERSION 4.1)
project(GetReadyForYourDate)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(GetReadyForYourDate main.cpp
        include/Player.h
        src/Player.cpp
        include/Partner.h
        src/Partner.cpp
        include/Event.h
        src/Event.cpp
        include/ChoiceEvent.h
        src/ChoiceEvent.cpp
        include/Choice.h
        src/Choice.cpp
        include/RandomEvent.h
        src/RandomEvent.cpp
        include/ChainEvent.h
        src/ChainEvent.cpp)
