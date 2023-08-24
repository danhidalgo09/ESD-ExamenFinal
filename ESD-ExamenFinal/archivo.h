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
	int respuesta;

	// Contar cantidad de letras
	int tamañoString(string _texto);

public:
	arbol cargarPreguntas();
	void guardarRespuestas(vector<int> _listaRespuestas);
	vector<int> cargarRespuestas();
};

