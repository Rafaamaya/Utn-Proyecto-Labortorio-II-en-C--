#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <clocale>
#include <windows.h>
#include <ctime>
#include <vector>

using namespace std;
/*#include "Funciones/fecha.h"
Fecha fsis;*/

int buscarArt(int);

#include "Funciones/Otras.h"
#include "Funciones/Ingreso.h"
#include "Menu/Clientes.h"
#include "Menu/Reportes.h"
#include "Menu/Proveedores.h"
#include "Menu/Articulos.h"
#include "Menu/Ventas.h"
#include "Menu/Presupuesto.h"
#include "Funciones/Configuracion.h"
#include "Menu/Agenda.h"

int main(){

//    vector <int> v;
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(3);
//
//    cout << "3er elemento: " << v[2] << endl;
//
//    cout << v.size();
//
//    return 0;

   // setlocale(LC_ALL, "Spanish");
    SetConsoleTitle("INGRESO");
    char opc;

        AjustarVentana(45,13);
    if(funcionIngreso()==true){
SetConsoleTitle("MENU");
AjustarVentana(123,40);
    while(true){
        textcolor();
        system("cls");


        Apariencia();
        textcolor(15,1);
        gotoxy(48,36);
        cout<<"***********MENU PRINCIPAL***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) CLIENTES"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) ARTICULOS"<<endl;
        textcolor(15,0);
        gotoxy(35,37);
        cout<<"3) VENTAS"<<endl;
        textcolor(15,0);
        gotoxy(35,38);
        cout<<"4) PRESUPUESTOS"<<endl;
        textcolor(15,0);
        gotoxy(70,37);
        cout<<"5) REPORTES"<<endl;
        textcolor(15,0);
        gotoxy(70,38);
        cout<<"6) PROVEEDORES"<<endl<<endl;
       textcolor(15,0);
        gotoxy(105,36);
        cout<<"7) CONFIGURACION"<<endl<<endl;
       textcolor(cCIAN_CLARO,0);

        gotoxy(18,39);
        cout << "A: PARA ABRIR AGENDA";

        gotoxy(70,39);
        cout << "C: PARA ABRIR CALCULADORA";


        textcolor(15,0);
        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        textcolor();
        cin>>opc;

        switch(opc){
            case '1':
            MenuClientes();
            break;

            case '2':
            MenuArticulos();
            break;

            case '3':
            MenuVentas();
            break;

            case '4':
            menuPresupuesto();
            break;

            case '5':
            menuReportes();
            break;

            case '6':
            MenuProveedores();
            break;

            case '7':
            menuConfiguracion();
            break;

            case 'a':case'A':
            MenuAgenda();
            break;

            case 'c':case'C':
            system("C:\\Windows\\system32\\calc.exe");
            break;

            case '0':
            return 0;
            break;

            default: cout<<"INGRESO INCORRECTO"<<endl; system("pause");
            break;
        }


    }

}
system("cls");
cout<<"PROGRAMA FINALIZADO"<<endl<<endl;
}
