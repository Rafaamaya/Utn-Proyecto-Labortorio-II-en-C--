#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

class proveedores{
private:
    int IdProveedor;
    char razonSocial[30];
    char telefono[11];
    char direccion[30];
    char email[30];
    int estado;
public:
    void SetIdProveedor();
    void SetRazonSocial(char *);
    void SetTelefono(char *);
    void SetDireccion(char *);
    void SetEmail(char *);
    void SetEstado(int);
    int  GetIdProveedor();
    char * GetRazonSocial();
    char * GetTelefono ();
    char * GetDireccion ();
    char * GetEmail ();
    bool  GetEstado ();
    void Cargar ();
    void GrabarRegistro ();
    void ModificarRegistro(int);///dada una pos modifica un registro
    void MostrarRegistro ();
    void MostrarRegistro(int);
    int  Leer_de_disco(int);
};

/// *************************************************************** PROTOTIPOS *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

int CantidadRegistrosProv();
int buscarProv(int cod);///Dado un ID me Retorna Su Pos o -1 Si No Lo Encuentro
void AltaProv();
void Listar_Proveedores();
void listarProveedorXID();
void modificarProveedorXID();
void EliminarProveedor();

const  char A_PROVEEDORES[] = "datos/proveedores.dat";

/// *************************************************************** MENUUUUUUUUUU *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************


void MenuProveedores(){
    system("cls");
    char opc;
    while(true){

        system("cls");
        Apariencia();
        textcolor(15,1);
        gotoxy(48,36);
        cout<<"*********** MENU PROVEEDORES ***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) NUEVO PROVEEDOR"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) LISTAR PROVEEDOR"<<endl;
        textcolor(15,0);
        gotoxy(35,37);
        cout<<"3) BUSCAR PROVEEDOR"<<endl;
        textcolor(15,0);
        gotoxy(35,38);
        cout<<"4) MODIFICAR PROVEEDOR"<<endl;
        textcolor(15,0);
        gotoxy(70,37);
        cout<<"5) BORRAR PROVEEDOR"<<endl;

       textcolor(15,0);
        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opc;

        switch(opc){
            case '1':
                system("cls");
                AltaProv();
            break;
            case '2':
                system("cls");
                Listar_Proveedores();
                cout<<endl<<endl;
                system("pause");
            break;
            case '3':
                system("cls");
                listarProveedorXID();
            break;
            case '4':
                system("cls");
                modificarProveedorXID();
            break;
            case '5':
                system("cls");
                EliminarProveedor();
            break;
            case '0':
                return;
            break;
            default:
                cout<<"OPCION INGRESADA INCORRECTA"<<endl; system("pause");
            break;
        }
    }
    return;
}
/// *************************************************************** FUNCIONES *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************



void AltaProv(){
    proveedores Reg;
    Apariencia_Proveedor_Ingreso("INGRESO DE PROVEEDORES - PANTALLA PRINCIPAL");
    Reg.Cargar();
    Reg.GrabarRegistro();
}


/// *******************************************************************************************************************************************************************************
void Listar_Proveedores(){
    Recuadro obj2;
    proveedores obj;
    FILE *p;
    int id;
	p = fopen(A_PROVEEDORES,"rb");
	if(p==NULL){
        obj2.Ventana_Error("ERROR DE ARCHIVO",16,6,56,4);
        return;
    }

    int Can=CantidadRegistrosProv();
    Recuadro obj3;
    obj3.Dibujar(0,0,121,2);
    gotoxy(1,1);
    cout<<"ID";
    gotoxy(11,1);
    cout<<"RAZON SOCIAL";
    gotoxy(27,1);
    cout<<"TELEFONO";
    gotoxy(48,1);
    cout<<"DIRECCION";
    gotoxy(70,1);
    cout<<"EMAIL";

    int largo=3;
	while(fread(&obj,sizeof(proveedores),1,p)){
            if(obj.GetEstado()!=0){
	    if ((Can%2)==0){
                obj3.Dibujar(1,largo,119,0,cBLANCO,cBLANCO);
                textcolor(cNEGRO,cBLANCO);
	    }
           obj.MostrarRegistro(largo);
           textcolor();

            largo=largo+1;
           Can--;
	}
	}
}

///********************************************************************************************************************************************************
///                                        LISTAR PROVEEDOR POR ID

