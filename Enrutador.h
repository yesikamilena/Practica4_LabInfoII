#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>

using namespace std;

class enrutador
{
public:
    bool agregar_enlace(char nombre, int costo);
    bool eliminar_enlace(char nombre);
    bool modificar_enlace(char nombre, int costo);
    void imprimir();
    void imprimir_costo();
    void reducir_red();
private:
    map<char,int> router;
    map<char,int>::iterator it;
};

#endif // ENRUTADOR_H
