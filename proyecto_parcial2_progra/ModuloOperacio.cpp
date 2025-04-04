#include "ModuloOperacio.h"

ModuloOperacio::ModuloOperacio(int tamMax)
{
	this->tamMax = tamMax;
	ind = 0;
	operaciones = new Operacion * [tamMax];	
}

ModuloOperacio::~ModuloOperacio()
{
	for (int i = 0; i < ind; i++) {
		delete operaciones[i];
	}
	delete[] operaciones;
}

void ModuloOperacio::agregarOperacion(TipoOperacion tipo, float monto, Fecha fecha)
{
	if (ind < tamMax) {
		operaciones[ind] = new Operacion(tipo, monto, fecha);
		ind++;
	}
	else {
		cout << "El historial de operaciones esta lleno." << endl;
	}
}

void ModuloOperacio::mostrarHistorial() const
{
	if (ind == 0) {
		cout << "No hay operaciones registradas." << endl;
		return;
	}

	for (int i = 0; i < ind; i++) {
		operaciones[i]->mostrar();
	}
}

int ModuloOperacio::getIndice() const
{
	return ind;
}
