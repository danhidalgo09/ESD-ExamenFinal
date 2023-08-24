#include "Arbol.h"

void arbol::registrarPregunta(pregunta* _pregunta)
{
    try
    {
        if (raiz == nullptr)
        {
            raiz = new nodo(_pregunta);
        }
        else
        {
            _nodoArbol.registrarPregunta(raiz, _pregunta);
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

nodo* arbol::obtenerRaiz()
{
    return raiz;
}
