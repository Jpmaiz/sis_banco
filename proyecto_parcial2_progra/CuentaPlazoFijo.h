#pragma once
#include "Cuenta.h"

class CuentaPlazoFijo : public Cuenta {
private:
    Fecha fechaVencimiento;

public:
    CuentaPlazoFijo(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura, Fecha fechaVencimiento);

    bool retirar(float monto, Fecha fechaActual) override;
    void depositar(float monto, Fecha fechaActual) override;
    Fecha getFechaVencimiento() const;

    void mostrar() override;
};