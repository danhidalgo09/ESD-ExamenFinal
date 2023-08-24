#include "interfaz.h"

void interfaz::menuPrincipal()
{
	// Cargamos las preguntas en el nodo
	_arbol = _archivo.cargarPreguntas();

	// Obtenemos la raiz del arbol
	_preguntas = _arbol.obtenerRaiz();

	while (_preguntas != nullptr)
	{
		system("cls");

		// Mostramos la pregunta
		cout << _preguntas -> obtenerPregunta() -> getPregunta() << endl;

		// Le solicitamos al usuario la respuesta
		cin >> respuesta;

		// Si el usuario escribe que sí, obtendremos el nodoSi
		if (respuesta == "S")
		{
			_preguntas = _preguntas -> obtenerSi();
		}
		else if (respuesta == "N")
		{
			_preguntas = _preguntas -> obtenerNo();
		}
	}
}
