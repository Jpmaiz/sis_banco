#include "CuentaAhorro.h"

CuentaAhorro::CuentaAhorro(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura)
    : Cuenta(nroCuenta, saldo, propietario, fechaApertura)
{
    this->ultimoMesInteres = fechaApertura.getMes();
    this->ultimoAnioInteres = fechaApertura.getAnio();
}

bool CuentaAhorro::retirar(float monto, Fecha fechaActual)
{
    if (monto <= saldo) {
        saldo = saldo - monto;
        agregarOperacion(RETIRO, monto, fechaActual); 
        fechaUltimaOperacion = fechaActual;
        return true;
    }
    else {
        cout << "No tiene saldo suficiente para realizar este retiro." << endl;
        return false;
    }
}

void CuentaAhorro::depositar(float monto, Fecha fechaActual)
{
    saldo = saldo + monto;
    agregarOperacion(DEPOSITO, monto, fechaActual);
    fechaUltimaOperacion = fechaActual;
}

void CuentaAhorro::aplicarInteresMensual(Fecha fechaActual)
{
    if (fechaActual.getDia() == 1 &&
        (fechaActual.getMes() != ultimoMesInteres || fechaActual.getAnio() != ultimoAnioInteres))
    {

        float interes = saldo * 0.04f;
        saldo = saldo + interes;

        agregarOperacion(INTERES, interes, fechaActual); 

        ultimoMesInteres = fechaActual.getMes();
        ultimoAnioInteres = fechaActual.getAnio();
    }
}
