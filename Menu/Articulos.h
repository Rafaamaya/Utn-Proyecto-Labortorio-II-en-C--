#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED


class articulos{
    private:
        int codArticulo;
        int idproveedores;
        char tipo [4];
        char nombre[50];
        float precioCosto;
        float precioVenta;
        int stock;
        bool estado;
    public:
        void SetCodArticulo();
        void SetIdProveedores(int);
        void SetTipo(char *);
        void SetNombre(char *);
        void SetPrecioCosto(float);
        void SetPrecioVenta(float);
        void SetStock(float);
        void SetEstado(bool);
        int  GetCodArticulo ();
        int  GetIdProveedores ();
        char * GetTipo();
        char * GetNombre ();
        float GetPrecioCosto ();
        float GetPrecioVenta ();
        float GetStock ();
        bool  GetEstado ();
        bool Cargar ();
        void GrabarRegistro ();
        void ModificarRegistro(int);///dada una pos modifica un registro
        void MostrarRegistro ();
        void MostrarRegistro (int);
        int  Leer_de_disco(int);
};

const  char A_ARTICULOS[] = "datos/Articulos.dat";



///*******************************************************************************************************************
///                                             PROTOTIPOS
///*******************************************************************************************************************

int CantidadRegistros();
int buscarArt(int cod);///Dado un ID me Retorna Su Pos o -1 Si No Lo Encuentro



int buscarProv(int cod);
void Alta();
void Listar_Articulo();
void listarArticuloXID();
void modificarArticuloXID();
void Eliminar();
void gotoxy(int ,int) ;


