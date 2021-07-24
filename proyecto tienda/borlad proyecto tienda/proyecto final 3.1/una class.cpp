#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include <ctype.h>
#define sal 27

char op;
struct fecha{
char dia[3], mes[8], year[5];
};
//******************************************************************************
class producto{
private:
char codigo[12];
char nombre[30];
char grupo[12];
char especifico[20];
char unidad[8];
char lugar[10];
double almacen;
double precio;
fecha fechacompra;

public:
producto(){}
producto(char *cod,char *nomb,char *grup,char *espes,char *unin,
char *lug,double alm,double pre,char *di,char *me,char *yea){
strcpy(codigo,cod);
strcpy(nombre,nomb);
strcpy(grupo,grup);
strcpy(especifico,espes);
strcpy(unidad,unin);
strcpy(lugar,lug);
almacen=alm;
precio=pre;
strcpy(fechacompra.dia,di);
strcpy(fechacompra.mes,me);
strcpy(fechacompra.year,yea);
}
void setcodigo(char *cod){strcpy(codigo,cod);}
void setnombre(char *nomb){strcpy(nombre,nomb);}
void setgrupo(char *grup){strcpy(grupo,grup);}
void setespecifico(char *espes){strcpy(especifico,espes);}
void setunidad(char *unin){strcpy(unidad,unin);}
void setlugar(char *lug){strcpy(lugar,lug);}
void setalmacen(double alm){almacen=alm;}
void setprecio(double pre){precio=pre;}
void setfecha(char *di,char *me,char *yea){strcpy(fechacompra.dia,di);
                                        strcpy(fechacompra.mes,me);
                                        strcpy(fechacompra.year,yea);}
char *getcodigo(){return codigo;}
char *getnombre(){return nombre;}
char *getgrupo(){return grupo;}
char *getespecifico(){return especifico;}
char *getunidad(){return unidad;}
char *getlugar(){return lugar;}
double getalmacen(){return almacen;}
double getprecio(){return precio;}
fecha getfecha(){return fechacompra;}
void change();
void lista();

};
class productoA{
private:
fstream archivo;
producto unproducto;
int n,tamreg,error;

public:
productoA(){
archivo.open("producto.dat",ios::in|ios::out|ios::binary);
if (!archivo){error=1;}
else {
 error=0;
     tamreg=sizeof(unproducto);
     archivo.seekg(0,ios::end);
     n=archivo.tellg()/tamreg;
     }
}
~productoA(){ if(!error) archivo.close();}

void addproducto(producto obj){
archivo.seekp(0,ios::end);
archivo.write((char*)& obj,tamreg);
n++;
}

producto getproducto(int i){
archivo.seekg(i*tamreg,ios::beg);
archivo.read((char*)&unproducto,tamreg);
return unproducto;
}

void setproducto(producto obj,int i){
archivo.seekp(i*tamreg,ios::beg);
archivo.write((char*)&obj,tamreg);
}

int numproductos(){return n;}

int buscaproducto(char *busca){producto productoleido;



for (int p=0;p<n;p++){

archivo.seekg(p*tamreg,ios::beg);
archivo.read((char*)&productoleido,tamreg);
if(strcmp(productoleido.getcodigo(),busca)==0)return p;
if(strcmp(productoleido.getnombre(),busca)==0)return p;
if(strcmp(productoleido.getgrupo(),busca)==0)return p;
}
return -1;
}
};
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
 void mensaje(char *m){cout<<endl<<m<<endl;}
};


//*****************************************************************************
void main(){
gestorproductosA objgestor;
objgestor.ejecuta();
}
//******************************************************************************












void producto::change(){char op;
 clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista ();

cout<<"\n\nIngrese Opcion   :";
    op=getch();
     switch(op)
     {case'1': do{cout<<"\tCodigo............:";gets(codigo);
                if(strlen(codigo)>12){cout<<"\t\aMaximo 12 cifras\n";}
               }while( strlen(codigo)>12); break;
      case'2': do{cout<<"\tNombre............:";gets(nombre);
               if(strlen(nombre)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
               }while( strlen(nombre)>30); break;
      case'3':  do{cout<<"\tGrupo.............:";gets(grupo);
                if(strlen(grupo)>12){cout<<"\t\t\aMaximo 12 cifras\n";}
                 }while( strlen(grupo)>12); break;
      case'4':  do{cout<<"\tEspecifico........:";gets(especifico);
                 if(strlen(especifico)>20){cout<<"\t\t\aMaximo 20 cifras\n";}
                }while( strlen(especifico)>20); break;
      case'5':  do{cout<<"\tUnidad............:";gets(unidad);
                if(strlen(unidad)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                  }while( strlen(unidad)>8);break;
      case'6': do{cout<<"\tLugar de almacen..:";gets(lugar);
               if(strlen(lugar)>10){cout<<"\t\t\aMaximo 10 cifras\n";}
                }while( strlen(lugar)>10);break;
      case'7': cout<<"\tFecha de compra........:";
                do{cout<<"\n\t\tDia....: ";gets(fechacompra.dia);
              	 if(strlen(fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
              	 }while( strlen(fechacompra.dia)>3);
                do{cout<<"\t\tMes....: ";gets(fechacompra.mes);
      	  			if(strlen(fechacompra.mes)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
      				}while( strlen(fechacompra.mes)>8);
     					 do{cout<<"\t\tYear....: ";gets(fechacompra.year);
      			 if(strlen(fechacompra.year)>5){cout<<"\t\t\aMaximo 5 cifras\n";}
      			 }while( strlen(fechacompra.year)>5);
     					cout<<"\n\t\t"<<fechacompra.dia<<" / "<<fechacompra.mes;
            	 cout<<" / "<<fechacompra.year<<"\n\n";  break;
                  case'8': cout<<"\tAlmacen ........:";cin>>almacen; break;
      case'9': cout<<"\tPrecio ........:";cin>>precio; break;
      }
     clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista ();

}


//*************************************************************************
void producto::lista(){
  cout<<"\n     1.- Codigo.............:   "<<codigo<<endl;
cout<<"\n     2.- Nombre.............:   "<<nombre<<endl;
cout<<"\n     3.- Grupo..............:   "<<grupo<<endl;
cout<<"\n     4.- Especifico.........:   "<<especifico<<endl;
cout<<"\n     5.- Unidad.............:   "<<unidad<<endl;
cout<<"\n     6.- Lugar de Almacen...:   "<<lugar<<endl;
cout<<"\n     7.- Fecha de compra....:   ";
cout<<fechacompra.dia<<" / "<<fechacompra.mes;
cout<<" / "<<fechacompra.year<<"\n";
cout<<"\n     8.- Almacen............:   "<<almacen<<endl;
cout<<"\n     9.- Precio Unitario....:   "<<precio<<endl;
cout<<"\n\tPresio Unitario.....:"<<(almacen/precio);
cout<<"\n\n";
}
//*************************************************************************

void gestorproductosA::ejecuta(){
 do{  clrscr();   cout<<"\n\n\t\t\t\tTIENDA GUILLE\n";
                cout<<"\t\t\t\t-------------\n\n";
    gotoxy(32,8);cout<<"1.- crear Item";
    gotoxy(32,10);cout<<"2.- Buscar";
    gotoxy(32,12);cout<<"3.- Lista";
    gotoxy(32,16);cout<<"4.- Salir";
    gotoxy(32,18);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1': ingreso_producto();break;
    case '2': buscar();break;
    case '3': lista1();break;
    }
 }while(op!='4');
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
if(strlen(codigo)>12){cout<<"\t\aMaximo 12 cifras\n";}
}while( strlen(codigo)>12);
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

