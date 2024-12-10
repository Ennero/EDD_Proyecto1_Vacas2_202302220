#include <iostream>

#include "includes/Transaccion.h"

#include "includes/MatrizDispersa/Matriz.h"
#include "includes/ListaCircularDoble/Lista.h"

#include <cstdlib>
#include <ctime>

#include "includes/Activo.h"
using namespace std;


//Función para crear un id alfanumerico aleatorio a partir de la hora :)
string asignarIdAlfanumerico(){
    std::srand(time(0));
    string idAlfanumerico = "";
    for (int i=0; i<15;i++){ //Lo itero 16 veces para que sea de longitud de 16
        int opcion = std::rand() % 2 + 1;
            if (opcion==1){ //Si es 1, será alfabetico
                int letra=char(std::rand()%26+97);
                idAlfanumerico+=char(letra);
            }else{
                int valor=char(std::rand()%10+48);
                idAlfanumerico+=char(valor);
            }
    }
    //Retorno el id alfanumérico
    return idAlfanumerico;
}





//Ciclo para mostrar el menu del usuario :)
void usuarioMenu(string usuario,string contra, string depa, string empre){
    cout<<"Bienvenido"<<usuario<<endl;

    bool menu = true;
    while(menu){
        int opcion=0;
        cout<<"Selecciona una opcion:"<<endl;
        cout<<"1. Agregar Activo"<<endl;
        cout<<"2. Eliminar Activo"<<endl;
        cout<<"3. Modificar Activo"<<endl;
        cout<<"4. Rentar Activo"<<endl;
        cout<<"5. Activos Rentados"<<endl;
        cout<<"6. Mis activos Rentados"<<endl;
        cout<<"7. Cerrar Sesion"<<endl;
        cin>>opcion;

        switch(opcion){
        case 1:
            //Aquí voy a meter lo de agregar activo
                break;
        case 2:
            //Aquí meto lo de la eliminación del activo
                break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            cout<<"Opcion invalida"<<endl;
            break;
        }
    }
}

//Ciclo para mostrar el menu del administrador :(
void adminMenu(){
    cout<<"---------------BIENVENIDO ADMINISTRADOR---------------"<<endl;

    bool menu=true;
    while(menu){
        int opcion=0;
        cout<<"Selecciona una opcion:"<<endl;
        cout<<"1. Registrar Usuario"<<endl;
        cout<<"2. Reporte Matriz Dispersa"<<endl;
        cout<<"3. Reporte de Activos Disponibles en un Departamento"<<endl;
        cout<<"4. Reporte de Activos Disponibles en una empresa"<<endl;
        cout<<"5. Reporte de Transacciones"<<endl;
        cout<<"6. Reporte de Activos de un Usuario"<<endl;
        cout<<"7. Activos Rentados por un Usuario"<<endl;
        cout<<"8. Ordenar Transacciones"<<endl;
        cout<<"9. Cerrar Sesión"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"---------------CREAR USUARIO---------------"<<endl;


                break;
            case 2:
                cout<<"---------------REPORTE DE MATRIZ DISPERSA---------------"<<endl;

                break;
            case 3:
                cout<<"---------------REPORTE DE ACTIVOS DISPONIBLES EN UN DEPARTAMENTO---------------"<<endl;

                break;
            case 4:
                cout<<"---------------REPORTE DE ACTIVOS DISPONIBLES DE UNA EMPRESA---------------"<<endl;

                break;
            case 5:
                cout<<"---------------REPORTE DE TRANSACCIONES---------------"<<endl;

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }



    }

}

//Ciclo para el ingreso de datos cuando se seleccionó la opción para esto
void ingreso(){ //void para el ingreso de los datos

    //Declaración de algunas variables que usaré
    string usuario,contra,depa,empre; //variables para solicitar datos
    string adminU="admin";
    cout<<"---------------INICIO DE SESION---------------"<<endl;

    //Ingreso de todos los datos
    cout<<"Ingrese Usuario:"<<endl;
    cin>>usuario;
    if (usuario==adminU){
        //adminMenu();
        cout<<"Hola senor admin :)"<<endl;

    }else{ //Si no es el administrador, será un usuario (supongo)
        cout<<"Ingrese Contrasena:"<<endl;
        cin>>contra;
        cout<<"Ingrese Departamento"<<endl;
        cin>>depa;
        cout<<"Ingrese Empresa:"<<endl;
        cin>>empre;

        //Aquí tendría que colocar una validación para que si sea el usuario
        usuarioMenu(usuario, contra, depa, empre);

        //Si los datos no se tiene registrados, se regresará al main para mostar el inicio de la interfaz
        //cout<<"Datos no encontrados"<<endl;
    }
}

//Aquí se va a encontrar el ciclo principal desde se comenzará a corre el programa
int main(){ //El ciclo principal en donde voy a colocar todo

    Matriz *matriz=new Matriz();

    matriz->insertarValor(5,0,0);
    matriz->insertarValor(8,1,0);
    matriz->insertarValor(10,2,1);
    matriz->insertarValor(15,1,1);


    /*
    Transaccion *admin=new Transaccion("admin","admin","admin","admin","PoloCampero","admin","admin");
    cout<<admin->getEmpresa()<<endl;
    admin->setEmpresa("MC Donalds");
    admin->setUsarioRentador("Goofy");
    cout<<admin->getEmpresa()<<admin->getUsarioRentador()<<endl;
    */

/*
    Lista *lista=new Lista();
    Transaccion *tra=new Transaccion("hola","limones","Pañales","rentador","empresa","fecha","tiempo");
    lista->agregarNodo(tra);
    lista->obtenerNodoEnPosicion(0).mostrarTransaccion();

    cout<<"---------------------"<<endl;
    Transaccion *trra=new Transaccion("Palola","limones","Limznero","rentador","empresa","fecha","tiempo");
    lista->agregarNodo(trra);
    cout<<"Adios Mundo"<<endl;


    lista->obtenerNodoEnPosicion(1).mostrarTransaccion();
    lista->obtenerNodoEnPosicion(0).mostrarTransaccion();
*/


    /*
    bool inicio=true;
    cout<<"---------------RENTA DE ACTIVOS---------------"<<endl;
    while (inicio){ //Ciclo principal en donde se inicia
        int opcionInicio=0; //Declaro la variable antes :)
        cout<<"Ingrese un numero "<<endl; //Mensajitos
        cout<<"1. Iniciar Sesion"<<endl;
        cout<<"2. Salir"<<endl;
        cin >> opcionInicio;//Ingreso de la variables solicitada

        switch (opcionInicio){ //El switchcase
        case 1: //Caso para inicializar el
            ingreso();
            break;
        case 2:
            inicio=false;
            cout<<"Saliendo..."<<endl;
            break;
        default:
            cout<<"Opcion incorrecta"<<endl;
            break;
        }
    }*/


    return 0;
}




