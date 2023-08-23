#pragma once

#include <iostream>
#include <string>

using namespace std;


class Nodo
{
public:

    string pregunta;

    // Puntero al nodo izquierdo en el arbol.
    Nodo* si;

    // Puntero al nodo derecho en el arbol.
    Nodo* no;


    Nodo(const string& _pregunta);

    string ToString() const;

};

