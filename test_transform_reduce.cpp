#include <iostream>
#include <vector>

#include "concepts_algoritmos.h"
#include "clases_definidas.h"

int main() {
    std::cout << "CASOS VALIDOS CON DATOS (DOUBLE) Y CLASE (ESFERA/COORDENADA):" << std::endl;

    // Caso 1: transform_reduce con double, lambda x^2
    std::vector<double> datos{1.0, 2.0, 3.0, 4.0};
    auto resultado_cuadrados = core_concept::transform_reduce(
        datos,
        [](double x) { return x * x; }
    );
    std::cout << "Caso 1: transform_reduce(x^2, {1,2,3,4}): " << resultado_cuadrados << "\n";

    // Caso 2: transform_reduce con Esfera, lambda calcula area superficial 4*pi*r^2
    std::vector<Esfera> esferas{Esfera(1.0), Esfera(2.0), Esfera(3.0)};
    auto resultado_areas = core_concept::transform_reduce(
        esferas,
        [](const Esfera& e) { return Esfera(4.0 * M_PI * e.radio * e.radio); }
    );
    std::cout << "Caso 2: transform_reduce(4*pi*r^2, {r=1,r=2,r=3}): " << resultado_areas << "\n";

    // Caso 3: transform_reduce con Vector3D, lambda dobla cada componente
    std::vector<Vector3D> vectores{Vector3D(1.0,1.0,1.0), Vector3D(2.0,2.0,2.0)};
    auto resultado_doble = core_concept::transform_reduce(
        vectores,
        [](const Vector3D& v) { return Vector3D(v.x*2, v.y*2, v.z*2); }
    );
    std::cout << "Caso 3: transform_reduce(v*2, {(1,1,1),(2,2,2)}): " << resultado_doble << "\n";

    std::cout << "CASOS INVALIDOS CON DATOS (STRING) Y CLASE (TEXTO):" << std::endl;

    // Caso 4: transform_reduce con lambda que devuelve void
    // std::vector<double> v{5.0, 3.0};
    // auto falla = core_numeric::transform_reduce(v, [](double x){ std::cout << x; });

    // Falla ya que Addable<void> no se cumple, void no tiene operator+.

    // Caso 5: transform_reduce con lambda que devuelve std::string desde double
    // std::vector<double> v2{18.0, 21.0};
    // auto falla2 = core_numeric::transform_reduce(v2, [](double x){ return std::to_string(x); });

    // Da error dado que el acumulador se inicializa con TipoResultado{} lo cual no falla pero
    // string + string devuelve string; sin embargo el concept lo rechazara
    // si el tipo no satisface correctamente same_as en el concepto definido.


    std::cout << "Casos invalidos comentados. Descomenta para ver errores de compilacion.\n";

    return 0;
}
