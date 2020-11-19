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


void red::eliminar_todo()
{
    enrutador router;
    for(it=net.begin();it!=net.end();it++){
        net.erase(it->first);
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
    agregar_enrutador_txt(data2);
    cout<<data2<<endl;
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

void red::agregar_enrutador_txt(string linea)
{
    enrutador router;
    char name=linea[2];
    int valor=0;
    int entero=0;
    int entero2=0;
    char nombre=linea[0];
    for(int j=4; j<linea.length(); j++){
        entero=char2int(linea[j]);
        entero2=entero2*10+entero;
    }
    valor=entero2;

    router.agregar_enlace(nombre,0);
    for(it=net.begin();it!=net.end();it++){
        router.agregar_enlace(it->first,-1);
        it->second.agregar_enlace(nombre,-1);
    }

//    router.agregar_enlace(nombre,0);
    //router.agregar_enlace(linea[2],0);

//    for(it=net.begin();it!=net.end();it++){
//        router.agregar_enlace(it->first,-1);
//        it->second.agregar_enlace(nombre,-1);
//    }


    if(!router.modificar_enlace(name,valor)) {
        router.agregar_enlace(name,-1);
//        for(it=net.begin();it!=net.end();it++){
//        net[name].agregar_enlace(it->first,-1);
//        it->second.agregar_enlace(name,-1);
//    }

        router.modificar_enlace(name,valor);
    }

    net[name].modificar_enlace(nombre,valor);

    net.insert(pair<char,enrutador>(nombre,router));


//    if(net.find(nombre)==net.end()){
//        router.agregar_enlace(nombre,0);
//        for(it=net.begin();it!=net.end();it++){
//            router.agregar_enlace(it->first,-1);
//            it->second.agregar_enlace(nombre,-1);
//        }
//        do{
//            cout << "Ingrese el nombre del nodo con el que se va a enlazar el nodo " <<  nombre << ". Presiona % para no agregar ningun nombre."<< endl;
//            cin >> name;
//            if(name!='%'){
//                cout << "Ingrese el costo del enlace: ";
//                cin >> valor;
//                if(!router.modificar_enlace(name,valor))    cout << "El nodo ingresado no existe" << endl;
//                else net[name].modificar_enlace(nombre,valor);
//            }
//        }while(name!='%');
//        net.insert(pair<char,enrutador>(nombre,router));
//    }




}

int red::char2int(char caracter)
{
    int entero=0;
    entero=caracter-48;
    return entero;
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

void red::mejor_ruta(char inicio, char fin)
{
    enrutador router;
    router.reducir_red();
    imprimir_matriz_adyacencia();

}

void red::matriz_aleatoria()
{
    char nombre_router;
    int numero_routers=0;
    numero_routers= rand() % 20 +2;

    for(int i=0; i<numero_routers ; i++){
        nombre_router=65+i;
        agregar_enrutador_aleatorio(nombre_router, i);
    }
}

void red::agregar_enrutador_aleatorio(char nombre, int i)
{
    enrutador router;
    char name;
    int valores=0;
    int maximo_valor_nombre;
    bool repetido=0;
    router.agregar_enlace(nombre,0);
    for(it=net.begin();it!=net.end();it++){
        router.agregar_enlace(it->first,-1);
        it->second.agregar_enlace(nombre,-1);
    }

    if (i==1){  //Si hay solo 2 routers, entonces se deben conectar entre ellos
        name='A';
        valores= rand() % 100 + 1;
        router.modificar_enlace(name,valores);
        net[name].modificar_enlace(nombre,valores);
    }
    else if(i>1){

        int numero_rutas=0;
        numero_rutas= rand() % i + 1;
        do{
            repetido=0;
            maximo_valor_nombre=64+numero_rutas+65;
            name= rand() % maximo_valor_nombre + 65;
            int* vector_usados=new int [numero_rutas];

            for(i=0; i<numero_rutas; i++){
                if (vector_usados[i]==name) repetido=1;
            }

            if(numero_rutas>0 | repetido==0){

                valores= rand() % 100 + 1;
                if(!router.modificar_enlace(name,valores))    cout << "El nodo ingresado no existe" << endl;
                else net[name].modificar_enlace(nombre,valores);
                numero_rutas--;
            }
        }while(numero_rutas>0);
    }
    net.insert(pair<char,enrutador>(nombre,router));
}