void MenuArticulos(){

    char opc;
    while(true){
        system("cls");
        Apariencia();
        textcolor(15,1);
        gotoxy(48,36);
        cout<<"*********** MENU ARTICULOS ***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) ALTA"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) LISTAR ARTICULO"<<endl;
        textcolor(15,0);
        gotoxy(35,37);
        cout<<"3) LISTAR ARTICULOS POR ID"<<endl;
        textcolor(15,0);
        gotoxy(35,38);
        cout<<"4) MODIFICAR ARTICULO"<<endl;
        textcolor(15,0);
        gotoxy(70,37);
        cout<<"5) ELIMINAR"<<endl;

       textcolor(15,0);
        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opc;

        switch(opc){
            case '1':
                Alta();
            break;
            case '2':
                system("cls");
                Listar_Articulo();
                cout<<endl<<endl;
                system("pause");
            break;
            case '3':
                system("cls");
                listarArticuloXID();
            break;
            case '4':
                system("cls");
                modificarArticuloXID();
            break;
            case '5':
                system("cls");
                Eliminar();
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
///******************************************** ALTA ARTICULO ********************************************

void Alta(){
    system ("cls");
    Apariencia_Ariculo_Ingreso("INGRESO DE ARTICULOS - PANTALLA PRINCIPAL");
    bool carg;
    articulos Reg;
    carg=Reg.Cargar();
    if(carg==false){
        return;
    }
    Reg.GrabarRegistro();
}

///******************************************** LISTAR ARTICULO ********************************************

void Listar_Articulo (){
    articulos obj;
    Recuadro obj2;
    FILE *p;
	p = fopen(A_ARTICULOS,"rb");
	if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    int Can=CantidadRegistros();
    int largo=3;
    Apariencia_Ariculo_Listado();
	while(fread(&obj,sizeof(articulos),1,p)){
	    if ((Can%2)==0){
                obj2.Dibujar(1,largo,119,0,cBLANCO,cBLANCO);
                textcolor(cNEGRO,cBLANCO);
	    }
	    if (obj.GetEstado()== 1){
           obj.MostrarRegistro(largo);
           textcolor();
           largo=largo+1;
           Can--;
	    }

	}
	textcolor();
	fclose(p);
}

///******************************************** ALTA ARTICULO POR ID ********************************************

void listarArticuloXID(){
    int ID;
    int pos;
    proveedores reg2;

    Apariencia_Ariculo_Ingreso("BUSQUEDA ARTICULOS - PANTALLA PRINCIPAL");
    gotoxy(14,5);
    cin>>ID;
    pos = buscarArt(ID);
    if (pos != -1){
            articulos reg;
            reg.Leer_de_disco(pos);
            reg.MostrarRegistro();

            /// MUESTRA NOMBRE DE PROVEEDOR
            textcolor(cNEGRO,cCIAN_CLARO);
                reg2.Leer_de_disco(buscarProv(reg.GetIdProveedores()));
                gotoxy(45,5);cout<<reg2.GetRazonSocial();
                textcolor();

            gotoxy( 25,16);
            textcolor(cBLANCO,cAZUL);
            system("pause");
            textcolor();
    }
    else{
        Recuadro obj;
        obj.Ventana_Error("NO EXISTE ARTICULO CON ESE ID",16,6,56,4);
    }
    textcolor();
}

///******************************************** MODIFICAR ARTICULO POR ID ********************************************

void modificarArticuloXID(){
    int ID;
    int pos;
    cout<<"INGRESE EL ID DEL ARTICULO A MODIFICAR: ";
    cin>>ID;
    cout <<endl<<endl<<endl<<endl;
    pos = buscarArt(ID);
    if (pos != -1){
        articulos reg;
        reg.Leer_de_disco(pos);
        Apariencia_Ariculo_Listado();

        reg.MostrarRegistro(3);

        char Nombre[50];
        char tip[4];
        float PreCosto , PreVenta;
        int Stock ,CodProv;
        cout<<endl<<endl<<"INGRESE CODIGO DEL PROVEEDOR: ";
        cin>>CodProv;
        cout<<endl<<"INGRESE LA CATEGORIA A LA QUE PERTENECE ( ACS / CEL / MAN ): ";
        cin>>tip;
        cout<<endl<<"INGRESE NOMBRE: ";
        cin.ignore();
        gets(Nombre);
        cout<<endl<<"INGRESE PRECIO DE COSTO: ";
        cin>>PreCosto;
        cout<<endl<<"INGRESE PRECIO DE VENTA: ";
        cin>>PreVenta;
        cout<<endl<<"STOCK: ";
        cin>>Stock;
        reg.Leer_de_disco(pos);
        reg.SetIdProveedores(CodProv);
        reg.SetTipo(tip);
        reg.SetNombre(Nombre);
        reg.SetPrecioCosto(PreCosto);
        reg.SetPrecioVenta(PreVenta);
        reg.SetStock(Stock);
        reg.ModificarRegistro(pos);
    }
    else {
         cout << "NO EXISTE EL ARTICULO" << endl;
    }

}
///******************************************** ELIMINAR ARTICULO POR ID********************************************


void Eliminar(){
    int ID;
    int pos;
    Recuadro obj;
    Apariencia_Ariculo_Ingreso("ELIMINAR ARTICULO - PANTALLA PRINCIPAL");
    //cout<<"INGRESE EL ID DEL ARTICULO A MODIFICAR: ";
    gotoxy(14,5);
    cin>>ID;
    pos = buscarArt(ID);
    articulos reg;
    reg.Leer_de_disco(pos);
    if ((pos != -1)&& (reg.GetEstado()== 1)){
        //articulos reg;
        //reg.Leer_de_disco(pos);
        gotoxy(41,5);
        cout << reg.GetIdProveedores();
        gotoxy(81,5);
        cout << reg.GetTipo();
        gotoxy(28,7 );
        cout << reg.GetNombre();
        int Op;
        Op = obj.Ventana_Confirmacion("DESEA BORRAR EL REGISTRO? S/N ",24,9);
        if (Op==1){
                reg.SetEstado(0);
                reg.ModificarRegistro(pos);
        }
    }
    else {
         obj.Ventana_Error("NO EXISTE EL ARTICULO A ELIMINAR",16,6,56,4);
         //cout << "NO EXISTE EL ARTICULO" << endl;
    }
}
///******************************************** SET ARTICULO + GET ********************************************


void articulos::SetCodArticulo(){
    int CantRegistros;
    CantRegistros = CantidadRegistros();
    if (CantRegistros == 0 ){
        articulos::codArticulo = 1;
    }
    else{
//        articulos reg;
//        reg.Leer_de_disco(CantRegistros-1);
//        codArticulo = GetCodArticulo()+1;
        codArticulo = CantRegistros+1;
    }
}
int articulos::GetCodArticulo(){
    return codArticulo;
}
void articulos::SetIdProveedores(int aux){
    idproveedores= aux;
}
int articulos::GetIdProveedores(){
    return idproveedores;
}
void articulos::SetTipo(char *nom){
    strcpy(tipo,nom);
}
char * articulos::GetTipo(){
    return tipo;
}
void articulos::SetNombre(char *nom){
    strcpy(nombre,nom);
}
char * articulos::GetNombre(){
    return nombre;
}
void articulos::SetPrecioCosto(float aux){
    precioCosto = aux;
}
float articulos::GetPrecioCosto(){
    return precioCosto;
}
void articulos::SetPrecioVenta(float aux){
    precioVenta = aux;
}
float articulos::GetPrecioVenta(){
    return precioVenta;
}
void articulos::SetStock(float aux){
    stock = aux;
}
float articulos::GetStock(){

    return stock;
}
void articulos::SetEstado(bool aux=1){
    estado = aux;
}
bool articulos::GetEstado(){
    return estado;
}

/// ************************************************ CARGAR ARTICULO ************************************************

bool articulos::Cargar(){
    Recuadro obj;
    proveedores reg2;
    articulos::SetCodArticulo();
    gotoxy(14,5);
    textcolor(cNEGRO,cCIAN_CLARO);
    cout << articulos::GetCodArticulo();
    //cout<<endl<<"INGRESE CODIGO DEL PROVEEDOR: ";
    gotoxy(30,5);
    cin>>idproveedores;

    ///SE VALIDA QUE EXISTA EL PROVEEDOR
    if(buscarProv(idproveedores)==-1){

        obj.Ventana_Error("NO EXISTE PROVEEDOR",16,6,56,4);
        return false;
    }

    reg2.Leer_de_disco(buscarProv(idproveedores));
    gotoxy(45,5);cout<<reg2.GetRazonSocial();

    gotoxy( 10,14);
    cout<<"NOTA: INGRESAR EN TIPO: MAN (MANO DE OBRA), CEL (CELULAR), ACS (ACCESORIO).";

    gotoxy(81,5);
    cin.ignore();
    gets(tipo);

    gotoxy(28,7 );
    gets(nombre);

    gotoxy(24,9);
    cin>>precioVenta;

    gotoxy(58,9);
    cin>>precioCosto;

    gotoxy(80,9);
    cin>>stock;

    obj.Ventana_Error("GUARDADO CORRECTAMENTE",16,6,56,4);
    articulos::SetEstado();
    textcolor();
    return true;
}

/// ************************************************ GRABAR ARTICULO ************************************************

void articulos::GrabarRegistro(){/// Agrega un registro
  FILE *p;
    p=fopen(A_ARTICULOS,"ab");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
      }
  fwrite(this, sizeof (articulos), 1, p);
  fclose(p);
  //cout<<"ARCHIVO GUARDADO DE FORMA EXITOSA"<<endl;
  //system("pause");
}

/// ************************************************ MODIFICAR ARTICULO ************************************************

void articulos::ModificarRegistro(int pos){
    FILE *p;
    p=fopen(A_ARTICULOS,"rb+");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
    }
    fseek(p , pos* sizeof (articulos) , 0);
    fwrite(this,sizeof (articulos),1,p);
    fclose(p);
}

