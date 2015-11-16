cmake_minimum_required(VERSION 3.3)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        GreedyApproach/DisjointSet.h
        GreedyApproach/DisjointSet.c
        GreedyApproach/MST.c
        GreedyApproach/MST.h
        GreedyApproach/MSTMain.c
        GreedyApproach/Graph.c
        GreedyApproach/Graph.h
        GreedyApproach/PriorityQueue.c
        GreedyApproach/PriorityQueue.h)

add_executable(Algorithm ${SOURCE_FILES})