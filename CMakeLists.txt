cmake_minimum_required(VERSION 3.13)
project(EdgeSOM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EdgeSOM
        src/ClosestPair.cpp
        src/ClosestPair.h
        src/DataManager.cpp
        src/DataManager.h
        src/HelperFunctions.cpp
        src/HelperFunctions.h
        src/LayersManager.cpp
        src/LayersManager.h
        src/main.cpp
        src/MergingLayer.cpp
        src/MergingLayer.h
        src/ServersLayer.cpp
        src/ServersLayer.h
        src/SOM.cpp
        src/SOM.h
        src/SquareMesh.cpp
        src/SquareMesh.h
        src/WeightFunction.h)
