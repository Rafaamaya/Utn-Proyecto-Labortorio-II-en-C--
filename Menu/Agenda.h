#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

const  char A_AGENDA[] = "datos/Agenda.dat";

class Agenda{
    private:
        int Id;
        int Dia;
        int Mes;
        int Ano;
        char Memo [50];
        bool Estado;
    public:
        void SetId     ();
        void SetDia    (int);
        void SetMes    (int);
        void SetAno    (int);
        void SetMemo   (char *);
        void SetEstado (bool);
        int  GetId     ();
        int  GetDia    ();
        int  GetMes    ();
        int  GetAno    ();
        char *GetMemo  ();
        bool GetEstado ();
        void Cargar ();
        void GrabaEnDisco();
        int LeerEnDisco(int pos);
        void ModificarRegistro(int pos);

};




void Calendario2 (int ano, int mes, int hoy);
int CantidadRegistrosAgenda();
void Listar_Eventos (int x,int y,int Dia, int Mes, int ano);
void Listar_Eventos2 (int x,int y,int Dia, int Mes, int ano);
void Listar_Eventos (int Dia, int Mes, int Ano);
int buscarEveto(int cod);
void Agregar_Evento();
void Listar_Por_Fecha ();
void Eliminarevento();


void MenuAgenda(){
//Listar_Eventos ();
    char opc;
    while(true){
        system("cls");
        int Dia,Mes,ano,Ho,Mi,Se;
        Fecha(&Dia, &Mes, &ano, &Ho, &Mi, &Se);
        Calendario2(ano,Mes,Dia);
        Listar_Eventos (3,4,Dia, Mes, ano);
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) AGREGAR EVENTO"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) LISTAR EVENTO POR FECHA"<<endl;
        textcolor(15,0);
        gotoxy(50,37);
//        cout<<"3) MODIFICAR EVENTO"<<endl;
//        textcolor(15,0);
//        gotoxy(50,38);
        cout<<"4) ELIMINAR"<<endl;
        textcolor(15,0);
        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;

        textcolor(cBLANCO,cCIAN);
        gotoxy(2,35);
        cout<<"ELIJA UNA OPCION: ";

        cin>>opc;

        switch(opc){
            case '1':
  Agregar_Evento();
            break;
            case '2':
Listar_Por_Fecha ();
textcolor(cBLANCO,cAZUL);
gotoxy(3,33);system("pause");
textcolor();
            break;
            case '3':

            break;
            case '4':
Eliminarevento();
system("pause");
            break;

            case '0':
                return;
            break;
            default:
                cout<<"OPCION INGRESADA INCORRECTA"<<endl;
                system("pause");
            break;
        }
    }

return ;
}
void Agregar_Evento(){
    Agenda reg;
    reg.Cargar();
    reg.GrabaEnDisco();
}
void Listar_Por_Fecha (){
    int Dia, Mes, ano;
    Recuadro obj;
    obj.Dibujar  (2,2,63,32,cAZUL,cAZUL);
    obj.Recuadro2(2,35,118,0,cCIAN,cCIAN);
    gotoxy(2,35);
     textcolor(cBLANCO,cCIAN);
    cout << "INGRESE FECHA:   /  /    ";
    gotoxy(17,35);
    cin >> Dia;
    gotoxy(20,35);
    cin >> Mes;
    gotoxy(23,35);
    cin >> ano;
    textcolor(cBLANCO,cAZUL);
    Listar_Eventos2 (3,4,Dia, Mes, ano);
    textcolor();
  //  system("pause>nul");
}
void Eliminarevento(){
    int Dia, Mes, ano,Id;
    Recuadro obj;
    obj.Dibujar  (2,2,63,32,cAZUL,cAZUL);
    obj.Recuadro2(2,35,118,0,cCIAN,cCIAN);
    gotoxy(2,35);
     textcolor(cBLANCO,cCIAN);
    cout << "INGRESE FECHA:   /  /    ";
    gotoxy(17,35);
    cin >> Dia;
    gotoxy(20,35);
    cin >> Mes;
    gotoxy(23,35);
    cin >> ano;
    Listar_Eventos (Dia, Mes, ano);
    obj.Recuadro2(2,35,118,0,cCIAN,cCIAN);
    gotoxy(2,35);
    textcolor(cBLANCO,cCIAN);
    cout << "INGRESE INGRESE ID A MODIFICAR ";
    gotoxy(33,35);
    cin >> Id;
    int pos = buscarArt(Id);
    Agenda reg;
    reg.LeerEnDisco(pos);
    if ((pos != -1)&& (reg.GetEstado()== 1)){
        int Op;
        Op = obj.Ventana_Confirmacion("REALMENTE DESEA BORRAR EL REGISTRO",24,9);
        if (Op==1){
                reg.SetEstado(0);
                reg.ModificarRegistro(pos);
        }
    }

}

