#include "Banco.h"


Banco::Banco(string nombre) : clientes(MAXclientes)
{
	this->nombre = nombre;
}

Banco::~Banco()
{
}

string Banco::getNombre()
{
	return nombre;
}

void Banco::setNombre(string nombre)
{
	this->nombre = nombre;	
}

ModuloCliente& Banco::getClientes()
{
	return clientes;
}

void Banco::mostrar()
{
}
