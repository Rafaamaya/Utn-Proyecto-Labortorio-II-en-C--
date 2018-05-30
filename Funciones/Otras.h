#ifndef OTRAS_H_INCLUDED
#define OTRAS_H_INCLUDED

#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10

void Listar_Eventos (int x,int y,int Dia, int Mes, int ano);
void Listar_Eventos2 (int x,int y,int Dia, int Mes, int ano);

/// ******************************************** GETCH **************************************************
/// ******************************************** GETCH **************************************************
char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

   ReadConsoleA (ih, &c, 1, &contador, NULL);

   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }

   SetConsoleMode (ih, modo); // Devolvemos control normal

   return c;
}

COORD coord = {0,0};
void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/// ******************************************** COLOR  **************************************************
/// ******************************************** COLOR **************************************************

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

/// ******************************************** CLASE RECUADRO Y VENTANA **************************************************
/// ******************************************** CLASE RECUADRO Y VENTANA **************************************************

class Recuadro{
    private:
    short iniX, iniY, ancho, alto;
    short colorLinea, colorFondo;

    public:
    void Dibujar(short , short , short , short , short , short);
    void Recuadro2(short , short , short , short , short , short);
    void Recuadro3D(short , short , short , short , short , short);
    void Ventana_Error(char *, short , short , short , short);
    void Ocultar(short , short , short , short);
    void Recuadro3(short , short , short , short , short , short);
    int Ventana_Confirmacion (char *Mensaje, short iniX, short iniY);
};
void Recuadro::Dibujar(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
        int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
void Recuadro::Recuadro2(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
        int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;///┌
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191; ///┐
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;///└
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;///┘
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;///─
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;///│
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
void Recuadro::Ocultar(short iniX, short iniY, short ancho, short alto ){
     int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(cNEGRO, cNEGRO);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
void Recuadro::Recuadro3D(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cGRIS){
        int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                textcolor(cNEGRO, colorFondo);
                cout << (char) 218;///┌
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191; ///┐
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                textcolor(cNEGRO, colorFondo);
                cout << (char) 192;///└
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;///┘
            }
            //Lineas arriba

            else if(j==iniY){
                textcolor(cNEGRO, colorFondo);
                cout << (char) 196;///─
            }
            //Lineas abajo
            else if(j==iniY+alto){
                cout << (char) 196;///─
            }
            //Lineas izquierda
            else if(i==iniX){
                textcolor(cNEGRO, colorFondo);
                cout << (char) 179;///│
            }
            //Lineas derecha
            else if(i==iniX+ancho){
                cout << (char) 179;///│
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
void Recuadro::Ventana_Error(char *Mensaje, short iniX, short iniY, short ancho, short alto){
        Recuadro::Dibujar(iniX, iniY, ancho, alto, cNEGRO, cNEGRO);///Sombra
        Recuadro::Dibujar(iniX-1,iniY-1,ancho,alto,cBLANCO,cROJO);///Recuadro de texto
        textcolor(cBLANCO,cROJO);
        int Tam = strlen(Mensaje);
        Tam= ((ancho-Tam)/2)+iniX;
        gotoxy(Tam,6);
        cout << Mensaje;
        gotoxy(25,8);
        system("pause");
        textcolor();
}

int Recuadro::Ventana_Confirmacion (char *Mensaje, short iniX, short iniY){/// Si Preciona "S" o "s" =1
        int Tam = strlen(Mensaje);                                         /// Si Preciona "N" o "n" =0 El resto no importa
        Recuadro::Dibujar(iniX, iniY, Tam+10, 6, cNEGRO, cNEGRO);///Sombra
        Recuadro::Recuadro3D(iniX-2,iniY-1, Tam+10, 6);///Recuadro de texto
        textcolor(cNEGRO,cGRIS);
        int Tam2 = (10/2)+(iniX-2);
        gotoxy(Tam2,iniY);
        cout << Mensaje;

        Tam = (((Tam+10)-30)/2)+(iniX-2);
        Recuadro::Recuadro3D(Tam, iniY+2, 10, 2);
        gotoxy(Tam+4,iniY+3);
        cout << "SI";
        Recuadro::Recuadro3D(Tam+20, iniY+2, 10, 2);
        gotoxy(Tam+24,iniY+3);
        cout << "NO";

        int tecla;
        int OP=0;
        while(OP == 0){
            tecla = getch();
            //gotoxy(iniX+30,iniY+3);
            //cout << tecla;
            if ((tecla == 115) || (tecla == 83)){
                OP = 1;
                textcolor();
                return 1;
            }
            if ((tecla == 110) || (tecla == 78)){
                OP = 1;
                textcolor();
                return 0;
            }
        tecla = 0;
        }
        textcolor();
        return -1;
}

///  ***************************************** RECUADRO 3 *******************************************************************
void Recuadro::Recuadro3(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO,short colorFondo=cNEGRO){
        int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea,colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;///┌
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191; ///┐
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;///└
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;///┘
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;///─
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;///│
            }
            //Dentro del recuadro
            else{
                cout << "";
            }
        }
    }
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}


/// ******************************************** RECUADRO **************************************************
/// ******************************************** RECUADRO **************************************************

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

/// ******************************************* FUNCION APARIENCIA *********************************************************************************************


///******************************************************************************************************************
///                                     FECHA Y HORA DEL SISTEMA
///******************************************************************************************************************
int Fecha(int *Dia, int *Mes, int *Ano, int *Ho, int *Mi, int *Se){///me  trae la fecha y la hora del sistema
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;
  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);
 *Dia = tmPtr->tm_mday;
 *Mes = tmPtr->tm_mon+1;
*Ano = 1900+tmPtr->tm_year;
  *Ho = tmPtr->tm_hour;
 *Mi = tmPtr->tm_min;
*Se = tmPtr->tm_sec;

  return 0;
}
///******************************************************************************************************************
///                                        CALENDARIO
///******************************************************************************************************************
// Devuelve
// 0 = Domingo, 1 = Lunes, 2 = Martes, 3 = Miercoles,
// 4 = Jueves, 5 = Viernes, 6 = Sábado
int zeller(int ano, int mes) {
 int a = (14 - mes) / 12;
 int y = ano - a;
 int m = mes + 12 * a - 2;
 int dia = 1, d;
 d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
 return d;
 }
