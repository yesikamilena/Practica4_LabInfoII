#include "Enrutador.h"
#include "Red.h"

using namespace std;

int main()
{
    enrutador router;
    red net;
    int a;
    char name;

    while(true){
        char punto;
        cout << "Elije el punto que quieres hacer (Del A al E): ";
        cin>> punto;

        switch(punto){

        case 'A':
            cout <<"Escogiste el A"<<endl;
            cout<<"Presiona 1 para agregar enlace, 2 para eliminar enlace, 3 para modificar enlace, 4 para imprimir todo: ";
            cin >>a;
            switch (a){
            case 1:
                cout << "Ingrese nombre y costo del enlace: ";
                cin >> name >> a;
                if(!router.agregar_enlace(name,a)) cout << "Error al agregar el enlace. Este ya existe."<<endl;
                break;
            case 2:
                cout <<"Ingrese nombre: ";
                cin>> name;
                if(!router.eliminar_enlace(name)) cout<< "Error al eliminar el enlace. Este no existe."<<endl;
                break;
            case 3:
                cout << "Ingrese nombre y costo del enlace a modificar: ";
                cin >> name >>a;
                if(!router.modificar_enlace(name,a)) cout << "Error al modificar el enlace. Este no existe."<<endl;
                break;
            default:
                router.imprimir();
                break;
            }
            break;
        case 'B':
            cout <<"Escogiste el B"<<endl;
            cout << "Presiona 1 para agregar enlace: ";
            cin >> a;
            switch (a){
            case 1:
                cout << "Ingrese el nombre del nuevo enrutador: ";
                cin >> name;
                net.agregar_enrutador(name);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;


            }
            break;
        case 'C':
            cout <<"Escogiste el C"<<endl;
            break;

        case 'D':
            cout <<"Escogiste el D"<<endl;
            break;
        case 'E':
            cout <<"Escogiste el E"<<endl;
            break;
        }

    }
    return 0;
}
