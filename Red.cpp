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
    fstream k(name, fstream::in);	//para leerlo
    if(k.is_open()){
    while(!k.eof()){
    getline(k, data2);
    //data.append("\n\r");
    //data.append(data2);
    //cout<<data2<<endl;
    agregar_enrutador_txt(data2);
    //modificar_enrutador_txt(data2);
    cout<<"Aquí empieza";
    cout<<data2<<endl;
    //cout<<"    "<<endl;
    }
    }
    else cout<<"El archivo de texto no existe" <<endl;
}


void red::agregar_enrutador_txt(string linea)
{
    enrutador router;
    char nombre=linea[0];
    char name=linea[2];
    int valor=0;
    int entero=0;
    int entero2=0;
    for(int j=4; j<linea.length(); j++){
        entero=char2int(linea[j]);
        entero2=entero2*10+entero;
    }
    valor=entero2;

    net[nombre].agregar_enlace(nombre,0);
    net[name].agregar_enlace(name,0);

    for(it=net.begin();it!=net.end();it++){
      //  router.agregar_enlace(it->first,-1);
        net[nombre].agregar_enlace(name,-1);
        it->second.agregar_enlace(nombre,-1);
        net[nombre].agregar_enlace(it->first,-1);
        //it->second.agregar_enlace(it->first,-1);
        net[name].agregar_enlace(it->first,-1);
        //it->second.agregar_enlace(it->first,-1);
    }

    net[nombre].modificar_enlace(name,valor);
    net[name].modificar_enlace(nombre,valor);

    net.insert(pair<char,enrutador>(nombre,router));
}


void red::modificar_enrutador_txt(string linea)
{
    enrutador router;
    char nombre=linea[0];
    char name=linea[2];
    int valor=0;
    int entero=0;
    for(int j=4; j<linea.length(); j++){
        entero=char2int(linea[j]);
        valor=valor*10+entero;
    }

    net[nombre].modificar_enlace(name,valor);
    net[name].modificar_enlace(nombre,valor);
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
//    enrutador router;
//    router.reducir_red();
//    imprimir_matriz_adyacencia();

}


void red::matriz_aleatoria()
{
    char nombre=0;
    char numero_nombre_router=0;
    int numero_routers=0;
    srand (time(NULL));
    //numero_routers= rand() % 20 + 2;
    numero_routers=7;

    cout<<"Numero de routers: "<< numero_routers <<endl;

    for(int i=0; i<numero_routers ; i++){
        numero_nombre_router=65+i;
        nombre=numero_nombre_router;
        agregar_enrutador_aleatorio(nombre, i, numero_routers);
    }
}

void red::agregar_enrutador_aleatorio(char nombre, int i, int numero_routers)
{
    enrutador router;
    char name;
    int valores=0;
    bool repetido=0;
    int l=0;

    net[nombre].agregar_enlace(nombre,0);

    for(it=net.begin();it!=net.end();it++){
        net[nombre].agregar_enlace(it->first,-1);
        it->second.agregar_enlace(nombre,-1);
    }

    //Variables para el else
    int numero_rutas=0;
    int rutas_maximas;
    int maximo_valor_random=0;

    //    int* vector_usados=new int [numero_rutas];

    //    if (numero_routers==2){  //Si hay solo 2 routers, entonces se deben conectar entre ellos
    //        name='A';
    //        valores= rand() % 100 + 1;
    //        cout<<"valor: "<<valores<<endl;
    //        router.modificar_enlace(name,valores);
    //        //net[nombre].modificar_enlace(name,valores); //Añadido
    //        net[name].modificar_enlace(nombre,valores);
    //    }

    //else
    if(numero_routers>1){
        rutas_maximas=i+1;
        numero_rutas= rand() % rutas_maximas + 1;

        do{

            if(i==0){
                name=66;
            }
            else{

                maximo_valor_random=rand() % i;
                name=65+maximo_valor_random;
                //cout<<"name: "<<name<<endl;

            }

            //for(int k=0; k<numero_rutas; k++){
            //    if (vector_usados[k]==name) repetido=1;
            //}

            if(numero_rutas>0 | repetido==0){

                valores= rand() % 100 + 1;
                net[nombre].modificar_enlace(name,valores);
                net[name].modificar_enlace(nombre,valores);
                numero_rutas--;
            }
        }while(numero_rutas>0);
    }
    net.insert(pair<char,enrutador>(nombre,router));
}