void listarProveedorXID(){
    int ID;
    int pos;
    Recuadro obj;
    Apariencia_Proveedor_Ingreso("BUSQUEDA PROVEEDORES - PANTALLA PRINCIPAL");
    gotoxy(15,5);
    cin>>ID;
    pos = buscarArt(ID);
    if (pos != -1){
            proveedores reg;
            reg.Leer_de_disco(pos);

            if(reg.GetEstado()==0){
                obj.Ventana_Error("EL PROVEEDOR NO EXISTE (ELIMINADO)",16,6,56,4);
                return;
            }

            textcolor(cNEGRO,cCIAN_CLARO);

            gotoxy(45,5);cout<< reg.GetRazonSocial();
            gotoxy(18,7);cout<< reg.GetTelefono();
            gotoxy(42,7);cout<< reg.GetDireccion();
            gotoxy(14,9);cout<< reg.GetEmail();

            gotoxy( 25,16);
            textcolor(cBLANCO,cAZUL);
            system("pause");
            textcolor();
    }
    else{

        obj.Ventana_Error("NO EXISTE PROVEEDOR CON ESE ID",16,6,56,4);
    }


}

///********************************************************************************************************************************************************

///********************************************************************************************************************************************************

void modificarProveedorXID(){

    Recuadro obj;
    int ID;
    int pos;
    recuadro(2,2,47,2,cBLANCO,cNEGRO);
    gotoxy(3,3);cout<<"INGRESE ID DE PROVEEDOR A BUSCAR: ";
    cin>>ID;

    pos= buscarProv(ID);
    if(pos==-1){
        obj.Ventana_Error("NO SE ENCONTRO PROVEEDOR",16,6,56,4);
        return;
    }
        proveedores reg;
        char raz[30];
        char tel[11];
        char dir[30];
        char em[30];
        int CodProv;

        reg.Leer_de_disco(pos);
        if(reg.GetEstado()==0){
            obj.Ventana_Error("NO SE ENCONTRO PROVEEDOR",16,6,56,4);
            return;
        }

        recuadro(2,6,43,7,cBLANCO,cNEGRO);
        gotoxy(3,8);cout<<"RAZON SOCIAL: "<<reg.GetRazonSocial();
        gotoxy(3,9);cout<<"TELEFONO: "<<reg.GetTelefono();
        gotoxy(3,10);cout<<"DIRECCION: "<<reg.GetDireccion();
        gotoxy(3,11);cout<<"EMAIL: "<<reg.GetEmail();

        recuadro(2,14,43,7,cBLANCO,cNEGRO);

        gotoxy(3,16);cout<<"INGRESE RAZON SOCIAL: ";
        cin>>raz;
        gotoxy(3,17);cout<<"INGRESE TELEFONO: ";
        cin>>tel;
        gotoxy(3,18);cout<<"INGRESE DIRECCION: ";
        cin>>dir;
        gotoxy(3,19);cout<<"INGRESE EMAIL: ";
        cin>>em;

        reg.SetRazonSocial(raz);
        reg.SetTelefono(tel);
        reg.SetDireccion(dir);
        reg.SetEmail(em);
        reg.ModificarRegistro(pos);

    gotoxy(3,14);system("pause");

}

///**********************************************************************************************************************************************************

///**********************************************************************************************************************************************************

void EliminarProveedor(){
    int ID;
    int pos;
    Recuadro obj;

    AjustarVentana(89,16);

        obj.Dibujar(16, 6, 56, 4, cNEGRO, cNEGRO);///Sombra
        obj.Dibujar(16-1,6-1,56,4,cBLANCO,cROJO);///Recuadro de texto
        textcolor(cBLANCO,cROJO);
        int Tam = strlen("INGRESE EL ID DEL PROVEEDOR A ELIMINAR: ");
        Tam= ((56-Tam)/2)+16;
        gotoxy(Tam,6);
        cout << "INGRESE EL ID DEL PROVEEDOR A ELIMINAR: ";
        cin>>ID;

    pos = buscarProv(ID);
    if (pos != -1){
        proveedores reg;
        reg.Leer_de_disco(pos);
        if(reg.GetEstado()==0){
            obj.Ventana_Error("PROVEEDOR PREVIAMENTE ELIMINADO",16,6,56,4);
            return;
        }
        reg.SetEstado(0);
        reg.ModificarRegistro(pos);
    }
    else {
         obj.Ventana_Error("NO EXISTE PROVEEDOR",16,6,56,4);
         return;
    }

    obj.Ventana_Error("PROVEEDOR ELIMINADO",16,6,56,4);
}

/// *************************************************************** SET Y GET *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

/// ******************* ID PROVEEDOR
void proveedores::SetIdProveedor(){
    int CantRegistros;
    CantRegistros = CantidadRegistrosProv();
    if (CantRegistros == 0 ){
        proveedores::IdProveedor = 1;
    }
    else{
        IdProveedor = CantRegistros+1;
    }
}

