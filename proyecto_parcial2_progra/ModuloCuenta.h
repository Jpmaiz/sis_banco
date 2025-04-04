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

	void mostrar();
};



