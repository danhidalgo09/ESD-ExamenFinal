#include "std.h"

class metodoInterfaz
{
public:
	// Cambiar el color de la opcíon marcada en el menú
	void color(int _color);

	// Indicará la posición del texto al mostrarse en la consola
	void moverXY(int _x, int _y);

	// Hará que el usuario pueda seleccionar si desea continuar con la accion o no
	int confirmarDatos(string _texto, int _posicion);

	// Mostrará un cuadro de mensaje cuando ocurre un error durante la realización de una accion
	void mostrarMensajeFallido(string _mensaje);

	// Mostrará un cuadro de mensaje con la respuesta final de las preguntas
	void mostrarMensajeRespuesta(string _personaje, string _descripcion, string _descripcion2, string _descripcion3);
};

