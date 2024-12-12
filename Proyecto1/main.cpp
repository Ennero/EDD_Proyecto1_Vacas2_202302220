#include <iostream>

#include "includes/Transaccion.h"

#include "includes/MatrizDispersa/Matriz.h"
#include "includes/ListaCircularDoble/Lista.h"
#include "includes/MatrizDispersa/Usuario.h"


#include <cstdlib>
#include <ctime>

#include "includes/Activo.h"
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------
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




//-------------------------------------------------------------------------------------------------------------------------------------------
//Ciclo para mostrar el menu del usuario :)
void usuarioMenu(string usuario,string contra, string depa, string empre){
    cout<<"Bienvenido"<<usuario<<endl;

    bool menu = true;
    while(menu){
        int opcion;
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
//------------------------------------------------------------------------------------------------------------------------------------------
//Ciclo para mostrar el menu del administrador :(
void adminMenu(){
    cout<<"---------------BIENVENIDO ADMINISTRADOR---------------"<<endl;
    Matriz *matri=new Matriz();
    bool menu=true;

/*
    matri->insertarValor(Usuario("elian", "1234", "guate", "igss"), Usuario("guate"), Usuario("igss"));
    matri->insertarValor(Usuario("elian", "1234", "juatiapa", "max"), Usuario("juatiapa"), Usuario("max"));
    matri->insertarValor(Usuario("elian", "1234", "jalapa", "cinepolis"), Usuario("jalapa"), Usuario("cinepolis"));
    matri->insertarValor(Usuario("elian", "1234", "zacapa", "pollo"), Usuario("zacapa"), Usuario("pollo"));
    matri->insertarValor(Usuario("elian", "1234", "peten", "pinulito"), Usuario("peten"), Usuario("pinulito"));
    matri->insertarValor(Usuario("elian", "1234", "izabal", "zara"), Usuario("izabal"), Usuario("zara"));
*/
    int opt;
    while(menu){

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
        cin>>opt;

        switch(opt){
        case 1:{
            //Declaro unas variables
            string nombreUsuario,depa,empre;
            cout<<"---------------CREAR USUARIO---------------"<<endl;
            //Creo el usuario
            cout<<"Ingrese nombre de usuario:"<<endl;
            cin>>nombreUsuario;
            cout<<"Ingrese el departamento:"<<endl;
            cin>>depa;
            cout<<"Ingrese la empresa:"<<endl;
            cin>>empre;
            //Inserto los valores solicitados
            matri->insertarValor(nombreUsuario,depa,empre);
            cout<<"Usuario ingresado exitosamente"<<endl;
            break;
        }
        case 2:{
            cout<<"---------------REPORTE DE MATRIZ DISPERSA---------------"<<endl;

            break;
        }
        case 3:{
            cout<<"---------------REPORTE DE ACTIVOS DISPONIBLES EN UN DEPARTAMENTO---------------"<<endl;

            break;
        }
        case 4:{
            cout<<"---------------REPORTE DE ACTIVOS DISPONIBLES DE UNA EMPRESA---------------"<<endl;

            break;
        }
        case 5:{
            cout<<"---------------REPORTE DE TRANSACCIONES---------------"<<endl;

            break;
        }
        case 6:{

            break;
        }
        case 7:{

            break;
        }
        case 8:{

            break;
        }
        case 9:{
            menu=false;
            break;
        }
        default:{
            cout<<"Opcion invalida"<<endl;
            break;
        }
        }



    }

}
//----------------------------------------------------------------------------------------------------------------------------------------
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
        adminMenu();

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
//----------------------------------------------------------------------------------------------------------------------------------------
//Aquí se va a encontrar el ciclo principal desde se comenzará a correr el programa
int main(){ //El ciclo principal en donde voy a colocar todo
/*
    Matriz *matriz=new Matriz();

    matriz->insertarValor(5,0,0);
    matriz->insertarValor(8,1,0);
    matriz->insertarValor(10,2,1);
    matriz->insertarValor(15,1,1);
*/

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

    Matriz *matri=new Matriz();
    matri->insertarValor("5","0","0");
    matri->insertarValor("8","1","0");
    matri->insertarValor("10","2","1");
    matri->insertarValor("15","1","1");*/
    //Ciclo para iniciar el programa
    Matriz *matri=new Matriz();
    matri->insertarValor("juanito","Guateamal","pollo");
    matri->insertarValor("pedro","quiche","mac");
    matri->insertarValor("luis","xela","mac");
    matri->insertarValor("jacob","quiche","pollo");
    matri->insertarValor("enner","Guateamal","mac");
    matri->insertarValor("antonieta","xela","pollo");
    matri->insertarValor("alberto","Guateamal","mac");
    matri->insertarValor("matasano","quiche","pollo");
    matri->insertarValor("kevin","quiche","pollo");
    matri->generarReporteMatriz();

    //Aquí voy a meter más valores para ir probando

    bool inicio=true;
    cout<<"---------------RENTA DE ACTIVOS---------------"<<endl;
    int opcionInicio=0;
    while (inicio){ //Ciclo principal en donde se inicia
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
    }

    return 0;
}




