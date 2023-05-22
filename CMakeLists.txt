cmake_minimum_required(VERSION 3.22)
project(ComputerClub)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(ComputerClub
        src/main.cpp
        src/FileParser/FileParser.cpp
        src/FileParser/FileParser.h
        src/ComputerClub/ComputerClub.cpp
        src/ComputerClub/ComputerClub.h
        src/EventsHandler/EventsHandler.cpp
        src/EventsHandler/EventsHandler.h
        src/Event/Events.h src/Event/EventType.h)
