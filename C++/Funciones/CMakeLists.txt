cmake_minimum_required (VERSION 2.6)

project (MetaHeuristicas)

add_executable(MetaHeuristicas MetaHeuristicas.cpp Ackley.cpp IteratedLocalSearchN.cpp IteratedLocalSearchT.cpp Function.cpp 
Griewank.cpp Rastrigin.cpp Record.cpp Schwefel.cpp Sphere.cpp Utils.cpp)

