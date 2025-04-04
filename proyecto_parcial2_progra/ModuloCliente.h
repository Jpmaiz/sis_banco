#pragma once
#include <iostream>	
#include <string>	
#include "Cliente.h"

using namespace std;

class ModuloCliente
{
private:
	Cliente** clientes;
	int tamMax;
	int ind;

public:
	ModuloCliente(int tamMax);	
	~ModuloCliente();

	void agregarCliente(Cliente* cliente);	
	Cliente* buscar(int ci);

	void mostrar();	

};

