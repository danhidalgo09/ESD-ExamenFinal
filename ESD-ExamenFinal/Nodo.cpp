#include "nodo.h"

// Constructor
nodo::nodo(pregunta*& _pregunta): preguntas(_pregunta), si(nullptr), no(nullptr) {}

// Destructor
nodo::~nodo() { }

// Obtendrá la pregunta que se realizará al usuario
pregunta* nodo::obtenerPregunta()
{
	return preguntas;
}

// Obtener el siguiente nodo si la respuesta es sí
nodo* nodo::obtenerSi()
{
	return si;
}

// Obtener el siguiente nodo si la respuesta es no
nodo* nodo::obtenerNo()
{
	return no;
}

// Guardará la siguiente pregunta que se realizará si la respuesta es sí
void nodo::guardarSi(nodo* _si)
{
	this -> si = _si;
}

// Guardará la siguiente pregunta que se realizará si la respuesta es no
void nodo::guardarNo(nodo* _no)
{
	this -> no = _no;
}
