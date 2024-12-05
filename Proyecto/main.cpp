#include <iostream>
using namespace std;





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
    cout<<"Bienvenido Administrador"<<endl;

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
    }
    return 0;
}

