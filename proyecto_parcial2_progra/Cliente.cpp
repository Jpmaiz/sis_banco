#include "Cliente.h"

Cliente::Cliente(int ci, string nombre, string apellido)
	:cuentas(10) 
{
	this->ci = ci;	
	this->nombre = nombre;	
	this->apellido = apellido;
}

Cliente::~Cliente()
{
}

int Cliente::getCi()
{
	return ci;
}

void Cliente::setCi(int ci)
{
	this->ci = ci;	
}

string Cliente::getNombre()
{
	return nombre;
}

void Cliente::setNombre(string nombre)
{
	this->nombre = nombre;	
}

string Cliente::getApellido()
{
	return apellido;	
}

void Cliente::setApellido(string apellido)
{
	this->apellido = apellido;	
}

ModuloCuenta& Cliente::getModuloCuenta()
{
	return cuentas;
}

void Cliente::agregarCuenta(Cuenta* cuenta)
{
	cuentas.agregarCuenta(cuenta);
}

void Cliente::mostrarCuentas()
{
	cuentas.mostrar();	
}

void Cliente::mostrar()
{
	cout << "CI: " << ci << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;	
	cuentas.mostrar();
}





