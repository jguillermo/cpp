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
void listafecha();
void listacodigo();
void listadoc();
void lista4();
void marco(int t);
void marcocodigo();
void discodigo(int y,producto pro,int &p,int l);
void dis(int y,producto pro,int &p,int l,int t);
void buscar();
void debusca(char bu[30],int tipo);
void elimina();
void modifica();
void actualiza(int act);
void crear(char cod[9]);
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
char actua;
if (p!=-1){producto   aproducto=objproductos.getproducto(p);

              cout<<"\n\tProducto Especifico    : "<<aproducto.getproductoespecifico();
              cout<<"\n\tGrupo Producto         : "<<aproducto.getgrupoproducto();
              cout<<"\n\tUnidad                 : "<<aproducto.getunidad();
              cout<<"\n\tLugar de almacen       : "<<aproducto.getlugar();





cout<<"\n\n\tEL CODIGO YA EXISTE DESEA ACTUALIZAR   Y/N ";
           actua=getch();
           if(actua=='y'||actua=='Y')actualiza(p);  }
   else{crear(codigo);}


op=getch();
}while(op!=sal);
}
//**************************************************************
//******************************************************************************
//**ACTUALIZA**ACTUALIZA****ACTUALIZA*****ACTUALIZA*****ACTUALIZA***ACTUALIZA*****
//****************************************************************************
void gestorproductosA::actualiza(int act){

 double preciosugerido;

double precio;
fecha fechacompra;
double cancomprada;
char numboleta[8];
char tipoboleta[3];
char opl; clrscr();
char lugar[6];

   cout<<"\n\tACTUALIZA  PRODUCTO";
                      cout<<"\n\t-------------------\n\n";
 producto   aproducto=objproductos.getproducto(act);
              cout<<"\n\tCodigo                 : "<<aproducto.getcodigo();
              cout<<"\n\tProducto Especifico    : "<<aproducto.getproductoespecifico();
              cout<<"\n\tGrupo Producto         : "<<aproducto.getgrupoproducto();
              cout<<"\n\tUnidad                 : "<<aproducto.getunidad();

int nl=0;
do{cout<<"\n\tLugar de almacen.....:   ";

                  	cout<<"\n\t\t1.- Tienda";
                     cout<<"\n\t\t2.- Casa";
                     cout<<"\n\t\t3.- Departamento"; opl=getch();
                  switch(opl){
                  case '1': strcpy(lugar,"Tienda");nl=1;break;
                   case '2': strcpy(lugar,"Casa");nl=1;break;
                   case '3': strcpy(lugar,"Depa");nl=1;break;
						}
                }while(nl!=1);

//*********
clrscr();
 cout<<"\n\tACTUALIZA DE PRODUCTO";
if(h==1){gotoxy(40,2);cout<<"         Fecha : "<<tem1<<" / "<<tem2<<" / "<<tem3;}
 cout<<"\n\t--------------------";
cout<<"\n\n\tCodigo...............:   "<<aproducto.getcodigo();
cout<<"\n\tGrupo Producto.......:   "<<aproducto.getgrupoproducto();
cout<<"\n\tProducto Especifico..:   "<<aproducto.getproductoespecifico();
cout<<"\n\tUnidad...............:   "<<aproducto.getunidad();

cout<<"\n\tLugar de Almacen.....:   "<<lugar;



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
 cout<<"\n\tACTUALIZA DE PRODUCTO";
if(h==1){gotoxy(40,2);cout<<"         Fecha : "<<tem1<<" / "<<tem2<<" / "<<tem3;}
 cout<<"\n\t--------------------";
cout<<"\n\n\tCodigo.............       :   "<<aproducto.getcodigo();
cout<<"\n\tGrupo Producto.......       :   "<<aproducto.getgrupoproducto();
cout<<"\n\tProducto Especifico..       :   "<<aproducto.getproductoespecifico();
cout<<"\n\tUnidad...............       :   "<<aproducto.getunidad();
cout<<"\n\tLugar de Almacen.....       :   "<<lugar<<endl;
cout<<"\tTipo de documento......       :   "<<tipoboleta;
//*************************************************************************

do{cout<<"\n\tNumero de Documento........:";gets(numboleta);
                 if(strlen(numboleta)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                }while( strlen(numboleta)>8);
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
cout<<"\tPrecio por "<<aproducto.getunidad()<<"........:   ";cin>>precio;
double presug=precio*1.15*1.5;
cout<<"\n\Precio de venta sugerido x "<<aproducto.getunidad()<<" al 50 p de FOB   :  ";
cout<<presug<<" Desea Cambiarlo? Y/N ";
prsg=getch();
if(prsg=='y'||prsg=='Y'){
cout<<"\nIngrese Precio Sugerido ";cin>>preciosugerido;}
else{preciosugerido=presug;}
cout<<"\n\tCantidad comprada por "<<aproducto.getunidad()<<"  :  ";cin>>cancomprada;
//***************************************************************
int l=aproducto.getla();
    l++;
 if(l>=15)l=0;   
aproducto.setla(l);
aproducto.setprecio(precio,l);
 aproducto.setfecha(fechacompra.dia,fechacompra.mes,fechacompra.year,l);
 aproducto.setcancomprada(cancomprada,l);
 aproducto.setnumboleta(numboleta,l);
 aproducto.settipoboleta(tipoboleta,l);
 aproducto.setpreciosugerido(preciosugerido,l);




char op2;
do{
   cout<<"\n\nDesea corregir Y/N";op2=getch();

  if(op2==89 ||op2==121){aproducto.change(l); }
   if(op2==78)break;
 }while( op2!= 110);

  objproductos.setproducto(aproducto,act);
 mensaje("Actualizar realizado satisfactoriamente");
cout<<"\n\n\t\tESC para salir";






}
//*************************************************************
//******************************************************************************
//**CREAR**CREAR*****CREAR******CREAR******CREAR*******CREAR*********CREAR***
//****************************************************************************
void gestorproductosA::crear(char cod[9]){


char grupoproducto[30];
char productoespecifico[60];
char unidad[3];
char lugar[6];
double preciosugerido;

double precio;
fecha fechacompra;
double cancomprada;
char numboleta[8];
char tipoboleta[3];


do{cout<<"\tGrupo Producto.......:   ";gets(grupoproducto);
if(strlen(grupoproducto)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
}while( strlen(grupoproducto)>30);

do{cout<<"\tProducto Especifico..:   ";gets(productoespecifico);
if(strlen(productoespecifico)>60){cout<<"\t\t\aMaximo 60 cifras\n";}
}while( strlen(productoespecifico)>60);

do{cout<<"\tUnidad...............:   ";gets(unidad);
if(strlen(unidad)>2){cout<<"\t\t\aMaximo 2 cifras\n";}
}while( strlen(unidad)>2);
//cout<<"\n\tCantidad comprada por "<<unidad[0]<<unidad[1]<<"  : ";cin>>cancomprada;
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
cout<<"\n\n\tCodigo...............:   "<<cod;
cout<<"\n\tGrupo Producto.......:   "<<grupoproducto;
cout<<"\n\tProducto Especifico..:   "<<productoespecifico;
cout<<"\n\tUnidad...............:   "<<unidad;
//cout<<"\n\tCantidad comprada por "<<unidad<<"  : "<<cancomprada;
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
cout<<"\n\n\tCodigo.............:   "<<cod;
cout<<"\n\tGrupo Producto.......:   "<<grupoproducto;
cout<<"\n\tProducto Especifico..:   "<<productoespecifico;
cout<<"\n\tUnidad...............:   "<<unidad;
//cout<<"\n\tCantidad comprada por "<<unidad<<"  : "<<cancomprada;
cout<<"\n\tLugar de Almacen.....:   "<<lugar;
cout<<"\n\tTipo de documento....:   "<<tipoboleta;
//*************************************************************************

do{cout<<"\n\tNumero de Documento........:";gets(numboleta);
                 if(strlen(numboleta)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                }while( strlen(numboleta)>8);
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
cout<<"\n\tCantidad comprada por "<<unidad<<"  : ";cin>>cancomprada;


//***************************************************************************
producto unproducto(cod,grupoproducto,productoespecifico,unidad,lugar,precio,
preciosugerido,fechacompra.dia,fechacompra.mes,fechacompra.year,cancomprada,
numboleta,tipoboleta);
char op2;
do{
   cout<<"\n\nDesea corregir Y/N";op2=getch();

  if(op2==89 ||op2==121){unproducto.change(0); }
   if(op2==78)break;
 }while( op2!= 110);

 objproductos.addproducto(unproducto);
 mensaje("ingreso realizodo satisfactoriamente");
cout<<"\n\n\tEnter para ingresar mas registros ESC para salir";
}
//*************************************************************
//******************************************************************************
//**BUSCAR***BUSCAR***BUSCAR**BUSCAR**BUSCAR**BUSCAR**BUSCAR******************
//****************************************************************************
void gestorproductosA::buscar()
{char bu[30];int tipo;
  do{  clrscr();   cout<<"\n\n\t\t\t\tBUSCA PRODUCTO \n";
                       cout<<"\t\t\t\t--------------\n\n";
    gotoxy(32,10);cout<<"  1.- Codigo";
    gotoxy(32,12);cout<<"  2.- Producto Especifico";
    gotoxy(32,14);cout<<"Esc.- Salir";
    gotoxy(32,16);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1':clrscr();  cout<<"\n\n\t\t\t\tBUSCA PRODUCTO \n";
                       cout<<"\t\t\t\t--------------\n\n";
              do{cout<<"\n\n\n\tCodigo :";gets(bu);

                 if(strlen(bu)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
               }while(strlen(bu)!=8);
               tipo=1;
                debusca(bu,tipo);



				break;

    case '2':clrscr();     cout<<"\n\n\t\t\t\tBUSCA PRODUCTO \n";
                       cout<<"\t\t\t\t--------------\n\n";
    				do{cout<<"\n\n\n\tProducto Especifico..:   ";gets(bu);
                 if(strlen(bu)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
                 }while( strlen(bu)>30);
                 tipo=2;
                 debusca(bu,tipo);
          break;

    }
 }while(op!=sal);
}
//*****************************************************************************
void gestorproductosA::debusca(char bu[30],int tipo){
int q;
 producto uproducto;
  if(tipo==1){q=objproductos.buscacodigo(bu); }
  else{q=objproductos.buscaproducto(bu);}
  q=objproductos.buscacodigo(bu);

             if(q==-1){cout<<"NO EXISTE EL ARCHIVO"; getch();}
             else
             {clrscr();  uproducto=objproductos.getproducto(q);
               int l=uproducto.getla();
              cout<<"\n\tCodigo                 : "<<uproducto.getcodigo();
              cout<<"\n\tProducto Especifico    : "<<uproducto.getproductoespecifico();
              cout<<"\n\tGrupo Producto         : "<<uproducto.getgrupoproducto();
              cout<<"\n\t la                      "<<uproducto.getla()<<"       "<<l;
              double cif=uproducto.getprecio(l),fob=uproducto.getprecio(l)*1.15;
              textcolor(2);
            cprintf("\n\n\rPrecio de Venta    ");cout<<uproducto.getpreciosugerido(l);
              char opotros,opotros2;
              cout<<"\n\notros precios ......Y/N ";opotros=getch();
              if(opotros=='y'||opotros=='Y'){

              cout<<"\n\n\n\tCompra CIF =   "<<cif;
                  cout<<"\t\tCompra FOB =   "<<fob;
              cout<<"\n\n\n0.10 p   =   "<<fob*1.1;cout<<"\t\t\t0.30 p   =   "<<fob*1.3;
              cout<<"\n\n0.50 p   =   "<<fob*1.5;cout<<"\t\t\t  1  p   =   "<<fob*2;
              do{ for(int k=19;k<=25;k++){gotoxy(1,k);clreol();}

              gotoxy(1,19);cout<<"MAS PRECIOS     Y/N";opotros2=getch();
              if(opotros2=='y'||opotros2=='Y'){ double preciosugerido;
              cout<<"\n\n\tIngrese Precio sugerido  ";cin>>preciosugerido;
              if(preciosugerido>=fob){
              if(fob!=0){cout<<"\n\tGanancia de "<<(preciosugerido-fob);
              cout<<"    Representa el "<<(( (preciosugerido-fob)/fob)*100)<<" p" ;}
              }else {if(fob!=0){cout<<"\n\a\a\a\t Este precio representa perdida del "<<(fob-preciosugerido);
              cout<<"    Representa el "<<(( (preciosugerido-fob)/fob)*100)<<"  p";}}
													} getch();
                      }while(opotros2!='n');

              }

				}

}
//**************************************************************************
//***LISTA***LISTA**LISTA***LISTA**LISTA**LISTA****LISTA*****LISTA****LISTA*******
//*****************************************************************************
void gestorproductosA::lista(){

do{  clrscr();   cout<<"\n\n\t\t\t\tLISTA\n";
                     cout<<"\t\t\t\t-----\n\n";
     gotoxy(32,8);cout<<"1.- Fecha";
    gotoxy(32,10);cout<<"2.- Tipo y Numero de Documento";
    gotoxy(32,12);cout<<"3.- Codigo";
    gotoxy(32,14);cout<<"4.- Lista";

    gotoxy(30,18);cout<<"Esc.- Salir";
    op=getch();
    switch(op)
    {
    case '1': listafecha();break;
    case '2': listadoc();break;
    case '3': listacodigo();break;

    case '4': lista4();break;
    }
 }while(op!=sal);


}
//****************************************************************************

//******************************************************************************

//******************************************************************************
void gestorproductosA::listadoc(){producto ulproducto; clrscr();
char *numboleta,*tipoboleta;
char opl;
int p,l,n1=0,y=10,yact=12,t=1;
do{cout<<"\n\tTIPO DE DODUMENTO";

                  	cout<<"\n\t\t\t1.- BOLETA\n";
                     cout<<"\t\t\t2.- FACTURA\n";
                     cout<<"\t\t\t3.- OTROS\n"; opl=getch();
                  switch(opl){
                   case '1': strcpy(tipoboleta,"B");n1=1;break;
                   case '2': strcpy(tipoboleta,"F");n1=1;break;
                   case '3': strcpy(tipoboleta,"SN");n1=1;break;
						}
                 }while(n1!=1);
                 cout<<"\n\n["<<tipoboleta<<"]";
do{cout<<"\tNUMERO DE DOCUMENTO       :";gets(numboleta);
                 if(strlen(numboleta)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                }while( strlen(numboleta)>8);
 clrscr();cout<<"\n\n\t\t["<<tipoboleta<<"]\t\tNumero ...:  "<<numboleta;
 marco(t);


      int la,ve=0;
     for (int i=0;i<objproductos.numproductos();i++)
		       { la=objproductos.buscatiponum2(tipoboleta,numboleta,i);
               if(la!=-1)
                    { ulproducto=objproductos.getproducto(i);
                      dis(y,ulproducto,yact,la,t);
                       y=yact; ve=1;
                    }


             }



 if(la=-1&&ve==0){cout<<"\n\n\nNO EXISTE EL ARCHIVO";}getch();
}
//******************************************************************************
void gestorproductosA::listacodigo(){producto unproducto; clrscr();
char codigo[9];
int y=14,yact;
do{cout<<"\n\n\n\t\tCODIGO        :    ";gets(codigo);
if(strlen(codigo)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
}while(strlen(codigo)!=8);
  int q=objproductos.buscacodigo(codigo);
  if(q==-1){cout<<"\n\n\nNO EXISTE EL ARCHIVO"; getch();}
             else
             {clrscr();
             cout<<"\n\n\t\tCODIGO   :  "<<codigo;
              unproducto=objproductos.getproducto(q);

              cout<<"\n\tProducto Especifico    : "<<unproducto.getproductoespecifico();
              cout<<"\n\tGrupo Producto         : "<<unproducto.getgrupoproducto();
              cout<<"\n\tUnidad                 : "<<unproducto.getunidad();
             marcocodigo();
             for(int l=0;l<=unproducto.getla();l++){
             discodigo(y,unproducto,yact,l);
             y=yact;
             }

             }
 getch();
}
//*****************************************************************************
void gestorproductosA::marcocodigo(){char a1=196,a2=179,a3=193,a4=194,a5=191,a6=180,a7=195,a8=217;
char a9=218,a10=192,a11=197;
int y;

for(int h=1;h<=79;h++){gotoxy(h,8);cout<<a1;gotoxy(h,10);cout<<a1;}
y=8;
gotoxy(1,y);cout<<a9;gotoxy(13,y);cout<<a4;gotoxy(40,y);cout<<a4;gotoxy(50,y);cout<<a4;gotoxy(63,y);cout<<a4;gotoxy(79,y);cout<<a5;
y++;
gotoxy(1,y);cout<<a2;gotoxy(13,y);cout<<a2;gotoxy(40,y);cout<<a2;gotoxy(50,y);cout<<a2;gotoxy(63,y);cout<<a2;gotoxy(79,y);cout<<a2;
y++;
gotoxy(1,y);cout<<a10;gotoxy(13,y);cout<<a3;gotoxy(40,y);cout<<a3;gotoxy(50,y);cout<<a3;gotoxy(63,y);cout<<a3;gotoxy(79,y);cout<<a8;

y=9;
gotoxy(4,y);cout<<" FECHA";
gotoxy(16,y);cout<<"TIPO Y NUM DE DOCUMENTO";
gotoxy(44,y);cout<<"CIF";
//gotoxy(65,y);cout<<"UNIDAD";
gotoxy(54,y);cout<<"CAN COMPRADA";


}
//*****************************************************************************
void gestorproductosA::discodigo(int y,producto pro,int &p,int l){ char a1=196;
if(l!=0)for(int h=1;h<=79;h++){gotoxy(h,y-2);cout<<a1;}
fecha f=pro.getfecha(l);
gotoxy(4,y);cout<<f.dia<<"/"<<f.mes<<"/"<<f.year;
//gotoxy(4,y);cout<<pro.getcodigo();
gotoxy(16,y);cout<<pro.gettipoboleta(l)<<"   "<<pro.getnumboleta(l);
gotoxy(44,y);cout<<pro.getprecio(l);
//gotoxy(65,y);cout<<pro.getunidad();
gotoxy(54,y);cout<<pro.getcancomprada(l);
y=y+2;
p=y+2;


}
//******************************************************************************
void gestorproductosA::lista4(){producto lis4producto;
clrscr();

cout<<"codigo     nombre        grupo            precio"<<"\t"<<objproductos.numproductos();
cout<<"\n\n";
for (int i=0;i<objproductos.numproductos();i++)
{
lis4producto=objproductos.getproducto(i);
cout<<" "<<lis4producto.getcodigo()<<"   "<<lis4producto.getgrupoproducto()<<"  "<<lis4producto.getproductoespecifico()<<"   "<<"\n";
}
getch();



}
//******************************************************************************
void gestorproductosA::marco(int t){ 
char a1=196,a2=179,a3=193,a4=194,a5=191,a6=180,a7=195,a8=217;
char a9=218,a10=192,a11=197;
int y;

for(int h=1;h<=79;h++){gotoxy(h,5);cout<<a1;gotoxy(h,9);cout<<a1;gotoxy(h,7);cout<<a1;}
y=5;
gotoxy(1,y);cout<<a9;gotoxy(13,y);cout<<a4;gotoxy(40,y);cout<<a4;gotoxy(50,y);cout<<a4;gotoxy(63,y);cout<<a4;gotoxy(79,y);cout<<a5;
y++;
gotoxy(1,y);cout<<a2;gotoxy(13,y);cout<<a2;gotoxy(40,y);cout<<a2;gotoxy(50,y);cout<<a2;gotoxy(63,y);cout<<a2;gotoxy(79,y);cout<<a2;
y++;
gotoxy(1,y);cout<<a7;gotoxy(13,y);cout<<a3;gotoxy(40,y);cout<<a11;gotoxy(50,y);cout<<a3;gotoxy(63,y);cout<<a3;gotoxy(79,y);cout<<a6;
y++;
gotoxy(1,y);cout<<a2;gotoxy(40,y);cout<<a2;gotoxy(79,y);cout<<a2;
y++;
gotoxy(1,y);cout<<a10;gotoxy(40,y);cout<<a3;gotoxy(79,y);cout<<a8;
y=6;
gotoxy(4,y);cout<<" CODIGO";
if(t==1){gotoxy(16,y);cout<<"FECHA DE COMPRA"; }
else{gotoxy(16,y);cout<<"TIPO Y NUM DE DOCUMENTO"; }
gotoxy(44,y);cout<<"CIF";
gotoxy(54,y);cout<<"UNIDAD";
gotoxy(65,y);cout<<"CAN COMPRADA";
y=y+2;
gotoxy(3,y);cout<<"\tGRUPO PRODUCTO";
gotoxy(42,y);cout<<"\tPRODUCTO ESPECIFICO";

}
//***********************************************************
void gestorproductosA::dis(int y,producto pro,int &p,int l,int t){
char a1=196;
for(int h=1;h<=79;h++){gotoxy(h,y-1);cout<<a1;}
fecha f=pro.getfecha(l);
gotoxy(4,y);cout<<pro.getcodigo();

if(t==1){gotoxy(16,y);cout<<f.dia<<"/"<<f.mes<<"/"<<f.year; }
else{gotoxy(16,y);cout<<pro.gettipoboleta(l)<<"   "<<pro.getnumboleta(l);  }

gotoxy(44,y);cout<<pro.getprecio(l);
gotoxy(54,y);cout<<pro.getunidad();
gotoxy(65,y);cout<<"    "<<pro.getcancomprada(l);
y=y+2;
p=y+2;
gotoxy(3,y); cout<<pro.getgrupoproducto();
gotoxy(39,y); cout<<"   "<<pro.getproductoespecifico();

/*
gotoxy(4,y);cout<<" CODIGO";
gotoxy(16,y);cout<<"TIPO Y NUM DE DOCUMENTO";
gotoxy(44,y);cout<<"CIF";
gotoxy(54,y);cout<<"UNIDAD";
gotoxy(65,y);cout<<"CAN COMPRADA";
y=y+2;
p=y+2;
gotoxy(3,y);cout<<"\tGRUPO PRODUCTO";
gotoxy(42,y);cout<<"\tPRODUCTO ESPECIFICO";  */

}
//*********************************************************************
void gestorproductosA::listafecha(){  clrscr();
fecha fc;
producto ulproducto;
int p,l;
int y=10,yact=12,t=2;
int con=0;
cout<<"\n\n\n\tFECHA DE COMPRA";
      cout<<"\n\t---------------";
      do{cout<<"\n\t\tDia....: ";gets(fc.dia);
         if(strlen(fc.dia)>2){cout<<"\t\t\aMaximo 2 cifras\n";}
       }while( strlen(fc.dia)>2);
      do{cout<<"\t\tMes....: ";gets(fc.mes);
        if(strlen(fc.mes)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
      }while( strlen(fc.mes)>3);
      do{cout<<"\t\tYear...: ";gets(fc.year);
       if(strlen(fc.year)>4){cout<<"\t\t\aMaximo 4 cifras\n";}
       }while( strlen(fc.year)>4);
clrscr();
cout<<"\n\n\t\t\t\t"<<fc.dia<<" / "<<fc.mes;
cout<<" / "<<fc.year<<"\n\n\n\n";

marco(t);


int la,ve=0;


                  for (int i=0;i<objproductos.numproductos();i++)
                       {
                          la=objproductos.buscafecha(fc,i);
                           if(la!=-1)
                              {
                               ulproducto=objproductos.getproducto(i);
                               dis(y,ulproducto,yact,la,t);
                               y=yact;ve=1;
                              }
                       }
 if(la=-1&&ve==0){cout<<"\n\n\nNO EXISTE EL ARCHIVO";}getch();
}

//***********************************************************************
//*******ELIMINA*******ELIMINA*******ELIMINA****************
//ELIMINA*******ELIMINA*******ELIMINA****************
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
 int l=eproducto.getla();
 eproducto.lista(l);
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
  char codi[9],opmo;
  cout<<"\n\n\t\t\t\tMODIFICA PRODUCTO \n";
      cout<<"\t\t\t\t-----------------\n\n";
      do{cout<<"\tCodigo............:";gets(codi);

                 if(strlen(codi)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
               }while(strlen(codi)!=8);



               int q=objproductos.buscacodigo(codi);

             if(q==-1){textcolor(2);cprintf("\r               NO EXISTE EL ARCHIVO");getch();}
             else{   producto uproducto=objproductos.getproducto(q);
               int l=uproducto.getla();
               int nn=l;
               cout<<"\n\n\tEl Numero de Modificacion es :"<<l<<"Desea Cambiarlo? Y/N ";
               opmo=getch();
               if(opmo=='y'||opmo=='Y')
               {do{cout<<"\n\n\tIngrese Nuevo Numero  :  ";cin>>l; }while(l>=nn+1||l<0);
               }

              uproducto.lista(l);
              char op2; do{
   cout<<"\n\nDesea corregir Y/N";op2=getch();

  if(op2==89 ||op2==121){uproducto.change(l); }
   if(op2==78)break;
 }while( op2!= 110);

    objproductos.setproducto(uproducto,q);
 mensaje("Modificacion realizado satisfactoriamente");getch();

             }


}





