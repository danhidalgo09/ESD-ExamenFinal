#include "Nodo.h"
#include "Arbol.h"

using namespace std;
int main()
{

    Arbol chatbotTree;
    Nodo* raiz = new Nodo("�Es un mam�fero?");
    chatbotTree.insertar(raiz, "�Tiene rayas?", "Cebra");
    chatbotTree.insertar(raiz->no, "�Tiene plumas?", "Serpiente");

    chatbotTree.insertar(raiz->si, "�Vive en el agua?", "Delf�n");
    chatbotTree.insertar(raiz->no->si, "�Puede volar?", "Ping�ino");
    chatbotTree.insertar(raiz->no->no, "�Es venenoso?", "Rat�n");

    cout << "�Hola! Soy un chatbot interactivo. Responde las preguntas con 'si' o 'no'." << endl;
    chatbotTree.recorrerArbol(raiz);

    delete raiz->si;
    delete raiz->no->si;
    delete raiz->no->no;
    delete raiz->no;
    delete raiz;

    return 0;

}//FIN MAIN