#include "nodoArbol.h"

class arbol
{
protected:
    nodoArbol _nodoArbol;
    nodo* raiz;

public:
    // Insertará las preguntas en el nodo
    void registrarPregunta(pregunta* _pregunta);

    // Obtenemos el nodo raiz del arbol
    nodo* obtenerRaiz();

    //void recorrerArbol(nodo* _nodo);
};

