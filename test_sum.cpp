#include <iostream>
#include <vector>

#include "concepts_algoritmos.h"
#include "clases_definidas.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (COORDENADA/ESFERA):" << std::endl;

    // Caso 1: sum con double
    std::vector<double> reales{1.5, 2.5, 3.0};
    auto resultado_double = core_concept::sum(reales);
    std::cout << "Caso 1: sum<double> {1.5, 2.5, 3.0}: " << resultado_double << "\n";

    // Caso 2: sum con Coordenada
    std::vector<Coordenada> coords{Coordenada(1.0, 2.0), Coordenada(3.0, 4.0)};
    auto resultado_coord = core_concept::sum(coords);
    std::cout << "Caso 2: sum<Coordenada> {(1,2), (3,4)}: " << resultado_coord << "\n";

    // Caso 3: sum con Esfera
    std::vector<Esfera> esferas{Esfera(1.0), Esfera(2.0), Esfera(3.0)};
    auto resultado_esfera = core_concept::sum(esferas);
    std::cout << "Caso 3: sum<Esfera> {r=1, r=2, r=3}: " << resultado_esfera << "\n";

    std::cout << "CASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 4: sum con std::string
    // std::vector<std::string> palabras{"cinco", "veinete"};
    // auto falla1 = core_concept::sum(palabras);

    // La falla se debe a que Addable<std::string> requiere que (a + b) de un same_as<string>.
    // Aunque string tiene operator+, devuelve string pero el concept exige same_as<T> estricto; ademas sum no tiene sentido semantico para strings.

    // Caso 5: sum con Texto (clase incompleta)
    // std::vector<Texto> textos{Texto("puede ir mas texto"), Texto("no tengo tiempo")};
    // auto falla2 = core_concept::sum(textos);

    // La falla se debe a que Texto::operator+(Texto) tecnicamente existe (por concatenacion),
    // pero Texto no satisface Addable porque el resultado no es same_as<Texto> de forma estricta.

    std::cout << "Casos invalidos comentados. Descomenta para ver errores de compilacion.\n";

    return 0;
}