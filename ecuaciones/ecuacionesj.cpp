#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
 class contrasena{private:char codigo[30];char busca[30];public:
void setbusca(char *bus){strcpy(busca,bus);}
void setcodigo(char *cod){strcpy(codigo,cod);}
char *getcodigo(){return codigo;}
char *getbusca(){return busca;}};limpiar_menu();int ancho=7;
void main(){contrasena tt;double a[50][51];int n,i,np,j,m,y=5,com,xc,yc,cc;
double fc,bg,te,sm;char op,opc;char busqueda[30];char codi[30]={"guillermo"};
do{  clrscr();gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES";
tt.setcodigo(codi);gotoxy(10,10);cout<<"ingrese contrasena      =   ";cin>>busqueda;
tt.setbusca(busqueda);com=strcmp(tt.getbusca(),tt.getcodigo());
if (com==0){clrscr();
gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES";
gotoxy(15,3);cout<<"---------------------------------------------------";
gotoxy(15,11);cout<<"                UNI - PERU  2007 ";
gotoxy(15,20);cout<<"  para un optimo desarrollo maximo 9 ecuaciones";
gotoxy(15,22);cout<<"     Presione cualquier tecla para continuar";
gotoxy(1,25);cout<<"programa creado por   jg_antony  ";
getch();do{clrscr();
gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES";
gotoxy(1,24);cout<<"numero de ecuaciones  =  ";cin>>n;for (i=1;i<=n;i++)
{for(j=1;j<=n;j++){limpiar_menu();
gotoxy(1,23);cout<<"Ingrese Posicion ("<<i<<","<<j<<")   =    " ;cin>>a[i][j];
gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
cout<<a[i][j];}limpiar_menu();
gotoxy(1,23);cout<<"Es igual a =   ";cin>>a[i][n+1];
gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
cout<<"= "<<a[i][j];}limpiar_menu();for (int cc=1;;cc++){limpiar_menu();
gotoxy(1,23);cout<<"  DESEA CORREGIR ALGUNA ECUACION Y/N " ;cin>>opc;
if(opc=='y'){limpiar_menu();
gotoxy(1,23);cout<<"Ingrese Posicion  x    =    " ;cin>>xc;
gotoxy(1,24);cout<<"Ingrese Posicion  y    =    " ;cin>>yc;
gotoxy(1,25);cout<<"Ingrese Correccion     =    " ;cin>>cc;
gotoxy(1,26);clreol();a[xc][yc]=cc;clrscr();
gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES";
for (i=1;i<=n;i++){for(j=1;j<=n+1;j++)
{gotoxy(40-(ancho*(n+1)+1*(n+2))/2+(j-1)*ancho+j,13-(2*n)/2+2*(i-1));
cout<<a[i][j];}}}else break;}limpiar_menu();for (m=1;m<=n;m++){np=m;
bg=abs(a[m][m]);for(i=m;i<=n;i++){if(abs(a[i][m])>bg){bg=abs(a[i][m]);np=i;}}
if(np!=m){for (i=m;i<=n+1;i++){te=a[m][i];a[m][i]=a[np][i];a[np][i]=te;}}
for (i=m+1;i<=n;i++){fc=a[i][m]/a[m][m];for( j=m+1;j<=n+1;j++)
{a[i][j]=a[i][j]-(fc*a[m][j]);}}}if (a[n][n]==0) break;
a[n][n+1]=a[n][n+1]/a[n][n];for (i=n-1;i>=1;i--){sm=0;for(j=i+1;j<=n;j++)
{sm=sm+a[i][j]*a[j][n+1];}a[i][n+1]=(a[i][n+1]-sm)/a[i][i];}int medio;
medio=n/2;gotoxy(5,24+medio*2);cout<<"respuestas";for( i=1;i<=n;i++)
{gotoxy(20,22+i+i);cout<<"X("<<i<<") = "<<a[i][n+1];
}cout<<" \n\n\n\n\n PARA CONTINUAR    C " ;cin>>op;cout<<" \n\n\n";
}while(op=='c');if (a[n][n]==0){  clrscr();
gotoxy(15,2);cout<<"PROGRAMA PARA LA SOLUCION DE SISTEMAS DE ECUACIONES\n";
for (int err=1;err<=3;err++)
{gotoxy(23,10+err+err);cout<<"ERROR AL ESCRIBIR LAS ECUACIONES " ;}
}getch();}}while(y==5); getch();}
limpiar_menu(){gotoxy(1,23);clreol();gotoxy(1,24);clreol();
gotoxy(1,25);clreol();}
