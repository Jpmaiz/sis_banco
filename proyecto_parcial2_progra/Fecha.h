#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;

    bool esBisiesto(int a) const {
        return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
    }

    int diasEnMes(int m, int a) const {
        int diasPorMes[12] = { 31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31 };
        if (m == 2 && esBisiesto(a)) return 29;
        return diasPorMes[m - 1];
    }

public:
    Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

    void mostrar() const {
        cout << (dia < 10 ? "0" : "") << dia << "/"
            << (mes < 10 ? "0" : "") << mes << "/"
            << anio << endl;
    }

    void avanzarDias(int dias) {
        while (dias > 0) {
            int diasDelMes = diasEnMes(mes, anio);
            int diasRestantes = diasDelMes - dia;

            if (dias <= diasRestantes) {
                dia += dias;
                dias = 0;
            }
            else {
                dias -= (diasRestantes + 1);
                dia = 1;
                mes++;
                if (mes > 12) {
                    mes = 1;
                    anio++;
                }
            }
        }
    }

    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    // Devuelve fecha como string (opcional)
    string toString() const {
        string dd = (dia < 10 ? "0" : "") + to_string(dia);
        string mm = (mes < 10 ? "0" : "") + to_string(mes);
        return dd + "/" + mm + "/" + to_string(anio);
    }

    // Comparación básica
    bool esMayorQue(const Fecha& otra) const {
        if (anio != otra.anio) return anio > otra.anio;
        if (mes != otra.mes) return mes > otra.mes;
        return dia > otra.dia;
    }
};
