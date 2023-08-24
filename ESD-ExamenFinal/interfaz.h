#include "archivo.h"

class interfaz
{
protected:
	// Llamado a otras clases
	archivo _archivo;
	arbol _arbol;

	// Contenedor del arbol
	nodo* _preguntas;

	// Variable para el usuario
	string respuesta;

public:
	void menuPrincipal();
};

