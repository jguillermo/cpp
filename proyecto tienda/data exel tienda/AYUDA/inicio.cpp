#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include <ctype.h>
#define sal 27

struct fecha{
char dia[3], mes[8], year[5];
};

struct producto{
char codigo[12];
char nombre[30];
char grupo[12];
char especifico[20];
char unidad[8];
double almacen;
double precio;
char lugar[10];
fecha fechacompra;
};

fstream datosproducto;
producto inicioproducto,temporal;
long nproductos;
long tproducto=sizeof(inicioproducto);
char op;
//apertura de archivo***************************************************//*
apertura_producto(){                                                    //*
datosproducto.open("tiendaarchivos.txt",ios::in|ios::out|ios::binary);  //*
if(datosproducto.bad()){                                                //*
      cout<<"\tError no se puede abrir el archivo";                     //*
      getch();                                                          //*
      exit(1);                                                          //*
      }                                                                 //*
 datosproducto.seekg(0L,ios::end);                                      //*
 nproductos=datosproducto.tellg()/tproducto;                            //*
}                                                                       //*
//**********************************************************************//*

//funcion crear item
corregir(producto corrige);
void ingreso_producto();
void lista(producto produ);
//funcion buscar
void buscar();
main ()
{
   do{  clrscr();   cout<<"\n\n\t\t\t\tTIENDA GUILLE\n";
                cout<<"\t\t\t\t-------------\n\n";
    gotoxy(32,8);cout<<"1.- crear Item";
    gotoxy(32,10);cout<<"2.- Buscar";
    gotoxy(32,12);cout<<"3.- Modificar";
    gotoxy(32,14);cout<<"4.- Lista";
    gotoxy(32,16);cout<<"4.- Salir";
    gotoxy(32,18);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1': ingreso_producto();break;
    case '2': buscar();break;
    //case '3': buscar_Curso();break;
    }
 }while(op!='4');
}
//******************************************************************************
void ingreso_producto(){
char op1,op2;producto corrige;
int cuenta =0;
do{clrscr();
 cout<<"\n\tINGRESO DE PRODUCTOS";
cout<<"\n\t--------------------\n\n";
cout<<"Para salir ESC";op=getch();if(op==sal)break; gotoxy(1,5);clreol();
cuenta++;

apertura_producto();



do{cout<<"\tCodigo............:";gets(inicioproducto.codigo);
if(strlen(inicioproducto.codigo)>12){cout<<"\t\aMaximo 12 cifras\n";}
}while( strlen(inicioproducto.codigo)>12);

do{cout<<"\tNombre............:";gets(inicioproducto.nombre);
if(strlen(inicioproducto.nombre)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
}while( strlen(inicioproducto.nombre)>30);

do{cout<<"\tGrupo.............:";gets(inicioproducto.grupo);
if(strlen(inicioproducto.grupo)>12){cout<<"\t\t\aMaximo 12 cifras\n";}
}while( strlen(inicioproducto.grupo)>12);

do{cout<<"\tEspecifico........:";gets(inicioproducto.especifico);
if(strlen(inicioproducto.especifico)>20){cout<<"\t\t\aMaximo 20 cifras\n";}
}while( strlen(inicioproducto.especifico)>20);

do{cout<<"\tUnidad............:";gets(inicioproducto.unidad);
if(strlen(inicioproducto.unidad)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
}while( strlen(inicioproducto.unidad)>8);

do{cout<<"\tLugar de almacen..:";gets(inicioproducto.lugar);
if(strlen(inicioproducto.lugar)>10){cout<<"\t\t\aMaximo 10 cifras\n";}
}while( strlen(inicioproducto.lugar)>10);

cout<<"\tFecha de compra........:";
      do{cout<<"\n\t\tDia....: ";gets(inicioproducto.fechacompra.dia);
         if(strlen(inicioproducto.fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
       }while( strlen(inicioproducto.fechacompra.dia)>3);
      do{cout<<"\t\tMes....: ";gets(inicioproducto.fechacompra.mes);
        if(strlen(inicioproducto.fechacompra.mes)>10){cout<<"\t\t\aMaximo 8 cifras\n";}
      }while( strlen(inicioproducto.fechacompra.mes)>8);
      do{cout<<"\t\tYear....: ";gets(inicioproducto.fechacompra.year);
       if(strlen(inicioproducto.fechacompra.year)>10){cout<<"\t\t\aMaximo 5 cifras\n";}
       }while( strlen(inicioproducto.fechacompra.year)>10);
cout<<"\n\t\t"<<inicioproducto.fechacompra.dia<<" / "<<inicioproducto.fechacompra.mes;
cout<<" / "<<inicioproducto.fechacompra.year<<"\n\n";
cout<<"\tAlmacen ........:";cin>>inicioproducto.almacen;

cout<<"\tPrecio ........:";cin>>inicioproducto.precio;

cout<<"\tPresio Unitario.....:"<<(inicioproducto.almacen/inicioproducto.precio);
do{
   cout<<"\n\nDesea corregir Y/N";op2=getch();

  if(op2==121){corregir(inicioproducto); }

 }while(op2!=110);
datosproducto.write((char *)& inicioproducto,tproducto);
nproductos++;
cout<<"\n\n\tEnter para ingresar mas registros ESC para salir";
op=getch();
datosproducto.close();
}while(op!=sal);
}
//*******************************************************************************

corregir(producto corrige){

clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista (inicioproducto);

cout<<"\n\nIngrese Opcion   :";
    op=getch();
     switch(op)
     {case'1': do{cout<<"\tCodigo............:";gets(inicioproducto.codigo);
                if(strlen(inicioproducto.codigo)>12){cout<<"\t\aMaximo 12 cifras\n";}
               }while( strlen(inicioproducto.codigo)>12); break;
      case'2': do{cout<<"\tNombre............:";gets(inicioproducto.nombre);
               if(strlen(inicioproducto.nombre)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
               }while( strlen(inicioproducto.nombre)>30); break;
      case'3':  do{cout<<"\tGrupo.............:";gets(inicioproducto.grupo);
                if(strlen(inicioproducto.grupo)>12){cout<<"\t\t\aMaximo 12 cifras\n";}
                 }while( strlen(inicioproducto.grupo)>12); break;
      case'4':  do{cout<<"\tEspecifico........:";gets(inicioproducto.especifico);
                 if(strlen(inicioproducto.especifico)>20){cout<<"\t\t\aMaximo 20 cifras\n";}
                }while( strlen(inicioproducto.especifico)>20); break;
      case'5':  do{cout<<"\tUnidad............:";gets(inicioproducto.unidad);
                if(strlen(inicioproducto.unidad)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                  }while( strlen(inicioproducto.unidad)>8);break;
      case'6': do{cout<<"\tLugar de almacen..:";gets(inicioproducto.lugar);
               if(strlen(inicioproducto.lugar)>10){cout<<"\t\t\aMaximo 10 cifras\n";}
                }while( strlen(inicioproducto.lugar)>10);break;
      case'7': cout<<"\tFecha de compra........:";
                do{cout<<"\n\t\tDia....: ";gets(inicioproducto.fechacompra.dia);
              	 if(strlen(inicioproducto.fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
              	 }while( strlen(inicioproducto.fechacompra.dia)>3);
                do{cout<<"\t\tMes....: ";gets(inicioproducto.fechacompra.mes);
      	  			if(strlen(inicioproducto.fechacompra.mes)>10){cout<<"\t\t\aMaximo 8 cifras\n";}
      				}while( strlen(inicioproducto.fechacompra.mes)>8);
     					 do{cout<<"\t\tYear....: ";gets(inicioproducto.fechacompra.year);
      			 if(strlen(inicioproducto.fechacompra.year)>10){cout<<"\t\t\aMaximo 5 cifras\n";}
      			 }while( strlen(inicioproducto.fechacompra.year)>10);
     					cout<<"\n\t\t"<<inicioproducto.fechacompra.dia<<" / "<<inicioproducto.fechacompra.mes;
            	 cout<<" / "<<inicioproducto.fechacompra.year<<"\n\n";  break;
      case'8': cout<<"\tAlmacen ........:";cin>>inicioproducto.almacen; break;
      case'9': cout<<"\tPrecio ........:";cin>>inicioproducto.precio; break;

     }
     clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista (inicioproducto);

}
void lista(producto produ){
  cout<<"\n     1.- Codigo.............:   "<<inicioproducto.codigo<<endl;
cout<<"\n     2.- Nombre.............:   "<<inicioproducto.nombre<<endl;
cout<<"\n     3.- Grupo..............:   "<<inicioproducto.grupo<<endl;
cout<<"\n     4.- Especifico.........:   "<<inicioproducto.especifico<<endl;
cout<<"\n     5.- Unidad.............:   "<<inicioproducto.unidad<<endl;
cout<<"\n     6.- Lugar de Almacen...:   "<<inicioproducto.lugar<<endl;
cout<<"\n     7.- Fecha de compra....:   ";
cout<<inicioproducto.fechacompra.dia<<" / "<<inicioproducto.fechacompra.mes;
cout<<" / "<<inicioproducto.fechacompra.year<<"\n";
cout<<"\n     8.- Almacen............:   "<<inicioproducto.almacen<<endl;
cout<<"\n     9.- Precio Unitario....:   "<<inicioproducto.precio<<endl;
cout<<"\n\tPresio Unitario.....:"<<(inicioproducto.almacen/inicioproducto.precio);
cout<<"\n\n";

}
//******************************************************************************
// funciones buscar ------------------------------------------------------------
//******************************************************************************
void buscar(){
 char opb,tem[15];

   do{ clrscr();cout<<"\n\t\t\t\tBUSCAR PRODUCTO\n";
            cout<<"\t\t\t\t---------------\n\n";
    gotoxy(35,8); cout<<"  1.- Codigo";
    gotoxy(35,10);cout<<"  2.- Nombre";
    gotoxy(35,12);cout<<"Esc.- Salir";
    gotoxy(35,14);cout<<"ingrese opcion";opb=getch();
    clrscr();
    switch(opb)
    {
    case '1':clrscr();cout<<"\n\n\n\tCodigo :";gets(tem);
             do{datosproducto.read((unsigned char*)&inicioproducto,sizeof(inicioproducto));
             }while((!datosproducto.eof())&&strcmp(tem,inicioproducto.codigo)!=0);
             if(strcmp(tem,inicioproducto.codigo)==0)
             {gotoxy(30,2);cout<<"REGISTRO HALLADO";
              gotoxy(30,4);cout<<"Codigo    : "<<inicioproducto.codigo;
              gotoxy(30,6);cout<<"Nombre    : "<<inicioproducto.nombre;
              gotoxy(15,7);cout<<"Precio "<<inicioproducto.precio;
               gotoxy(30,8);cout<<"10%  =  "<<(inicioproducto.precio*1.1);cout<<"    100%  =  "<<(inicioproducto.precio*2);
              gotoxy(30,10);cout<<"20%  =  "<<(inicioproducto.precio*1.2);cout<<"    110%  =  "<<(inicioproducto.precio*2.1);
              gotoxy(30,12);cout<<"30%  =  "<<(inicioproducto.precio*1.3);cout<<"    120%  =  "<<(inicioproducto.precio*2.2);
              gotoxy(30,14);cout<<"40%  =  "<<(inicioproducto.precio*1.4);cout<<"    130%  =  "<<(inicioproducto.precio*2.3);
              gotoxy(30,16);cout<<"50%  =  "<<(inicioproducto.precio*1.5);cout<<"    140%  =  "<<(inicioproducto.precio*2.4);
              gotoxy(30,18);cout<<"60%  =  "<<(inicioproducto.precio*1.6);cout<<"    150%  =  "<<(inicioproducto.precio*2.5);
              gotoxy(30,20);cout<<"70%  =  "<<(inicioproducto.precio*1.7);cout<<"    180%  =  "<<(inicioproducto.precio*2.8);
              gotoxy(30,22);cout<<"80%  =  "<<(inicioproducto.precio*1.8);cout<<"    200%  =  "<<(inicioproducto.precio*3);
              gotoxy(30,24);cout<<"90%  =  "<<(inicioproducto.precio*1.9);cout<<"    300%  =  "<<(inicioproducto.precio*4);

				}

            else cout<<"REGISTRO NO HALLADO";
            getch();break;
    case '2': clrscr();cout<<"\n\n\n\tNombre :";gets(tem);
             do{datosproducto.read((unsigned char*)&inicioproducto,sizeof(inicioproducto));
             }while((!datosproducto.eof())&&strcmp(tem,inicioproducto.nombre)!=0);
             if(strcmp(tem,inicioproducto.nombre)==0)
             {gotoxy(30,2);cout<<"REGISTRO HALLADO";
              gotoxy(30,4);cout<<"Codigo    : "<<inicioproducto.codigo;
              gotoxy(30,6);cout<<"Nombre    : "<<inicioproducto.nombre;
              gotoxy(15,7);cout<<"Precio "<<inicioproducto.precio;
               gotoxy(30,8);cout<<"10%  =  "<<(inicioproducto.precio*1.1);cout<<"    100%  =  "<<(inicioproducto.precio*2);
              gotoxy(30,10);cout<<"20%  =  "<<(inicioproducto.precio*1.2);cout<<"    110%  =  "<<(inicioproducto.precio*2.1);
              gotoxy(30,12);cout<<"30%  =  "<<(inicioproducto.precio*1.3);cout<<"    120%  =  "<<(inicioproducto.precio*2.2);
              gotoxy(30,14);cout<<"40%  =  "<<(inicioproducto.precio*1.4);cout<<"    130%  =  "<<(inicioproducto.precio*2.3);
              gotoxy(30,16);cout<<"50%  =  "<<(inicioproducto.precio*1.5);cout<<"    140%  =  "<<(inicioproducto.precio*2.4);
              gotoxy(30,18);cout<<"60%  =  "<<(inicioproducto.precio*1.6);cout<<"    150%  =  "<<(inicioproducto.precio*2.5);
              gotoxy(30,20);cout<<"70%  =  "<<(inicioproducto.precio*1.7);cout<<"    180%  =  "<<(inicioproducto.precio*2.8);
              gotoxy(30,22);cout<<"80%  =  "<<(inicioproducto.precio*1.8);cout<<"    200%  =  "<<(inicioproducto.precio*3);
              gotoxy(30,24);cout<<"90%  =  "<<(inicioproducto.precio*1.9);cout<<"    300%  =  "<<(inicioproducto.precio*4);

				}

            else cout<<"REGISTRO NO HALLADO";
            getch();break;

    }
 }while(opb!=sal);

}





































