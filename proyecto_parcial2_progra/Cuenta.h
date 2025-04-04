#pragma once
#include <iostream>	
#include <string>	
#include "Fecha.h"
#include "ModuloOperacio.h"
#include "Cliente.h"

using namespace std;


class Cuenta
{
protected:
	int nroCuenta;
	float saldo;
	Cliente* propietario;
	Fecha fechaApertura;
	Fecha fechaUltimaOperacion;
	ModuloOperacio historial;

public:
	Cuenta(int nroCuenta, float saldo, Cliente* propietario, Fecha fechaApertura);
	~Cuenta();

	int getNroCuenta()const;
	float getSaldo()const;
	Cliente* getCliente()const;

	void agregarOperacion(TipoOperacion tipo, float monto, Fecha fecha);
	void mostrarHistorial() const;


	virtual void depositar(float monto, Fecha fechaActual) = 0;
	virtual bool retirar(float monto, Fecha fechaActual) = 0;
	virtual void mostrar() = 0;

};

 

