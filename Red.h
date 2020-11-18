#ifndef RED_H
#define RED_H

#include "Enrutador.h"

class red{
public:
    void agregar_enrutador(char nombre);
    void eliminar_enrutador(char nombre);
    void imprimir_todo();
    void imprimir_enrutador(char nombre);
private:
    map<char,enrutador> net;
    map<char,enrutador>::iterator it;
};

#endif // RED_H
