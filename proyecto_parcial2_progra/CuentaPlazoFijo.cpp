#include "CuentaPlazoFijo.h"

CuentaPlazoFijo::CuentaPlazoFijo(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura, Fecha fechaVencimiento)
    : Cuenta(nroCuenta, saldo, propietario, fechaApertura)
{
	this->fechaVencimiento = fechaVencimiento;  
}

bool CuentaPlazoFijo::retirar(float monto, Fecha fechaActual) {
    if (fechaActual.esMayorQue(fechaVencimiento) ||
        (fechaActual.getDia() == fechaVencimiento.getDia() &&
            fechaActual.getMes() == fechaVencimiento.getMes() &&
            fechaActual.getAnio() == fechaVencimiento.getAnio())) {

        if (monto <= saldo) {
            saldo = saldo - monto;
            agregarOperacion(RETIRO, monto, fechaActual); // ← historial
            fechaUltimaOperacion = fechaActual;
            return true;
        }
        else {
            cout << "No tiene saldo suficiente para retirar." << endl;
            return false;
        }

    }
    else {
        cout << "No se puede retirar antes de la fecha de vencimiento." << endl;
        return false;
    }
}


void CuentaPlazoFijo::depositar(float monto, Fecha fechaActual)
{
    cout << "No se permiten depositos en una cuenta a plazo fijo." << endl;
}

Fecha CuentaPlazoFijo::getFechaVencimiento() const
{
    return fechaVencimiento;
}

void CuentaPlazoFijo::mostrar()
{
    cout << "=== Cuenta a Plazo Fijo ===" << endl;
    cout << "Numero de cuenta: " << nroCuenta << endl;
    cout << "Saldo actual: $" << saldo << endl;

    cout << "Fecha de vencimiento: ";
    fechaVencimiento.mostrar();
    cout << endl;

    if (historial.getIndice() > 0) {
        cout << "Fecha de ultima operacion: ";
        fechaUltimaOperacion.mostrar();
        cout << endl;
    }
    else {
        cout << "No se ha realizado ninguna operacion aun." << endl;
    }


}
