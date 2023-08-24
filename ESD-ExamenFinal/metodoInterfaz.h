#include "std.h"

class metodoInterfaz
{
public:
	// Cambiar el color de la opc�on marcada en el men�
	void color(int _color);

	// Indicar� la posici�n del texto al mostrarse en la consola
	void moverXY(int _x, int _y);

	// Har� que el usuario pueda seleccionar si desea continuar con la accion o no
	int confirmarDatos(string _texto, int _posicion);

	// Mostrar� un cuadro de mensaje cuando ocurre un error durante la realizaci�n de una accion
	void mostrarMensajeFallido(string _mensaje);

	// Mostrar� un cuadro de mensaje con la respuesta final de las preguntas
	void mostrarMensajeRespuesta(string _personaje, string _descripcion, string _descripcion2, string _descripcion3);
};

