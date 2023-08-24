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

void archivo::guardarRespuestas(vector<int> _listaRespuestas)
{
    try
    {
        if (!_listaRespuestas.empty())
        {
            ofstream guardarRespuestas("datosRespuestas.dat");
            
            while (!_listaRespuestas.empty())
            {
                guardarRespuestas << _listaRespuestas.front() << "\n";
                _listaRespuestas.erase(_listaRespuestas.begin());
            }

            guardarRespuestas.close();
        }
        else
        {
            ofstream guardarRespuestas("datosRespuestas.dat");
            guardarRespuestas << "";
            guardarRespuestas.close();
        }
    }
    catch (exception& e)
    {
        throw e;
    }
}

vector<int> archivo::cargarRespuestas()
{
    try
    {
        vector<int> listaRespuestas;

        // Cargamos el archivo con las respuestas
        ifstream cargarRespuesta("datosRespuestas.dat");

        // Si el archivo existe se abre
        if (cargarRespuesta.is_open())
        {
            // Se irá por cada linea de datos archivo y se iran definiendo cada dato para luego ser agregado de vuelta en el arbol
            while (getline(cargarRespuesta, linea))
            {
                // Respuesta dadas por el usuario
                respuesta = stoi(linea);

                listaRespuestas.push_back(respuesta);
            }
        }

        return listaRespuestas;
    }
    catch (exception& e)
    {
        throw e;
    }
}
