#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class cliente{
    private:
        int IdCliente;
        char dni[9];
        char nombre[50];
        char apellido[50];
        char email[60];
        char telefono[20];
        float estadoDeCuenta;
        int estado;
    public:
        void GrabarClienteEnDisco();
        void modificarCliente();
        void eliminarCliente();
        int buscarPosClienteXID(int );
        void mostrarCliente();
        void MostrarRegistro(int);

        int getIdcliente(){return IdCliente;}
        char *getDni(){return dni;}
        char *getNombre(){return nombre;}
        char *getApellido(){return apellido;}
        char *getEmail(){return email;}
        char *getTelefono(){return telefono;}
        float getEstadoDeCuenta(){return estadoDeCuenta;}
        int getEstado(){return estado;}

        int setIdCliente(int id){IdCliente=id;}
        void setDni(char*);
        void setNombre(char*);
        void setApellido(char *);
        void setEmail(char *);
        void setTelefono(char *);
        void setEstadoDeCuenta(float);
        void setEstado(int );


};

/// *********************************************** PROTOTIPOS ********************************************************************************************************
    void cargarCliente();
    int cantidadRegistrosClientes();
    void listarClientes();
    void listarClientesXDNI();
    int buscarPosClienteXDNI(char*);
    bool ValidarDni(char*);

/// ********************************************************************************************************************************************************************

const  char A_CLIENTES[] = "datos/clientes.dat";


///***************************************MENU CLIENTES**************************************************************

