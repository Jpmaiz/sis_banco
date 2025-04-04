#include "ModuloCuenta.h"

ModuloCuenta::ModuloCuenta(int tamMax)
{
	this->tamMax = tamMax;
	ind = 0;
	cuentas = new Cuenta * [tamMax];
}

ModuloCuenta::~ModuloCuenta()
{
	for (int i = 0; i < ind; i++) {
		delete cuentas[i];
	}
	delete[] cuentas;
}

void ModuloCuenta::agregarCuenta(Cuenta* cuenta)
{
	if (ind < tamMax) {
		cuentas[ind] = cuenta;
		ind++;
	}
	else {
		cout << "No se pueden agregar mas cuentas a este cliente." << endl;
	}
}

Cuenta* ModuloCuenta::buscar(int nroCuenta)
{
	for (int i = 0; i < ind; i++) {
		if (cuentas[i]->getNroCuenta() == nroCuenta) {
			return cuentas[i];
		}
	}
	return nullptr; 
}

void ModuloCuenta::mostrar()
{
	if (ind == 0) {
		cout << "Este cliente no tiene cuentas registradas." << endl;
		return;
	}

	cout << "Listado de cuentas:" << endl;

	for (int i = 0; i < ind; i++) {
		cout << "Cuenta #" << cuentas[i]->getNroCuenta()
			<< " | Saldo: $" << cuentas[i]->getSaldo() << endl;
	}
}