string NombreMes (int mes){
    switch(mes){
    case 1:
        return "ENERO";
    case 2:
        return "FEBRERO";
    case 3:
        return "MARZO";
    case 4:
        return "ABRIL";
    case 5:
        return "MAYO";
    case 6:
        return "JUNIO";
    case 7:
        return "JULIO";
    case 8:
        return "AGOSTO";
    case 9:
        return "SEPTIRMBRE";
    case 10:
        return "OCTUBRE";
    case 11:
        return "NOVIEMBRE";
    case 12:
        return "DICIEMBRE";
    }
}
bool bisiesto (int ano){
    if (((ano %4)==0)&&((ano %100)!=0) ||((ano %100)==0) &&  (ano %400)==0) {///si es año bisiesto le agregamos un dia mas a febrero
        return true;
    }
    return false;
}
int Dia_x_Mes(int ano, int mes){
    if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
        return 31;
    }
    if (mes == 2){
            if (bisiesto (ano) == true){
                return 29;
            }
        return 28;
    }
    return 30;
}
void Calendario(int ano , int mes , int hoy){
    int dia,diames,z,r;
gotoxy(98,5);
        cout << NombreMes (mes) <<endl;
gotoxy(88,6);
        cout << "Dom Lun Mar Mir Jue Vie Sab" <<endl;
        z = zeller(ano, mes);
        int m = 88;
        m = m+(z*4);
        gotoxy(m,7);
        diames = Dia_x_Mes(ano, mes);
        int f = 8;
        int rojo;
        if (z==0){
            rojo=1;
        }
        else{
            rojo = 0;
        }
        for(dia = 1 ; dia <= diames ; dia++){
                if(rojo==0){
                    if(dia==hoy){
                        textcolor(11.0);
                        printf("%3d " , dia);
                        rojo = 0;
                    }
                    else {
                    textcolor(15.0);
                    printf("%3d " , dia);
                    }

                }
                if(rojo==1){
                    textcolor(4.0);
                    printf("%3d " , dia);
                    rojo = 0;
                }

            z++;
            if(z % 7 == 0){
                gotoxy(88,f);
                f++;
                rojo = 1;
            }
         }
        cout << endl<<endl;
return;
}
///********************************************************************************************************************
///                                             ESTETICA
///******************************************************************************************************************

