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
bool semillita = false;
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------
//Función para crear un id alfanumerico aleatorio a partir de la hora :)
string asignarIdAlfanumerico(){
    if (!semillita) {
        std::srand(static_cast<unsigned>(std::time(0))); // Semilla solo una vez
        semillita = true;
    }
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
        cout<<"---------------MENU---------------"<<endl;
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
                int optar;
                cout<<"Digite un opcion:"<<endl;
                cout<<"1.Rentar"<<endl;
                cout<<"Cualquier otro numero para cancelar"<<endl;
                cin>>optar;
                cin.ignore();
                cin.clear();
                switch (optar){
                    case 1:{
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
                        break;
                    }
                    default:{
                        cout<<"Cancelando accion..."<<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 5:{
            if (usuario->getActivosRentados()->getTamano()<=0){
                cout<<"No hay activos rentados"<<endl;
            }else{
                //Aquí colocar la devolver
                //************************************************************************************************************
                cout<<"---------------ACTIVOS RENTADOS---------------"<<endl;
                usuario->getActivosRentados()->imprimirNodos();
                cout<<"Digite un opcion:"<<endl;
                cout<<"1.Devolver"<<endl;
                cout<<"Cualquier otro numero para cancelar"<<endl;
                int optar;
                cin>>optar;
                cin.ignore();
                cin.clear();
                switch (optar){
                    case 1:{
                        cout<<"Ingrese el id del activo de desea devolver"<<endl;
                        string idActivo;
                        cin>>idActivo;
                        cin.ignore();
                        cin.clear();
                        matriz->devolverActivo(idActivo,usuario->getUsuario(),usuario->getContrasena());
                        break;
                    }
                    default:{
                        cout<<"Cancelando accion..."<<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 6:{
            if (usuario->getActivos()->hayActivosRentados()==false){
                cout<<"No hay activos agregados en renta"<<endl;
            }else{
                cout<<"---------------MIS ACTIVOS RENTADOS---------------"<<endl;
                usuario->getActivos()->imprimirActivosNoDisponibles();
            }
            break;
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
        cout<<"---------------MENU---------------"<<endl;
        cout<<"Selecciona una opcion:"<<endl;
        cout<<"1. Registrar Usuario"<<endl;
        cout<<"2. Reporte Matriz Dispersa"<<endl;
        cout<<"3. Reporte de Activos Disponibles en un Departamento"<<endl;
        cout<<"4. Reporte de Activos Disponibles en una empresa"<<endl;
        cout<<"5. Reporte de Transacciones"<<endl;
        cout<<"6. Reporte de Activos de un Usuario"<<endl;
        cout<<"7. Reporte de Activos Rentados por un Usuario"<<endl;
        cout<<"8. Ordenar Transacciones"<<endl;
        cout<<"9. Cerrar Sesion"<<endl;
        cin>>opta;//obtengo la opcion
        cin.ignore(); // Limpia el estado de cin porque me anda dando probelmas
        cin.clear();
        switch(opta){
        case 1:{
            //Declaro unas variables
            string nombreUsuario,depa,empre,contra;
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
            //Inserto los valores solicitados
            matriz->insertarValor(nombreUsuario,depa,empre,contra,"elianito");
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
                cout<<"---------REPORTE DE ACTIVOS RENTADOS POR UN USUARIO---------"<<endl;
                cout<<"Ingrese el usuario que desea consultar"<<endl;
                string user;
                cin>>user;
                cout<<"Ingrese la contrasena del usuario que desea consultar"<<endl;
                string contra;
                cin>>contra;
                matriz->generarReporteActivosRentados(user,contra);
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


    //Aquí se colocan los usuario quemados-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    matriz->insertarValor("elian_estrada","guatemala","igss","1234","");
    matriz->encontrarUsuario("1234","elian_estrada")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"madera","madera para albanil");//serán 20 dias
    matriz->encontrarUsuario("1234","elian_estrada")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"martillos","martillos para madera");//10 dias
    matriz->encontrarUsuario("1234","elian_estrada")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"caladora","caladora para cortar maderas prefabricadas");//15
    matriz->encontrarUsuario("1234","elian_estrada")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"barreno","balanza con maximo de 25kg");//5

    matriz->insertarValor("juanito","jutiapa","max","4567","");
    matriz->insertarValor("pedrito","jalapa","usac","48956","");

    matriz->insertarValor("mafer","peten","cinepolis","54312","");
    matriz->encontrarUsuario("54312","mafer")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"audifonos","audifonos para grabaciones de estudio");//10
    matriz->encontrarUsuario("54312","mafer")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"microfonos","microfonos de todo tipo");//8
    matriz->encontrarUsuario("54312","mafer")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"pedestales","pedestales para microfonos grandes y pequenos");//12
    matriz->encontrarUsuario("54312","mafer")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"atriles","atriles para colocar hojas con gancho");//14


    matriz->insertarValor("juanma","guatemala","usac","32897","");

    matriz->insertarValor("casimiro","guatemala","max","721896","");
    matriz->encontrarUsuario("721896","casimiro")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"balanza","balanza con maximo de 25kg");//15
    matriz->encontrarUsuario("721896","casimiro")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"canastas","canastas para frutas y verduras");//45
    matriz->encontrarUsuario("721896","casimiro")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"linternas","linternas para alumbrar cuartos oscuros");//10
    matriz->encontrarUsuario("721896","casimiro")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"cargadores","cargadores de telefonos tipo c");//5
    matriz->encontrarUsuario("721896","casimiro")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"cables","cables de todo tipo");//10
    matriz->encontrarUsuario("721896","casimiro")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"lazos","lazos para tender ropa");//20

    matriz->insertarValor("fuego03","jutiapa","cinepolis","891346","");
    matriz->encontrarUsuario("891346","fuego03")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"termos","pequenos termos para bebidas calientes");//10
    matriz->encontrarUsuario("891346","fuego03")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"maletas","maletas desde pequenas a grandes");//15
    matriz->encontrarUsuario("891346","fuego03")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"peliculas","todo tipo de peliculas de accion");//5

    matriz->insertarValor("azurdia","jutiapa","usac","780145","");

    matriz->insertarValor("incrediboy","jutiapa","max","201598","");//Este lo colocaré atras
    matriz->encontrarUsuario("201598","incrediboy")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"casets","casets con musica de todo tipo");//5
    matriz->encontrarUsuario("201598","incrediboy")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"pantallas","pantallas para proyeccion");//10
    matriz->encontrarUsuario("201598","incrediboy")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"canonera","canonera para proyeccion");//10
    matriz->encontrarUsuario("201598","incrediboy")->getUsuario()->getActivos()->insertar(asignarIdAlfanumerico(),"toldo","toldo para eventos al exterior");//5

    matriz->insertarValor("alcachofa","jalapa","usac","20435",""); //Este lo colocaré atras
    //Aquí se colocan los usuario quemados-----------------------------------------------------------------------------------------------------------------------------------------------------------------




    //Aquí voy a meter más valores para ir probando
    bool inicio=true;
    int opcionInicio=0;
    while (inicio){ //Ciclo principal en donde se inicia
        cout<<"---------------RENTA DE ACTIVOS---------------"<<endl;
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

}

