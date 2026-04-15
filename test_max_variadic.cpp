#include <iostream>
#include "concepts_algoritmos.h"
#include "clases_definidas.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (INT/DOUBLE) Y CLASE (TEXTO):" << std::endl;

    // Caso 1: max_variadic con int
    auto resultado_int = core_concept::max_variadic(50, 12, 73, 48);
    std::cout << "Caso 1: max_variadic(50, 12, 73, 48): " << resultado_int << "\n";

    // Caso 2: max_variadic con double
    // Numeric<double>: mismo mecanismo con comparacion operator< OK
    auto resultado_double = core_concept::max_variadic(1.8, 2.7, 3.5, 4.5);
    std::cout << "Caso 2: max_variadic(1.8, 2.7, 3.5, 4.5): " << resultado_double << "\n";

    std::cout << "\nCASOS INVALIDOS CON UNA CLASE (TEXTO):" << std::endl;

    // Caso 3: max_variadic con Texto
    // auto falla = core_concept::max_variadic(Texto("Estas ahi?"), Texto("Porque nadie me entiende..."));

    // La falla se da en Numeric<Texto> dado que la clase
    // Texto no implementa operator< (Comparable falla) ni operator/(size_t) (Divisible incompatible).

    std::cout << "Caso invalido comentado. Descomenta para ver el error de compilacion.\n";

    return 0;
}