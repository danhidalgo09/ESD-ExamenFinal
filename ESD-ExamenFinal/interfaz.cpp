#include "interfaz.h"

void interfaz::menuPrincipal()
{
	try
	{
		// Cargamos las preguntas en el nodo
		_arbol = _archivo.cargarPreguntas();

		// Cargamos las respuestas en el vector
		listaRespuesta = _archivo.cargarRespuestas();

		while (1)
		{
			// Obtenemos la raiz del arbol
			_preguntas = _arbol.obtenerRaiz();

			// Si el vector no esta vacio
			if (!listaRespuesta.empty())
			{
				// Moveremos el nodo hasta la ultima posicion seleccionada por el usuario
				for (int i = 0; i < listaRespuesta.size(); i++)
				{
					if (listaRespuesta[i] == 1)
					{
						_preguntas = _preguntas -> obtenerSi();
					}
					else if (listaRespuesta[i] == 2)
					{
						_preguntas = _preguntas -> obtenerNo();
					}
				}
			}

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

			for (int i = 0; i < 7; i++)
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
				respuesta = _mInterfaz.confirmarDatos(_preguntas -> obtenerPregunta() -> getPregunta(), 6);

				if (_preguntas -> obtenerPregunta() -> getCodigo() == "3" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Grito Guanaco");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "4" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Laura Ortega");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "6" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Ignacio Santos");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "6" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Migue");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "7" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Diego Garro");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "7" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Ale Grillo");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "8" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Kebria");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();
					
					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "8" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Ganoza");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "9" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Julian");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "10" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("La Power");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "10" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Viviyiyi");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				// Si no se cumplen ninguna de las condiciones anteriores, solo se obtiene la respuesta para avanzar a la siguiente pregunta
				else if (respuesta == 1)
				{
					_mInterfaz.moverXY(0, 6);
					cout << cuadroLado << "\033[100m\033[30m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << "\033[100m" << endl;
					_preguntas = _preguntas -> obtenerSi();

					// Se agrega la respuesta a la lista
					listaRespuesta.push_back(respuesta);
				}
				else if (respuesta == 2)
				{
					_mInterfaz.moverXY(0, 6);
					cout << cuadroLado << "\033[100m\033[30m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << "\033[100m" << endl;
					_preguntas = _preguntas -> obtenerNo();

					// Se agrega la respuesta a la lista
					listaRespuesta.push_back(respuesta);
				}

				// Se guarda la lista en el archivo
				_archivo.guardarRespuestas(listaRespuesta);
			}

			_mInterfaz.moverXY(0, 6);
			cout << "\033[44m" << cuadroLado << "\033[100m\033[30m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << "\033[100m" << endl;
			_mInterfaz.moverXY(25, 7);
			cout << cuadroIngresarTexto;

			_mInterfaz.moverXY(25, 6);
			cout << "Hemos llegado al final de las preguntas...";

			// El "u8" al inicio del string es para indicar que hacemos uso de caracteres de codificacion UTF-8
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