void Listar_Eventos (int x ,int y ,int Dia, int Mes, int Ano){
    Agenda reg;
    Recuadro obj2;
    int pos = 0;
    if (reg.LeerEnDisco(pos) == 1){
        while (reg.LeerEnDisco(pos) == 1){
                if ((reg.GetDia() == Dia) && (reg.GetMes() == Mes) && (reg.GetAno() == Ano) && (reg.GetEstado() == 1)){
                        gotoxy(x+3,y);
                        cout << "  /  /    :";
                        gotoxy(x+3,y);
                        cout<<reg.GetDia();
                        gotoxy(x+7,y);
                        cout<<reg.GetMes();
                        gotoxy(x+9,y);
                        cout<< reg.GetAno();
                        gotoxy(x+15,y);
                        cout<< reg.GetMemo();
                       y++;
                }

            pos++;

        }
    }
    else{
            gotoxy(x +4,y);
        cout << "SIN EVENTOS INGRESADOS";
    }
}
void Listar_Eventos (int Dia, int Mes, int Ano){
    Agenda reg;
    int pos = 0;
    int x=3;
    int y=4;
    if (reg.LeerEnDisco(pos) == 1){
        while (reg.LeerEnDisco(pos) == 1){
                if ((reg.GetDia() == Dia) && (reg.GetMes() == Mes) && (reg.GetAno() == Ano) && (reg.GetEstado() == 1)){
                        gotoxy(x,y);
                        cout << "ID ";
                        gotoxy(x+3,y);
                        cout << reg.GetId();
                        gotoxy(x+6,y);
                        cout << "  /  /    :";
                        gotoxy(x+6,y);
                        cout<<reg.GetDia();
                        gotoxy(x+10,y);
                        cout<<reg.GetMes();
                        gotoxy(x+11,y);
                        cout<< reg.GetAno();
                        gotoxy(x+18,y);
                        cout<< reg.GetMemo();
                        gotoxy(x+38,y);
                        cout<< reg.GetEstado();
                       y++;
                }
            pos++;

        }
    }
    else{
            gotoxy(x +4,y);
        cout << "SIN EVENTOS INGRESADOS";
    }
}

///************************ SOBRECARGA EVENTOS *********************************************

void Listar_Eventos2 (int x ,int y ,int Dia, int Mes, int Ano){
    Agenda reg;
    Recuadro obj;
    int pos = 0,z=0;
    if (reg.LeerEnDisco(pos) == 1){
        while (reg.LeerEnDisco(pos) == 1){
                if ((reg.GetDia() == Dia) && (reg.GetMes() == Mes) && (reg.GetAno() == Ano) && (reg.GetEstado() == 1)){
                        gotoxy(x+3,y);
                        cout << "  /  /    :";
                        gotoxy(x+3,y);
                        cout<<reg.GetDia();
                        gotoxy(x+7,y);
                        cout<<reg.GetMes();
                        gotoxy(x+9,y);
                        cout<< reg.GetAno();
                        gotoxy(x+15,y);
                        cout<< reg.GetMemo();
                       y++;

                       z=1;
                }

            pos++;

        }
    }
    else{
            gotoxy(x +4,y);
        cout << "SIN EVENTOS INGRESADOS";
        system("pause");
    }
    if(z==0){
    obj.Ventana_Error("FECHA NO ENCONTRADA O INCORRECTA",16,6,56,4);
    }
}

///* **************************************************************************************

int CantidadRegistrosAgenda(){///Me Retorna la cantidad de registro que tiene el archivo
    FILE *p;
    p = fopen(A_AGENDA,"rb");
    if (p == NULL){///"NO EXISTE ARCHIVO A LISTAR"
        return 0;
    }
    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Agenda);
}
void Calendario2 (int ano, int mes, int hoy){
    Recuadro obj;
    obj.Dibujar  (1,1,120,34,cBLANCO,cAZUL);
    obj.Recuadro2(2,1,118,0,cCIAN,cCIAN);
    textcolor(cNEGRO,cCIAN);
    gotoxy(60,1);
    cout << "A G E N D A";
    obj.Recuadro2(69,5,40,21,cNEGRO,cNEGRO);
    obj.Recuadro2(67,4,40,21,cNEGRO,cGRIS);
    obj.Recuadro2(68,4,38,0,cCIAN,cCIAN);
    textcolor(cNEGRO,cCIAN);
    gotoxy(83,4);
    cout << "CALENDARIO";
    obj.Recuadro2(2,35,118,0,cCIAN,cCIAN);
    textcolor(cNEGRO,cGRIS);
//-------------------------------------------------------------------------------------------
    int dia,diames,z;
gotoxy(81,5);
        cout << NombreMes (mes) << ",  "<<ano<<endl;
gotoxy(71,6);
        cout << "Dom  Lun  Mar  Mir  Jue  Vie  Sab" <<endl;
        z = zeller(ano, mes);
        int m = 71;
        m = m+(z*5);
        gotoxy(m,8);
        diames = Dia_x_Mes(ano, mes);
        int f = 11;
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
                        textcolor(11,cNEGRO);
                        printf("%3d " , dia);
                        rojo = 0;
                    }
                    else {
                    textcolor(15,cGRIS);
                    printf("%3d  " , dia);
                    }
                }
                if(rojo==1){
                    textcolor(4,cGRIS);
                    printf("%3d  " , dia);
                    rojo = 0;
                }
            z++;
            if(z % 7 == 0){
                gotoxy(71,f);
                f=f+3;
                rojo = 1;
            }
         }
