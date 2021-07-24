#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include <ctype.h>

respuestas(double a[8][9],int n);
cargar(double a[8][9],int n);
resolver1(double a[8][9],int n);
resolver2(double a[8][9],int n);
//drawxy();
titulo();
introduccion();
double contrasena();
limpiar_menu();
corregir(double a[8][9],int n);
int pedirecuacion();
//error();
//ecuacion();
 int ancho=7;
void main()
{
 double a[8][9];
 int n,i,np,j,m,y=5,xc,yc,cc;
 double fc,bg,te,sm,com;
 char op;
 int opc;
 char busqueda[30];
 char codi[30]={"guillermo"};

 do{

  com=contrasena();
 if (com==0)
 {clrscr();
   introduccion();
  getch();
 do
 {
  clrscr();


   n=pedirecuacion();
   clrscr();titulo();
    cargar(a,n);
    limpiar_menu();
do{
    gotoxy(3,23);cout<<"DESEA CORREGIR ALGUNA ECUACION Y/N " ;
   cin>>opc;
    if(opc==121)corregir(a,n);
    }while(opc!=110);
   limpiar_menu();
    resolver1(a,n);
    if (a[n][n]==0)
      break;
      resolver2(a,n);
    respuestas(a,n);

  cout<<" \n\n\n\n\n PARA CONTINUAR    C " ;cin>>op;
  cout<<" \n\n\n";
 }while(op=='c');

    if (a[n][n]==0)
     {  clrscr();
        titulo();
        for (int err=1;err<=3;err++)
             {gotoxy(15,10+err+err);cout<<"        ERROR AL ESCRIBIR LAS ECUACIONES " ;
             }
     }  getch();
 }
 }while(y==5); getch();


}







 //funciones *******************************************************************
  limpiar_menu()
  {
  gotoxy(1,23);clreol();
  gotoxy(1,24);clreol();
  gotoxy(1,25);clreol();
  }
  titulo(){gotoxy(11,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES LINEALES";}
 introduccion(){

  titulo();

gotoxy(11,3);cout<<"------------------------------------------------------------";
gotoxy(15,11);cout<<"                UNI - PERU  2007 ";
gotoxy(15,20);cout<<"  para un optimo desarrollo maximo 9 ecuaciones";
gotoxy(15,22);cout<<"     Presione cualquier tecla para continuar";
gotoxy(1,25);cout<<"programa creado por   jg_antony  ";
  }
 //**************************************************************

 int pedirecuacion(){
 double n;
 do{ titulo();limpiar_menu();
      gotoxy(11,3);cout<<"------------------------------------------------------------";
     gotoxy(1,24);cout<<"numero de ecuaciones  =  ";cin>>n;
     if(n<=2){gotoxy(5,12);cout<<"Como minimo 2 ecuaciones ";}
     if(n>=9){gotoxy(5,14);cout<<"maximo 9 ecuaciones ";}
     }while(n<=1||n>=10);

   return n; }
 //************************************************************************

 //*************************************************************************

double contrasena(){
 char busqueda[20],codi[20]={"guillermo"};
 clrscr();
  titulo();
  gotoxy(10,10);cout<<"ingrese contraseña      =   ";gets(busqueda);
  return strcmp(busqueda,codi); }

 cargar(double a[8][9],int n){
  int i,j;
  for (i=1;i<=n;i++)
       { for(j=1;j<=n;j++)
            {
             limpiar_menu();
             gotoxy(1,23);cout<<"Ingrese Posicion ("<<i<<","<<j<<")   =    " ;
             cin>>a[i][j];

             gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
             cout<<a[i][j];

            }
             limpiar_menu();
             gotoxy(1,23);cout<<"Es igual a =   ";cin>>a[i][n+1];
             gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
             cout<<" = "<<a[i][j];
            }
        }
 //****************************************************************************
 corregir(double a[8][9],int n){
   limpiar_menu();
   int i,j,xc,yc,cc;
   //grawxy();
                   gotoxy(1,23);cout<<"Ingrese Posicion  x    =    " ;cin>>xc;
                   gotoxy(1,24);cout<<"Ingrese Posicion  y    =    " ;cin>>yc;
                   gotoxy(1,25);cout<<"Ingrese Correccion     =    " ;cin>>cc;
                   gotoxy(1,26);clreol();
                   a[xc][yc]=cc;
                    clrscr();
                    titulo();
                   for (i=1;i<=n;i++)
                       { for(j=1;j<=n+1;j++)
                         {gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
                          cout<<a[i][j];
                         }
                       }

 }
 //******************************************************************************
 resolver(double a[8][9],int n){
 int i,np,j,m;
 double fc,bg,te,sm,com;
   for (m=1;m<=n;m++)
       {np=m;
        bg=abs(a[m][m]);
        for(i=m;i<=n;i++)
           {if(abs(a[i][m])>bg)
                {bg=abs(a[i][m]);np=i;
                }
           }
        if(np!=m)
          {for (i=m;i<=n+1;i++)
               {te=a[m][i];
                a[m][i]=a[np][i];
                a[np][i]=te;
               }
          }
        for (i=m+1;i<=n;i++)
            { fc=a[i][m]/a[m][m];
              for( j=m+1;j<=n+1;j++)
                 {a[i][j]=a[i][j]-(fc*a[m][j]);
                 }
            }
       }
   }
 //****************************************************************************
 resolver2(double a[8][9],int n){
   int i,np,j,m;
 double fc,bg,te,sm,com;
    a[n][n+1]=a[n][n+1]/a[n][n];
  for (i=n-1;i>=1;i--)
      {sm=0;
       for(j=i+1;j<=n;j++)
          {sm=sm+a[i][j]*a[j][n+1];
          }
             a[i][n+1]=(a[i][n+1]-sm)/a[i][i];
      }


 }
//****************************************************************************
respuestas(double a[8][9],int n){
   int medio,i;
  medio=n/2;
  gotoxy(5,24+medio*2);cout<<"respuestas";
  for( i=1;i<=n;i++)
     {gotoxy(20,22+i+i);cout<<"X("<<i<<") = "<<a[i][n+1];
     }


}




















