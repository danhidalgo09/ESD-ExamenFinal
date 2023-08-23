#pragma once

#include <iostream>
#include <string>
#include "Nodo.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

class Arbol
{
public:

    Arbol();

    void insertar(Nodo* nodo, const string& _nuevaP, const string& _nuevaR);

    void recorrerArbol(Nodo* nodo);

private:
    Nodo* raiz;

   
};

