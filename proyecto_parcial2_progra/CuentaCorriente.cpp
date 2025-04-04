#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura)
	: Cuenta(nroCuenta, saldo, propietario, fechaApertura)
{
	this->sobregiroMensual = 0;
	this->sobregiroYaCobrado = 0;
	this->mesSobregiro = fechaApertura.getMes();
	this->anioSobregiro = fechaApertura.getAnio();
	this->deuda = 0;
}

bool CuentaCorriente::retirar(float monto, Fecha fechaActual)
{
    if (fechaActual.getMes() != mesSobregiro || fechaActual.getAnio() != anioSobregiro) 
    {
        sobregiroMensual = 0;
        sobregiroYaCobrado = 0;
        mesSobregiro = fechaActual.getMes();
        anioSobregiro = fechaActual.getAnio();
    }

    if (monto <= saldo) 
    {
        saldo = saldo - monto;

    }
    else 
    {
        float diferencia = monto - saldo;
        float sobregiroTotalTentativo = sobregiroMensual + diferencia;

        saldo = 0;
        sobregiroMensual = sobregiroMensual + diferencia;

        if (sobregiroTotalTentativo > 1000.0f) 
        {
            float excedente = sobregiroTotalTentativo - 1000.0f;
            if (excedente > sobregiroYaCobrado) 
            {
                float nuevoExcedente = excedente - sobregiroYaCobrado;
                float comision = (nuevoExcedente * 5.0f) / 100.0f;

                deuda = deuda + comision;
                sobregiroYaCobrado = sobregiroYaCobrado + nuevoExcedente;

                agregarOperacion(COMISION, comision, fechaActual);
            }
        }

        deuda = deuda + diferencia;
    }

    agregarOperacion(RETIRO, monto, fechaActual);  // Registro del retiro
    fechaUltimaOperacion = fechaActual;

    return true;
}

void CuentaCorriente::depositar(float monto, Fecha fechaActual)
{
    int opcion;

    cout << "Tiene una deuda con el banco de: $" << deuda << endl;
    cout << "Desea usar el deposito de $" << monto << " para:" << endl;
    cout << "1. Pagar la deuda con el banco" << endl;
    cout << "2. Agregar al saldo disponible de la cuenta" << endl;
    cout << "Ingrese su opcion (1 o 2): ";
    cin >> opcion;

    if (opcion == 1) {
        if (monto >= deuda) {
            float excedente = monto - deuda;
            cout << "La deuda ha sido pagada completamente." << endl;
            deuda = 0;
            saldo = saldo + excedente;

            agregarOperacion(PAGO_DEUDA, deuda, fechaActual);
            deuda = 0;

            if (excedente > 0) {
                saldo = saldo + excedente;
                agregarOperacion(DEPOSITO_EXCEDENTE, excedente, fechaActual);
            }
        }
        else {
            deuda = deuda - monto;
            cout << "Pago parcial realizado. Deuda restante: $" << deuda << endl;
            agregarOperacion(PAGO_PARCIAL, monto, fechaActual);
        }
    }
    else if (opcion == 2) {
        saldo = saldo + monto;
        agregarOperacion(DEPOSITO, monto, fechaActual);
    }
    else {
        cout << "Opcion invalida. No se realizo el deposito." << endl;
    }

    fechaUltimaOperacion = fechaActual;
}


float CuentaCorriente::getDeuda() const
{
    return deuda;
}

float CuentaCorriente::getSobregiroMensual() const
{
    return sobregiroMensual;
}

void CuentaCorriente::mostrar()
{
    cout << "=== Cuenta Corriente ===" << endl;
    cout << "Numero de cuenta: " << nroCuenta << endl;
    cout << "Saldo actual: $" << saldo << endl;

    if (deuda > 0) {
        cout << "Deuda con el banco: $" << deuda << endl;
    }

    if (sobregiroMensual > 0) {
        cout << "Sobregiro acumulado este mes: $" << sobregiroMensual << endl;
    }

    cout << "Fecha de ultima operacion: ";
    fechaUltimaOperacion.mostrar();
    cout << endl;

    // Opcional: mostrar el nombre del cliente
    if (propietario != nullptr) {
        cout << "Cliente: " << propietario->getNombre() << endl;
    }
}

