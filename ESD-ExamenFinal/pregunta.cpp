#include "pregunta.h"

// Constructores
pregunta::pregunta() { }

pregunta::pregunta(
	string _codigo, 
	string _pregunta, 
	string _codigoPregunta, 
	bool _respuesta
) {
	codigo = _codigo;
	preguntas = _pregunta;
	codigoPregunta = _codigoPregunta;
	respuesta = _respuesta;
}

// Destructor
pregunta::~pregunta() { }

// Getters
string pregunta::getCodigo()
{
	return codigo;
}

string pregunta::getPregunta()
{
	return preguntas;
}

string pregunta::getCodigoPregunta()
{
	return codigoPregunta;
}

bool pregunta::getRespuesta()
{
	return respuesta;
}

// Setters
void pregunta::setCodigo(string _codigo)
{
	codigo = _codigo;
}

void pregunta::setPregunta(string _pregunta)
{
	preguntas = _pregunta;
}

void pregunta::setCodigoPregunta(string _codigoPregunta)
{
	codigoPregunta = _codigoPregunta;
}

void pregunta::setRespuesta(bool _respuesta)
{
	respuesta = _respuesta;
}
