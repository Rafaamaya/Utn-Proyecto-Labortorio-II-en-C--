#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void menuReportes(){

    char opc;

    while(true){

        system("cls");
        Apariencia();
        textcolor(15,1);

        gotoxy(48,36);
        cout<<"*********** MENU REPORTES ***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) CLIENTE CON MAS COMPRAS"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) ARTICULO MAS VENDIDO"<<endl;
        textcolor(15,0);
        gotoxy(35,37);
        cout<<"3) USUARIO CON MAS VENTAS"<<endl;
        textcolor(15,0);
        gotoxy(35,38);
        cout<<"4) VENTA TOTAL DEL MES Y GANANCIA"<<endl;
        textcolor(15,0);
        gotoxy(70,37);
        cout<<"5) GASTOS A PROVEEDORES"<<endl;

       textcolor(15,0);
        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opc;

               switch(opc){
            case '1':

            break;

            case '2':

            break;

            case '3':

            break;

            case '4':

            break;

            case '0':
            return ;
            break;

            default: cout<<"INGRESO INCORRECTO"<<endl; system("pause");
            break;
        }
    }

    system("pause");
    return ;

    }



#endif // REPORTES_H_INCLUDED
