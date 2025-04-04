#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"

#include "Cuenta.h"




class ModuloCuenta
{
private:
	Cuenta** cuentas;
	int tamMax;
	int ind;

public:
	ModuloCuenta(int tamMax);
	~ModuloCuenta();

	void agregarCuenta(Cuenta* cuenta);
	Cuenta* buscar(int nroCuenta);

	int getIndice() {
		return ind;
	}


	Cuenta* buscarPorPosicion(int pos) const {
		if (pos >= 0 && pos < ind)
			return cuentas[pos];
		return nullptr;
	}

	void mostrar();
};



