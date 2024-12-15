#include <iostream>

#include "includes/Transaccion.h"

#include "includes/MatrizDispersa/Matriz.h"
#include "includes/ListaCircularDoble/Lista.h"
#include "includes/MatrizDispersa/ArbolAVL.h"
#include "includes/MatrizDispersa/NodoMatriz.h"

#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iomanip>

//Declaraciones globales para que esté en todos lados
Matriz *matriz=new Matriz();//inicializo la matriz
Lista *lista=new Lista();//inicializo la lista para las transacciones

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
void usuarioMenu(Usuario *usuario){
    cout<<"Bienvenido "<<usuario->getUsuario()<<endl;//Se supone que ya tengo el usuario presesnte

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
        cout<<"7. Mis activos"<<endl;
        cout<<"8. Cerrar Sesion"<<endl;
        cin>>opcion;
        cin.ignore();

        switch(opcion){
        case 1:{
            cout<<"---------------AGREGAR ACTIVO---------------"<<endl;
            cout<<"Ingrese el nombre del activo"<<endl;
            string nombreActivo,descripcionActivo;
            cin>>nombreActivo;
            cin.ignore();
            cout<<"Ingrese la descripcion del activo"<<endl;
            cin>>descripcionActivo;
            cin.ignore();
            string id=asignarIdAlfanumerico();
            cout<<"El id asignado al activo es: "<<id<<endl;
            usuario->getActivos()->insertar(id,nombreActivo,descripcionActivo);
            break;
        }
        case 2:{
            if (usuario->getActivos()->getRaiz()==nullptr){
                cout<<"No hay activos para eliminar"<<endl;
            }else{
                cout<<"---------------ELIMINAR ACTIVO---------------"<<endl;
                cout<<"Mostrando activos"<<endl;
                usuario->getActivos()->imprimirActivos();
                cout<<"Ingrese el id del activo de desea eliminar"<<endl;
                string idActivo;
                cin>>idActivo;
                cin.ignore();
                usuario->getActivos()->eliminar(idActivo);
                cout<<"Activo eliminado con exito"<<endl;
            }
            break;
        }
        case 3:{
            if (usuario->getActivos()->getRaiz()==nullptr){
                cout<<"No hay activos para modificar"<<endl;
            }else{
                cout<<"---------------MODIFICAR ACTIVO---------------"<<endl;
                cout<<"Mostrar los activos"<<endl;
                usuario->getActivos()->imprimirActivos();
                cout<<"Ingrese el id del activo de desea modificar"<<endl;
                string idActivo;
                cin>>idActivo;
                cin.ignore();
                cout<<"Ingrese el nuevo nombre del activo"<<endl;
                string nombreActivo;
                cin>>nombreActivo;
                cin.ignore();
                cout<<"Ingrese la nueva descripcion del activo"<<endl;
                string descripcionActivo;
                cin>>descripcionActivo;
                cin.ignore();
                usuario->getActivos()->modificar(idActivo,nombreActivo,descripcionActivo);
            }
            break;
        }
        case 4:{
            if (matriz->hayActivosEnRenta()==false){
                cout<<"No hay activos disponibles para rentar"<<endl;
            }else{
                cout<<"---------------RENTAR ACTIVO---------------"<<endl;
                cout<<"Activos Disponibles"<<endl;
                matriz->mostrarActivosDisponibles();
                cout<<"Ingrese el id del activo de desea rentar"<<endl;
                string idActivo;
                cin>>idActivo;
                cin.ignore();
                cin.clear();
                cout<<"Ingrese el numero de dias por lo que quiere rentar el activo"<<endl;
                int dias;
                cin>>dias;
                cin.ignore();
                cin.clear();
                matriz->rentarActivo(idActivo,dias,usuario->getUsuario(),usuario->getContrasena());
                cout<<"Activo rentado con exito"<<endl;

                //Aquí voy a generar la transaccion
                //Se supone que aquí ando creando una transaccion
                //Esta es una parte para genera la hora y la fecha
                time_t tiempo = time(0);
                tm* now=localtime(&tiempo);
                ostringstream oss;
                oss<<put_time(now, "%H:%M %d-%m-%Y");

                lista->agregarNodo(new Transaccion(asignarIdAlfanumerico(), idActivo, usuario->getUsuario(),
                                                   usuario->getDepartamento(), usuario->getEmpresa(), oss.str(),
                                                   to_string(dias)));
                cout<<"Transaccion finalizada"<<endl;
            }
            break;
        }
        case 5:{
            if (usuario->getActivosRentados()->getTamano()==0){
                cout<<"No hay activos rentados"<<endl;
            }else{
                //Aquí colocar la devolver
                //************************************************************************************************************
                cout<<"---------------ACTIVOS RENTADOS---------------"<<endl;
                usuario->getActivosRentados()->imprimirNodos();
            }
            break;
        }
        case 6:{
            if (usuario->getActivos()->hayActivosRentados()==false){
                cout<<"No hay activos rentados"<<endl;
            }else{
                cout<<"---------------MIS ACTIVOS RENTADOS---------------"<<endl;
                usuario->getActivos()->mostrarActivosRentados();
                break;
            }

        }
        case 7:{
            if (usuario->getActivos()->getRaiz()==nullptr){
                cout<<"No hay activos agregados"<<endl;
            }else{
                cout<<"---------------MIS ACTIVOS---------------"<<endl;
                usuario->getActivos()->imprimirActivos();
            }
            break;
        }
        case 8:{
            cout<<"Cerrando sesion..."<<endl;
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
//------------------------------------------------------------------------------------------------------------------------------------------
//Ciclo para mostrar el menu del administrador :(
void adminMenu(){
    cout<<"---------------BIENVENIDO ADMINISTRADOR---------------"<<endl;
    bool menu=true;//mientras se desee que se continue mostrando el menu
    int opta; //la opción
    while(menu){//Ciclo while para las opciones
        cout<<"Selecciona una opcion:"<<endl;
        cout<<"1. Registrar Usuario"<<endl;
        cout<<"2. Reporte Matriz Dispersa"<<endl;
        cout<<"3. Reporte de Activos Disponibles en un Departamento"<<endl;
        cout<<"4. Reporte de Activos Disponibles en una empresa"<<endl;
        cout<<"5. Reporte de Transacciones"<<endl;
        cout<<"6. Reporte de Activos de un Usuario"<<endl;
        cout<<"7. Activos Rentados por un Usuario"<<endl;
        cout<<"8. Ordenar Transacciones"<<endl;
        cout<<"9. Cerrar Sesion"<<endl;
        cin.ignore(); // Limpia el estado de cin porque me anda dando probelmas
        cin>>opta;//obtengo la opcion

/*
        if (std::cin.fail()){
            // Limpia el estado de cin
            std::cin.clear(); // Descarta el resto del input inválido
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opción inválida, por favor ingrese un número del 1 al 9." << std::endl;
            continue; // Pasa a la siguiente iteración del loop
        }*/

        matriz->insertarValor("juanito","Guateamal","pollo","1234","");
        matriz->insertarValor("pedro","quiche","mac","1234","");
        matriz->insertarValor("luis","xela","mac","1234","");
        matriz->insertarValor("jacob","quiche","pollo","1234","");
        matriz->insertarValor("enner","Guateamal","mac","1234","");
        matriz->insertarValor("antonieta","xela","pollo","1234","");
        matriz->insertarValor("alberto","Guateamal","mac","1234","");
        matriz->insertarValor("matasano","quiche","pollo","1234","");
        matriz->insertarValor("kevin","quiche","pollo","1234","");
        
        switch(opta){
        case 1:{
            //Declaro unas variables
            string nombreUsuario,depa,empre,contra,nombrecito;
            cout<<"---------------CREAR USUARIO---------------"<<endl;
            //Creo el usuario
            cout<<"Ingrese nombre de usuario:"<<endl;
            cin>>nombreUsuario;
            cin.ignore();
            cout<<"Ingrese el departamento:"<<endl;
            cin>>depa;
            cin.ignore();
            cout<<"Ingrese la empresa:"<<endl;
            cin>>empre;
            cin.ignore();
            std::cout<<"Ingrese la contrasena: "<<std::endl;
            std::cin>>contra;
            cin.ignore();
            std::cout<<"Ingrese el nombre completo: "<<std::endl;
            cin>>nombrecito;
            cin.ignore();
            //Inserto los valores solicitados
            matriz->insertarValor(nombreUsuario,depa,empre,contra,nombrecito);
            break;
        }
        case 2:{
            if (matriz->getCabeceraHorizontal()==nullptr){
                cout<<"No se ha generado una matriz dispersa"<<endl;
            }else{
                cout<<"---------------REPORTE DE MATRIZ DISPERSA---------------"<<endl;
                matriz->generarReporteMatriz();
            }
            break;
        }
        case 3:{
            if (matriz->getCabeceraHorizontal()==nullptr){
                cout<<"No hay departamentos registrados"<<endl;
            }else{
                cout<<"---------------REPORTE DE ACTIVOS DISPONIBLES EN UN DEPARTAMENTO---------------"<<endl;
                cout<<"Ingrese el departamento que desea consultar"<<endl;
                string depo;
                cin>>depo;
                matriz->generarReporteActivosDepartamento(depo);
            }
            break;
        }
        case 4:{
            if (matriz->getCabeceraHorizontal()==nullptr){
                cout<<"No hay empresas registradas"<<endl;
            }else{
                cout<<"---------------REPORTE DE ACTIVOS DISPONIBLES DE UNA EMPRESA---------------"<<endl;
                cout<<"Ingrese la empresa a la que le desea consultar los activos"<<endl;
                string empr;
                cin>>empr;
                matriz->generarReporteActivosEmpresa(empr);//Esperemos que jale xd
            }
            break;
        }
        case 5:{
            if (lista->getTamano()==0){
                cout<<"No hay transacciones registradas"<<endl;
            }else{
                cout<<"---------------REPORTE DE TRANSACCIONES---------------"<<endl;
                lista->generarReporte();
                cout<<"Reporte generado exitosamente"<<endl;
            }
            break;
        }
        case 6:{
            if (matriz->getCabeceraHorizontal()==nullptr){
                cout<<"No hay usuarios registrados"<<endl;
            }else{
                cout<<"---------------REPORTE DE ACTIVOS DE UN USUARIO---------------"<<endl;
                cout<<"Ingrese el usuario que desea consultar"<<endl;
                string user;
                cin>>user;
                cout<<"Ingrese la contrasena del usuario que desea consultar"<<endl;
                string contra;
                cin>>contra;
                matriz->mostrarActivosUsuario(user,contra);
            }
            break;
        }
        case 7:{
            if (matriz->getCabeceraHorizontal()==nullptr){
                cout<<"No hay usuarios registrados"<<endl;
            }else{
                cout<<"---------------ACTIVOS RENTADOS POR UN USUARIO---------------"<<endl;
                cout<<"Ingrese el usuario que desea consultar"<<endl;
                string user;
                cin>>user;
                cout<<"Ingrese la contrasena del usuario que desea consultar"<<endl;
                string contra;
                cin>>contra;
                matriz->mostrarActivosRentados(user,contra);
            }

            break;
        }
        case 8:{
            if (lista->getTamano()==0){
                cout<<"No hay transacciones para ordenar"<<endl;
            }else{
                cout<<"---------------ORDENAR TRANSACCIONES---------------"<<endl;
                cout<<"Escoja un opcion:"<<endl;
                cout<<"1. Orden Ascendente"<<endl;
                cout<<"2. Orden desdescendente"<<endl;
                int optOrden;
                cin>>optOrden;
                switch(optOrden){
                case 1:
                    lista->ordenarAscendente();
                    cout<<"Transacciones ordenadas ascendentemente"<<endl;
                    break;
                case 2:
                    lista->ordenarDescendente();
                    cout<<"Transacciones ordenadas descendentemente"<<endl;
                    break;
                default:
                    cout<<"Opcion invalida"<<endl;
                    break;
                }
            }
            break;
        }
        case 9:{
            cout<<"Cerrando sesion..."<<endl;
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


        /*
        cout<<"Ingrese Departamento"<<endl;
        cin>>depa;
        cout<<"Ingrese Empresa:"<<endl;
        cin>>empre;*/




        NodoMatriz *usuarioito = matriz->encontrarUsuario(contra,usuario);//Encontrar el usuario
        if (usuarioito==nullptr){
            cout<<"Usuario no encontrado"<<endl;
        }else{
            cout<<"Usuario encontrado"<<endl;
            cout<<"Redirigiendo a menu de usuario"<<endl;
            usuarioMenu(usuarioito->getUsuario());
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------
//Aquí se va a encontrar el ciclo principal desde se comenzará a correr el programa
int main(){ //El ciclo principal en donde voy a colocar todo

    //probando el arbolito
    /*
    ArbolAVL *arbol=new ArbolAVL();
    arbol->insertar("111");
    arbol->insertar("222");
    arbol->insertar("333");
    arbol->insertar("889");arbol->insertar("890");
    arbol->insertar("444");
    arbol->insertar("555");
    arbol->insertar("666");
    arbol->insertar("777");
    arbol->insertar("888");
    arbol->insertar("999");
    arbol->insertar("1010");
    arbol->insertar("1111");
    arbol->generarDotGrafica();
    arbol->eliminar("111");
    arbol->eliminar("222");
    arbol->generarDotGrafica();
    */

/*
    Matriz *matriz=new Matriz();

    matriz->insertarValor(5,0,0);
    matriz->insertarValor(8,1,0);
    matriz->insertarValor(10,2,1);
    matriz->insertarValor(15,1,1);
*/
/*
    Lista *lista=new Lista();
    lista->agregarNodo(new Transaccion("2","limones","Limznero","rentador","empresa","fecha","tiempo"));
    lista->agregarNodo(new Transaccion("1","limones","Pañales","rentador","empresa","fecha","tiempo"));
    lista->agregarNodo(new Transaccion("5","limones","Limznero","rentador","empresa","fecha","tiempo"));
    lista->agregarNodo(new Transaccion("4","limones","Limznero","rentador","empresa","fecha","tiempo"));
    lista->agregarNodo(new Transaccion("3","limones","Limznero","rentador","empresa","fecha","tiempo"));
    lista->generarReporte();
    lista->ordenarDescendente();
    lista->generarReporte();
    lista->ordenarAscendente();
    lista->generarReporte();
*/
    //Ciclo para iniciar el programa
    /*
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
    cout<<"**********************************************"<<endl;
    cout<<matri->encontrarUsuario("10","enner")->getUsuario()->getUsuario()<<endl;

    */
    //Aquí voy a meter más valores para ir probando
    cout<<"**********************************************"<<endl;
    bool inicio=true;

    cout<<"---------------RENTA DE ACTIVOS---------------"<<endl;
    int opcionInicio=0;
    while (inicio){ //Ciclo principal en donde se inicia
        cout<<"Ingrese un numero "<<endl; //Mensajitos
        cout<<"1. Iniciar Sesion"<<endl;
        cout<<"2. Salir"<<endl;
        cin.clear(); // Limpia el estado de cin porque me anda dando probelmas
        cin >> opcionInicio;//Ingreso de la variables solicitada
        cin.ignore();
        cin.clear();
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

