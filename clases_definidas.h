#ifndef UNTITLED_CLASES_DEFINIDAS_H
#define UNTITLED_CLASES_DEFINIDAS_H

#pragma once
#include <iostream>
#include <cmath>
#include <string>

class Coordenada {
private:
    double x, y;
public:
    Coordenada() : x(0.0), y(0.0) {}
    Coordenada(double coordX, double coordY) : x(coordX), y(coordY) {}

    // Sobrecarga de operadores
    Coordenada operator+(const Coordenada& otra) const {
        return Coordenada(x + otra.x, y + otra.y);
    }
    Coordenada operator-(const Coordenada& otra) const {
        return Coordenada(x - otra.x, y - otra.y);
    }
    Coordenada operator*(const Coordenada& otra) const {
        return Coordenada(x * otra.x, y * otra.y);
    }
    Coordenada operator/(std::size_t n) const {
        return Coordenada(x / static_cast<double>(n),
                          y / static_cast<double>(n));
    }
    bool operator<(const Coordenada& otra) const {
        double magnitud_propia = x * x + y * y;
        double magnitud_otra   = otra.x * otra.x + otra.y * otra.y;
        return magnitud_propia < magnitud_otra;
    }
    friend std::ostream& operator<<(std::ostream& flujo, const Coordenada& c) {
        flujo << "(" << c.x << ", " << c.y << ")";
        return flujo;
    }
};

struct Vector3D {
    double x, y, z;
    Vector3D() : x(0.0), y(0.0), z(0.0) {}
    Vector3D(double coordX, double coordY, double coordZ) : x(coordX), y(coordY), z(coordZ) {}

    double magnitud() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    // Sobrecarga de operadores
    Vector3D operator+(const Vector3D& otro) const {
        return Vector3D(x + otro.x, y + otro.y, z + otro.z);
    }
    Vector3D operator-(const Vector3D& otro) const {
        return Vector3D(x - otro.x, y - otro.y, z - otro.z);
    }
    Vector3D operator*(const Vector3D& otro) const {
        return Vector3D(x * otro.x, y * otro.y, z * otro.z);
    }
    Vector3D operator/(std::size_t n) const {
        return Vector3D(x / static_cast<double>(n),
                        y / static_cast<double>(n),
                        z / static_cast<double>(n));
    }
    bool operator<(const Vector3D& otro) const {
        double magnitud_propia = x*x + y*y + z*z;
        double magnitud_otro   = otro.x*otro.x + otro.y*otro.y + otro.z*otro.z;
        return magnitud_propia < magnitud_otro;
    }
    friend std::ostream& operator<<(std::ostream& flujo, const Vector3D& v) {
        flujo << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return flujo;
    }
};

struct Esfera {
    double radio;

    Esfera() : radio(0.0) {}
    Esfera(double r) : radio(r) {}

    double volumen() const {
        return (4.0 / 3.0) * M_PI * radio * radio * radio;
    }
    // Sobrecarga de operadores
    Esfera operator+(const Esfera& otra) const {
        return Esfera(radio + otra.radio);
    }
    Esfera operator-(const Esfera& otra) const {
        return Esfera(radio - otra.radio);
    }
    Esfera operator*(const Esfera& otra) const {
        return Esfera(radio * otra.radio);
    }
    Esfera operator/(std::size_t n) const {
        return Esfera(radio / static_cast<double>(n));
    }
    bool operator<(const Esfera& otra) const {
        return radio < otra.radio;
    }
    friend std::ostream& operator<<(std::ostream& flujo, const Esfera& e) {
        flujo << "Esfera(radio=" << e.radio << ")";
        return flujo;
    }
};

class Texto {
private:
    std::string contenido;
public:
    Texto() : contenido("") {}
    Texto(const std::string& cadena) : contenido(cadena) {}

    // Sobrecarga de operadores
    Texto operator+(const Texto& otro) const {
        return Texto(contenido + otro.contenido);
    }
    friend std::ostream& operator<<(std::ostream& flujo, const Texto& t) {
        flujo << "\"" << t.contenido << "\"";
        return flujo;
    }
};

#endif //UNTITLED_CLASES_DEFINIDAS_H