void Mostrar_Titulo (){
    int X = 2;
    int Y = 0;


    char Line1[] = {"  ---------------------------------------------------------------------------- "};
    char Line2[] = {" |                            PHONE SYSTEM V 1.0                              |"};
    char Line3[] = {" |                                                                            |"};
    char Line4[] = {" |                 AMAYA RAFAEL - ELIAS AVALOS - TOBIAS OLEA                  |"};
    char Line5[] = {" |                        TSP - LABORATORIO II 2016                           |"};
    char Line6[] = {"  ---------------------------------------------------------------------------- "};
    char Line7[] = {"_______________________________________________________________________________"};


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    gotoxy (X,Y+2);
    for (unsigned int i= 0; i < sizeof(Line1); i++)
    {
        cout << Line1[i];
        Sleep(0);
    }
    gotoxy (X,Y+3);
    for (unsigned int i= 0; i < sizeof(Line2); i++)
    {
        cout << Line2[i];
        Sleep(0);
    }
    gotoxy (X,Y+4);
    for (unsigned int i= 0; i < sizeof(Line3); i++)
    {
        cout << Line3[i];
        Sleep(0);
    }
    gotoxy (X,Y+5);
    for (unsigned int i= 0; i < sizeof(Line4); i++)
    {
        cout << Line4[i];
        Sleep(0);
    }
    gotoxy (X,Y+6);
    for (unsigned int i= 0; i < sizeof(Line5); i++)
    {
        cout << Line5[i];
        Sleep(0);
    }
    gotoxy (X,Y+7);
    for (unsigned int i= 0; i < sizeof(Line6); i++)
    {
        cout << Line6[i];
        Sleep(0);
    }
   gotoxy (X,Y+8);
    for (unsigned int i= 0; i < sizeof(Line7); i++)
    {
        cout << Line7[i];
        Sleep(0);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/// ********************************************************** APARIENCIA MENU*****************************************

void Apariencia (){
    AjustarVentana(123,40);
    SetConsoleTitle("MENU");
    Recuadro obj;
    int Dia,Mes,Ano,Ho,Mi,Se;
    Fecha(&Dia, &Mes, &Ano, &Ho, &Mi, &Se);
    obj.Dibujar(1,1,81,34);
    obj.Dibujar(83,1,38,12);
    obj.Dibujar(83,14,38,21);
    obj.Dibujar(1,36,120,0,cAZUL,cAZUL);
    Mostrar_Titulo();
    gotoxy(96,2);
    cout << "CALENDARIO " << Ano;
    gotoxy(84,3);
    cout << "-------------------------------------";
    Calendario(Ano,Mes,Dia);
    Listar_Eventos (82,15,Dia, Mes, Ano);
}

/// ******************************************** APARIENCIA ALTA DE ARTICULO ***********************************************
void Apariencia_Ariculo_Ingreso(char *Titulo){
    int Dia,Mes,Ano,Ho,Mi,Se;
    Fecha(&Dia, &Mes, &Ano, &Ho, &Mi, &Se);
    Recuadro obj;
    AjustarVentana(89,16);
    SetConsoleTitle("ARTICULO - INGRESO");
    obj.Dibujar(0,0,88,16,cAZUL,cAZUL);
        int Tam = strlen(Titulo);
        Tam= ((88-Tam)/2);
        gotoxy(Tam,2);
    //gotoxy( 28,2);
    textcolor(cAMARILLO,cNEGRO);
    cout << Titulo;
    obj.Dibujar(3,3,84,12,cBLANCO,cAZUL);
    gotoxy( 6,5);
    textcolor(cBLANCO,cAZUL);
    cout << "CODIGO:";
    obj.Dibujar(13,5,4,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 20,5);
    textcolor(cBLANCO,cAZUL);
    cout << "ID PROV:";
    obj.Dibujar(29,5,2,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 33,5);
    textcolor(cBLANCO,cAZUL);
    cout << "PROVEEDOR:";
    obj.Dibujar(44,5,29,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 75,5);
    textcolor(cBLANCO,cAZUL);
    cout << "TIPO:";
    obj.Dibujar(80,5,5,0,cCIAN_CLARO,cCIAN_CLARO);
    gotoxy( 6,7);
    textcolor(cBLANCO,cAZUL);
    cout << "NOMBRE DEL ARTICULO:";
    obj.Dibujar(27,7,58,0,cCIAN_CLARO,cCIAN_CLARO);
    gotoxy( 6,9);
    textcolor(cBLANCO,cAZUL);
    cout << "PRECIO DE VENTA:";
    obj.Dibujar(23,9,10,0,cCIAN_CLARO,cCIAN_CLARO);
    gotoxy( 38,9);
    textcolor(cBLANCO,cAZUL);
    cout << "PRECIO DE COSTO:";
    obj.Dibujar(57,9,10,0,cCIAN_CLARO,cCIAN_CLARO);
    gotoxy( 72,9);
    textcolor(cBLANCO,cAZUL);
    cout << "STOCK:";
    obj.Dibujar(79,9,6,0,cCIAN_CLARO,cCIAN_CLARO);
    gotoxy( 6,11);
    textcolor(cBLANCO,cAZUL);
    cout << "FECHA: ";
    gotoxy( 13,11);
    cout <<Dia <<"/"<<Mes<<"/"<<Ano;
    gotoxy( 72,11);
    textcolor(cBLANCO,cAZUL);
    cout << "HORA: ";
    gotoxy( 78,11);
    cout <<Ho <<":"<<Mi<<":"<<Se;

    textcolor();

}
void Apariencia_Ariculo_Listado(){
Recuadro obj2;
    obj2.Dibujar(0,0,121,2);
    gotoxy(1,1);
    cout<<"ID ART";
    gotoxy(11,1);
    cout<<"ID PRO";
    gotoxy(22,1);
    cout<<"TIPO";
    gotoxy(33,1);
    cout<<"NOMBRE";
    gotoxy(60,1);
    cout<<"PRECIO DE COSTO";
    gotoxy(85,1);
    cout<<"PRECIO DE VENTA";
    gotoxy(110,1);
    cout<<"STOCK";
}

///****************************************** APARIENCIA PROVEEDOR ***********************************************************************

void Apariencia_Proveedor_Ingreso(char *Titulo){
    int Dia,Mes,Ano,Ho,Mi,Se;
    Fecha(&Dia, &Mes, &Ano, &Ho, &Mi, &Se);
    Recuadro obj;
    AjustarVentana(89,16);
    SetConsoleTitle("PROVEEDOR - INGRESO");
    obj.Dibujar(0,0,88,16,cAZUL,cAZUL);
        int Tam = strlen(Titulo);
        Tam= ((88-Tam)/2);
        gotoxy(Tam,2);
    //gotoxy( 28,2);
    textcolor(cAMARILLO,cNEGRO);
    cout << Titulo;
    obj.Dibujar(3,3,84,12,cBLANCO,cAZUL);

    gotoxy( 6,5);
    textcolor(cBLANCO,cAZUL);
    cout << "CODIGO:";
    obj.Dibujar(14,5,10,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 30,5);
    textcolor(cBLANCO,cAZUL);
    cout << "RAZON SOCIAL:";
    obj.Dibujar(44,5,30,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 30,7);
    textcolor(cBLANCO,cAZUL);
    cout << "DIRECCION:";
    obj.Dibujar(41,7,30,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 6,7);
    textcolor(cBLANCO,cAZUL);
    cout << "TELEFONO:";
    obj.Dibujar(16,7,12,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 6,9);
    textcolor(cBLANCO,cAZUL);
    cout << "EMAIL:";
    obj.Dibujar(13,9,30,0,cCIAN_CLARO,cCIAN_CLARO);


    gotoxy( 6,11);
    textcolor(cBLANCO,cAZUL);
    cout << "FECHA: ";
    gotoxy( 13,11);
    cout <<Dia <<"/"<<Mes<<"/"<<Ano;
    gotoxy( 72,11);
    textcolor(cBLANCO,cAZUL);
    cout << "HORA: ";
    gotoxy( 78,11);
    cout <<Ho <<":"<<Mi<<":"<<Se;

    gotoxy( 10,14);
   // cout<<"NOTA: EN TIPO TIPEAR MAN (MANO DE OBRA), CEL (CELULAR), ACS (ACCESORIO).";
    textcolor();

}

void Apariencia_proveedor_Listado(){
Recuadro obj2;
    obj2.Dibujar(0,0,121,2);
    gotoxy(1,1);
    cout<<"ID ART";
    gotoxy(11,1);
    cout<<"ID PRO";
    gotoxy(22,1);
    cout<<"TIPO";
    gotoxy(33,1);
    cout<<"NOMBRE";
    gotoxy(60,1);
    cout<<"PRECIO DE COSTO";
    gotoxy(85,1);
    cout<<"PRECIO DE VENTA";
    gotoxy(110,1);
    cout<<"STOCK";
}
///********************************************************************************************************************

void Apariencia_Cliente_Ingreso(char *Titulo){
    int Dia,Mes,Ano,Ho,Mi,Se;
    Fecha(&Dia, &Mes, &Ano, &Ho, &Mi, &Se);
    Recuadro obj;
    AjustarVentana(89,16);
    SetConsoleTitle("CLIENTE - INGRESO");
    obj.Dibujar(0,0,88,16,cAZUL,cAZUL);
        int Tam = strlen(Titulo);
        Tam= ((88-Tam)/2);
        gotoxy(Tam,2);
    //gotoxy( 28,2);
    textcolor(cAMARILLO,cNEGRO);
    cout << Titulo;
    obj.Dibujar(3,3,84,12,cBLANCO,cAZUL);

    gotoxy( 6,5);
    textcolor(cBLANCO,cAZUL);
    cout << "CODIGO";
    obj.Dibujar(14,5,10,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 30,5);
    textcolor(cBLANCO,cAZUL);
    cout << "NOMBRE:";
    obj.Dibujar(38,5,30,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 30,7);
    textcolor(cBLANCO,cAZUL);
    cout << "APELLIDO:";
    obj.Dibujar(40,7,30,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 6,7);
    textcolor(cBLANCO,cAZUL);
    cout << "TELEFONO:";
    obj.Dibujar(16,7,12,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 6,9);
    textcolor(cBLANCO,cAZUL);
    cout << "EMAIL:";
    obj.Dibujar(13,9,30,0,cCIAN_CLARO,cCIAN_CLARO);

    gotoxy( 45,9);
    textcolor(cBLANCO,cAZUL);
    cout << "DNI:";
    obj.Dibujar(50,9,12,0,cCIAN_CLARO,cCIAN_CLARO);


    gotoxy( 6,11);
    textcolor(cBLANCO,cAZUL);
    cout << "FECHA: ";
    gotoxy( 13,11);
    cout <<Dia <<"/"<<Mes<<"/"<<Ano;
    gotoxy( 72,11);
    textcolor(cBLANCO,cAZUL);
    cout << "HORA: ";
    gotoxy( 78,11);
    cout <<Ho <<":"<<Mi<<":"<<Se;

    gotoxy( 10,14);
   // cout<<"NOTA: EN TIPO TIPEAR MAN (MANO DE OBRA), CEL (CELULAR), ACS (ACCESORIO).";
    textcolor();

}


///***********************************************************************************************************************

void borrarCuadro(){
    int i,j;
    for(i=8;i<34;i++)
    {
        gotoxy(2,i);cout<<"                                                                                "<<endl;
    }
}
#endif // OTRAS_H_INCLUDED
