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
					_mInterfaz.mostrarMensajeRespuesta("Grito Guanacasteco", "Sueles ser un poco timido y reservado en ocaciones lo cual", "puede jugarte malas pasadas. No tengas miedo a salir de tu zona de", u8"confort y hacer oír tu voz.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "4" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Laura Ortega", "Tienes una fuerte personalidad y eso suele meterte en", u8"problemas. Usualmente estás escuchando todos los chismes de tu", u8"círculo o bien siendo parte de ellos.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "6" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Ignacio Santos", "Sueles ser una persona centrada y resposable. Las personas", "te suelen tomar en serio. Sin embargo, ten cuidado con las parejas que", "elijes ya que algunas solo quieren ser millonarias.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "6" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Migue", "Tienes una personalidad muy calmada y sueles ser", "introvertido. En ocasiones suele darle mucha importancia a lo que las", u8"demás personas piensan de tí, pero debes aprender a ignorarlos.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "7" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Diego Garro", "Tienes una personalidad muy original y no tienes miedo de", u8"ser tú mismo. aunque las personas a tu alrededor suelen reirse de tus", "extravagancias.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "7" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Ale Grillo", "Eres una persona amable, calmada y que se lleva bien con", u8"los demás. Sueles estar alejado del drama y tienes buenas relaciones", "personales.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "8" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Kebria", u8"Tiendes a llamar la atención por tu burbujeante", u8"personalidad. Sin embargo, sueles tomar pésimas decisiones cuando hay", "alcohol involucrado.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();
					
					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "8" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Brayan Ganoza", "Eres muy extrovertido y en ocasiones eso te lleva a hacer", u8"el ridiculo en público, aunque eso no te detiene de sacar tus mejores", "pasos de baile.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "9" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta(u8"Julián Valverde (Tucán)", u8"Eres una persona muy simpática y carismática, sueles estar", "rodeado de buenas amistades, a pesar de eso eres una persona con los", "pies en la tierra y trabajador.");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerNo();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "10" && respuesta == 1)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("La Power", u8"¡Eres es-pec-ta-cu-lar!, tienes una personalidad fuerte y", u8"explosiva. Eres hermosa e irresistible, o al menos eso crees tú.", "");

					// Se obtiene el nodo con la respuesta para obtener el nodo nulo y salir del while
					_preguntas = _preguntas -> obtenerSi();

					// Se limpia la lista ya que se ha llegado al de una de las ramas de preguntas
					listaRespuesta.clear();
				}
				else if (_preguntas -> obtenerPregunta() -> getCodigo() == "10" && respuesta == 2)
				{
					// Se crea un cuadro de mensaje al que se le envia el nombre del personaje
					_mInterfaz.mostrarMensajeRespuesta("Viviyiyi", u8"Tienes una personalidad única y te gusta llamar mucho la", u8"atención, no de buena manera. Asiste donde un profesional.", "");

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

			for (int i = 0; i < 6; i++)
			{
				cout << "\033[44m" << cuadroLado << "\033[100m\033[30m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << "\033[100m" << endl;
			}
			
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
