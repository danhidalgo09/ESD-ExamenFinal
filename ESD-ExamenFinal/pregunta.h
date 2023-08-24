#include "std.h"

class pregunta
{
protected:
	string codigo;
	string preguntas;
	string codigoPregunta;
	bool respuesta;

public:
	// Constructor vacio
	pregunta();

	// Constructor lleno
	pregunta(
		string _codigo,
		string _pregunta,
		string _codigoPregunta,
		bool _respuesta
	);

	// Destructor
	~pregunta();

	// Getters
	string getCodigo();
	string getPregunta();
	string getCodigoPregunta();
	bool getRespuesta();

	// Setters
	void setCodigo(string _codigo);
	void setPregunta(string _pregunta);
	void setCodigoPregunta(string _codigoPregunta);
	void setRespuesta(bool _respuesta);
};

