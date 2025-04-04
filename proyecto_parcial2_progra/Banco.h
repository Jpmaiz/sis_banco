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

	void agregarCliente(int ci, const string& nombre, const string& apellido);
	Cliente* buscarCliente(int ci);
	void mostrarClientes();



	void mostrar();
};

