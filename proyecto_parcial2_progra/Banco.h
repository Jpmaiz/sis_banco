#pragma once
#include <iostream>	
#include <string>	
#include "ModuloCliente.h"
#define MAXclientes 100 


using namespace std;


class Banco
{
private: 
	string nombre;
	ModuloCliente clientes;

public:
	Banco(string nombre);
	~Banco();
	string getNombre();
	void setNombre(string nombre);

	ModuloCliente& getClientes();


	void mostrar();
};

