cmake_minimum_required(VERSION 3.13)
project(DistributedSOM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DistributedSOM
        ClosestPair.cpp
        ClosestPair.h
        DataManager.cpp
        DataManager.h
        HelperFunctions.cpp
        HelperFunctions.h
        LayersManager.cpp
        LayersManager.h
        main.cpp
        MergingLayer.cpp
        MergingLayer.h
        ServersLayer.cpp
        ServersLayer.h
        SOM.cpp
        SOM.h
        SquareMesh.cpp
        SquareMesh.h
        WeightFunction.h)
