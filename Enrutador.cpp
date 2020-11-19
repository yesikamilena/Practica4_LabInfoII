#include "Enrutador.h"

bool enrutador::agregar_enlace(char nombre, int costo)
{
    bool st=false;
    if(router.find(nombre)==router.end()){
        router.insert(pair<char,int>(nombre,costo));
        st=true;
    }
    return st;
}

bool enrutador::eliminar_enlace(char nombre)
{
    bool st=false;
    if(router.find(nombre)!=router.end()){
        router.erase(nombre);
        st=true;
    }
    return st;
}

bool enrutador::modificar_enlace(char nombre, int costo)
{
    bool st=false;
    if(router.find(nombre)!=router.end()){
        router[nombre]=costo;
        st=true;
    }
    return st;
}

void enrutador::imprimir()
{
    for(it=router.begin();it!=router.end();it++)    cout<<it->first << '\t' << it->second <<endl;
}





void enrutador::imprimir_costo()
{
    for(it=router.begin();it!=router.end();it++)    cout<<it->second << '\t';
}

void enrutador::reducir_red()
{
    for(it=router.begin();it!=router.end();it++){
        if (it->second==0 || it->second==-1){
            router.erase(it->first);
        }
    }
    //return it->second;
}
