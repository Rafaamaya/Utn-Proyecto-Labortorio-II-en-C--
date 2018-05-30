#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED


///                                   //////////////////////////PROTOTIPOS////////////////////////////////
void menuConfiguracion();

void crear_copia();
bool copia_clientes();
bool copia_articulos();
bool copia_ventas();
bool copia_artVentas();
bool copia_presupuestos();
bool copia_proveedores();
bool copia_ingreso();

void restablecer_copia();
bool res_clientes();
bool res_articulos();
bool res_ventas();
bool res_artVentas();
bool res_presupuestos();
bool res_proveedores();
bool res_ingreso();
///////////////////////////////////////////////////////////////////
/// ************************************************************ CREAR COPIA *******************************************************

/// ********************************************************************************************************************************


void crear_copia(){
    system("cls");
    cout<<"COPIAS DE SEGURIDAD"<<endl;
    cout<<"-------------------"<<endl;
if (copia_clientes()==true){
      cout<<"BACKUP CLIENTES: \t\tOK"<<endl;
}
else{
    cout<<"BACKUP CLIENTES: \t\tERROR"<<endl;
}
if (copia_articulos()==true){
      cout<<"BACKUP ARTICULOS: \t\tOK"<<endl;
}
else{
    cout<<"BACKUP ARTICULOS: \t\tERROR"<<endl;
}
if (copia_ventas()==true){
      cout<<"BACKUP VENTAS: \t\t\tOK"<<endl;
}
else{
    cout<<"BACKUP VENTAS: \t\tERROR"<<endl;
}
if (copia_artVentas()==true){
      cout<<"BACKUP ARTVENTAS: \t\tOK"<<endl;
}
else{
    cout<<"BACKUP ARTVENTAS: \t\tERROR"<<endl;
}
if (copia_presupuestos()==true){
      cout<<"BACKUP PRESUPUESTOS: \t\tOK"<<endl;
}
else{
    cout<<"BACKUP PRESUPUESTOS: \t\tERROR"<<endl;
}
if (copia_proveedores()==true){
      cout<<"BACKUP PROVEEDORES: \t\tOK"<<endl;
}
else{
    cout<<"BACKUP PROVEEDORES: \t\tERROR"<<endl;
}
if (copia_ingreso()==true){
      cout<<"BACKUP INGRESO: \t\tOK"<<endl;
}
else{
    cout<<"BACKUP INGRESO: \t\tERROR"<<endl;
}

system("pause >nul");
system("cls");
}

