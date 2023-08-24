#include "metodoInterfaz.h"

void metodoInterfaz::color(int _color)
{
	// Obtendrá el codigo de color para la consola
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void metodoInterfaz::moverXY(int _x, int _y)
{
	// Este tipo de dato indica las coordenadas de donde se escribirá el texto
	COORD c;
	c.X = _x;
	c.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int metodoInterfaz::confirmarDatos(string _texto, int _posicion)
{
    try
    {
		// Usando el mismo sistema de la interface, se recibirá un texto para que el usuario escoja si desea realizar
		// la accion o no, y se recibira un "int _posicion" que en la posicion en Y donde aparecerá el texto
		int key;
		int nConfirmacion = 1;
		int oConfirmacion[] = { 71, 128 };

		color(128);
		moverXY(25, _posicion);
		cout << _texto;
		moverXY(28, _posicion + 1);
		cout << "/";

		while (1)
		{
			moverXY(25, _posicion + 1);
			color(oConfirmacion[0]);
			cout << "Si";

			moverXY(30, _posicion + 1);
			color(oConfirmacion[1]);
			cout << "No";

			key = _getch();

			if (key == 224)
			{

				key = _getch();

				// Valida si la flecha izquierda fue pulsada, valor 77 en ASCII
				if (key == 77)
				{
					nConfirmacion--;

					if (nConfirmacion == 0)
					{
						nConfirmacion = 2;
					}
				}
				// Valida si la flecha izquierda fue pulsada, valor 75 en ASCII
				else if (key == 75)
				{
					nConfirmacion++;

					if (nConfirmacion == 3)
					{
						nConfirmacion = 1;
					}
				}
			}
			else if (key == 27)
			{
				cout << "\033[40m\033[37m";
				system("cls");
				exit(0);
			}
			else if (key == '\r')
			{
				break;
			}

			oConfirmacion[0] = 128;
			oConfirmacion[1] = 128;

			switch (nConfirmacion)
			{
			case 1:
				oConfirmacion[0] = 71;
				break;

			case 2:
				oConfirmacion[1] = 71;
				break;
			}
		}
		cout << "\033[44m";

		return nConfirmacion;
    }
    catch (exception& e)
    {
        throw e;
    }
}

void metodoInterfaz::mostrarMensajeFallido(string _mensaje)
{
	// Se creará un cuadro de mensaje mostrando que ha ocurrido un error durante el proceso de X accion
	int key;
	string espacios(120, ' ');
	string cuadroLado(20, ' ');
	string cuadroFinal(18, ' ');
	string cuadroBorde(76, '_');
	string cuadroRelleno(76, ' ');

	system("cls");

	cout << "\033[44m\033[30m" << espacios << endl;
	cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
	}

	cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << "\033[44m\033[30m" << espacios;

	moverXY(55, 4);
	cout << "\033[100m\033[30m" << "¡Error!";

	moverXY(25, 6);
	cout << _mensaje;

	moverXY(55, 8);
	cout << "\033[41m\033[37m" << "Aceptar";

	while (1)
	{
		key = _getch();

		if (key == '\r')
		{
			break;
		}
	}

	cout << "\033[44m\033[30m";
}

void metodoInterfaz::mostrarMensajeRespuesta(string _personaje, string _descripcion, string _descripcion2, string _descripcion3)
{
	// Se creará un cuadro de mensaje mostrando que ha ocurrido un error durante el proceso de X accion
	int key;
	string espacios(120, ' ');
	string cuadroLado(20, ' ');
	string cuadroFinal(18, ' ');
	string cuadroBorde(76, '_');
	string cuadroRelleno(76, ' ');

	system("cls");

	cout << "\033[44m\033[30m" << espacios << endl;
	cout << cuadroLado << "\033[100m ." << cuadroBorde << ". \033[44m" << cuadroLado << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << cuadroLado << "\033[100m |" << cuadroRelleno << "| \033[40m  \033[44m" << cuadroFinal << endl;
	}

	cout << cuadroLado << "\033[100m |" << cuadroBorde << "| \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "\033[100m  " << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << cuadroLado << "  \033[40m" << cuadroRelleno << "  \033[40m  \033[44m" << cuadroFinal << endl;
	cout << "\033[44m\033[30m" << espacios;

	moverXY(50, 4);
	cout << "\033[100m\033[30m" << "Chatbot - Respuesta";

	moverXY(25, 6);
	cout << u8"Tú eres: " << _personaje;
	moverXY(25, 7);
	cout << u8"Descripción: " << _descripcion;
	moverXY(25, 8);
	cout << _descripcion2;
	moverXY(25, 9);
	cout << _descripcion3;

	moverXY(55, 11);
	cout << "\033[41m\033[37m" << "Aceptar";

	while (1)
	{
		key = _getch();

		if (key == '\r')
		{
			break;
		}
	}

	cout << "\033[44m\033[30m";
}
