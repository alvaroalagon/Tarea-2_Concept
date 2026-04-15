#include <iostream>
#include "concepts_algoritmos.h"

int main() {

    std::cout << "=== CASOS VALIDOS ===" << std::endl;

    // Caso 1: variance_variadic con double
    auto resultado_double = core_concept::variance_variadic(1.0, 2.0, 3.0, 4.0);
    std::cout << "Caso 1: variance_variadic(1.0, 2.0, 3.0, 4.0): " << resultado_double << "\n";

    // Caso 2: variance_variadic con mas argumentos double
    auto resultado_doble2 = core_concept::variance_variadic(2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0);
    std::cout << "Caso 2: variance_variadic(2,4,4,4,5,5,7,9): " << resultado_doble2 << "\n";

    std::cout << "\n=== CASO INVALIDO ===" << std::endl;

    // Caso 3: variance_variadic con tipos mezclados (int y double)
    // auto falla = core_concept::variance_variadic(1, 2.0, 3.0, 4.0);

    // FALLA: requires (same_as<int, double> && ...) es false.
    // Todos los argumentos deben ser exactamente del mismo tipo.

    std::cout << "Caso invalido comentado. Descomenta para ver el error de compilacion.\n";

    return 0;
}
