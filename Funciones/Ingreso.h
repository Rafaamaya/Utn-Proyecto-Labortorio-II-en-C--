#ifndef INGRESO_H_INCLUDED
#define INGRESO_H_INCLUDED

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define BACK 8

char USUARIO_GLOBAL[20];


class ingreso{
private:
    int IdIngreso;
    char usuario[20];
    char contrasenia[9];
    float TotalVentas;
    int estado;
public:

    int getIdIngreso(){return IdIngreso;}
    char *getUsuario(){return usuario;}
    char *getContrasenia(){return contrasenia;}
    float getTotalVentas(){return TotalVentas;}
    int getEstado(){return estado;}

    void setIdIngreso(int id){IdIngreso=id;}
    void setUsuario(char* us){strcpy(usuario,us);}
    void setContrasenia(char* co){strcpy(contrasenia,co);}
    void setTotalVentas(float to){TotalVentas=to;}
    void setEstado(int es){estado=es;}

    bool validarUsuario(char*);
    bool validarContrasenia(char*, char*);
    bool crearUsuario();
    void mostrarIngreso(int);
    int Leer_en_disco(int);
    void Grabar_en_Disco();
    void ModificarRegistroXpos(int);

    int cantidadRegistrosIngreso();
};

///****************************************** PROTOTIPO ******************************************************************
///****************************************** PROTOTIPO ******************************************************************

bool menuOpcionUsuario();
bool ingresoUsuario();
void listarIngreso();
int buscarPosIngreso(int);
void eliminarIngreso();
void modificarIngreso();

///************************************************************************************************************************
const  char A_INGRESO[] = "datos/ingreso.dat";


///********************************  INGRESO *************************************************

bool ingresoUsuario(){
    system("cls");
    ingreso reg;

    char user[20],pass[9];

    recuadro(0,0,44,12,cBLANCO, cROJO);

                    int i;
                gotoxy(6,4);cout<<(char)218;for(i=0;i<30;i++){cout<<(char)196;}cout<<char(191);
                gotoxy(6,5);cout<<(char)179;                      gotoxy(37,5);cout<<(char)179;
                gotoxy(6,6);cout<<(char)179;                      gotoxy(37,6);cout<<(char)179;
                gotoxy(6,7);cout<<(char)179;                      gotoxy(37,7);cout<<(char)179;
                gotoxy(6,8);cout<<(char)179;                      gotoxy(37,8);cout<<(char)179;
                gotoxy(6,9);cout<<(char)192;for(i=0;i<30;i++){cout<<(char)196;}cout<<char(217);

    gotoxy(8,6 );cout<<"INGRESE USUARIO: ";
    cin>>user;

    if(reg.validarUsuario(&user[0])==false){
     gotoxy(8,8);   cout<<"USUARIO INCORRECTO"<<endl;

        return false;
    }
    gotoxy(8,7);cout<<"INGRESE CONTRASE"<<(char)165<<"A: ";
    cin>>pass;

        if(reg.validarContrasenia(&pass[0], &user[0])==false){
       gotoxy(8,8); cout<<"CONTRASE"<<(char)165<<"A INCORRECTA"<<endl;
        return false;
    }

    strcpy(USUARIO_GLOBAL,user);
    return true;
}


///******************************** MENU INGRESO *************************************************
///******************************** MENU INGRESO *************************************************


