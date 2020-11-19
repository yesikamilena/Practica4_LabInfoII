#include "Enrutador.h"
#include "Red.h"

using namespace std;

int main()
{
    enrutador router;
    red net;
    red net2;
    int a;
    char name;
    string texto;
    string nombre_texto;
    char inicio, fin;

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
            case 4:
                router.imprimir();
                break;
            default:
                break;
            }
            break;
        case 'B':
            cout <<"Escogiste el B"<<endl;
            cout << "Presiona 1 para agregar enlace, 2  para eliminar enlace, 3 para imprimir enrutador y 4 para imprimir toda la red, 5 para configurar la red del texto red.txt:  ";
            cin >> a;
            switch (a){
            case 1:
                cout << "Ingrese el nombre del nuevo enrutador: ";
                cin >> name;
                net.agregar_enrutador(name);
                break;
            case 2:
                cout << "Ingrese el nombre del enrutador a eliminar: ";
                cin >> name;
                net.eliminar_enrutador(name);
                break;
            case 3:
                cout << "Ingrese el nombre del enrutador a imprimir: ";
                cin >> name;
                net.imprimir_enrutador(name);
                break;
            case 4:
                net.imprimir_todo();
                break;
            case 5:
                cout<<"dame el nombre del archivo de texto: ";
                cin>>nombre_texto;
                net.leer_txt(nombre_texto);
                cout << texto <<endl;
                break;
            default:
                break;


            }
            break;
        case 'C':
            cout <<"Escogiste el C. Se va a imprimir la MATRIZ DE ADYACENCIA"<<endl;
            net.imprimir_matriz_adyacencia();
            break;

        case 'D':
            cout <<"Escogiste el D"<<endl;
            cout<< "Dame el router de inicial y el router final: "<<endl;
            cin>>inicio >> fin;
            net2=net;
            net.mejor_ruta(inicio, fin);
            net=net2;
            break;
        case 'E':
            cout <<"Escogiste el E"<<endl;
            net.matriz_aleatoria();
            break;
        }

    }
    return 0;
}

