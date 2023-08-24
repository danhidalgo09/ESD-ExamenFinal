#include "pregunta.h"

class nodo
{
protected:
    // Pregunta que le realizar� al usuario
    pregunta* preguntas;

    // Puntero al nodo izquierdo en el arbol.
    nodo* si;

    // Puntero al nodo derecho en el arbol.
    nodo* no;

public:
    // Constructor
    nodo(pregunta*& _pregunta);

    // Destructor
    virtual ~nodo();

    // Obtendr� la pregunta que se realizar� al usuario
    virtual pregunta* obtenerPregunta();

    // Obtener el siguiente nodo si la respuesta es s�
    virtual nodo* obtenerSi();

    // Obtener el siguiente nodo si la respuesta es no
    virtual nodo* obtenerNo();

    // Guardar� la siguiente pregunta que se realizar� si la respuesta es s�
    virtual void guardarSi(nodo* _si);

    // Guardar� la siguiente pregunta que se realizar� si la respuesta es no
    virtual void guardarNo(nodo* _no);
};

