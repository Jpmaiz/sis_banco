#include "ModuloCliente.h"

ModuloCliente::ModuloCliente(int tamMax)
{
	this->tamMax = tamMax;
	ind = 0;
	clientes = new Cliente * [tamMax];
}

ModuloCliente::~ModuloCliente()
{
}

void ModuloCliente::agregarCliente(Cliente* cliente)
{
	if (ind < tamMax)
	{
		clientes[ind] = cliente;
		ind++;
	}
	else
	{
		cout << "No se puede agregar mas clientes" << endl;	
	}
}

Cliente* ModuloCliente::buscar(int ci)
{
	for (int i = 0; i < ind; i++)
	{
		if (clientes[i]->getCi() == ci)
		{
			return clientes[i];
		}
	}

	return nullptr;
}

void ModuloCliente::mostrar()
{
	for (int i = 0; i < ind; i++)
	{
		clientes[i]->mostrar();
	}
}
