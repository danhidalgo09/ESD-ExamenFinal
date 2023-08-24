#include "interfaz.h"

void interfaz::menuPrincipal()
{
	try
	{
		// Cargamos las preguntas en el nodo
		_arbol = _archivo.cargarPreguntas();

		while (1)
		{
			// Obtenemos la raiz del arbol
			_preguntas = _arbol.obtenerRaiz();

			// Series de string usados para el diseño de la interface
			// Repetirá un caracter X cantidad de veces cada vez que se llame
			string espacios(120, ' ');
			string cuadroLado(20, ' ');
			string cuadroFinal(18, ' ');
			string cuadroBorde(76, '_');
			string cuadroRelleno(76, ' ');
			string cuadroIngresarTexto(50, ' ');

			cout << "\033[44m\033[30m";
			system("cls");
			cout << espacios << endl;
			cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

			for (int i = 0; i < 9; i++)
			{
				cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
			}

			cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
			cout << "\033[44m\033[30m" << espacios;

			_mInterfaz.moverXY(50, 4);
			cout << "\033[100m" << "Chatbot - Preguntas";

			while (_preguntas != nullptr)
			{
				// Se le mostrará la pregunta al usuario y el usuario deberá seleccionar una opcion
				if (_mInterfaz.confirmarDatos(_preguntas->obtenerPregunta()->getPregunta(), 6) == 1)
				{
					_mInterfaz.moverXY(25, 6);
					cout << "\033[100m" << cuadroIngresarTexto;
					_preguntas = _preguntas->obtenerSi();
				}
				else
				{
					_mInterfaz.moverXY(25, 6);
					cout << "\033[100m" << cuadroIngresarTexto;
					_preguntas = _preguntas -> obtenerNo();
				}
			}

			_mInterfaz.moverXY(25, 6);
			cout << "\033[100m\033[30m" << cuadroIngresarTexto;
			_mInterfaz.moverXY(25, 7);
			cout << cuadroIngresarTexto;

			_mInterfaz.moverXY(25, 6);
			cout << "Hemos llegado al final de las preguntas...";

			if (_mInterfaz.confirmarDatos(u8"¿Quieres reiniciar el ciclo de preguntas?", 8) == 2)
			{
				break;
			}
		}

		cout << "\033[40m\033[37m";
		system("cls");
	}
	catch (exception& e)
	{
		_mInterfaz.mostrarMensajeFallido(e.what());
	}
}