void MenuClientes(){
    cliente reg;
    char opc;

    while(true){
        system("cls");
        Apariencia();
        textcolor(15,1);
        gotoxy(48,36);
        cout<<"*********** MENU CLIENTES ***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) ALTA"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) LISTAR CLIENTES"<<endl;
        textcolor(15,0);
        gotoxy(35,37);
        cout<<"3) LISTAR CLIENTES POR DNI"<<endl;
        textcolor(15,0);
        gotoxy(35,38);
        cout<<"4) MODIFICAR CLIENTE"<<endl;
        textcolor(15,0);
        gotoxy(70,37);
        cout<<"5) BAJA"<<endl;

       textcolor(15,0);
        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opc;

        switch(opc){
            case '1':
            system("cls");
            cargarCliente();
            break;

            case '2':
            system("cls");
            listarClientes();
            cout<<endl<<endl;
            system("pause");
            break;

            case '3':
            system("cls");
            listarClientesXDNI();

            break;

            case '4':
            system("cls");
            reg.modificarCliente();
            break;

            case '5':
            system("cls");
            reg.eliminarCliente();
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

/// ************************************ CARGAR CLIENTE ********************************************************************

int cantidadRegistrosClientes(){///Me Retorna la cantidad de registro que tiene el archivo

    FILE *p;
    p = fopen("datos/clientes.dat","rb");
    if (p == NULL){
        return 1;

    }

    int cv=1;
    cliente reg;

    while(fread(&reg, sizeof (cliente), 1, p)){
        cv++;

    }
    fclose(p);
    return cv;

}

void cargarCliente(){
    Recuadro obj2;
    cliente reg;
    int cant;
    char dni[9],nombre[50],apellido[50],email[60],telefono[20];

    cant=cantidadRegistrosClientes();
    reg.setIdCliente(cant);

    textcolor(cNEGRO,cCIAN_CLARO);
    Apariencia_Cliente_Ingreso("INGRESO DE CLIENTES - PANTALLA PRINCIPAL");

    gotoxy(15,5);cout<<reg.getIdcliente()<<endl;

    gotoxy(39,5 );
    cin>>nombre;

    gotoxy(17,7);
    cin>>telefono;
    gotoxy(41,7);
    cin>>apellido;
    gotoxy(14,9);
    cin>>email;
    gotoxy(51,9);
    cin>>dni;
    if(ValidarDni(&dni[0]) == false){
        obj2.Ventana_Error("DNI INGRESADO YA EXISTENTE",16,6,56,4);
        return;
    }

    reg.setDni(dni);
    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setEmail(email);
    reg.setTelefono(telefono);
    reg.setEstado(1);

    reg.GrabarClienteEnDisco();
    textcolor();
}

/// ************************************GRABAR EN DISCO***********************************

void cliente::GrabarClienteEnDisco(){
    Recuadro obj2;
	FILE *p;

	p=fopen("datos/clientes.dat","ab");
	if(p==NULL){cout<<"Error de archivo";return;}
	fwrite(this,sizeof *this,1,p);
	obj2.Ventana_Error("GUARDADO CORRECTAMENTE",16,6,56,4);
	fclose(p);
	}

/// ******************************************** LISTAR CLIENTE *************************************

void listarClientes(){
cliente obj;
    FILE *p;
	p = fopen(A_CLIENTES,"rb");
	if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    int Can=cantidadRegistrosClientes();
    Recuadro obj2;
    obj2.Dibujar(0,0,121,2);
    gotoxy(1,1);
    cout<<"ID";
    gotoxy(11,1);
    cout<<"ID DNI";
    gotoxy(27,1);
    cout<<"NOMBRE";
    gotoxy(48,1);
    cout<<"APELLIDO";
    gotoxy(70,1);
    cout<<"EMAIL";
    gotoxy(105,1);
    cout<<"TELEFONO";

    int largo=3;
	while(fread(&obj,sizeof(cliente),1,p)){
        if(obj.getEstado()!=0){
	    if ((Can%2)==0){
                obj2.Dibujar(1,largo,119,0,cBLANCO,cBLANCO);
                textcolor(cNEGRO,cBLANCO);
	    }
           obj.MostrarRegistro(largo);
           textcolor();

            largo=largo+1;
           Can--;
        }
	}
	fclose(p);
}

/// ******************************* BUSCAR POSICION CLIENTE POR DNI **************************************************

int buscarPosClienteXDNI(char *d){
    int pos=0;
    FILE *p;
    cliente reg;
	p=fopen("datos/clientes.dat","rb");
	if(p==NULL){cout<<"Error de archivo"<<endl;return -2;}

    while(fread(&reg,sizeof (cliente),1,p)){
        if(strcmp(reg.getDni(),d)==0 && reg.getEstado()!=0){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return pos=-1;
}


///******************************************** LISTAR CLIENTES POR DNI***********************************************************************

void listarClientesXDNI(){
    char d[9];
    int pos;
    cliente reg;
    Recuadro obj;
    recuadro(2,2,43,2,cBLANCO,cNEGRO);
    gotoxy(3,3);cout<<"INGRESE DNI DE CLIENTE A BUSCAR: ";
    cin>>d;

    pos= buscarPosClienteXDNI(&d[0]);
    if(pos==-1){
        obj.Ventana_Error("NO SE ENCONTRO CLIENTE",16,6,56,4);
        return;
    }
    FILE *p;
	p=fopen("datos/clientes.dat","rb");
	if(p==NULL){cout<<"Error de archivo"<<endl;return;}

    fseek(p,pos*sizeof (cliente),0);
    fread(&reg,sizeof (cliente),1,p);
    if(reg.getEstado()==0){
        obj.Ventana_Error("NO SE ENCONTRO CLIENTE (ELIMINADO)",16,6,56,4);
        fclose(p);
        return;
    }
    recuadro(2,6,43,11,cBLANCO,cNEGRO);
    reg.mostrarCliente();
    fclose(p);

    gotoxy(3,15);system("pause");
}

/// ********************************************MODIFICAR CLIENTE ***************************************************
void cliente::modificarCliente(){
    Recuadro obj;
    char d[9];
    int pos;
    recuadro(2,2,47,2,cBLANCO,cNEGRO);
    gotoxy(3,3);cout<<"INGRESE DNI DE CLIENTE A MODIFICAR: ";
    cin>>d;

    pos= buscarPosClienteXDNI(&d[0]);
    if(pos==-1){
        obj.Ventana_Error("NO SE ENCONTRO CLIENTE",16,6,56,4);
        return;
    }
    FILE *p;
	p=fopen("datos/clientes.dat","rb+");
	if(p==NULL){cout<<"Error de archivo"<<endl;return;}

    fseek(p,pos*sizeof *this,0);
    fread(this,sizeof *this,1,p);
    fseek(p,pos*sizeof *this,0);

    char n[50],a[50],e[60],t[20];
    float est;


    recuadro(2,6,43,9,cBLANCO,cNEGRO);

    cliente::mostrarCliente();

    recuadro(2,17,43,7,cBLANCO,cNEGRO);
    gotoxy(3,19);cout<<"INGRESE NOMBRE:";
    cin>>n;
    gotoxy(3,20);cout<<"INGRESE APELLIDO:";
    cin>>a;
    gotoxy(3,21);cout<<"INGRESE EMAIL:";
    cin>>e;
    gotoxy(3,22);cout<<"INGRESE TELEFONO:";
    cin>>t;

    cliente::setNombre(&n[0]);
    cliente::setApellido(&a[0]);
    cliente::setEmail(&e[0]);
    cliente::setTelefono(&t[0]);
    cliente::setEstadoDeCuenta(est);

    fwrite(this,sizeof *this,1,p);

    fclose(p);
    gotoxy(3,26);system("pause");

}
/// *********************************************** ELIMINAR CLIENTE ************************************************
void cliente::eliminarCliente(){
    Recuadro obj;
    char ID[9];
    int pos;

    AjustarVentana(89,16);

        obj.Dibujar(16, 6, 56, 4, cNEGRO, cNEGRO);///Sombra
        obj.Dibujar(16-1,6-1,56,4,cBLANCO,cROJO);///Recuadro de texto
        textcolor(cBLANCO,cROJO);
        int Tam = strlen("INGRESE DNI DEL CLIENTE: ");
        Tam= ((56-Tam)/2)+16;
        gotoxy(Tam,6);
        cout << "INGRESE DNI DEL CLIENTE: ";
        cin>>ID;

    pos= buscarPosClienteXDNI(&ID[0]);
    if(pos==-1){
        obj.Ventana_Error("NO SE ENCONTRO CLIENTE",16,6,56,4);
        return;
    }
    FILE *p;
	p=fopen("datos/clientes.dat","rb+");
	if(p==NULL){
        obj.Ventana_Error("ERROR DE ARCHIVO",16,6,56,4);
        return;
    }

    fseek(p,pos*sizeof *this,0);
    fread(this,sizeof *this,1,p);
    fseek(p,pos*sizeof *this,0);

    cliente::setEstado(0);

    fwrite(this,sizeof *this,1,p);
    fclose(p);

 obj.Ventana_Error("CLIENTE ELIMINADO",16,6,56,4);
}

///***********************************************************************************************************************************

int cliente::buscarPosClienteXID(int id){
            int pos=0;
            FILE *p;
            cliente reg;
            p=fopen("datos/clientes.dat","rb");
            if(p==NULL){cout<<"Error de archivo"<<endl;return -2;}
            while(fread(&reg,sizeof (cliente),1,p)){
                if(reg.getIdcliente()==id){
                    fclose(p);
                    return pos;
                }
                pos++;
            }
            fclose(p);
            return pos=-1;
}

cliente obtenerCliente(int cod)
{
    FILE *p; p=fopen("datos/clientes.dat","rb");
     if(p==NULL){cout<<"Error de archivo"<<endl;
     }
     cliente reg;
	while(fread(&reg,sizeof (cliente),1,p)){
            if(cod==reg.getIdcliente()){return reg;}
	}

}

void cliente::setDni(char *d){
    strcpy(dni,d);
}

void cliente::setNombre(char *n){
    strcpy(nombre,n);
}

void cliente::setApellido(char *a){
    strcpy(apellido,a);
}

void cliente::setEmail(char *em){
    strcpy(email,em);
}

void cliente::setTelefono(char *t){
     strcpy(telefono,t);
}

void cliente::setEstadoDeCuenta(float est){
    estadoDeCuenta=est;
}

void cliente::setEstado(int e){
    estado=e;
}

///************************************** mostra cliente ****************************************************
void cliente::mostrarCliente(){
    if(estado==0){
    return;
    }
    gotoxy(3,8);cout<<"IDcliente: "<<IdCliente;
    gotoxy(3,9);cout<<"DNI: "<<dni;
    gotoxy(3,10);cout<<"NOMBRE: "<<nombre;
    gotoxy(3,11);cout<<"APELLIDO: "<<apellido;
    gotoxy(3,12);cout<<"EMAIL: "<<email;
    gotoxy(3,13);cout<<"TELEFONO: "<<telefono;

}

///******************************* mostrar cliente cuadro ***************************************

void cliente::MostrarRegistro(int largo){

    gotoxy(1,largo);
    cout<</*endl<<"CODIGO DEL ARTICULO: " << */getIdcliente();
    gotoxy(11,largo);
    cout<</*endl<<"CODIGO DEL PROVEEDOR: " << */getDni();
    gotoxy(27,largo);
    cout<</*endl<<"TIPO: " << */getNombre();
    gotoxy(48,largo);
    cout<</*endl<<"NOMBRE: " << */getApellido();
    gotoxy(70,largo);
    cout<</*endl<<"PRECIO DE COSTO: " << */getEmail();
    gotoxy(105,largo);
    cout<</*endl<<"PRECIO DE VENTA: " << */getTelefono();

  }

bool ValidarDni(char *d){
    cliente reg;
    FILE *p;
    p=fopen(A_CLIENTES, "rb");
    if(p==NULL){
        return false;
    }

    while(fread(&reg, sizeof (cliente), 1 , p)){
        if(strcmp(reg.getDni(), d)==0 && reg.getEstado()==1){
            fclose(p);
            return false;
        }
    }
    fclose(p);
    return true;
}

#endif // CLIENTES_H_INCLUDED
