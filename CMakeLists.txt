cmake_minimum_required(VERSION 4.2)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tarea-2_Concept clases_definidas.h concepts_algoritmos.h
        test_max.cpp
)

# Instrucciones de compilación:
# - Cada algoritmo ha sido probado en un archivo de test independiente (.cpp).
# - Para compilar el programa, es necesario incluir:
#   1) Los archivos base:  clases_definidas.h y concepts_algoritmos.h
#   2) El archivo de test correspondiente al algoritmo que se desea ejecutar.
# - Puedes compilar un test a la vez agregando únicamente el archivo .cpp correspondiente en add_executable.

# Lista de tests disponibles:
# - test_max.cpp
# - test_max_variadic.cpp
# - test_mean.cpp
# - test_mean_variadic.cpp
# - test_sum.cpp
# - test_sum_variadic.cpp
# - test_variance.cpp
# - test_variance_variadic.cpp
# - test_transform_reduce.cpp