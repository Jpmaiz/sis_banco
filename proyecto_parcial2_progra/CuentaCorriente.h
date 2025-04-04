#pragma once
#include "Cuenta.h"


class CuentaCorriente : public Cuenta
{
	private:
        float sobregiroMensual;
        float sobregiroYaCobrado;
        int mesSobregiro;
        int anioSobregiro;
        float deuda;

public:
    CuentaCorriente(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura);

    bool retirar(float monto, Fecha fechaActual) override;
    void depositar(float monto, Fecha fechaActual) override;


    float getDeuda() const;
    float getSobregiroMensual() const;

    void mostrar() override;
};