bool funcionIngreso(){

/// **************************** FUNCION TECLAS **************************************

        char tecla;
        int opcionSeleccionada=1;


while(true){


bool repite=true;

    recuadro(0,0,44,12,cBLANCO, cROJO);

   gotoxy(15,5); cout<<"INGRESAR";
   gotoxy(15,6); cout<<"OPCIONES USUARIO";
   gotoxy(15,7); cout<<"SALIR";

    while(repite){
///*********************************** MENU PRINCIPAL ***********************************************
///*********************************** MENU PRINCIPAL ***********************************************


        gotoxy(9,2 + opcionSeleccionada); cout<<"   ";
        gotoxy(9,3 + opcionSeleccionada); cout<<"   ";
        gotoxy(9,4 + opcionSeleccionada); cout<<"==>";
        gotoxy(9,5 + opcionSeleccionada); cout<<"   ";
        gotoxy(9,6 + opcionSeleccionada); cout<<"   ";
        gotoxy(9,7 + opcionSeleccionada); cout<<"   ";


///  ***************************************FUNCION TECLAS*****************************************

        gotoxy(12,4 + opcionSeleccionada);tecla = getch();
        switch(tecla){

        case TECLA_ARRIBA:
        opcionSeleccionada--;
        if(opcionSeleccionada < 1){
            opcionSeleccionada = 3;
        }
        break;

        case TECLA_ABAJO:
        opcionSeleccionada++;
            if(opcionSeleccionada > 3){
            opcionSeleccionada = 1;
        }
        break;

        case ENTER:
        repite = false;
        break;

        }

    }

/// ******************************************* MENU USUARIO ***********************************************************
        ingreso reg;
        switch(opcionSeleccionada){

        case 1:
        if(ingresoUsuario()==true){
            return true;
        }
        system("pause>nul");
        break;

        case 2:
        menuOpcionUsuario();
        break;

        case 3:
        return false;
        break;

        default: cout<<"INGRESO INCORRECTO"<<endl;
         system("pause");
        break;
        }
       system("cls");
    }
}

///******************************** VALIDAR USUARIO *************************************************


