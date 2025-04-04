#include "Operacion.h"

Operacion::Operacion(TipoOperacion tipo, float monto, Fecha fecha)
{
	this->tipo = tipo;
	this->monto = monto;
	this->fecha = fecha;	
}

void Operacion::mostrar() const
{
}

string Operacion::getTipoTexto() const
{
	return string();
}

TipoOperacion Operacion::getTipo() const
{
	return TipoOperacion();
}

float Operacion::get_Monto()  const
{
	return monto;
}

Fecha Operacion::getFecha() const
{
	return Fecha();
}
