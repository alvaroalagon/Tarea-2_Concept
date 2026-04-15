#include <iostream>
#include <vector>

#include "clases_definidas.h"
#include "concepts_algoritmos.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (ESFERA/COORDENADA):" << std::endl;

    // Caso 1: mean con double
    std::vector<double> reales{1.5, 30.4, 4.7};
    auto resultado_double = core_concept::mean(reales);
    std::cout << "Caso 1: mean<double> {1.5, 30.4, 4.7}: " << resultado_double << "\n";

    // Caso 2: mean con Esfera
    std::vector<Esfera> esferas{Esfera(1.0), Esfera(3.5), Esfera(2.1)};
    auto resultado_esfera = core_concept::mean(esferas);
    std::cout << "Caso 2: mean<Esfera> {r=1, r=3.5, r=2.1}: " << resultado_esfera << "\n";

    // Caso 3: mean con Coordenada
    std::vector<Coordenada> coords{Coordenada(9.0, 10.0), Coordenada(5.0, 2.0), Coordenada(3.0, 6.0)};
    auto resultado_coord = core_concept::mean(coords);
    std::cout << "Caso 3: mean<Coordenada> {(9,10),(5,2),(3,6)}: " << resultado_coord << "\n";

    std::cout << "\nCASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 4: mean con std::string
    // std::vector<std::string> palabras{"matematica", "programacion"};
    // auto falla1 = core_concept::mean(palabras);

    // La error se da en Divisible<std::string> ya que el tipo de dato
    // std::string no tiene operator/(size_t), por lo que no se puede calcular el promedio.

    // Caso 5: mean con Texto
    // std::vector<Texto> textos{Texto("Hola Diego, como estas?"), Texto("Hay alguien que se llame Eduardo?"), Texto("Aron es el jefe del salon")};
    // auto falla2 = core_concept::mean(textos);

    // La falla se da en Divisible<Texto> ya que la clase
    // Texto no implementa operator/(size_t), mean no puede dividir entre cantidad.

    std::cout << "Casos invalidos comentados. Descomenta para ver errores de compilacion.\n";
    return 0;
}