bool ingreso::validarUsuario(char *user){
    FILE *p;
	p=fopen(A_INGRESO,"rb");
	if(p==NULL){
        gotoxy(15,10);cout<<"Error de archivo...";
        fclose(p);
        return false;
    }
    while(fread(this,sizeof *this,1,p)){
        if(strcmp(user,usuario)==0 && estado !=0){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;

}

///******************************** VALIDAR CONTRASEÑA *************************************************

bool ingreso::validarContrasenia(char *pass, char *user){
    FILE *p;
	p=fopen(A_INGRESO,"rb");
	if(p==NULL){cout<<"Error de archivo";return false;}

    while(fread(this,sizeof *this,1,p)){
        if(strcmp(contrasenia,pass)==0 && strcmp(usuario,user)==0 && estado !=0){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;

}

///******************************** CREAR USUARIO *************************************************


bool ingreso::crearUsuario(){
    Recuadro obj;
    system("cls");

    IdIngreso=cantidadRegistrosIngreso();
    int id=IdIngreso;
    recuadro(0,0,44,12,cBLANCO,cROJO);

    gotoxy(15,3 );cout<<"ID DE USUARIO: "<<IdIngreso<<endl;
    gotoxy(5,6 );cout<<"INGRESE NUEVO USUARIO: ";
    cin>>usuario;

    char us[20];
    strcpy(us ,usuario);

    if(ingreso::validarUsuario(&us[0]) == true){
        system("cls");
        recuadro(0,0,44,12,cBLANCO,cROJO);
        gotoxy(15,6);cout<<"USUARIO EXISTENTE"<<endl;
        return false;
    }
    strcpy(usuario ,us);
    IdIngreso=id;

    gotoxy(5,8); cout<<"INGRESE NUEVA CONTRASE"<<(char)165<<"A: ";
    cin>>contrasenia;

    TotalVentas=0;
    estado=1;

    FILE *p;
    p=fopen(A_INGRESO, "ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return false;
    }

    fseek(p,0,0);
    fwrite(this,sizeof *this,1,p);
	fclose(p);
	system("cls");
	recuadro(0,0,44,12,cBLANCO,cROJO);
	gotoxy(15,6);cout<<"USUARIO CREADO"<<endl;
	return true;
}

///************************************ CANTIDAD REGISTROS ***********************************************

int ingreso::cantidadRegistrosIngreso(){///Me Retorna la cantidad de registro que tiene el archivo

    FILE *p;
    p = fopen(A_INGRESO,"rb");
    if (p == NULL){
        return 1;

    }

    int cv=1;
    ingreso reg;

    while(fread(&reg, sizeof (ingreso), 1, p)){
        cv++;

    }
    fclose(p);
    return cv;

}


/// **************************************   MENU USUARIO    **************************************************
/// **************************************  CLAVE EMPRESARIAL   ******************************************************

bool menuOpcionUsuario(){
    system("cls");
    char pass[4];

                recuadro(0,0,44,12,cBLANCO, cROJO);

                int i;
                gotoxy(6,4);cout<<(char)218;for(i=0;i<30;i++){cout<<(char)196;}cout<<char(191);
                gotoxy(6,5);cout<<(char)179<<" CLAVE EMPRESARIAL: ";gotoxy(37,5);cout<<(char)179;
                gotoxy(6,6);cout<<(char)192;for(i=0;i<30;i++){cout<<(char)196;}cout<<char(217);

    gotoxy(27,5);cin>>pass;

    if(strcmp(pass,"afk")!=0){
       system("cls");
       gotoxy(5,3 );
       gotoxy(5,4 ); cout<<"ACCESO RESTRINGIDO"<<endl;
       gotoxy(5,5 );

        return false;
    }

  char tecla;
        int opcionSeleccionada=1,borrarFlechaA=1,borrarFlechaB=1;

while(true){

bool repite=true;

    recuadro(0,0,44,12,cBLANCO, cROJO);

    gotoxy(15,4); cout<<"CREAR USUARIO";
    gotoxy(15,5); cout<<"LISTAR USUARIOS";
    gotoxy(15,6); cout<<"MODIFICAR USUARIO";
    gotoxy(15,7); cout<<"ELIMINAR";
    gotoxy(15,8); cout<<"SALIR";

    while(repite){

///*********************************** MENU OPCIONES USUARIO ***********************************************

        gotoxy(9,2 + opcionSeleccionada); cout<<"   ";
        gotoxy(9,3 + opcionSeleccionada); cout<<"==>";
        gotoxy(9,4 + opcionSeleccionada); cout<<"   ";

///  *****************************************************************************************************

        gotoxy(12,3 + opcionSeleccionada);tecla = getch();
        switch(tecla){

        case TECLA_ARRIBA:
        opcionSeleccionada--;


        if(opcionSeleccionada < 1){
            opcionSeleccionada = 5;
            gotoxy(9,4); cout<<"   ";
        }

        break;

        case TECLA_ABAJO:
        opcionSeleccionada++;

        if(opcionSeleccionada > 5){
            opcionSeleccionada = 1;
            gotoxy(9,8); cout<<"   ";
        }


        break;

        case ENTER:
        repite = false;
        break;

        }

    }

/// ******************************************* FUNCION TECLAS ***********************************************************
        ingreso reg;
        switch(opcionSeleccionada){

        case 1:
        reg.crearUsuario();
        system("pause>nul");
        break;

        case 2:
        listarIngreso();
        system("pause>nul");
        break;

        case 3:
        system("cls");
        modificarIngreso();
        system("pause>nul");
        break;

        case 4:
        eliminarIngreso();
        system("pause>nul");
        break;

        case 5:
        return false;
        break;

        default: cout<<"INGRESO INCORRECTO"<<endl;
         system("pause");
        break;
        }
       system("cls");
    }
}

/// ********************************************** FUNCIONES *****************************************************************

void ingreso::mostrarIngreso(int alto){
    if(estado==0){
    return;
    }
    gotoxy(3,alto);cout<<IdIngreso;
    gotoxy(15,alto);cout<<usuario;
    gotoxy(30,alto);cout<<contrasenia;

}

///********************************************** LISTAR TODOS LOS INGRESOS ******************************************************************************************

void listarIngreso(){
    system("cls");
    ingreso reg;
    Recuadro obj2;
    	FILE *p;
	p=fopen(A_INGRESO,"rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return ;
		}

    gotoxy(3,1);cout<<"ID ";
    gotoxy(15,1);cout<<"USUARIO ";
    gotoxy(30,1);cout<<"CONTRASE"<<(char)165<<"A ";

    int alto=3,alto2;
    while(fread(&reg,sizeof (ingreso),1,p)){
        if(reg.getEstado()!=0){

        int i;
        gotoxy(1,alto2=alto-1);for(i=0;i<43;i++){cout<<(char)196;}

        reg.mostrarIngreso(alto);
        alto=alto+2;
        }
    }
    fclose(p);
}

/// ********************************************************************************************************************************************************

///****************************************************          ELIMINAR INGRESO               ************************************************************

void eliminarIngreso(){
    system("cls");
    ingreso reg;
    int id;
    int pos,e=0;

    recuadro(0,0,44,12,cBLANCO,cROJO);

    gotoxy(4,3 );cout<<"INGRESE EL ID DE USUARIO A ELIMINAR: ";
    cin>>id;

    pos= buscarPosIngreso(id);
    if(pos==-1){
        gotoxy(10,5 );cout<<"NO SE ENCONTRO ID DE USUARIO"<<endl;
        return;
    }

    reg.Leer_en_disco(pos);
    reg.setEstado(e);
    reg.ModificarRegistroXpos(pos);


    system("cls");
    recuadro(0,0,44,12,cBLANCO,cROJO);
    gotoxy(14,5 );cout<<"USUARIO ELIMINADO"<<endl;
}

/// ********************************************************************************************************************************************************

///****************************************************          BUSCAR POS INGRESO               ************************************************************

int buscarPosIngreso(int d){
    FILE *p;
    ingreso reg;
    int pos=0;
    p=fopen(A_INGRESO,"rb");
    if(p==NULL){
        cout<<"No existe el archivo";
    system("pause>nul");
		return -1;
    }

    while(fread(&reg,sizeof (ingreso),1,p)){
        if(reg.getIdIngreso()==d && reg.getEstado()!=0){
            return pos;
            fclose(p);
        }
        pos++;
    }
    return pos=-1;
    fclose(p);
}

/// ********************************************************************************************************************************************************

/// *****************************************************  LEER EN DISCO  ********************************************************************

int ingreso::Leer_en_disco(int pos){
	int x;
	FILE *p;
	p=fopen(A_INGRESO,"rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fseek(p,pos*sizeof *this,0);

	fclose(p);
	return x;
}

/// ********************************************************************************************************************************************************

/// *********************************************************  MODIFICAR INGRESO  *********************************************************************


void modificarIngreso(){

    char d[9];
    int pos,id;
    ingreso reg;

    recuadro(0,0,44,12,cBLANCO,cROJO);

    gotoxy(3,3 );cout<<"INGRESE ID DE USUARIO A MODIFICAR: ";
    cin>>id;

    pos= buscarPosIngreso(id);
    if(pos==-1){
        gotoxy(14,5 );cout<<"NO SE ENCONTRO USUARIO";
        return;
    }
    FILE *p;
	p=fopen(A_INGRESO,"rb+");
	if(p==NULL){cout<<"Error de archivo"<<endl;return;}

    reg.Leer_en_disco(pos);

    char us[20],co[9];

    gotoxy(5,6 );cout<<"INGRESE NUEVO USUARIO:";
    cin>>us;
    gotoxy(5,8);cout<<"INGRESE NUEVA CONTRASE"<<(char)165<<"A:";
    cin>>co;

    reg.setUsuario(us);
    reg.setContrasenia(co);

    reg.ModificarRegistroXpos(pos);

    fclose(p);
    system("cls");
    recuadro(0,0,44,12,cBLANCO,cROJO);
    gotoxy(14,5 );cout<<"USUARIO MODIFICADO"<<endl;
}

/// ********************************************************************************************************************************************************

/// ***********************************************************  GRABAR EN DISCO  **********************************************************************

void ingreso::Grabar_en_Disco(){
	FILE *p;
	system("pause");

	p=fopen(A_INGRESO,"ab");
	if(p==NULL){
    cout<<"Error de archivo";
	system("pause");
	return;
	}
	fwrite(this,sizeof *this,1,p);
	cout<<"Guardado correctamente"<<endl;
	fclose(p);
	}

void ingreso::ModificarRegistroXpos(int pos){
    FILE *p;
    p=fopen(A_INGRESO,"rb+");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
    }
    fseek(p , pos* sizeof (ingreso) , 0);
    fwrite(this,sizeof (ingreso),1,p);
    fclose(p);
}



#endif // INGRESO_H_INCLUDED
