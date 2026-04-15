#include <iostream>
#include <vector>

#include "concepts_algoritmos.h"
#include "clases_definidas.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (VECTOR3D/ESFERA):" << std::endl;

    // Caso 1: max con double
    std::vector<double> reales{1.0, 2.7, 0.3, 5.1, 3.3};
    auto resultado_double = core_concept::max(reales);
    std::cout << "Caso 1: max<double> {1.0, 2.7, 0.3, 5.1, 3.3}: " << resultado_double << "\n";

    // Caso 2: max con Vector3D (por magnitud)
    std::vector<Vector3D> vectores{
        Vector3D(1.0, 0.0, 3.0),
        Vector3D(0.0, 1.0, 5.0),
        Vector3D(2.0, 2.0, 6.0)
    };
    auto resultado_v3d = core_concept::max(vectores);
    std::cout << "Caso 2: max<Vector3D>: " << resultado_v3d << "\n";

    // Caso 3: max con Esfera (por radio)
    std::vector<Esfera> esferas{Esfera(1.0), Esfera(3.5), Esfera(2.0)};
    auto resultado_esfera = core_concept::max(esferas);
    std::cout << "Caso 3: max<Esfera> {r=1, r=3.5, r=2}: " << resultado_esfera << "\n";

    std::cout << "\nCASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 4: max con std::string
    // std::vector<std::string> palabras{"perros", "gatos"};
    // auto error1 = core_concept::max(palabras);

    // EL error se encuentra en Numeric<std::string> ya que no se cumple.
    // string tiene operator+ y operator<, pero carece de operator/(size_t): Divisible falla.

    // Caso 5: max con Texto
    // std::vector<Texto> textos{Texto("Era hace mucho tiempo dos amigos"), Texto("La traicion duele mas de lo que parece")};
    // auto error2 = core_concept::max(textos);

    // LA falla se encuentra en Numeric<Texto> ya que no se cumple por dos razones simultaneas.
    // Texto no tiene: 1. operator/(size_t) por tanto Divisible falla. 2. operator< por tanto Comparable falla.

    std::cout << "Casos invalidos comentados. Descomenta para ver errores de compilacion.\n";

    return 0;
}