#ifndef PRESUPUESTO_H_INCLUDED
#define PRESUPUESTO_H_INCLUDED

const  char F_PRESUPUESTO[] = "datos/presupuesto.dat";
///---------------------------------CLASE VENTA-------------------------------------------------------
class presupuesto
{
    private:
		int IDCliente;
		int numeroDePresupuesto;
		float importeTotal;
		int dia,mes,anio;
	public:
		int getDNI(){return IDCliente;}
		int getDia(){return dia;}
		int getMes(){return mes;}
		int getAnio(){return anio;}
		int getNumeroDeVenta(){return numeroDePresupuesto;}
		void setDia(int n){dia=n;}
		void setMes(int n){mes=n;}
		float getImporte(){return importeTotal;}
		void setAnio(int n){anio=n;}
		void setIDcliente(int n){IDCliente=n;};
		void setNumeroDeVenta(int n){numeroDePresupuesto=n;}
		void setImporte(float n){importeTotal=n;}
		void guardarPresupuesto();
};

void presupuesto::guardarPresupuesto()
{
    FILE *F;F=fopen(F_PRESUPUESTO,"ab");if(F==NULL){F=fopen(F_PRESUPUESTO,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    fwrite(this, sizeof (venta),1,F);
    fclose(F);
}
presupuesto objPres;
void cargarPresupuesto();
void listarPresupuestos();

/// ****************************************************  MENU PRESUPUESTO***********************************************************************************

void menuPresupuesto(){
    int i;bool flag=true,aux=true;char opc;
    while(true){
        system("cls");
        Apariencia();
        textcolor(15,1);
        gotoxy(48,36);
        cout<<"*********** MENU PRESUPUESTOS ***********"<<endl<<endl;
        textcolor(15,0);
        gotoxy(5,37);
        cout<<"1) NUEVO PRESUPUESTO"<<endl;
        textcolor(15,0);
        gotoxy(5,38);
        cout<<"2) LISTAR PRESUPUESTOS"<<endl;

        gotoxy(105,37);
        cout<<"0) EXIT"<<endl;
        gotoxy(5,10);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opc;
        switch(opc){
            case '1':
                system("cls");
                cargarPresupuesto();
            ;break;

            case '2':
                system("cls");
                listarPresupuestos();
            ;break;

            case '0':
                return;
            break;

            default: cout<<"OPCION INCORRECTA"<<endl; system("pause");
            break;
        }
    }
}


int cuentaPresupuestos()
{
    FILE *F;F=fopen(F_PRESUPUESTO,"rb");if(F==NULL){F=fopen(F_PRESUPUESTO,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    int cp=1;presupuesto reg;
    while(fread(&reg,sizeof (presupuesto),1,F)){cp++;}
    fclose(F);return cp;

}

bool buscarPresupuesto(int num)
{
    FILE *F;F=fopen(F_PRESUPUESTO,"rb");if(F==NULL){F=fopen(F_PRESUPUESTO,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    int cp=1;presupuesto reg;
    while(fread(&reg,sizeof (presupuesto),1,F))
    {
        if(reg.getNumeroDeVenta()==num){return true;}
        cp++;
    }
    fclose(F);
    return false;
}

presupuesto obtenerPresupuesto(int num)
{
    FILE *F;F=fopen(F_PRESUPUESTO,"rb");if(F==NULL){F=fopen(F_PRESUPUESTO,"wb");if(F==NULL){cout<<"No se ha abierto el archivo";}}
    int cp=1;presupuesto reg;
    while(fread(&reg,sizeof (presupuesto),1,F))
    {
        if(reg.getNumeroDeVenta()==num){return reg;}
    }
    system("pause");
}
void listarArticulosDePresupuesto(int);

void agregarArticulosALaVenta(int,int);

bool comprobarStockPresupuesto(int n){
    FILE *f;f=fopen(F_ARTPRESUPUESTOS,"rb");if (f==NULL){return false;}
    articulosVenta reg;articulos art;
    while(fread(&reg,sizeof(articulosVenta),1,f)){
        if(reg.getNumeroDeVenta()==n){
            art=obtenerArt(reg.getCodigoArticulo());
            gotoxy(5,37);
            cout<<"EL PRESUPUESTO "<<n<<" SE LLEVA "<<reg.getCantidad()<<" Y HAY EN STOCK"<<art.GetStock();
            system("pause");
            if(reg.getCantidad()>art.GetStock()){
                return false;
            }
        }

    }
    fclose(f);return true;
}

float addPresupuesto(int nVenta,int *lineaPresu)
{
    FILE *p;p=fopen(F_PRESUPUESTO,"rb");if(p==NULL){cout<<"Error de archivo";}
    int INT;presupuesto regPres;float IMPORTE=0;int flag;articulosVenta artVenta;
    gotoxy(77,37);cout<<"INGRESAR PRESUPUESTO?   1)SI  2)NO  OPC: ";cin>>flag;
    gotoxy(77,37);cout<<"                                           ";
    artVenta.setNumeroDeVenta(nVenta);
    while (flag==1)
    {
        gotoxy(5,*lineaPresu);
        cout<<"N DE PRESUPUESTO: ";cin>>INT;
        if(INT==0){flag=2;}
        if(buscarPresupuesto(INT)==true)
        {
            regPres=obtenerPresupuesto(INT);
            if(comprobarStockPresupuesto(INT)==true){
                agregarArticulosALaVenta(INT,nVenta);
                gotoxy(30,*lineaPresu);
                cout<<"IMPORTE: "<<"$"<<regPres.getImporte()<<endl;
                IMPORTE+=regPres.getImporte();flag=2;*lineaPresu=(*lineaPresu)+1;
            }
            else{
                gotoxy(35,*lineaPresu);cout<<"STOCK INSUFICIENTE DE UNO DE LOS ARTICULOS.";system("pause");flag=2;
                gotoxy(35,*lineaPresu);cout<<"                                                                       ";
            }

        }
        else{gotoxy(5,*lineaPresu);cout<<"PRESUPUESTO NO EXISTE ";system("pause");gotoxy(5,*lineaPresu);
        cout<<"                                                                    ";gotoxy(5,*lineaPresu);
        }
    }
    return IMPORTE;
}



void cargarPresupuesto()
{
   time_t tiempo;struct tm *tmPtr;int i;int q=0;
    tiempo = time(NULL);tmPtr = localtime(&tiempo);
    objPres.setDia(tmPtr->tm_mday);
    objPres.setMes(tmPtr->tm_mon+1);
    objPres.setAnio(tmPtr->tm_year+1900);
    objPres.setNumeroDeVenta(cuentaPresupuestos());int INT;char CHAR[50];float importeTotal=0;

    entornoGraficoVenta();gotoxy(2,1);
    for(i=0;i<60;i++){cout<<" ";}
    gotoxy(45,1);cout<<"NUEVO PRESUPUESTO";
    gotoxy(54,5);int linea=9;
    cout<<"N"<<(char)167<<" DE PRESUPUESTO: "<<objPres.getNumeroDeVenta()<<endl;
    gotoxy(3,7);for(i=0;i<115;i++){cout<<(char)196;}
    gotoxy(5,linea);charAddArt(&linea);linea++;
    importeTotal+=addArticulo(2,&linea,&q);///PARA AGREGAR ARTICULOS SIEMPRE Y CUANDO SU ID EXISTA, Y HALLA STOCK
    gotoxy(85,linea);cout<<"IMPORTE TOTAL: "<<importeTotal<<endl;
    objPres.setImporte(importeTotal);
    linea=linea+5;
    objPres.guardarPresupuesto();
    gotoxy(45,linea);cout<<"PRESUPUESTO CARGADO.";
    gotoxy(40,linea+1);system("pause");
}

void listarArticulosDePresupuesto(int nVenta)
{

    FILE *f;f=fopen(F_ARTPRESUPUESTOS,"rb");if(f==NULL){cout<<"ERROR DE ARCHIVO";}
    while(fread(&objArtVent,sizeof (articulosVenta),1,f))
    {
        if(nVenta==objArtVent.getNumeroDeVenta())
        {
            cout<<"              Articulo: "<<objArtVent.getCodigoArticulo()<<" --Cantidad: "<<objArtVent.getCantidad()<<
            " --PU:"<<objArtVent.getPrecio()<<endl;
        }
    }
    fclose(f);
}

void agregarArticulosALaVenta(int nPresupuesto,int nVenta)
{
    FILE *f;f=fopen(F_ARTPRESUPUESTOS,"rb");if(f==NULL){cout<<"ERROR DE ARCHIVO";}
    articulosVenta objArtVent,reg;int pos;articulos regArt;
    while(fread(&objArtVent,sizeof (articulosVenta),1,f)){
        if(nPresupuesto==objArtVent.getNumeroDeVenta()){
                reg.setNumeroDeVenta(nVenta);
                reg.setCodigoArticulo(objArtVent.getCodigoArticulo());
                reg.setCantidad(objArtVent.getCantidad());
                reg.setPrecio(objArtVent.getPrecio());
                reg.guardarRegistro(1);
                pos=buscarArt(reg.getCodigoArticulo());
                regArt=obtenerArt(reg.getCodigoArticulo());
                modificarStock(pos,regArt.GetStock()-reg.getCantidad());
        }
    }

}

void chartPresupuestos()
{
    int i;
    gotoxy(0,0);cout<<(char)218;for(i=0;i<118;i++){cout<<(char)196;};cout<<(char)191;
    gotoxy(0,1);cout<<char(179);gotoxy(50,1);cout<<"PRESUPUESTOS";gotoxy(119,1);cout<<(char)179;
    gotoxy(0,2);cout<<(char)195;for(i=0;i<118;i++){cout<<(char)196;};cout<<(char)180;
    for(i=3;i<35;i++){gotoxy(0,i);cout<<(char)179;}
    for(i=3;i<35;i++){gotoxy(119,i);cout<<(char)179;}
    gotoxy(0,35);cout<<(char)192;for(i=0;i<118;i++){cout<<(char)196;};cout<<(char)217;


}

void verPresupuesto(int n)
{
    presupuesto reg;int nLinea=6;
    reg=obtenerPresupuesto(n);
    entornoGraficoVenta();
    gotoxy(45,1);cout<<"     PRESUPUESTO";
    gotoxy(105,5);cout<<"           ";
    gotoxy(105,5);cout<<reg.getDia()<<"/"<<reg.getMes()<<"/"<<reg.getAnio();
    gotoxy(54,5);cout<<"N"<<(char)167<<" DE PRESUPUESTO: "<<reg.getNumeroDeVenta()<<endl;
    gotoxy(5,8);cout<<"              ";
    gotoxy(5,nLinea);charAddArt(&nLinea);nLinea++;
    listarArticulosDeVenta(reg.getNumeroDeVenta(),&nLinea,2);
    gotoxy(78,nLinea);cout<<"IMPORTE: "<<reg.getImporte();
    gotoxy(77,33);system("pause");
}

bool comprobarPresupuesto(int N){
    FILE *F;F=fopen(F_PRESUPUESTO,"rb");if(F==NULL){cout<<"No se ha abierto el archivo";}
    presupuesto reg;
    while(fread(&reg,sizeof(reg),1,F)){
        if(N==reg.getNumeroDeVenta()){return true;}
    }
    return false;
}

void listarPresupuestos()
{
    int i=0,cP;cP=cuentaPresupuestos();
    chartPresupuestos();
    int opc,linea=3,columna=0;
    FILE *F;F=fopen(F_PRESUPUESTO,"rb");if(F==NULL){cout<<"No se ha abierto el archivo";}
    while(fread(&objPres,sizeof(presupuesto),1,F))
    {
        gotoxy(columna+2,linea);
        if(cP-objPres.getNumeroDeVenta()<96)
        {
            if(objPres.getNumeroDeVenta()<10){cout<<"0";}
            cout<<objPres.getNumeroDeVenta();
            cout<<" - ";if(objPres.getDia()<10){cout<<"0";}
            cout<<objPres.getDia()<<"/";
            if(objPres.getMes()<10){cout<<"0";}
            cout<<objPres.getMes()<<"/";
            if(objPres.getMes()==0){cout<<"000";}
            cout<<objPres.getAnio()<<" - $"<<
            objPres.getImporte();linea++;
            if(linea==30){linea=6;columna=columna+30;}
        }
    }
    gotoxy(77,37);cout<<"INGRESE NUMERO DE PRESUPUESTO: ";cin>>opc;
    fclose(F);
    system("cls");
    if(comprobarPresupuesto(opc)==true){
        verPresupuesto(opc);
    }
    else{
        gotoxy(25,13);cout<<"  EL PRESUPUESTO NO EXISTE         ";
        gotoxy(36,8);system("pause");
    }
}

#endif // PRESUPUESTO_H_INCLUDED
