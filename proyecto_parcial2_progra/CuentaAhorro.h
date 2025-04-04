#pragma once
#include "Cuenta.h"

class CuentaAhorro : public Cuenta {
private:
    int ultimoMesInteres;
    int ultimoAnioInteres;

public:
    CuentaAhorro(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura);

    bool retirar(float monto, Fecha fechaActual) override;
    void depositar(float monto, Fecha fechaActual) override;
    void aplicarInteresMensual(Fecha fechaActual) ;

    void mostrar() override;
};