/// ***************************************************************** COPIAS CLIENTES ************************************************************
//////////////////////////////////////////////////////////////////
bool copia_clientes(){
FILE *p;
cliente *reg;
long tam;
p=fopen(A_CLIENTES,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO CLIENTES"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(cliente *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(cliente),tam/sizeof(cliente),p);
fclose(p);
p=fopen("backup/clientes.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP CLIENTES"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(cliente),tam/sizeof(cliente),p);
free(reg);
fclose(p);
return true;
}
/// ***************************************************************** COPIAS ARTICULOS ************************************************************
//////////////////////////////////////////////////////////////////
bool copia_articulos(){
FILE *p;
articulos *reg;
long tam;
p=fopen(A_ARTICULOS,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO ARTICULOS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(articulos *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(articulos),tam/sizeof(articulos),p);
fclose(p);
p=fopen("backup/articulos.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP ARTICULOS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(articulos),tam/sizeof(articulos),p);
free(reg);
fclose(p);
return true;
}
/// ***************************************************************** COPIAS VENTAS ************************************************************
//////////////////////////////////////////////////////////////////
bool copia_ventas(){
FILE *p;
venta *reg;
long tam;
p=fopen(F_VENTAS,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO VENTAS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(venta *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(venta),tam/sizeof(venta),p);
fclose(p);
p=fopen("backup/ventas.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP VENTAS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(venta),tam/sizeof(venta),p);
free(reg);
fclose(p);
return true;
}
/// ***************************************************************** COPIAS ARTVENTAS ************************************************************
/////////////////////////////////////////////////////////////////
bool copia_artVentas(){
FILE *p;
articulosVenta *reg;
long tam;
p=fopen(F_ARTVENTAS,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO RESULTADOS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(articulosVenta *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE ARTVENTAS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(articulosVenta),tam/sizeof(articulosVenta),p);
fclose(p);
p=fopen("backup/artVentas.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP ARTVENTAS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(articulosVenta),tam/sizeof(articulosVenta),p);
free(reg);
fclose(p);
return true;
}
/// ***************************************************************** COPIAS PRESUPUESTOS ************************************************************
/////////////////////////////////////////////////////////////////
bool copia_presupuestos(){
FILE *p;
presupuesto *reg;
long tam;
p=fopen(F_PRESUPUESTO,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO PRESUPUESTOS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(presupuesto *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(presupuesto),tam/sizeof(presupuesto),p);
fclose(p);
p=fopen("backup/presupuestos.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP PRESUPUESTOS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(presupuesto),tam/sizeof(presupuesto),p);
free(reg);
fclose(p);
return true;
}
/// ***************************************************************** COPIAS PROVEEDORES ************************************************************
/////////////////////////////////////////////////////////////////

bool copia_proveedores(){
FILE *p;
proveedores *reg;
long tam;
p=fopen(A_PROVEEDORES,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO PROVEEDORES"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(proveedores *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(proveedores),tam/sizeof(proveedores),p);
fclose(p);
p=fopen("backup/proveedores.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP PROVEEDORES"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(proveedores),tam/sizeof(proveedores),p);
free(reg);
fclose(p);
return true;
}

/// ***************************************************************** COPIAS INGRESO ************************************************************
/////////////////////////////////////////////////////////////////

bool copia_ingreso(){
FILE *p;
ingreso *reg;
long tam;
p=fopen(A_INGRESO,"rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO INGRESO"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(ingreso *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(ingreso),tam/sizeof(ingreso),p);
fclose(p);
p=fopen("backup/ingreso.bak","wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP INGRESO"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(ingreso),tam/sizeof(ingreso),p);
free(reg);
fclose(p);
return true;
}

/// ******************************************************* RESTABLECER COPIA ********************************************************************************

///***********************************************************************************************************************************************************


/////////////////////////////////////////////////////////////////
void restablecer_copia(){
    system("cls");
    cout<<"RESTABLECER COPIAS DE SEGURIDAD"<<endl;
    cout<<"-------------------------------"<<endl;
if (res_clientes()==true){
      cout<<"CLIENTES: \t\tOK"<<endl;
}
else{
    cout<<"CLIENTES: \t\tERROR"<<endl;
}
if (res_articulos()==true){
      cout<<"ARTICULOS: \t\tOK"<<endl;
}
else{
    cout<<"ARTICULOS: \tERROR"<<endl;
}
if (res_ventas()==true){
      cout<<"VENTAS: \t\tOK"<<endl;
}
else{
    cout<<"VENTAS: \t\tERROR"<<endl;
}
if (res_artVentas()==true){
      cout<<"ARTVENTAS: \t\tOK"<<endl;
}
else{
    cout<<"ARTVENTAS: \t\tERROR"<<endl;
}
if (res_presupuestos()==true){
      cout<<"PRESUPUESTOS: \t\tOK"<<endl;
}
else{
    cout<<"PRESUPUESTOS: \t\tERROR"<<endl;
}
if (res_proveedores()==true){
      cout<<"PROVEEDORES: \t\tOK"<<endl;
}
else{
    cout<<"PROVEEDORES: \t\tERROR"<<endl;
}
if (res_ingreso()==true){
      cout<<"INGRESO: \t\tOK"<<endl;
}
else{
    cout<<"INGRESO: \t\tERROR"<<endl;
}

system("pause >nul");
system("cls");
}

/// ************************************************************************************ RESTABLECER CLIENTES
////////////////////////////////////////////////////////////////
bool res_clientes(){
    FILE *p;
cliente *reg;
long tam;
p=fopen("backup/clientes.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP CLIENTES"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(cliente *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(cliente),tam/sizeof(cliente),p);
fclose(p);
p=fopen(A_CLIENTES,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO CLIENTES"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(cliente),tam/sizeof(cliente),p);
free(reg);
fclose(p);
return true;
}
/// ************************************************************************************ RESTABLECER ARTICULOS
////////////////////////////////////////////////////////////////
bool res_articulos(){
    FILE *p;
articulos *reg;
long tam;
p=fopen("backup/articulos.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP ARTICULOS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(articulos *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(articulos),tam/sizeof(articulos),p);
fclose(p);
p=fopen(A_ARTICULOS,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO ARTICULOS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(articulos),tam/sizeof(articulos),p);
free(reg);
fclose(p);
return true;
}
/// ************************************************************************************ RESTABLECER VENTAS
////////////////////////////////////////////////////////////////
bool res_ventas(){
    FILE *p;
venta *reg;
long tam;
p=fopen("backup/ventas.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP VENTAS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(venta *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(venta),tam/sizeof(venta),p);
fclose(p);
p=fopen(F_VENTAS,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO VENTAS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(venta),tam/sizeof(venta),p);
free(reg);
fclose(p);
return true;
}
/// ************************************************************************************ RESTABLECER ART VENTAS
////////////////////////////////////////////////////////////////
bool res_artVentas(){
    FILE *p;
articulosVenta *reg;
long tam;
p=fopen("backup/artVentas.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP ARTVENTAS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(articulosVenta *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(articulosVenta),tam/sizeof(articulosVenta),p);
fclose(p);
p=fopen(F_ARTVENTAS,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO ARTVENTAS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(articulosVenta),tam/sizeof(articulosVenta),p);
free(reg);
fclose(p);
return true;
}
/// ************************************************************************************ RESTABLECER PRESUPUESTOS
////////////////////////////////////////////////////////////////
bool res_presupuestos(){
    FILE *p;
presupuesto *reg;
long tam;
p=fopen("backup/presupuestos.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP PRESUPUESTOS"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(presupuesto *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(presupuesto),tam/sizeof(presupuesto),p);
fclose(p);
p=fopen(F_PRESUPUESTO,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO PRESUPUESTOS"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(presupuesto),tam/sizeof(presupuesto),p);
free(reg);
fclose(p);
return true;
}

/// ************************************************************************************ RESTABLECER PROVEEDORES
////////////////////////////////////////////////////////////////

bool res_proveedores(){
    FILE *p;
proveedores *reg;
long tam;
p=fopen("backup/proveedores.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP PROVEEDORES"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(proveedores *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(proveedores),tam/sizeof(proveedores),p);
fclose(p);
p=fopen(A_PROVEEDORES,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO PROVEEDORES"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(proveedores),tam/sizeof(proveedores),p);
free(reg);
fclose(p);
return true;
}


/// ************************************************************************************ RESTABLECER INGRESO
////////////////////////////////////////////////////////////////

bool res_ingreso(){
    FILE *p;
ingreso *reg;
long tam;
p=fopen("backup/ingreso.bak","rb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO BACKUP PROVEEDORES"<<endl;
    system("pause");
    return false;
}
fseek(p,0,2);
tam=ftell(p);
reg=(ingreso *) malloc(tam);
if (reg==NULL){
    cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
    system("pause");
    return false;
}
fseek(p,0,0);
fread(reg,sizeof(ingreso),tam/sizeof(ingreso),p);
fclose(p);
p=fopen(A_INGRESO,"wb");
if (p==NULL){
    cout<<"ERROR DE ARCHIVO PROVEEDORES"<<endl;
    system("pause");
    return false;
}
fwrite(reg,sizeof(ingreso),tam/sizeof(ingreso),p);
free(reg);
fclose(p);
return true;
}

////////////////////////////////////////////////////////////////
/// ***************************************************************** MENU CONFIGURACION *****************************************************************************

/// ******************************************************************************************************************************************************************

void menuConfiguracion(){
while (true){

     system ("cls");
int opc;
    cout<<"MENU CONFIGURACION"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"1. CREAR COPIA DE SEGURIDAD\n2. RESTABLECER COPIA DE SEGURIDAD\n\n\n0.VOLVER"<<endl;
    cout<<"-----------------" << endl;
    cout<<"INGRESE OPCION: ";
    cin>>opc;
switch(opc){
case 1:
    int nuevo;
cout<<"ESTA SEGURO QUE DESEA CREAR UNA COPIA DE SEGURIDAD?"<<endl;
cout<<"1. SI\t\t0. NO"<<endl;
cin>>nuevo;
if (nuevo==1){
    crear_copia();
}
    break;
case 2:
    cout<<"ESTA SEGURO QUE DESEA RESTABLECER LA COPIA DE SEGURIDAD?"<<endl;
    cout<<"PERDERA TODOS SUS ARCHIVOS NO GUARDADOS. DESEA CONTINUAR?"<<endl;
cout<<"1. SI\t\t0. NO"<<endl;
cin>>nuevo;
if (nuevo==1){
    restablecer_copia();
}
    break;

case 0:
return;
break;}
}
}

#endif // CONFIGURACION_H_INCLUDED
