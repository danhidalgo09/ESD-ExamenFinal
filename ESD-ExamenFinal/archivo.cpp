#include "archivo.h"

int archivo::tamañoString(string _texto)
{
    int cantidad = 0;						// Cantidad de letras en el string
    for (int i = 0; _texto[i] != '\0'; i++)	// Contará la cantidad de letras que hay en el string
    {
        cantidad++;
    }
    return cantidad;
}

arbol archivo::cargarPreguntas()
{
    try
    {
        // Cargamos el archivo con las preguntas
        ifstream cargarPregunta("datosPreguntas.dat");

        // Si el archivo existe se abre
        if (cargarPregunta.is_open())
        {
            // Se irá por cada linea de datos archivo y se iran definiendo cada dato para luego ser agregado de vuelta en el arbol
            while (getline(cargarPregunta, linea))
            {
                // Codigo de pregunta para hallar la pregunta
                _preguntas.setCodigo(linea.substr(0, linea.find("/")));
                linea.erase(0, tamañoString(_preguntas.getCodigo()) + 1);

                // La pregunta que se mostrará al usuario
                _preguntas.setPregunta(linea.substr(0, linea.find("/")));
                linea.erase(0, tamañoString(_preguntas.getPregunta()) + 1);

                // El codigo que se usará para ubicar a la pregunta cual precederá esta pregunta
                _preguntas.setCodigoPregunta(linea.substr(0, linea.find("/")));
                linea.erase(0, tamañoString(_preguntas.getCodigoPregunta()) + 1);

                // Ubicar la pregunta si el usuario dice si o no
                _preguntas.setRespuesta(stoi(linea.substr(0)));

                preguntas = new pregunta(_preguntas.getCodigo(), _preguntas.getPregunta(), _preguntas.getCodigoPregunta(), _preguntas.getRespuesta());

                _arbol.registrarPregunta(preguntas);
            }
        }
        else
        {
            throw exception("¡Hubo un error al cargar el archivo!");
        }

        cargarPregunta.close();

        return _arbol;
    }
    catch (exception& e)
    {
        throw e;
    }
}
