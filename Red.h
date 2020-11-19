#ifndef RED_H
#define RED_H
#include <fstream>
#include <string>

#include "Enrutador.h"

class red{
public:
    void agregar_enrutador(char nombre);
    void eliminar_enrutador(char nombre);
    void imprimir_todo();
    void imprimir_enrutador(char nombre);
    void leer_txt(string name);
    void imprimir_matriz_adyacencia();
private:
    map<char,enrutador> net;
    map<char,enrutador>::iterator it;
};

#endif // RED_H
