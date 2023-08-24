#include "interfaz.h"

int main()
{
	interfaz _interfaz;

	HWND console = GetConsoleWindow();
	RECT r;
	// Guarda las dimensiones actuales de la ventana de la consola
	GetWindowRect(console, &r); 
	// Resolucion de la consola
	MoveWindow(console, r.left, r.top, 920, 520, TRUE); // 800 width, 100 height

	// Se configura la consola para mostrar caracteres de codificacion UTF-8
	SetConsoleOutputCP(CP_UTF8);

	// Llamamos al metodo para el menú principal de la interface
	_interfaz.menuPrincipal();

	return 0;
}