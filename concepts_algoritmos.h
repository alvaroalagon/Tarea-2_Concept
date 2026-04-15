#ifndef UNTITLED_CONCEPTS_ALGORITMOS_H
#define UNTITLED_CONCEPTS_ALGORITMOS_H

#pragma once
#include <concepts>
#include <iterator>
#include <cmath>
#include <stdexcept>
#include <limits>

namespace core_concept {

    // SECCION A: Definir concepts

    // Implementacion del concept Iterable
    template <typename Contenedor>
    concept Iterable = requires(Contenedor c) {
        std::begin(c);
        std::end(c);
    };

    // Implementacion del concept Addoble
    template <typename Tipo>
    concept Addable = requires(Tipo a, Tipo b) {
        { a + b } -> std::same_as<Tipo>;
    };

    // Implementacion del concept Divisible
    template <typename Tipo>
    concept Divisible = requires(Tipo a, std::size_t n) {
        { a / n } -> std::convertible_to<Tipo>;
    };

    // Implementacion propia del concept Comparable
    template <typename Tipo>
    concept Comparable = requires(Tipo a, Tipo b) {
        { a < b } -> std::convertible_to<bool>;
    };

    // Implementacion propia del concept Numeric
    template <typename Tipo>
    concept Numeric = Addable<Tipo> && Divisible<Tipo> && Comparable<Tipo>;

    // SECCION B: Definir algoritmos

    // Implementacion del algoritmo sum
    template <Iterable Contenedor>
    requires Addable<typename Contenedor::value_type>
    auto sum(const Contenedor& contenedor)
    {
        using Elemento = typename Contenedor::value_type;
        Elemento acumulador{};
        for (const auto& valor : contenedor) {
            if constexpr (std::is_integral_v<Elemento>) {
                acumulador = acumulador + valor;
            } else {
                acumulador = acumulador + valor;
            }
        }
        return acumulador;
    }

    // Implementacion del algoritmo mean
    template <Iterable Contenedor>
    requires Addable<typename Contenedor::value_type>
          && Divisible<typename Contenedor::value_type>
    auto mean(const Contenedor& contenedor)
    {
        using Elemento = typename Contenedor::value_type;
        std::size_t cantidad = static_cast<std::size_t>(
            std::distance(std::begin(contenedor), std::end(contenedor))
        );

        if (cantidad == 0) {
            throw std::invalid_argument("El contenedor está vacío");
        }

        Elemento total = sum(contenedor);
        return static_cast<Elemento>(total / cantidad);
    }

    // Implementacion del algoritmo variance
    template <Iterable Contenedor>
    requires Addable<typename Contenedor::value_type>
          && Divisible<typename Contenedor::value_type>
    auto variance(const Contenedor& contenedor)
    {
        using Elemento = typename Contenedor::value_type;
        std::size_t cantidad = static_cast<std::size_t>(
            std::distance(std::begin(contenedor), std::end(contenedor))
        );
        if (cantidad == 0) {
            throw std::invalid_argument("El contenedor está vacío");
        }

        Elemento media = mean(contenedor);
        Elemento suma_cuadrados{};
        for (const auto& valor : contenedor) {
            Elemento diferencia = valor - media;
            suma_cuadrados = suma_cuadrados + diferencia * diferencia;
        }
        return suma_cuadrados / cantidad;
    }

    // Implementacion del algoritmo max
    template <Iterable Contenedor>
    requires Numeric<typename Contenedor::value_type>
    auto max(const Contenedor& contenedor)
    {
        using Elemento = typename Contenedor::value_type;
        auto iterador  = std::begin(contenedor);
        auto fin       = std::end(contenedor);

        if (iterador == fin) {
            throw std::invalid_argument("max: el contenedor está vacío");
        }

        Elemento maximo_actual = *iterador;
        ++iterador;
        if constexpr (std::is_floating_point_v<Elemento>) {
            // Rama para double y float
            while (iterador != fin) {
                if (maximo_actual < *iterador) {
                    maximo_actual = *iterador;
                }
                ++iterador;
            }
        } else {
            // Rama para enteros y clases propias
            while (iterador != fin) {
                if (maximo_actual < *iterador) {
                    maximo_actual = *iterador;
                }
                ++iterador;
            }
        }
        return maximo_actual;
    }
    // Implementacion del algoritmo transform_reduce
    template <Iterable Contenedor, typename Funcion>
    requires Addable<std::invoke_result_t<Funcion, typename Contenedor::value_type>>
    auto transform_reduce(const Contenedor& contenedor, Funcion func)
    {
        using TipoResultado = std::invoke_result_t<Funcion, typename Contenedor::value_type>;
        TipoResultado acumulador{};
        for (const auto& valor : contenedor) {
            acumulador = acumulador + func(valor);
        }
        return acumulador;
    }

    // SECCION C: Variadic templates y fold expressions

    // Para el algoritmo sum
    template <Addable Tipo, Addable... Resto>
    requires (std::same_as<Tipo, Resto> && ...)  // todos deben ser del mismo tipo
    auto sum_variadic(Tipo primero, Resto... resto)
    {
        return (primero + ... + resto);
    }

    // Para el algoritmo mean
    template <Numeric Tipo, Numeric... Resto>
    requires (std::same_as<Tipo, Resto> && ...)
    auto mean_variadic(Tipo primero, Resto... resto)
    {
        constexpr std::size_t cantidad = 1 + sizeof...(resto);
        Tipo total = sum_variadic(primero, resto...);
        return total / cantidad;
    }

    // Para el algoritmo variance
    template <Numeric Tipo, Numeric... Resto>
    requires (std::same_as<Tipo, Resto> && ...)
    auto variance_variadic(Tipo primero, Resto... resto)
    {
        constexpr std::size_t cantidad = 1 + sizeof...(resto);
        Tipo media = mean_variadic(primero, resto...);

        // funcion lamba
        auto cuadrado_diferencia = [&media](Tipo x) -> Tipo {
            Tipo diferencia = x - media;
            return diferencia * diferencia;
        };

        Tipo suma_cuadrados = (cuadrado_diferencia(primero) + ... + cuadrado_diferencia(resto));
        return suma_cuadrados / cantidad;
    }


    // Para el algoritmo max
    template <Numeric Tipo, Numeric... Resto>
    requires (std::same_as<Tipo, Resto> && ...)
    auto max_variadic(Tipo primero, Resto... resto)
    {
        // Lambda que devuelve el mayor de dos valores
        auto elegir_mayor = [](Tipo a, Tipo b) -> Tipo {
            return (a < b) ? b : a;
        };

        Tipo maximo_actual = primero;

        // Fold con comma operator: ejecuta la asignación para cada arg en orden
        ((maximo_actual = elegir_mayor(maximo_actual, resto)), ...);

        return maximo_actual;
    }
}
#endif //UNTITLED_CONCEPTS_ALGORITMOS_H
