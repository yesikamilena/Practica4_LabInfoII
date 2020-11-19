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
        //router.eliminar_enlace(nombre);
        for(it=net.begin();it!=net.end();it++){
            //router.eliminar_enlace(it->first);
            it->second.eliminar_enlace(nombre);
        }
        net.erase(nombre);
    }
}


void red::imprimir_enrutador(char nombre)
{
    enrutador router;
    if(net.find(nombre)!=net.end()){
       // cout << nombre << '\t';
        net[nombre].imprimir();
        cout << endl;
    }
    else cout << "El enrutador no existe" << endl;
}


void red::imprimir_todo()
{
    enrutador router;
    for(it=net.begin();it!=net.end();it++){
        cout << it->first<<'\t';
        net[it->first].imprimir();
        }
        cout << endl;
}


void red::leer_txt(string name)
{
    string data, data2;
    fstream k("red.txt", fstream::in);	//para leerlo
    if(k.is_open()){
    while(!k.eof()){
    getline(k, data2);
    //data.append("\n\r");
    //data.append(data2);
    cout<<data2<<endl;
    cout<<data2[0]<<endl;
    cout<<data2[1]<<endl;
    cout<<data2[2]<<endl;
    cout<<data2[3]<<endl;
    cout<<data2[4]<<endl;

    //cout<<"    "<<endl;
    }
    }
    else cout<<"El archivo de texto no existe" <<endl;
    //cout<<data <<endl;



  //  return 0;


  //  long long int tam;
  //  string data, data2;
   // fstream k(name, fstream::in | fstream::ate | fstream::binary);  //
   // if(k.is_open()){
    //    //tam=k.tellg();
//        //k.seekg(0);
//        //for(long long int i=0; i<tam; i++) data.push_back(k.get());
//        while(!k.eof()){
 //       getline(k, data2);
//        //cout<< data2 <<endl;
//        //data.append("\n\r");
//        data.append(data2);
//        cout << "data " << data2 <<endl;
 //       return data;
//        }
//    }
//    else cout << "El archivo de texto no existe" << endl;
    //    k.close();
}

void red::imprimir_matriz_adyacencia()
{
    for(it=net.begin();it!=net.end();it++){
        cout << '\t' << it->first;
        //net[it->first].imprimir();
        }
    for(it=net.begin();it!=net.end();it++){
        cout<<endl;
        cout << it->first<< '\t' ;
        net[it->first].imprimir_costo();
        }
    cout<<endl;
}
