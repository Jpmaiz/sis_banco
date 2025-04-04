#pragma once
#include "Operacion.h"
#include "Fecha.h"

class ModuloOperacio
{
private:
	Operacion** operaciones;
	int tamMax;
	int ind;	
public:
	ModuloOperacio(int tamMax);
	~ModuloOperacio();

	void agregarOperacion(TipoOperacion tipo, float monto, Fecha fecha);
	void mostrarHistorial() const;
	int getIndice() const;

};

