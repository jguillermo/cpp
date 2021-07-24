#include<conio.h>
#include<iostream.h>



void main(){
float  m[10][10];
	int i,j,k,l,n;

     cout<<"orden de la matriz     ";cin>>n;

   for (i=1;i<=n;i++)
     for (j=1;j<=n;j++)
      { cout<<"ingrese "<<i<<" ; "<<j<<"  =  ";cin>>m[i][j];}

    float det;
    det=m[1][1];
        for(k=1;k<=(n-1);k++)
           {l=k+1;
             for(i=l;i<=n;i++)
					 for(j=l;j<=n;j++)
                 m[i][j]=(m[k][k]*m[i][j]-m[k][j]*m[i][k])/m[k][k];
           det=det*m[k+1][k+1];
           }
     cout<<"dfeterminante = "<<det;
     getch();
     }























/*int n,m[10][10],j
char op;
do{
cout<<"ingrese en orden de la matriz";cin>>n
 if (n>9)
 cout<<"maximo de orden 9" ;
   else
    { for(j=0;j<=n;j++)
      { for (i=0;i<=n;i++)
         {










      cout<<"continuar Y/N ";cin>>op;
      switch (op){
       case 'y':leer();break;
      }while(op!='n');   */

