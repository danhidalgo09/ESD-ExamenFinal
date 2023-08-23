#include "Nodo.h"

Nodo::Nodo(const string& _pregunta) : pregunta(_pregunta), si(nullptr), no(nullptr) {}

string Nodo::ToString() const {
    return pregunta;
}