#include "arbol.h"

class archivo
{
protected:
	// Llamados a las clases
	arbol _arbol;
	pregunta _preguntas;
	pregunta* preguntas;

	// Linea de la pregunta
	string linea;

	// Contar cantidad de letras
	int tama�oString(string _texto);

public:
	arbol cargarPreguntas();
};

