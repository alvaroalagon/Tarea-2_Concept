#include <iostream>
#include "concepts_algoritmos.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (COORDENADA/ESFERA):" << std::endl;

    // Caso 1: sum_variadic con int
    auto resultado_int = core_concept::sum_variadic(1, 2, 33, 4);
    std::cout << "Caso 1: sum_variadic(1, 2, 33, 4): " << resultado_int << "\n"; // 40

    // Caso 2: sum_variadic con double
    auto resultado_double = core_concept::sum_variadic(1.5, 2.5, 3.1);
    std::cout << "Caso 2: sum_variadic(1.5, 2.5, 3.1): " << resultado_double << "\n"; // 7.0

    std::cout << "CASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 3: sum_variadic con tipos mezclados (int y double)
    // auto falla = core_concept::sum_variadic(1, 2.0, 3);

    // La falla se da en el requires (same_as<int, double> && ...) ya ques es false,
    // sum_variadic exige que todos los argumentos sean exactamente del mismo tipo.

    std::cout << "Caso invalido comentado. Descomenta para ver el error de compilacion.\n";

    return 0;
}
