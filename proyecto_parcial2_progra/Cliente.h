#pragma once
#include <iostream>	
#include <string>	
#include "ModuloCuenta.h"

using namespace std;



class Cliente
{
private:
	int ci;
	string nombre;
	string apellido;
	ModuloCuenta cuentas; // Modulo de cuentas del cliente

public:

	Cliente(int ci, string nombre, string apellido);
	~Cliente();

	int getCi();

	void setCi(int ci);

	string getNombre();
	void setNombre(string nombre);

	string getApellido();
	void setApellido(string apellido);
	ModuloCuenta& getModuloCuenta();

	void agregarCuenta(Cuenta* cuenta);



	void mostrar();


};