#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include <ctype.h>
#include <math.h>
#define sal 27
#include "producto.h"
#include "productoa.h"
char op;
//******************************************************************************
class gestorproductosA{
private:
productoA objproductos;
public:
void ejecuta();
int h;
gestorproductosA(){h=0;}
private:
void ingreso_producto();
void lista();
void buscar();
void elimina();
void modifica();
void mensaje(char*m){cout<<endl<<m<<endl;}
};
char tem1[3],tem2[3],tem3[4];
//**************************************************
void main(){
gestorproductosA objgestor;
objgestor.ejecuta();
}
//******************************************************
void gestorproductosA::ejecuta(){
 do{  clrscr();   cout<<"\n\n\t\t\t\tTIENDA GUILLE\n";
                cout<<"\t\t\t\t-------------\n\n";
    gotoxy(32,8);cout<<"1.- crear Item";
    gotoxy(32,10);cout<<"2.- Buscar";
    gotoxy(32,12);cout<<"3.- Lista";
    gotoxy(32,14);cout<<"4.- Elimina";
    gotoxy(32,16);cout<<"5.- Modifica";
    gotoxy(32,18);cout<<"7.- Salir";
    gotoxy(32,20);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1': ingreso_producto();break;
    case '2': buscar();break;
    case '3': lista();break;
    case '4': elimina();break;
    case '5': modifica();break;
    }
 }while(op!='7');
}
//****************************************************************************
//****************************************************************************
void gestorproductosA::ingreso_producto(){
char codigo[9];

char grupoproducto[30];
char productoespecifico[60];
char unidad[3];
char lugar[6];

double precio;
double preciosugerido;
fecha fechacompra;
double cancomprada;
char numboleta[8];
char tipoboleta[3];
//char tem1[2],tem2[3],tem3[4];
do{clrscr();
 cout<<"\n\tINGRESO DE PRODUCTOS";
if(h==1){gotoxy(40,2);cout<<"         Fecha : "<<tem1<<" / "<<tem2<<" / "<<tem3;}
cout<<"\n\t--------------------\n\n";
cout<<"Para salir ESC";op=getch();if(op==sal)break; gotoxy(1,5);clreol();

do{cout<<"\tCodigo............:";gets(codigo);

                 if(strlen(codigo)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
               }while(strlen(codigo)!=8);
int p=objproductos.buscacodigo(codigo);
if (p!=-1)mensaje("Codigo ya esxiste");



do{cout<<"\tGrupo Producto.......:   ";gets(grupoproducto);
if(strlen(grupoproducto)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
}while( strlen(grupoproducto)>30);

do{cout<<"\tProducto Especifico..:   ";gets(productoespecifico);
if(strlen(productoespecifico)>60){cout<<"\t\t\aMaximo 60 cifras\n";}
}while( strlen(productoespecifico)>60);

do{cout<<"\tUnidad...............:   ";gets(unidad);
if(strlen(unidad)>2){cout<<"\t\t\aMaximo 2 cifras\n";}
}while( strlen(unidad)>2);
char opl;int nl=0;
do{cout<<"\tLugar de almacen.....:   ";

                  	cout<<"\n\t\t1.- Tienda";
                     cout<<"\n\t\t2.- Casa";
                     cout<<"\n\t\t3.- Departamento"; opl=getch();
                  switch(opl){
                   case '1': strcpy(lugar,"Tienda");nl=1;break;
                   case '2': strcpy(lugar,"Casa");nl=1;break;
                   case '3': strcpy(lugar,"Depa");nl=1;break;
						}
                }while(nl!=1);


//*********************************************************************
 clrscr();
 cout<<"\n\tINGRESO DE PRODUCTOS";
if(h==1){gotoxy(40,2);cout<<"         Fecha : "<<tem1<<" / "<<tem2<<" / "<<tem3;}
 cout<<"\n\t--------------------";
cout<<"\n\n\tCodigo...............:   "<<codigo;
cout<<"\n\tGrupo Producto.......:   "<<grupoproducto;
cout<<"\n\tProducto Especifico..:   "<<productoespecifico;
cout<<"\n\tUnidad...............:   "<<unidad;
cout<<"\n\tLugar de Almacen.....:   "<<lugar;

//*************************************************************************
int n1=0;
do{cout<<"\n\tTipo de documento..:";

                  	cout<<"\n\t\t\t1.- BOLETA\n";
                     cout<<"\t\t\t2.- FACTURA\n";
                     cout<<"\t\t\t3.- OTROS\n"; opl=getch();
                  switch(opl){
                   case '1': strcpy(tipoboleta,"B");n1=1;break;
                   case '2': strcpy(tipoboleta,"F");n1=1;break;
                   case '3': strcpy(tipoboleta,"SN");n1=1;break;
						}
                 }while(n1!=1);
 //*********************************************************************
 clrscr();
 cout<<"\n\tINGRESO DE PRODUCTOS";
if(h==1){gotoxy(40,2);cout<<"         Fecha : "<<tem1<<" / "<<tem2<<" / "<<tem3;}
 cout<<"\n\t--------------------";
cout<<"\n\n\tCodigo...............:   "<<codigo;
cout<<"\n\tGrupo Producto.......:   "<<grupoproducto;
cout<<"\n\tProducto Especifico..:   "<<productoespecifico;
cout<<"\n\tUnidad...............:   "<<unidad;
cout<<"\n\tLugar de Almacen.....:   "<<lugar;
cout<<"\n\tTipo de documento....:   "<<tipoboleta;
//*************************************************************************

do{cout<<"\n\tNumero de Documento........:";gets(numboleta);
                 if(strlen(numboleta)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                }while( strlen(unidad)>8);
char fe;
cout<<"\n\tFecha de compra......:  ";
if(h==1){cout<<" cambiar fecha?  Y/N ";fe=getch();}
else {h=1;fe='y';}

if (fe=='y'||fe=='Y'){
      do{cout<<"\n\t\tDia....: ";gets(fechacompra.dia);
         if(strlen(fechacompra.dia)>2){cout<<"\t\t\aMaximo 2 cifras\n";}
       }while( strlen(fechacompra.dia)>2);
      do{cout<<"\t\tMes....: ";gets(fechacompra.mes);
        if(strlen(fechacompra.mes)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
      }while( strlen(fechacompra.mes)>3);
      do{cout<<"\t\tYear...: ";gets(fechacompra.year);
       if(strlen(fechacompra.year)>4){cout<<"\t\t\aMaximo 4 cifras\n";}
       }while( strlen(fechacompra.year)>4);
        strcpy(tem1,fechacompra.dia);
        strcpy(tem2,fechacompra.mes);
        strcpy(tem3,fechacompra.year);
       }
  else {strcpy(fechacompra.dia,tem1);
        strcpy(fechacompra.mes,tem2);
        strcpy(fechacompra.year,tem3);
  }

cout<<"\n\t\t"<<fechacompra.dia<<" / "<<fechacompra.mes;
cout<<" / "<<fechacompra.year<<"\n\n";
char prsg;
cout<<"\tPrecio por "<<unidad[0]<<unidad[1]<<"........:   ";cin>>precio;
double presug=precio*1.15*1.5;
cout<<"\n\Precio de venta sugerido x "<<unidad[0]<<unidad[1]<<" al 50 p de FOB   :  ";
cout<<presug<<" Desea Cambiarlo? Y/N ";
prsg=getch();
if(prsg=='y'||prsg=='Y'){
cout<<"\nIngrese Precio Sugerido ";cin>>preciosugerido;}
else{preciosugerido=presug;}
cout<<"\n\tCantidad comprada.:";cin>>cancomprada;


//***************************************************************************
producto unproducto(codigo,grupoproducto,productoespecifico,unidad,lugar,precio,
preciosugerido,fechacompra.dia,fechacompra.mes,fechacompra.year,cancomprada,
numboleta,tipoboleta);
char op2;
do{
   cout<<"\n\nDesea corregir Y/N";op2=getch();

  if(op2==89 ||op2==121){unproducto.change(); }
   if(op2==78)break;
 }while( op2!= 110);

 objproductos.addproducto(unproducto);
 mensaje("ingreso realizodo satisfactoriamente");
cout<<"\n\n\tEnter para ingresar mas registros ESC para salir";
op=getch();

}while(op!=sal);
}
//**************************************************************
//******************************************************************************
//**BUSCAR***BUSCAR***BUSCAR**BUSCAR**BUSCAR**BUSCAR**BUSCAR******************
//****************************************************************************
void gestorproductosA::buscar()
{char bu[15],codi[9];  int q;
 producto uproducto;
  do{  clrscr();   cout<<"\n\n\t\t\t\tBUSCA PRODUCTO \n";
                       cout<<"\t\t\t\t--------------\n\n";
    gotoxy(32,10);cout<<"  1.- Codigo";
    gotoxy(32,12);cout<<"  2.- Grupo Producto";
    gotoxy(32,14);cout<<"Esc.- Salir";
    gotoxy(32,16);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1':clrscr();cout<<"\n\n\n\tCodigo :";gets (codi);
               q=objproductos.buscacodigo(codi);

             if(q==-1)cout<<"NO EXISTE EL ARCHIVO";
             else
             {clrscr();  uproducto=objproductos.getproducto(q);

              cout<<"\n\tCodigo                 : "<<uproducto.getcodigo();
              cout<<"\n\tProducto Especifico    : "<<uproducto.getproductoespecifico();
              cout<<"\n\tGrupo Producto         : "<<uproducto.getgrupoproducto();
              //gotoxy(15,7);cout<<"Precio "<<uproducto.getprecio();
              double cif=uproducto.getprecio(),fob=uproducto.getprecio()*1.15;
              gotoxy(15,9);cout<<"Precio de Venta "<<uproducto.getpreciosugerido();
              char opotros,opotros2;
              cout<<"\n\notros precios ......Y/N ";opotros=getch();
              if(opotros=='y'||opotros=='Y'){

              cout<<"\n\n\n Compra CIF =   "<<cif;
              cout<<"\n\n Compra FOB =     "<<fob;
              cout<<"\n\n\n0.10 p   =   "<<fob*1.1;cout<<"\t\t\t0.30 p   =   "<<fob*1.3;
              cout<<"\n\n0.50 p   =   "<<fob*1.5;cout<<"\t\t\t  1  p   =   "<<fob*2;
              cout<<"\n\n MAS PRECIOS ";opotros2=getch();
              if(opotros2=='y'||opotros2=='Y'){ double preciosugerido;
              cout<<"\n\tIngrese Precio sugerido  ";cin>>preciosugerido;
              if(preciosugerido>=fob){
              cout<<"\n\tGanancia de "<<(( (preciosugerido-fob)/fob)*100)<<" p" ;
              }else {cout<<"\n\a\a\a\t Este precio representa perdida del "<<(( (preciosugerido-fob)/fob)*100)<<"  p";}

              }
              }

				}
				getch();break;

    case '2':clrscr();cout<<"\n\n\n\tGrupo Producto :";gets(bu);
               q=objproductos.buscaproducto(bu);

             if(q==-1)cout<<"NO EXISTE EL ARCHIVO";
             else
             {clrscr();  uproducto=objproductos.getproducto(q);
              gotoxy(30,2);cout<<"REGISTRO HALLADO";
              gotoxy(30,4);cout<<"Codigo    : "<<uproducto.getcodigo();
              gotoxy(30,6);cout<<"Nombre    : "<<uproducto.getproductoespecifico();
              gotoxy(15,7);cout<<"Precio "<<uproducto.getprecio();
               gotoxy(30,8);cout<<"10%  =  "<<(uproducto.getprecio()*1.1);
               cout<<"    100%  =  "<<(uproducto.getprecio()*2);


				}


            getch();break;

    }
 }while(op!=sal);
}
//*****************************************************************************
//***LISTA***LISTA**LISTA***LISTA**LISTA**LISTA****LISTA*****LISTA****LISTA*******
//*****************************************************************************
void gestorproductosA::lista(){producto unproducto;
clrscr();

cout<<"codigo     nombre        grupo            precio";
cout<<objproductos.numproductos()<<"\n\n";
for (int i=0;i<objproductos.numproductos();i++)
{
unproducto=objproductos.getproducto(i);
cout<<" "<<unproducto.getcodigo()<<"   "<<unproducto.getgrupoproducto()<<"  "<<unproducto.getproductoespecifico()<<"   "<<unproducto.getprecio()<<"\n";
}
getch();
}

//***********************************************************************
//*******ELIMINA****************ELIMINA************ELIMINA****************
//*******ELIMINA****************ELIMINA************ELIMINA****************
//********************************************************************
void gestorproductosA::elimina(){  clrscr();
 char codigoe[8];
  cout<<"\n\tELIMINA  PRODUCTO";
  cout<<"\n\t-----------------";
do{cout<<"\n\n\tCodigo............:";gets(codigoe);

                 if(strlen(codigoe)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
               }while(strlen(codigoe)!=8);
int p=objproductos.buscacodigo(codigoe);



if (p==-1)mensaje("Codigo no esxiste");
 else{ clrscr();
 cout<<"\n\tELIMINA  PRODUCTO";
  cout<<"\n\t-----------------";
 producto eproducto=objproductos.getproducto(p);
 eproducto.lista();
 char opconfirma;
 cout<<"Esta seguro que desea eliminar este producto ...Y/N ";opconfirma=getch();
 //falta el elimina
     if(opconfirma=='y'||opconfirma=='Y'){
    eproducto.setcodigo("clear");
     objproductos.setproducto(eproducto,p);
       
     cout<<"\n\n Eliminacion satisfactoria";

     }
}  getch();

 }

//******************************************************************************
//******MODIFICA*********MODIFICA*************MODIFICA**************************
//**************MODIFICA*********MODIFICA**************MODIFICA*****************
//******************************************************************************
void gestorproductosA::modifica(){clrscr();
  char codi[9];
  cout<<"\n\n\t\t\t\tMODIFICA PRODUCTO \n";
      cout<<"\t\t\t\t-----------------\n\n";
      do{cout<<"\tCodigo............:";gets(codi);

                 if(strlen(codi)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
               }while(strlen(codi)!=8);



               int q=objproductos.buscacodigo(codi);

             if(q==-1){textcolor(5);cprintf("\r               NO EXISTE EL ARCHIVO");getch();}
             else{   producto uproducto=objproductos.getproducto(q);
              uproducto.lista();
              char op2; do{
   cout<<"\n\nDesea corregir Y/N";op2=getch();

  if(op2==89 ||op2==121){uproducto.change(); }
   if(op2==78)break;
 }while( op2!= 110);

    objproductos.setproducto(uproducto,q);
 mensaje("Modificacion realizado satisfactoriamente");getch();

             }


}














