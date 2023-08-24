#include "nodoArbol.h"

void nodoArbol::registrarPregunta(nodo*& _nodo, pregunta* _pregunta)
{
	try
	{
        nodo* temp;

        // Si llegamos al final del una rama, salimos del nodo
        if (_nodo == nullptr) 
        {
            return;
        }

        // Si encontramos el nodo con la pregunta del cual queremos que la nueva pregunta siga
        if (_nodo -> obtenerPregunta() -> getCodigo() == _pregunta -> getCodigoPregunta()) 
        {
            // Despues tenemos que averiguar en cual respuesta va la pregunta
            if (_pregunta -> getRespuesta()) 
            {
                _nodo -> guardarSi(new nodo(_pregunta));
            }
            else
            {
                _nodo -> guardarNo(new nodo(_pregunta));
            }

            // Una vez guardado el nodo regresamos
            return;
        }

        // Buscamos el nodo del seguirá la pregunta que se va a insertar
        temp = _nodo -> obtenerSi();
        registrarPregunta(temp, _pregunta);
        _nodo -> guardarSi(temp);

        temp = _nodo -> obtenerNo();
        registrarPregunta(temp, _pregunta);
        _nodo -> guardarNo(temp);
	}
	catch (exception& e)
	{
		throw e;
	}
}