/// ************************************************ MOSTRAR REGISTRO ARTICULO ************************************************

void articulos::MostrarRegistro(int largo){
    gotoxy(1,largo);
    cout<</*endl<<"CODIGO DEL ARTICULO: " << */GetCodArticulo();
    gotoxy(11,largo);
    cout<</*endl<<"CODIGO DEL PROVEEDOR: " << */GetIdProveedores();



    gotoxy(22,largo);
    cout<</*endl<<"TIPO: " << */GetTipo();
    gotoxy(27,largo);
    cout<</*endl<<"NOMBRE: " << */GetNombre();
    gotoxy(65,largo);
    cout<</*endl<<"PRECIO DE COSTO: " << */GetPrecioCosto();
    gotoxy(90,largo);
    cout<</*endl<<"PRECIO DE VENTA: " << */GetPrecioVenta();
    gotoxy(112,largo);
    cout<</*endl<<"STOCK: " << */GetStock();
//    cout<</*endl<<"ESTADO: " << */GetEstado() << endl;

  }

  /// ************************************************ MOSTRAR  ARTICULO ************************************************

void articulos::MostrarRegistro(){
    textcolor(cNEGRO,cCIAN_CLARO);
    gotoxy(14,5);
    cout<< GetCodArticulo();
    gotoxy(30,5);
    cout<<GetIdProveedores();
    gotoxy(81,5);
    cout<<GetTipo();
    gotoxy(28,7 );
    cout<< GetNombre();
    gotoxy(58,9);
    cout<<GetPrecioCosto();
    gotoxy(24,9);
    cout<<GetPrecioVenta();
    gotoxy(80,9);
    cout<<GetStock();
    textcolor();

  }

  /// ************************************************ LEER ARTICULO ************************************************

int articulos::Leer_de_disco(int pos){
	int x;
	FILE *p;
	p=fopen(A_ARTICULOS,"rb");
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

int buscarArt(int cod){ ///Dado un ID me Retorna Su Pos o -1 Si No Lo Encuentro
	int pos=0;
	articulos reg;
	while(reg.Leer_de_disco(pos) == 1) {
		if(cod == reg.GetCodArticulo())
        return pos;
		pos++;
    }
	return -1;
}

articulos obtenerArt(int cod){  ///Dado un ID me Retorna Su Regestro
	articulos reg;
	reg.Leer_de_disco(cod);
	return reg;
}
int CantidadRegistros(){///Me Retorna la cantidad de registro que tiene el archivo
    FILE *p;
    p = fopen(A_ARTICULOS,"rb");
    if (p == NULL){///"NO EXISTE ARCHIVO A LISTAR"
        return 0;
    }
    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(articulos);
}

void modificarStock(int pos,int stock){
    int x;
	FILE *p;
	articulos articulo;
	p=fopen(A_ARTICULOS,"rb+");
	if(p==NULL){
            cout<<"No existe el archivo";
            cout<<"Presione una tecla para continuar";
            system("pause<null");
    }
	fseek(p,sizeof(articulos)*pos,0);
	fread(&articulo,sizeof (articulos),1,p);
	fseek(p,sizeof(articulos)*pos,0);
	articulo.SetStock(stock);
	fwrite(&articulo,sizeof (articulos),1,p);
	fclose(p);
}


/// *********************************************** VALIDAR PROVEEDOR *********************************************************************


#endif // ARTICULOS_H_INCLUDED