//------------------------------------------------------------------------------------------
    int y=7;
    for (int r=0; r<6; r++ ){
        int x=70;
        for (int i=0; i<7; i++ ){
            obj.Recuadro3(x,y,4,2,cBLANCO,cGRIS);
            x=x+5;
        }
         y=y+3;
    }
    textcolor(cBLANCO,cAZUL);
    gotoxy(48,30);
}
int buscarEveto(int cod){ ///Dado un ID me Retorna Su Pos o -1 Si No Lo Encuentro
	int pos=0;
	Agenda reg;
	while(reg.LeerEnDisco(pos) == 1) {
		if(cod == reg.GetId())
        return pos;
		pos++;
    }
	return -1;
}

void Agenda::SetId (){
    int CantRegistros;
    CantRegistros = CantidadRegistrosAgenda();
    if (CantRegistros == 0 ){
        Id = 1;
    }
    else{
//        articulos reg;
//        reg.Leer_de_disco(CantRegistros-1);
//        codArticulo = GetCodArticulo()+1;
        Id = CantRegistros+1;
    }
}
void Agenda::SetDia (int Aux){
    Dia=Aux;
}
void Agenda::SetMes (int Aux){
    Mes=Aux;
}
void Agenda::SetAno(int Aux){
    Ano=Aux;
}
void Agenda::SetMemo (char *Aux){
    strcpy(Memo,Aux);
}
void Agenda::SetEstado(bool Aux=1){
    Estado = Aux;
}
int Agenda::GetId (){
    return  Id;
}
int Agenda::GetDia (){
    return Dia;
}
int Agenda::GetMes (){
    return Mes;
}
int Agenda::GetAno (){
    return Ano;
}
char * Agenda::GetMemo (){
    return Memo;
}
bool Agenda::GetEstado(){
    return Estado;
}
void Agenda::Cargar(){
    Recuadro obj;
    Agenda::SetId();
    obj.Recuadro2(2,35,118,0,cCIAN,cCIAN);
    gotoxy(2,35);
    textcolor(cBLANCO,cCIAN);
    cout << "INGRESE FECHA:   /  /    ";
    gotoxy(17,35);
    cin >> Dia;
    gotoxy(20,35);
    cin >> Mes;
    gotoxy(23,35);
    cin >> Ano;
    obj.Recuadro2(2,35,118,0,cCIAN,cCIAN);
    textcolor(cBLANCO,cCIAN);
    gotoxy(2,35);
    cout << "INGRESE UN MEMO: ";
    gotoxy(19,35);

    cin.ignore();
    gets(Memo);

    obj.Ventana_Error("GUARDADO CORRECTAMENTE",16,6,56,4);
    Agenda::SetEstado();
    textcolor();
}
void Agenda::GrabaEnDisco (){
    FILE *p;
    p=fopen(A_AGENDA,"ab");
    if(p==NULL){
           exit(1);
    }

    fwrite(this,sizeof (Agenda),1,p);
    fclose(p);
}
int Agenda::LeerEnDisco(int pos){
    int x;
    FILE *p;
    p = fopen(A_AGENDA,"rb");
    if (p == NULL){
     //   cout << "Error De Archivo";
      //  system("pause");
        return -1;
    }
    fseek(p,sizeof (Agenda)*pos,0);
    x = fread(this , sizeof (Agenda), 1 , p);
    return x;
}
void Agenda::ModificarRegistro(int pos){
    FILE *p;
    p=fopen(A_AGENDA,"rb+");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
    }
    fseek(p , pos* sizeof (Agenda) , 0);
    fwrite(this,sizeof (Agenda),1,p);
    fclose(p);
}

#endif // AGENDA_H_INCLUDED
