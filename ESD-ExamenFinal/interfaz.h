#include "archivo.h"
#include "metodoInterfaz.h"

class interfaz
{
protected:
	// Llamado a otras clases
	archivo _archivo;
	arbol _arbol;
	metodoInterfaz _mInterfaz;

	// Contenedor del arbol
	nodo* _preguntas;

	// Variable para el usuario
	int respuesta;
	vector<int> listaRespuesta;

public:
	void menuPrincipal();
};

