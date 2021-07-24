#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
limpiar_menu();
 int ancho=7;
void main(){
double a[20][21];
int n,i,np,j,m;
double fc,bg,te,sm;
char op;
gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES\n";
 gotoxy(1,15);cout<<"para un optimo desarrollo maximo 9 ecuaciones\n";
 gotoxy(1,16);cout<<"Enter para continuar\n";
 getch();
do{

clrscr();
 gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES\n";
gotoxy(1,24);cout<<"numero de ecuaciones  =  ";cin>>n;
//cout<<"\n\ncoeficientes de X \n\n";
for (i=1;i<=n;i++)
    { for(j=1;j<=n;j++)
          {//cout<<"X("<<i<<","<<j<<")= ";cin>>a[i][j];
            limpiar_menu();
      gotoxy(1,23);cout<<"Ingrese Posicion ("<<i<<","<<j<<")=";
      cin>>a[i][j];

       gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
       cout<<a[i][j];

          }
          limpiar_menu();
       gotoxy(1,23);cout<<"Es ugual a =   ";cin>>a[i][n+1];
       gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
       cout<<"= "<<a[i][j];

     }

   limpiar_menu();
for (m=1;m<=n;m++)
    {np=m;
     bg=abs(a[m][m]);
     for(i=m;i<=n;i++)
         {if(abs(a[i][m])>bg)
                {bg=abs(a[i][m]);np=i;}
         }
    if(np!=m)
          {for (i=m;i<=n+1;i++)
               {te=a[m][i];
                a[m][i]=a[np][i];
                a[np][i]=te;}
          }
      for (i=m+1;i<=n;i++)
           {fc=a[i][m]/a[m][m];
            for( j=m+1;j<=n+1;j++)
                {a[i][j]=a[i][j]-(fc*a[m][j]);}
           }
     }

     a[n][n+1]=a[n][n+1]/a[n][n];
     for (i=n-1;i>=1;i--)
          {sm=0;
           for(j=i+1;j<=n;j++)
              {sm=sm+a[i][j]*a[j][n+1];}
           a[i][n+1]=(a[i][n+1]-sm)/a[i][i];
          }
          int medio;
          medio=n/2;
          gotoxy(5,24+medio*2);cout<<"respuestas";
          for( i=1;i<=n;i++)
              {gotoxy(20,22+i+i);cout<<"X("<<i<<") = "<<a[i][n+1]; }



          cout<<" \n\n\n\n\n PARA CONTINUAR    C " ;cin>>op;
            cout<<" \n\n\n\n\n";
          }while(op=='c');


              }

  limpiar_menu()
{
  gotoxy(1,23);clreol();
  gotoxy(1,24);clreol();
  gotoxy(1,25);clreol();
}

