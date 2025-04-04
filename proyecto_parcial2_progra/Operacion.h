#pragma once
#include "Fecha.h"
#include <iostream> 
#include <string>

using namespace std;

enum TipoOperacion {
    RETIRO,
    DEPOSITO,
    INTERES,
    COMISION,
    PAGO_DEUDA,
    PAGO_PARCIAL,
    DEPOSITO_EXCEDENTE
};

class Operacion {
private:
    TipoOperacion tipo;
    float monto;
    Fecha fecha;

public:
    Operacion(TipoOperacion tipo, float monto, Fecha fecha);

    void mostrar() const;
    string getTipoTexto() const;
    TipoOperacion getTipo() const;
    float get_Monto() const;
    Fecha getFecha() const;
};