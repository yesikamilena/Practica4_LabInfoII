#ifndef RED_H
#define RED_H
#include <fstream>
#include <string>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
    void modificar_enrutador_txt(string linea);
    int char2int(char caracter);
    void imprimir_matriz_adyacencia();
    void mejor_ruta(char inicio, char fin);
    void mejor_ruta_2();
    void matriz_aleatoria();
    void agregar_enrutador_aleatorio(char nombre, int i, int numero_routers);
private:
    map<char,enrutador> net;
    map<char,enrutador>::iterator it;
};

#endif // RED_H
