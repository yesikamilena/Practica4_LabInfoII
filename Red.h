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
    void eliminar_todo();
    void leer_txt(string name);
    void agregar_enrutador_txt(string nombre);
    int char2int(char caracter);
    void imprimir_matriz_adyacencia();
    void mejor_ruta(char inicio, char fin);
    void matriz_aleatoria();
    void agregar_enrutador_aleatorio(char nombre, int i);
private:
    map<char,enrutador> net;
    map<char,enrutador>::iterator it;
};

#endif // RED_H
