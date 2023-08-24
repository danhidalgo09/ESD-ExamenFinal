#include "pregunta.h"

class nodo
{
protected:
    // Pregunta que le realizará al usuario
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

    // Obtendrá la pregunta que se realizará al usuario
    virtual pregunta* obtenerPregunta();

    // Obtener el siguiente nodo si la respuesta es sí
    virtual nodo* obtenerSi();

    // Obtener el siguiente nodo si la respuesta es no
    virtual nodo* obtenerNo();

    // Guardará la siguiente pregunta que se realizará si la respuesta es sí
    virtual void guardarSi(nodo* _si);

    // Guardará la siguiente pregunta que se realizará si la respuesta es no
    virtual void guardarNo(nodo* _no);
};

