#include "Cuenta.h"

Cuenta::Cuenta(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura) : historial(50)
{
	this->nroCuenta = nroCuenta;
	this->saldo = saldo;
	this->propietario = propietario;
	this->fechaApertura = fechaApertura;
	this->fechaUltimaOperacion = fechaApertura; 

	

}

Cuenta::~Cuenta()
{
}

int Cuenta::getNroCuenta() const 
{
	return nroCuenta;
}

float Cuenta::getSaldo() const
{
	return saldo;
}

Cliente* Cuenta::getCliente() const
{
	return propietario;
}

void Cuenta::agregarOperacion(TipoOperacion tipo, float monto, Fecha fecha)
{
	historial.agregarOperacion(tipo, monto, fecha);
}

void Cuenta::mostrarHistorial() const
{
	cout << "Historial de cuenta #" << nroCuenta << ":" << endl;
	historial.mostrarHistorial();
}

