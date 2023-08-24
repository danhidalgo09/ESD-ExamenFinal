#include "nodo.h"

// Constructor
nodo::nodo(pregunta*& _pregunta): preguntas(_pregunta), si(nullptr), no(nullptr) {}

// Destructor
nodo::~nodo() { }

// Obtendr� la pregunta que se realizar� al usuario
pregunta* nodo::obtenerPregunta()
{
	return preguntas;
}

// Obtener el siguiente nodo si la respuesta es s�
nodo* nodo::obtenerSi()
{
	return si;
}

// Obtener el siguiente nodo si la respuesta es no
nodo* nodo::obtenerNo()
{
	return no;
}

// Guardar� la siguiente pregunta que se realizar� si la respuesta es s�
void nodo::guardarSi(nodo* _si)
{
	this -> si = _si;
}

// Guardar� la siguiente pregunta que se realizar� si la respuesta es no
void nodo::guardarNo(nodo* _no)
{
	this -> no = _no;
}