int proveedores::GetIdProveedor(){
    return IdProveedor;
}

/// ******************* RAZON SOCIAL

void proveedores::SetRazonSocial(char *raz){
    strcpy(razonSocial,raz);
}

char * proveedores::GetRazonSocial(){
    return razonSocial;
}

/// ******************* TELEFONO

void proveedores::SetTelefono(char *tel){
    strcpy(telefono,tel);
}
char * proveedores::GetTelefono(){
    return telefono;
}

/// ******************* DIRECCION

void proveedores::SetDireccion(char *dir){
    strcpy(direccion,dir);
}
char * proveedores::GetDireccion(){
    return direccion;
}

/// ******************* EMAIL

void proveedores::SetEmail(char *em){
    strcpy(email,em);
}
char * proveedores::GetEmail(){
    return email;
}

/// ******************* ESTADO

void proveedores::SetEstado(int aux){
    estado = aux;
}
bool proveedores::GetEstado(){
    return estado;
}

/// *************************************************************** CARGAR CARGAR *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

void proveedores::Cargar(){

    textcolor(cNEGRO,cCIAN_CLARO);

    proveedores::SetIdProveedor();

    gotoxy(15,5);cout<<proveedores::GetIdProveedor();

    gotoxy(45,5);
    cin.ignore();
    gets(razonSocial);

    gotoxy(18,7 );
    cin>>telefono;

    gotoxy(42,7);
    cin.ignore();
    gets(direccion);

    gotoxy(14,9);
    cin>>email;

    proveedores::SetEstado(1);

    textcolor();

}

/// *************************************************************** CARGAR GRABAR  *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

void proveedores::GrabarRegistro(){/// Agrega un registro
  FILE *p;
  Recuadro obj;
    p=fopen(A_PROVEEDORES,"ab");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
      }
  fwrite(this, sizeof (proveedores), 1, p);
  fclose(p);
  obj.Ventana_Error("PROVEEDOR GUARDADO EXITOSAMENTE",16,6,56,4);
}

/// *************************************************************** MODIFICAR *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

void proveedores::ModificarRegistro(int pos){
    FILE *p;
    p=fopen(A_PROVEEDORES,"rb+");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
    }
    fseek(p , pos* sizeof (proveedores) , 0);
    fwrite(this,sizeof (proveedores),1,p);
    fclose(p);
}

/// *************************************************************** MODIFICAR  *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

void proveedores::MostrarRegistro(){

    textcolor(cNEGRO,cCIAN_CLARO);

    gotoxy(15,5);cout<< GetIdProveedor();
    gotoxy(45,5);cout<< GetRazonSocial();
    gotoxy(18,7 );cout<< GetTelefono();
    gotoxy(42,7);cout<< GetDireccion();
    gotoxy(14,9);cout<< GetEmail();

    textcolor();
  }

  /// *************************************************************** LEER EN DISCO  *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

int proveedores::Leer_de_disco(int pos){
	int x;
	FILE *p;
	p=fopen(A_PROVEEDORES,"rb");
	if(p==NULL)
		{
		cout<<"No existe el archivo";
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}

/// *************************************************************** BUSCAR *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

int buscarProv(int cod){ ///Dado un ID me Retorna Su Pos o -1 Si No Lo Encuentro
	int pos=0;
	proveedores reg;
	while(reg.Leer_de_disco(pos) == 1) {
		if(cod == reg.GetIdProveedor())
			return pos;
		pos++;
    }
	return -1;
}

/// *************************************************************** CANTIDAD  *********************************************************************************************************

/// ***********************************************************************************************************************************************************************************

int CantidadRegistrosProv(){///Me Retorna la cantidad de registro que tiene el archivo
FILE *p;
    p = fopen(A_PROVEEDORES,"rb");
    if (p == NULL){///"NO EXISTE ARCHIVO A LISTAR"
        return 0;
    }
    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(proveedores);
}

void proveedores::MostrarRegistro(int largo){
    gotoxy(1,largo);
    cout<</*endl<<"CODIGO DEL ARTICULO: " << */GetIdProveedor();
    gotoxy(11,largo);
    cout<</*endl<<"CODIGO DEL PROVEEDOR: " << */GetRazonSocial();
    gotoxy(27,largo);
    cout<</*endl<<"TIPO: " << */GetTelefono();
    gotoxy(48,largo);
    cout<</*endl<<"NOMBRE: " << */GetDireccion();
    gotoxy(70,largo);
    cout<</*endl<<"PRECIO DE COSTO: " << */GetEmail();

  }

#endif // PROVEEDORES_H_INCLUDED
