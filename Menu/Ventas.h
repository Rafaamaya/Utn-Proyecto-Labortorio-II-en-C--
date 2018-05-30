#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
const char F_VENTAS[]="datos/Ventas.dat";
const char F_ARTVENTAS[]="datos/artVentas.dat";
const char F_ARTPRESUPUESTOS[]="datos/artPresupuestos.dat";
///---------------------------------CLASE VENTA-------------------------------------------------------
class venta
{
    private:
		int IDCliente;
		int numeroDeVenta;
		float importeTotal;
		int dia,mes,anio;
	public:
		int getDNI(){return IDCliente;}
		int getDia(){return dia;}
		int getMes(){return mes;}
		int getAnio(){return anio;}
		int getNumeroDeVenta(){return numeroDeVenta;}
		void setDia(int n){dia=n;}
		void setMes(int n){mes=n;}
		float getImporte(){return importeTotal;}
		void setAnio(int n){anio=n;}
		void setIDcliente(int n){IDCliente=n;};
		void setNumeroDeVenta(int n){numeroDeVenta=n;}
		void setImporte(float n){importeTotal=n;}
		void guardarVenta(int);
};

void venta::guardarVenta(int linea)
{
    FILE *F;F=fopen(F_VENTAS,"ab");if(F==NULL){F=fopen(F_VENTAS,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    FILE *b;b=fopen("datos/artVenBACKUP.dat","ab");if(b==NULL){b=fopen(F_VENTAS,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    fwrite(this, sizeof (venta),1,F);
    fclose(F);
    gotoxy(50,linea+2);cout<<"VENTA CARGADA";
    gotoxy(40,linea+3);system("pause");
}

///---------------------------------CLASE ARTICULOS de VENTA-------------------------------------------------------
class articulosVenta
{
    private:
        int codigoArticulo;
        int cantidad;int numeroDeVenta;float precio;int linea;bool estado;
    public:
        int getLinea(){return linea;}
        bool getEstado(){return estado;}
        float getPrecio(){return precio;}
        int  getCodigoArticulo(){return codigoArticulo;}
        int getCantidad(){return cantidad;}
        int getNumeroDeVenta(){return numeroDeVenta;}
        void setEstado(bool dato){estado=dato;}
        void setLinea(int lin){linea=lin;}
        void setPrecio(float n){precio=n;}
        void setCodigoArticulo(int n){codigoArticulo=n;}
        void setCantidad(int n){cantidad=n;}
        void setNumeroDeVenta(int n){numeroDeVenta=n;}
        void guardarRegistro(int uso)
        {
            FILE *F;
            switch (uso)
            {
                case 1:
                    F=fopen(F_ARTVENTAS,"ab");
                    if(F==NULL){F=fopen(F_ARTVENTAS,"wb");
                    if(F==NULL){cout<<"No se ha abierto el archivo";}}
                    fwrite(this, sizeof (articulosVenta),1,F);
                    fclose(F);
                ;break;
                case 2:
                    F=fopen(F_ARTPRESUPUESTOS,"ab");
                    if(F==NULL){F=fopen(F_ARTPRESUPUESTOS,"wb");
                    if(F==NULL){cout<<"No se ha abierto el archivo";}}
                    fwrite(this, sizeof (articulosVenta),1,F);
                    fclose(F);
                ;break;
            }



        }
};

///-------------------------------------------------------------------------------------------------------------
articulosVenta objArtVent;
venta objVenta;

void chartVentas()
{
    int i,cv=5,j;
    gotoxy(3,1);
    for(i=0;i<100;i++){
        switch(i){
            case 0:cout<<(char)218;break;
            case 12:case 24:case 66:cout<<(char)194;break;
            case 99:cout<<(char)191;break;
            default:cout<<(char)196;break;
        }
    }
    gotoxy(3,2);
    for(i=0;i<45;i++){
        switch(i){
            case 0:case 23: cout<<(char)179;break;
            case 1:cout<<"Fecha      "<<(char)179;break;
            case 2:cout<<"Venta N    "<<(char)179;break;
            case 3:cout<<"Cliente                                  "<<(char)179;break;
            case 4:cout<<"Importe total ";break;
            default:cout<<" ";break;
        }
    }
    gotoxy(3,3);
    for(i=0;i<100;i++){
        switch(i){
            case 0:cout<<(char)192;break;
            case 12:case 24:case 66:cout<<(char)193;break;
            case 99:cout<<(char)217;break;
            default:cout<<(char)196;break;
        }
    }
    cout<<endl;
    for(j=0;j<16;j++){
        gotoxy(3,cv);cv=cv+2;
        for(i=0;i<99;i++){
                cout<<(char)196;
        }
    }

}

bool comprobarVenta(int N){
    FILE *F;F=fopen(F_VENTAS,"rb");if(F==NULL){cout<<"No se ha abierto el archivo";}
    venta reg;
    while(fread(&reg,sizeof(reg),1,F)){
        if(N==reg.getNumeroDeVenta()){return true;}
    }
    return false;
}


void cargarVenta();
void listarVentas();
void verVenta();
void verVenta(int);

///------------------------------------------MENU VENTAS---------------------------------------------------------------------
void MenuVentas()
{
    char opc;int i;

    while(true){
        system("cls");
        Apariencia();
        textcolor(15,1);
        gotoxy(48,36);
        cout<<"*********** MENU VENTAS ***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) NUEVA VENTA"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) LISTAR VENTAS"<<endl;
        textcolor(15,0);
        gotoxy(35,37);
        cout<<"3) VER VENTA"<<endl;
        textcolor(15,0);

        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opc;
        switch(opc){
            case '1':
                system("cls");
                cargarVenta();
            ;break;

            case '2':
                system("cls");
                listarVentas();
            ;break;
            case '3':
                gotoxy(25,12);cout<<(char)218;for(i=0;i<30;i++){cout<<(char)196;}cout<<char(191);
                gotoxy(25,13);cout<<(char)179<<" INGRESE NUMERO DE VENTA: ";gotoxy(56,13);cout<<(char)179;
                gotoxy(25,14);cout<<(char)192;for(i=0;i<30;i++){cout<<(char)196;}cout<<char(217);
                gotoxy(52,13);cin>>i;
                verVenta(i);gotoxy(77,37);system("pause");
                system("cls");
            break;

            case '0':
                return;
            break;

            default: cout<<"OPCION INCORRECTA"<<endl; system("pause");
            break;
        }
    }
}

int cuentaVentas()
{
    FILE *F;F=fopen(F_VENTAS,"rb");
    if(F==NULL){F=fopen(F_VENTAS,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    int cv=1;
    venta reg;
    while(fread(&reg,sizeof(venta),1,F)){cv++;}
    fclose(F);return cv;
}

void addCliente(const int x,const int y)
{
    bool flag=true;int INT;cliente objCliente;int i;
    while(flag==true)
    {
        gotoxy(x,y);
        cout<<"ID CLIENTE: ";cin>>INT;
        if(objCliente.buscarPosClienteXID(INT)!=-1){
            flag=false;objVenta.setIDcliente(INT);
            objCliente=obtenerCliente(INT);
            gotoxy(x+15,y);cout<<"NOMBRE: "<<objCliente.getNombre()<<" "<<objCliente.getApellido();gotoxy(x,y+1);
        }
        else{
            gotoxy(60,37);cout<<"CLIENTE INEXISTENTE.";system("pause");
            gotoxy(60,37);for(i=0;i<59;i++){cout<<" ";}
            gotoxy(x,y);cout<<"                                ";
        }
    }
}

int cuentaPresupuestos();
bool modificarEstado(int nVenta,int nLinea){
    FILE *f;f=fopen(F_ARTVENTAS,"rb");if(f==NULL){return false;}
    articulosVenta reg;
    while(fread(&reg,sizeof(articulosVenta),1,f)){
        if(reg.getLinea()==nLinea and reg.getNumeroDeVenta()==nVenta){
            cout<<"ESTAMOS EN VENTA "<<reg.getNumeroDeVenta()<<"LINEA "<<reg.getLinea();system("pause");
        }
    }
}

float addArticulo(int uso,int*linea,int *q)
{
    bool flag=true;int INT,pos;char CHAR[50];float importe=0;articulos reg;int i,nLinea=0;
    ///INGRESO DE LOS ARTICULOS
    gotoxy(77,37);
    cout<<"INGRESAR ARTICULO?  1)SI  2)NO   ";cin>>INT;
    if(INT==2){flag=false;}
    while(flag==true)
    {
        nLinea=nLinea+1;
        objArtVent.setEstado(true);
        objArtVent.setLinea(nLinea);
        gotoxy(3,*linea);cout<<objArtVent.getLinea();
        *q=*q+1;
        switch(uso)
        {
            case 1:objArtVent.setNumeroDeVenta(cuentaVentas());;break;
            case 2:objArtVent.setNumeroDeVenta(cuentaPresupuestos());;break;
        }

        while(flag==true)
        {
            gotoxy(77,37);cout<<"                                   ";
            gotoxy(77,37);cout<<"INGRESE CODIGO DE ARTICULO";
            gotoxy(6,*linea+1);for(i=0;i<106;i++){cout<<(char)196;}
            gotoxy(8,*linea);cin>>INT;
            pos=buscarArt(INT);
            if(pos==-1){
                    gotoxy(55,37);cout<<"ARTICULO INEXISTENTE ";system("pause");
                    gotoxy(55,37);cout<<"                                                            ";
                    gotoxy(8,*linea);cout<<"   ";
            }
            else{flag=false;objArtVent.setCodigoArticulo(INT);reg=obtenerArt(pos);}
        }
        gotoxy(23,*linea);cout<<reg.GetNombre();
        flag=true;objArtVent.setPrecio(reg.GetPrecioVenta());
        gotoxy(85,*linea);cout<<reg.GetPrecioVenta()<<endl;
        objArtVent.setPrecio(reg.GetPrecioVenta());
        while(flag==true)
        {
            if(reg.GetStock()!=0){
                gotoxy(77,37);cout<<"                                      ";
                gotoxy(77,37);cout<<"INGRESE CANTIDAD"<<"(HASTA "<<reg.GetStock()<<")";
                gotoxy(78,*linea);cin>>INT;
                if(INT>reg.GetStock() or INT<=0){
                        gotoxy(50,37);cout<<"STOCK NO DISPONIBLE ";system("pause");
                        gotoxy(50,37);cout<<"                                             ";
                        gotoxy(78,*linea);cout<<"   ";
                }

                else
                {
                    flag=false;
                    if(uso==1){
                        modificarStock(pos,reg.GetStock()-INT);objArtVent.setCantidad(INT);flag=false;
                    }
                    else{
                        objArtVent.setCantidad(INT);flag=false;
                    }
                }
            }
            else{
                gotoxy(60,37);cout<<"                                               ";
                gotoxy(60,37);cout<<"NO HAY STOCK ";system("pause");
                gotoxy(60,37);cout<<"                                               ";
                gotoxy(78,*linea);cout<<"S/T";
                objArtVent.setCantidad(0);flag=false;
            }

        }

        objArtVent.guardarRegistro(uso);flag=true;
        importe+=objArtVent.getPrecio()*objArtVent.getCantidad();
        gotoxy(100,*linea);cout<<importe;
        gotoxy(77,37);cout<<"                                      ";
        gotoxy(77,37);
        cout<<"INGRESAR ARTICULO?  1)SI  2)NO   ";cin>>INT;
        if(INT==2){flag=false;}
        *linea=(*linea)+2;
    }
    return importe;

}

float addPresupuesto(int,int*);
void coordenadas()
{
    int i;
    gotoxy(0,0);
    for (i=0;i<121;i++){cout<<i%10;}
    for (i=0;i<39;i++){cout<<i<<endl;}
}
void entornoGraficoVenta()
{
    time_t tiempo;struct tm *tmPtr; int dia,mes,anio;
    tiempo = time(NULL);tmPtr = localtime(&tiempo);
    dia=tmPtr->tm_mday;
    mes=tmPtr->tm_mon+1;
    anio=tmPtr->tm_year+1900;
    system("cls");int i,j;
    for(i=0;i<121;i++){
        switch(i){
            case 0:cout<<(char)218;break;
            case 120:cout<<(char)191;break;
            default:cout<<(char)196;break;
        }
    }
    gotoxy(0,1);cout<<(char)179;
    gotoxy(50,1);cout<<"NUEVA VENTA";
    gotoxy(120,1);cout<<(char)179;
    cout<<endl;
    for(i=0;i<121;i++){
        switch(i){
            case 0:cout<<(char)195;break;
            case 120:cout<<(char)180;break;
            default:cout<<(char)196;break;
        }
    }
    cout<<endl;
    for(i=3;i<38;i++){gotoxy(0,i);cout<<(char)179;}
    for(i=3;i<38;i++){gotoxy(120,i);cout<<(char)179;}
    gotoxy(0,38);
    for(i=0;i<121;i++){
        switch(i){
            case 0:cout<<(char)192;break;
            case 120:cout<<(char)217;break;
            default:cout<<(char)196;break;
        }
    }
    cout<<endl;
    gotoxy(8,4);cout<<"PHONESYSTEM";gotoxy(4,5);cout<<"Venta y reparacion de";gotoxy(5,6);cout<<"equipos moviles.";
    gotoxy(105,5);cout<<dia<<"/"<<mes<<"/"<<anio;
    //coordenadas();

}

void charAddArt(int*linea)
{
    int i;
    cout<<(char)218;
    for(i=0;i<105;i++){
        switch(i){
            case 10:case 70:case 75: case 90:cout<<(char)194;break;
            default:cout<<(char)196;break;
        }
    }
    cout<<(char)191<<endl;(*linea)=(*linea)+1;
    gotoxy(5,*linea);cout<<(char)179;
    for(i=0;i<105;i++){
        switch(i){
            case 10:case 70:case 75: case 90:cout<<(char)179;break;
            default: cout<<" ";break;
        }
    }cout<<(char)179<<endl;(*linea)=(*linea)+1;
    gotoxy(5,*linea);cout<<(char)192;
    for(i=0;i<105;i++){
        switch(i){
            case 10:case 70:case 75: case 90:cout<<(char)193;break;
            default:cout<<(char)196;break;
        }
    }
    cout<<(char)217;
    gotoxy(6,*linea-1);cout<<"N ARTICULO";
    gotoxy(22,*linea-1);cout<<"NOMBRE";
    gotoxy(78,*linea-1);cout<<"Q";
    gotoxy(83,*linea-1);cout<<"P/UNITARIO";
    gotoxy(98,*linea-1);cout<<"IMP. PARCIAL";

}

void recuperarArtVent()
{
    FILE *b;b=fopen("datos/artVenBACKUP.dat","rb");if(b==NULL){cout<<"Error de archivo";}
    articulosVenta backup;
    FILE *f;f=fopen(F_ARTVENTAS,"wb");if(f==NULL){cout<<"Error de archivo";}
    int cv=0;
    while(fread(&backup,sizeof(articulosVenta),1,b)){
        fwrite(&backup,sizeof(articulosVenta),1,f);
    }
    fclose(f);fclose(b);
}
void actualizarBackUp()
{
    FILE *b;b=fopen(F_ARTVENTAS,"rb");if(b==NULL){cout<<"Error de archivo";}
    articulosVenta backup;
    FILE *f;f=fopen("datos/artVenBACKUP.dat","wb");if(f==NULL){cout<<"Error de archivo";}
    int cv=0;
    while(fread(&backup,sizeof(articulosVenta),1,b)){
        fwrite(&backup,sizeof(articulosVenta),1,f);
    }
    fclose(f);fclose(b);

}



void cargarVenta()
{
    time_t tiempo;struct tm *tmPtr;int i;int q=0;
    tiempo = time(NULL);tmPtr = localtime(&tiempo);
    objVenta.setDia(tmPtr->tm_mday);
    objVenta.setMes(tmPtr->tm_mon+1);
    objVenta.setAnio(tmPtr->tm_year+1900);
    objVenta.setNumeroDeVenta(cuentaVentas());int INT;char CHAR[50];float importeTotal=0;

    entornoGraficoVenta();
    gotoxy(54,5);int linea=9;
    cout<<"N"<<(char)167<<" DE VENTA: "<<objVenta.getNumeroDeVenta()<<endl;
    gotoxy(3,7);for(i=0;i<115;i++){cout<<(char)196;}
    addCliente(5,8);///PARA AGREGAR UN CLIENTE SIEMPRE Y CUANDO SU ID EXISTA
    importeTotal+=addPresupuesto(objVenta.getNumeroDeVenta(),&linea);
    gotoxy(5,linea);charAddArt(&linea);linea++;
    importeTotal+=addArticulo(1,&linea,&q);///PARA AGREGAR ARTICULOS SIEMPRE Y CUANDO SU ID EXISTA, Y HALLA STOCK
    gotoxy(85,linea);cout<<"IMPORTE TOTAL: "<<importeTotal<<endl;
    objVenta.setImporte(importeTotal);
    linea=linea+5;
    gotoxy(43,linea);cout<<"REALIZAR VENTA?   1)SI  2)NO ";cin>>INT;
    if(INT==1){
        gotoxy(43,linea);gotoxy(50,linea+1);
        objVenta.guardarVenta(linea);actualizarBackUp();
    }
    else{
        gotoxy(43,linea+1);
        cout<<"VENTA CANCELADA";
        gotoxy(43,linea+2);system("pause");
        recuperarArtVent();
    }
}

void listarArticulosDeVenta(int nVenta, int *linea,int n)
{
    FILE *f;
    if(n==1){
        f=fopen(F_ARTVENTAS,"rb");if(f==NULL){cout<<"ERROR DE ARCHIVO";}
    }
    if(n==2){
        f=fopen(F_ARTPRESUPUESTOS,"rb");if(f==NULL){cout<<"ERROR DE ARCHIVO";}
    }

    articulos regArt;int i;
    while(fread(&objArtVent,sizeof (articulosVenta),1,f))
    {
        if(nVenta==objArtVent.getNumeroDeVenta())
        {
            regArt=obtenerArt(objArtVent.getCodigoArticulo());
            gotoxy(9,*linea);cout<<regArt.GetCodArticulo();
            gotoxy(20,*linea);cout<<regArt.GetNombre();
            gotoxy(78,*linea);cout<<objArtVent.getCantidad();
            gotoxy(88,*linea);cout<<(objArtVent.getPrecio());
            *linea=*linea+1;
            gotoxy(6,*linea);for(i=0;i<105;i++){cout<<(char)196;}
            *linea=*linea+1;
        }
    }
    fclose(f);
}


venta* vectorizarVentas()
{
    int cantVentas;venta *vec;int resultado;
    cantVentas=cuentaVentas()-1;resultado=cantVentas*sizeof(venta);
    vec=(class venta*)malloc(sizeof(venta)*cantVentas);
    FILE *F;F=fopen(F_VENTAS,"rb");if(F==NULL){cout<<"No se ha abierto el archivo";}
    //cout<<sizeof(venta)<<endl<<sizeof(vec)<<endl;
    fread(vec,sizeof(venta),cantVentas,F);
    fclose(F);
    return vec;
}

void borrarLineasVentas(){
    int i,linea=4;
    for (i=0;i<16;i++){

        gotoxy(3,linea);cout<<"                                                                                        ";
        linea=linea+2;
    }

}

void listarVentas()
{
    int cL=4,cuentaV,cPag=1,cvPag=0,nPag=0,nVenta=1,i,actual=4;
    cliente regCliente;char tecla;bool aux=true,flag=true;int desde, hasta;
    vectorizarVentas();venta *vec;
    vec=vectorizarVentas();
    cuentaV=cuentaVentas();
    cPag=1+(cuentaVentas()/15);
    cvPag=1+(cuentaVentas()/16);
    desde=nPag*16;
    hasta=(nPag*16)+16;
    gotoxy(1,4);cout<<">";
    while(aux==true)
    {
        gotoxy(45,0);cout<<"VENTAS";
        cL=4;chartVentas();
        gotoxy(57,37);{cout<<"< o > cambiar pagina   -    PAGINA: "<<nPag+1<<"/"<<cPag;}
        desde=(nPag*16)+1;
        hasta=(nPag*16)+16;
        for(i=desde;i<=hasta;i++)
        {
            if(vec[i-1].getAnio()>=2016 and  vec[i-1].getAnio()<=2020)
            {
                gotoxy(4,cL);cout<<vec[i-1].getDia()<<"/"<<vec[i-1].getMes()<<"/"<<vec[i-1].getAnio();
                gotoxy(19,cL);cout<<vec[i-1].getNumeroDeVenta();
                regCliente=obtenerCliente(vec[i-1].getDNI());
                gotoxy(30,cL);cout<<regCliente.getApellido()<<" "<<regCliente.getNombre();
                gotoxy(80,cL);cout<<vec[i-1].getImporte();
                cL=cL+2;
                cvPag++;
            }
        }
        flag=true;
        while(flag==true)
        {
            tecla = getch();
            switch(tecla){
                case TECLA_ARRIBA:
                    gotoxy(1,actual);cout<<"  ";
                    if(actual==4){
                        actual=34;
                        gotoxy(1,actual);cout<<">";
                    }
                    else{
                        actual=actual-2;
                        gotoxy(1,actual);cout<<">";
                    }

                ;break;

                case TECLA_ABAJO:
                    gotoxy(1,actual);cout<<"  ";
                    if(actual==34){
                        actual=4;
                        gotoxy(1,actual);cout<<">";
                    }
                    else{
                        actual=actual+2;
                        gotoxy(1,actual);cout<<">";
                    }
                ;break;

                case TECLA_IZQUIERDA:
                    if(nPag!=cPag){borrarLineasVentas();}
                    flag=false;
                    if(nPag==0)
                    {
                        nPag=cPag-1;
                    }
                    else
                    {
                        nPag=nPag-1;
                    }
                ;break;

                case TECLA_DERECHA:
                    if(nPag!=cPag){borrarLineasVentas();}
                    flag=false;
                    if(nPag==cPag-1){
                       nPag=0;
                    }
                    else{
                        nPag=nPag+1;
                    }
                ;break;

                case ENTER:
                    flag=false;nVenta=((actual-2)/2)+nPag*16;
                    system("cls");verVenta(nVenta);gotoxy(77,37);system("pause");system("cls");
                ;break;
                case BACK:
                    flag=false;aux=false;
                ;break;
            }
        }

    }

}

void verVenta(int INT){

    FILE *F;F=fopen(F_VENTAS,"rb");if(F==NULL){cout<<"No se ha abierto el archivo";}
    bool flag=false;int nLinea=9;
    entornoGraficoVenta();cliente regCliente;venta objVenta;
    while(fread(&objVenta,sizeof(venta),1,F)){
        if(objVenta.getNumeroDeVenta()==INT)
        {
            gotoxy(105,5);cout<<"           ";
            gotoxy(105,5);cout<<objVenta.getDia()<<"/"<<objVenta.getMes()<<"/"<<objVenta.getAnio();
            gotoxy(54,5);cout<<"N"<<(char)167<<" DE VENTA: "<<objVenta.getNumeroDeVenta()<<endl;
            regCliente=obtenerCliente(objVenta.getDNI());
            gotoxy(5,8);cout<<"CLIENTE: "<<regCliente.getApellido()<<" "<<regCliente.getNombre()<<endl;
            gotoxy(5,nLinea);charAddArt(&nLinea);nLinea++;
            listarArticulosDeVenta(objVenta.getNumeroDeVenta(),&nLinea,1);
            gotoxy(78,nLinea);cout<<"IMPORTE: "<<objVenta.getImporte();
            flag=false;
        }
    }
    fclose(F);
}

#endif // VENTAS_H_INCLUDED

