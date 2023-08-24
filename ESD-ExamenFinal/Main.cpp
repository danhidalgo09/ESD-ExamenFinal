#include "interfaz.h"

int main()
{
	interfaz _interfaz;

	// Se configura la consola para mostrar caracteres de codificacion UTF-8
	SetConsoleOutputCP(CP_UTF8);

	// Llamamos al metodo para el menú principal de la interface
	_interfaz.menuPrincipal();
}