project (MetaHeuristicas)
cmake_minimum_required (VERSION 2.6)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(MetaHeuristicas MetaHeuristicas.cpp Ackley.cpp FunctionFactory.cpp  IteratedLocalSearchN.cpp IteratedLocalSearchT.cpp Function.cpp 
Griewank.cpp Langermann.cpp Rastrigin.cpp Record.cpp Schwefel.cpp Sphere.cpp Utils.cpp)

target_link_libraries(MetaHeuristicas ${CONAN_LIBS})