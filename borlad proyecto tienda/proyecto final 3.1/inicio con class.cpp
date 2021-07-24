/*  adicionar codigo del fabricante debe preguntar ingresar y/n
    modificar :
   nombre to nombre del producto
   grupo especifico
   almacen to cantidad comprada
   precio incluir unidad




  */
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include <ctype.h>
#define sal 27
#include "producto.h"
#include "productoa.h"
char op;



//*****************************************************************************
class gestorproductosA {
private:
 productoA objproductos;

 public:
 void ejecuta();
  int h;
  gestorproductosA(){h=0;}
 private:

 void ingreso_producto();
 void lista1();
 void buscar();
 void elimina();
 void mensaje(char *m){cout<<endl<<m<<endl;}
};


//*****************************************************************************
void main(){
gestorproductosA objgestor;
objgestor.ejecuta();
}
//******************************************************************************
void gestorproductosA::ejecuta(){
 do{  clrscr();   cout<<"\n\n\t\t\t\tTIENDA GUILLE\n";
                cout<<"\t\t\t\t-------------\n\n";
    gotoxy(32,8);cout<<"1.- crear Item";
    gotoxy(32,10);cout<<"2.- Buscar";
    gotoxy(32,12);cout<<"3.- Lista";
    gotoxy(32,14);cout<<"4.- Elimina";
    gotoxy(32,16);cout<<"7.- Salir";
    gotoxy(32,18);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1': ingreso_producto();break;
    case '2': buscar();break;
    case '3': lista1();break;
    case '4': elimina();break;
    }
 }while(op!='7');
}
//******************************************************************************
void gestorproductosA::ingreso_producto(){
char codigo[12];
char nombre[30];
char grupo[12];
char especifico[20];
char unidad[8];
char lugar[10];
double almacen;
double precio;
fecha fechacompra;
char tem1[3],tem2[8],tem3[5];
do{clrscr();
 cout<<"\n\tINGRESO DE PRODUCTOS";
if(h==1){gotoxy(40,2);cout<<"         Fecha : "<<tem1<<" / "<<tem2<<" / "<<tem3;}
cout<<"\n\t--------------------\n\n";
cout<<"Para salir ESC";op=getch();if(op==sal)break; gotoxy(1,5);clreol();

 do{cout<<"\tCodigo............:";gets(codigo);
if(strlen(codigo)!=8){cout<<"\t\aDebe tener 8 cifras\n";}
}while( strlen(codigo)!=8);
int p=objproductos.buscaproducto(codigo);
if (p!=-1)mensaje("Codigo ya esxiste");

do{cout<<"\tNombre............:";gets(nombre);
if(strlen(nombre)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
}while( strlen(nombre)>30);

do{cout<<"\tGrupo.............:";gets(grupo);
if(strlen(grupo)>12){cout<<"\t\t\aMaximo 12 cifras\n";}
}while( strlen(grupo)>12);

do{cout<<"\tEspecifico........:";gets(especifico);
if(strlen(especifico)>20){cout<<"\t\t\aMaximo 20 cifras\n";}
}while( strlen(especifico)>20);

do{cout<<"\tUnidad............:";gets(unidad);
if(strlen(unidad)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
}while( strlen(unidad)>8);

do{cout<<"\tLugar de almacen..:";gets(lugar);
if(strlen(lugar)>10){cout<<"\t\t\aMaximo 10 cifras\n";}
}while( strlen(lugar)>10);
char fe;
cout<<"\tFecha de compra........:  ";
if(h==1){cout<<" cambiar fecha?  Y/N ";fe=getch();}
else {h=1;fe='y';}

if (fe=='y'||fe=='Y'){
      do{cout<<"\n\t\tDia....: ";gets(fechacompra.dia);
         if(strlen(fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
       }while( strlen(fechacompra.dia)>3);
      do{cout<<"\t\tMes....: ";gets(fechacompra.mes);
        if(strlen(fechacompra.mes)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
      }while( strlen(fechacompra.mes)>8);
      do{cout<<"\t\tYear....: ";gets(fechacompra.year);
       if(strlen(fechacompra.year)>5){cout<<"\t\t\aMaximo 5 cifras\n";}
       }while( strlen(fechacompra.year)>5);
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
cout<<"\tAlmacen ........:";cin>>almacen;
cout<<"\tPrecio ........:";cin>>precio;

cout<<"\tPresio Unitario.....:"<<(almacen/precio);

producto unproducto(codigo,nombre,grupo,especifico,unidad,lugar,almacen,precio,fechacompra.dia,fechacompra.mes,fechacompra.year);
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




//******************************************************************************
//**BUSCAR***BUSCAR***BUSCAR**BUSCAR**BUSCAR**BUSCAR**BUSCAR******************
//****************************************************************************
void gestorproductosA::buscar()
{char bu[15];  int q;
 producto uproducto;
  do{  clrscr();   cout<<"\n\n\t\t\t\tBUSCA PRODUCTO \n";
                       cout<<"\t\t\t\t--------------\n\n";
    gotoxy(32,10);cout<<"  1.- Codigo";
    gotoxy(32,12);cout<<"  2.- Nombre";
    gotoxy(32,14);cout<<"Esc.- Salir";
    gotoxy(32,16);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1':clrscr();cout<<"\n\n\n\tCodigo :";gets(bu);
               q=objproductos.buscaproducto(bu);
                uproducto=objproductos.getproducto(q);
             if(q==-1)cout<<"NO EXISTE EL ARCHIVO";
             else
             {gotoxy(30,2);cout<<"REGISTRO HALLADO";
              gotoxy(30,4);cout<<"Codigo    : "<<uproducto.getcodigo();
              gotoxy(30,6);cout<<"Nombre    : "<<uproducto.getnombre();
              gotoxy(15,7);cout<<"Precio "<<uproducto.getprecio();
               gotoxy(30,8);cout<<"10%  =  "<<(uproducto.getprecio()*1.1);cout<<"    100%  =  "<<(uproducto.getprecio()*2);
              gotoxy(30,10);cout<<"20%  =  "<<(uproducto.getprecio()*1.2);cout<<"    110%  =  "<<(uproducto.getprecio()*2.1);
              gotoxy(30,12);cout<<"30%  =  "<<(uproducto.getprecio()*1.3);cout<<"    120%  =  "<<(uproducto.getprecio()*2.2);
              gotoxy(30,14);cout<<"40%  =  "<<(uproducto.getprecio()*1.4);cout<<"    130%  =  "<<(uproducto.getprecio()*2.3);
              gotoxy(30,16);cout<<"50%  =  "<<(uproducto.getprecio()*1.5);cout<<"    140%  =  "<<(uproducto.getprecio()*2.4);
              gotoxy(30,18);cout<<"60%  =  "<<(uproducto.getprecio()*1.6);cout<<"    150%  =  "<<(uproducto.getprecio()*2.5);
              gotoxy(30,20);cout<<"70%  =  "<<(uproducto.getprecio()*1.7);cout<<"    180%  =  "<<(uproducto.getprecio()*2.8);
              gotoxy(30,22);cout<<"80%  =  "<<(uproducto.getprecio()*1.8);cout<<"    200%  =  "<<(uproducto.getprecio()*3);
              gotoxy(30,24);cout<<"90%  =  "<<(uproducto.getprecio()*1.9);cout<<"    300%  =  "<<(uproducto.getprecio()*4);

				}
				getch();break;

    case '2':clrscr();cout<<"\n\n\n\tNombre :";gets(bu);
               q=objproductos.buscaproducto(bu);
                uproducto=objproductos.getproducto(q);
             if(q==-1)cout<<"NO EXISTE EL ARCHIVO";
             else
             {gotoxy(30,2);cout<<"REGISTRO HALLADO";
              gotoxy(30,4);cout<<"Codigo    : "<<uproducto.getcodigo();
              gotoxy(30,6);cout<<"Nombre    : "<<uproducto.getnombre();
              gotoxy(15,7);cout<<"Precio "<<uproducto.getprecio();
               gotoxy(30,8);cout<<"10%  =  "<<(uproducto.getprecio()*1.1);cout<<"    100%  =  "<<(uproducto.getprecio()*2);
              gotoxy(30,10);cout<<"20%  =  "<<(uproducto.getprecio()*1.2);cout<<"    110%  =  "<<(uproducto.getprecio()*2.1);
              gotoxy(30,12);cout<<"30%  =  "<<(uproducto.getprecio()*1.3);cout<<"    120%  =  "<<(uproducto.getprecio()*2.2);
              gotoxy(30,14);cout<<"40%  =  "<<(uproducto.getprecio()*1.4);cout<<"    130%  =  "<<(uproducto.getprecio()*2.3);
              gotoxy(30,16);cout<<"50%  =  "<<(uproducto.getprecio()*1.5);cout<<"    140%  =  "<<(uproducto.getprecio()*2.4);
              gotoxy(30,18);cout<<"60%  =  "<<(uproducto.getprecio()*1.6);cout<<"    150%  =  "<<(uproducto.getprecio()*2.5);
              gotoxy(30,20);cout<<"70%  =  "<<(uproducto.getprecio()*1.7);cout<<"    180%  =  "<<(uproducto.getprecio()*2.8);
              gotoxy(30,22);cout<<"80%  =  "<<(uproducto.getprecio()*1.8);cout<<"    200%  =  "<<(uproducto.getprecio()*3);
              gotoxy(30,24);cout<<"90%  =  "<<(uproducto.getprecio()*1.9);cout<<"    300%  =  "<<(uproducto.getprecio()*4);

				}


            getch();break;

    }
 }while(op!=sal);
}
//*****************************************************************************
//***LISTA***LISTA**LISTA***LISTA**LISTA**LISTA****LISTA*****LISTA****LISTA*******
//*****************************************************************************
void gestorproductosA::lista1(){producto unproducto;
clrscr();
//cprintf("%-12s%-30s%-12%-10s\n","codigo","nombre","grupo","precio");
cout<<"codigo     nombre        grupo            precio";cout<<objproductos.numproductos()<<"\n\n";
for (int i=0;i<objproductos.numproductos();i++)
{
unproducto=objproductos.getproducto(i);
cout<<" "<<unproducto.getcodigo()<<"   "<<unproducto.getnombre()<<"  "<<unproducto.getgrupo()<<"   "<<unproducto.getprecio()<<"\n";
}
getch();
}
//*****************************************************************************
//***ELIMINA*ELIMINA**ELIMINA**ELIMINA**ELIMINA**ELIMINA***ELIMINA***ELIMINA***
//*****************************************************************************
void gestorproductosA::elimina(){
/*char bue[15],ope,ope1;  int qe,pe;
 producto uproductoe;
 do{  clrscr();    cout<<"\n\n\t\t\t\tELIMINA PRODUCTO \n";
                       cout<<"\t\t\t\t----------------\n\n";
    gotoxy(32,10);cout<<"  1.- Codigo";
    gotoxy(32,12);cout<<"  2.- Nombre";
    gotoxy(32,14);cout<<"Esc.- Salir";
    gotoxy(32,16);cout<<"ingrese opcion   ";ope1=getch();
    switch(ope1)
    {case '1':clrscr();cout<<"\n\n\n\tCodigo :";gets(bue);
               qe=objproductos.buscaproducto(bue);
                uproductoe=objproductos.getproducto(qe);
             if(qe==-1)cout<<"NO EXISTE EL ARCHIVO";
             else
             { gotoxy(30,2);cout<<"REGISTRO HALLADO";
             	//****************************
						cout<<"\n     1.- Codigo.............:   "<<uproductoe.getcodigo()<<endl;
						cout<<"\n     2.- Nombre.............:   "<<uproductoe.getnombre()<<endl;
						cout<<"\n     3.- Grupo..............:   "<<uproductoe.getgrupo()<<endl;
						cout<<"\n     4.- Especifico.........:   "<<uproductoe.getespecifico()<<endl;
						cout<<"\n     5.- Unidad.............:   "<<uproductoe.getunidad()<<endl;
						cout<<"\n     6.- Lugar de Almacen...:   "<<uproductoe.getlugar()<<endl;
						cout<<"\n     7.- Fecha de compra....:   ";
                  cout<<uproductoe.getfecha().dia<<" / "<<uproductoe.getfecha().mes;
						cout<<" / "<<uproductoe.getfecha().year<<"\n";
						cout<<"\n     8.- Almacen............:   "<<uproductoe.getalmacen()<<endl;
						cout<<"\n     9.- Precio Unitario....:   "<<uproductoe.getprecio()<<endl;
						cout<<"\n\tPresio Unitario.....:"<<(uproductoe.getalmacen()/uproductoe.getprecio());
						cout<<"\n\n";
                  cout<<"CONFIRMA QUE DESEA ELIMINAR Y/N";
                  //ope=getch();
                  //cout<<ope;getch();
              int y;cout<<"y";cin>>y;
              if(y==1)
              {
                        fstream otro;
              				otro.open("auxiliar.dat",ios::out|ios::binary);

              				for (int i=0;i<objproductos.numproductos();i++)
                        		{if (i=!qe)
                                 {
                                 producto elimina=objproductos.getproducto(i);
                                  otro.write((char*)&elimina,sizeof(elimina));
                       				}
                 				   }
              		otro.close();
              		fstream entrada,salida;
              		entrada.open("auxiliar.dat",ios::in|ios::binary);
              		salida.open("producto.dat",ios::out|ios::binary);
              		producto uno;
                  while(!entrada.eof())
              				{
               				entrada.read((char *)&uno, sizeof(uno));
			       				salida.write((char *)&uno, sizeof(uno));
             			   }
             		 entrada.close();
		      		  salida.close();
            		  objproductos.setN(objproductos.numproductos()-1);
                    mensaje("Eliminacion realizada satisfactoriamente");getch();
					}


             }break;
    //case '2':
    }
    }while(ope1!=sal); */
 }



