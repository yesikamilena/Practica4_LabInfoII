#include "Red.h"

void red::agregar_enrutador(char nombre)
{
    enrutador router;
    char name;
    int valor;
    if(net.find(nombre)==net.end()){
        router.agregar_enlace(nombre,0);
        for(it=net.begin();it!=net.end();it++){
            router.agregar_enlace(it->first,-1);
            it->second.agregar_enlace(nombre,-1);
        }
        do{
            cout << "Ingrese el nombre del nodo con el que se va a enlazar el nodo " <<  nombre << ". Presiona % para no agregar ningun nombre."<< endl;
            cin >> name;
            if(name!='%'){
                cout << "Ingrese el costo del enlace: ";
                cin >> valor;
                if(!router.modificar_enlace(name,valor))    cout << "El nodo ingresado no existe" << endl;
                else net[name].modificar_enlace(nombre,valor);
            }
        }while(name!='%');
        net.insert(pair<char,enrutador>(nombre,router));
    }
}


void red::eliminar_enrutador(char nombre)
{
    enrutador router;
    if(net.find(nombre)!=net.end()){
        router.eliminar_enlace(nombre);
        for(it=net.begin();it!=net.end();it++){
            router.eliminar_enlace(it->first);
            it->second.eliminar_enlace(nombre);
        }
    }
}


void red::imprimir_enrutador(char nombre)
{
    enrutador router;
    if(net.find(nombre)!=net.end()){
        cout << nombre << '\t';
        net[nombre].imprimir();
        cout << endl;
    }
    else cout << "El enrutador no existe" << endl;





}



