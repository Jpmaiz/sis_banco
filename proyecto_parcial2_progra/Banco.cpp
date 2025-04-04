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

void Banco::agregarCliente(int ci, const string& nombre, const string& apellido)
{
	Cliente* nuevo = new Cliente(ci, nombre, apellido);
	clientes.agregarCliente(nuevo);
}

Cliente* Banco::buscarCliente(int ci)
{
	return clientes.buscar(ci);
}

void Banco::mostrarClientes()
{
	clientes.mostrar();
}

void Banco::mostrar()
{
}
