cmake_minimum_required (VERSION 2.6)

project (FuncionesC)

add_executable(FuncionesC main.c ackley.c algoritmo.c esfera.c griewank.c hill_climbing.c r_restarts.c rastrigin.c schwefel.c)

target_link_libraries(FuncionesC m)