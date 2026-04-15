#include <iostream>
#include "concepts_algoritmos.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (COORDENADA/ESFERA):" << std::endl;

    // Caso 1: mean_variadic con double
    auto resultado_double = core_concept::mean_variadic(0.1, 2.0, 3.0, 4.0);
    std::cout << "Caso 1: mean_variadic(0.1, 2.0, 3.0, 4.0): " << resultado_double << "\n"; // 2.275

    // Caso 2: mean_variadic con int
    auto resultado_int = core_concept::mean_variadic(2, 4, 6, 8);
    std::cout << "Caso 2: mean_variadic(2, 4, 6, 8): " << resultado_int << "\n"; // 5

    std::cout << "CASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 3: mean_variadic con Texto
    // auto falla = core_numeric::mean_variadic(Texto("hola"), Texto("mundo"));

    // FALLA: Numeric<Texto> no se cumple.
    // Texto no tiene operator/(size_t) ni operator<, Divisible y Comparable fallan.

    std::cout << "Caso invalido comentado. Descomenta para ver el error de compilacion.\n";

    return 0;
}