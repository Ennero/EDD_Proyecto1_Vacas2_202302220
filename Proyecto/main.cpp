#include <iostream>

using namespace std;

string usuarioAdmin,contraAdmin,depaAdmin,empreAdmin;

usuarioAdmin="Administrador"




void ingreso(){ //void para el ingreso de los datos
    //Declaración de algunas variables que usaré
    string usuario,contra,depa,empre;

    system("cls");
    cout<<"---------------RENTA DE ACTIVOS---------------"<<endl;
    cout<<"Iniciar Sesión"<<endl;

    //Ingreso de todos los datos
    cout<<"Ingrese Usuario:"<<endl;
    cin>>usuario;
    cout<<"Ingrese Contraseña:"<<endl;
    cin>>contra;
    cout<<"Ingrese Departamento"<<endl;
    cin>>depa;
    cout<<"Ingrese Empresa:"<<endl;
    cin>>empre;


}

int main(){ //El ciclo principal en donde voy a colocar todo

    bool inicio=true;
    cout<<"---------------RENTA DE ACTIVOS---------------"<<endl;
    while (inicio){ //Ciclo principal en donde se inicia
        int opcionInicio; //Declaro la variable antes :)
        cout<<"Ingrese un número "<<endl; //Mensajitos
        cout<<"1. Iniciar Sesión"<<endl;
        cout<<"2. Salir"<<endl;
        cin >> opcionInicio;//Ingreso de la variables solicitada

        switch (opcionInicio){ //El switchcase
        case 1: //Caso para inicializar el
            ingreso();
            inicio=false;
        case 2:
            inicio=false;
            cout<<"Saliendo..."<<endl;
        default:
            cout<<"Opcion incorrecta"<<endl;
        }
    }




    return 0;
}

