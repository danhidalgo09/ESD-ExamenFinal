#include "Arbol.h"

Arbol::Arbol() : raiz(nullptr) {}



void Arbol::insertar(Nodo* nodo, const string& _nuevaP, const string& _nuevaR) {
    string anteriorP = nodo->pregunta;
    nodo->pregunta = _nuevaP;
    nodo->si = new Nodo(_nuevaP);
    nodo->no = new Nodo(anteriorP);
}

void Arbol::recorrerArbol(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }

    cout << nodo->pregunta << " si o no: ";
    string respuesta;
    cin >> respuesta;

    if (respuesta == "si") {
        recorrerArbol(nodo->si);
    }
    else if (respuesta == "no") {
        recorrerArbol(nodo->no);
    }
    else {
        cout << RED << "Respuesta inválida. Por favor, responder con 'si' o 'no'" << RESET << endl;
        recorrerArbol(nodo);
    }
}