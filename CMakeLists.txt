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
        src/EventHandler/EventHandler.cpp
        src/EventHandler/EventHandler.h
        src/Enums/EventType.h
        src/LoadedData/LoadedData.cpp
        src/LoadedData/LoadedData.h
        src/Table/Table.cpp
        src/Table/Table.h
        src/Time/Time.cpp
        src/Time/Time.h
        src/Event/Event.cpp
        src/Event/Event.h
        src/Event/EventCome.cpp
        src/Event/EventCome.h
        src/Event/EventSit.cpp
        src/Event/EventSit.h
        src/Event/EventWait.cpp
        src/Event/EventWait.h
        src/Event/EventLeave.cpp
        src/Event/EventLeave.h
        src/Application/Application.cpp
        src/Application/Application.h
        src/Exception/EventException.cpp
        src/Exception/EventException.h)
