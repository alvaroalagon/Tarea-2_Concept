#include <iostream>
#include <vector>

#include "concepts_algoritmos.h"
#include "clases_definidas.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (ESFERA/VECTOR3D):" << std::endl;

    // Caso 1: variance con double
    std::vector<double> datos{1.0, 2.0, 3.0, 4.0, 5.0};
    auto resultado_double = core_concept::variance(datos);
    std::cout << "Caso 1: variance<double> {1,2,3,4,5}: " << resultado_double << "\n";

    // Caso 2: variance con Esfera
    std::vector<Esfera> esferas{Esfera(1.0), Esfera(2.0), Esfera(3.0)};
    auto resultado_esfera = core_concept::variance(esferas);
    std::cout << "Caso 2: variance<Esfera> {r=1, r=2, r=3}: " << resultado_esfera << "\n";

    // Caso 3: variance con Vector3D
    std::vector<Vector3D> vectores{Vector3D(1.0,1.0,1.0), Vector3D(3.0,3.0,3.0), Vector3D(2.0,2.0,2.0)};
    auto resultado_v3d = core_concept::variance(vectores);
    std::cout << "Caso 3: variance<Vector3D> {(1,1,1),(3,3,3),(2,2,2)}: " << resultado_v3d << "\n";

    std::cout << "CASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 4: variance con std::string
    // std::vector<std::string> palabras{"plata", "coco", "gata"};
    // auto falla = core_concept::variance(palabras);

    // EL error se da en Divisible<std::string> ya que no se cumple,
    // variance llama a mean() internamente, que requiere dividir entre la cantidad de elementos.

    // Caso 5: variance con Texto (clase incompleta)
    // std::vector<Texto> textos{Texto("varios texto"), Texto("el odio")};
    // auto falla2 = core_concept::variance(textos);

    // La falla se da en Divisible<Texto> y Addable<Texto> ya que el
    // Texto carece de operator/(size_t), imposibilitando el calculo de la media interna.

    std::cout << "Casos invalidos comentados. Descomenta para ver errores de compilacion.\n";

    return 0;
}