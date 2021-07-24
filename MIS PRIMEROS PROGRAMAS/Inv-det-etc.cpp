#include<iostream.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>

void leer(float m[50][50],int*n);
void mostrar(float m[50][50],int n);
float deter(float m[50][50],int n);
float traz(float m[50][50],int n);
float cofact_aij(float m[50][50],int n,int a,int b);
void trans(float m[50][50],int n,float c[50][50],int*nc);
void adjunta(float m[50][50],int n,float c[50][50],int*nc);
	/*tras,cofact,inv se pudieron hacer en una sola para la inversa
     la adj es solo un ejemplo de como hacerlo*/
void inv(float m[50][50],int n,float c[50][50],int*nc);

void main()
{float m[50][50],c[50][50];
 int n,nc;
 char opcion;

 do
 	{clrscr();
    gotoxy(30,2);cout<<"MENU MATRIZ 'A'";
    gotoxy(30,5);cout<<"1.-Leer";
    gotoxy(30,6);cout<<"2.-Mostrar";
    gotoxy(30,7);cout<<"3.-Determinante";
    gotoxy(30,8);cout<<"4.-Traza";
    gotoxy(30,9);cout<<"5.-Cofactor de a[i][j]";
    gotoxy(30,10);cout<<"6.-Transpuesta";
    gotoxy(30,11);cout<<"7.-Adjunta";
    gotoxy(30,12);cout<<"8.-Inversa";
    gotoxy(30,13);cout<<"9.-Salir";
    gotoxy(25,16);cout<<"Ingrese opcion = ";cin>>opcion;

    switch(opcion)
 			{case '1': {clrscr();
         				cout<<"Leer(A)"<<endl;
         				leer(m,&n);break;
                     }

	 		 case '2': {clrscr();
          				cout<<"Mostrar(A)"<<endl;
          				mostrar(m,n);break;
                     }

          case '3': {clrscr();
          				cout<<"Determinante(A)"<<endl;
          				mostrar(m,n);
                     cout<<"\nDet(A)="<<deter(m,n);getch();break;
                     }	//getch(): congela deter(variable float)

          case '4': {clrscr();
          				cout<<"Traza(A)"<<endl;
          				mostrar(m,n);
                     cout<<"\nTraz(A)="<<traz(m,n);getch();break;
                     }

          case '5': {clrscr();
          				cout<<"Cofactor de a[i][j]"<<endl;
          				int i,j;
          				mostrar(m,n);
                     cout<<"Escoja [i]:";cin>>i;
                     cout<<"Escoja [j]:";cin>>j;
                     cout<<"\nCofac(A[i][j])="<<cofact_aij(m,n,i,j);
                     getch();break;
                     }

          case '6': {clrscr();
          				cout<<"Tranzpuesta(A)"<<endl;
          				mostrar(m,n);cout<<endl<<endl;
                     trans(m,n,c,&nc);
                     mostrar(c,nc);break;
                     }

          case '7': {clrscr();
          				cout<<"Adjunta(A)"<<endl;
          				mostrar(m,n);cout<<endl<<endl;
                     adjunta(m,n,c,&nc);
                     mostrar(c,nc);break;
                     }

          case '8': {clrscr();
          				cout<<"Inversa(A)"<<endl;
          				mostrar(m,n);cout<<endl<<endl;
                     inv(m,n,c,&nc);
                     mostrar(c,nc);break;
                     }
         }
 	}while(opcion!='9');
}

void leer(float m[50][50],int*n)
	{int i,j;
    cout<<"Ingrese el orden de la matriz:";cin>>*n;
    randomize();
    	for(i=1;i<=(*n);i++)
      	for(j=1;j<=(*n);j++)
         	m[i][j]=random(5)+5;
   mostrar(m,*n);
   }

void mostrar(float m[50][50],int n)
	{int i,j;
    	for(i=1;i<=n;i++)
      	{for(j=1;j<=n;j++)
         	cout<<m[i][j]<<" ";
          cout<<endl;
         }
    getch();
   }

float deter(float n[50][50],int n)
	{int i,j,k,l;
    float m[50][50];

    for (i=1;i<=n;i++)
     for (j=1;j<=n;j++)
       m[i][j]=n[i][j];

    float det;
    det=m[1][1];
        for(k=1;k<=(n-1);k++)
           {l=k+1;
             for(i=l;i<=n;i++)
					 for(j=l;j<=n;j++)
                 m[i][j]=(m[k][k]*m[i][j]-m[k][j]*m[i][k])/m[k][k];
           det=det*m[k+1][k+1];
          }
    return(det);
   }

float traz(float m[50][50],int n)
	{int i,p;
    p=0;
    	for(i=1;i<=n;i++)
      	p=p+m[i][i];
    return(p);
   }

float cofact_aij(float m[50][50],int n,int a,int b)
	{float cof,c[50][50];//'c' es de orden n-1
    int i,j,p,k;
    k=1;
    	for(i=1;i<=n;i++)
      	{p=1;
      	 for(j=1;j<=n;j++)
         		{if((i!=a)&&(j!=b))
             	 	{c[k][p]=m[i][j];
                	 	p=p++;
                		if(p==n)k=k++;
                	}
         		}
         } 			//estructura de la sub matriz 'c' de aij
    cof=pow(-1,(a+b))*deter(c,(n-1));
    return(cof);
   }

void trans(float m[50][50],int n,float c[50][50],int*nc)
	{int i,j;
    	for(i=1;i<=n;i++)
      	 for(j=1;j<=n;j++)
          		c[j][i]=m[i][j];
    *nc=n;
   }

void adjunta(float m[50][50],int n,float c[50][50],int*nc)
	{float mt[50][50];
    int i,j,nt;
		trans(m,n,mt,&nt);

    	for(i=1;i<=n;i++)
      	 for(j=1;j<=n;j++)
          		c[i][j]=cofact_aij(mt,nt,i,j);
    *nc=n;
   }

void inv(float m[50][50],int n,float c[50][50],int*nc)
	{int i,j,nt;
    float mt[50][50];
   	trans(m,n,mt,&nt);	/* llamada de la trans depositada en
      								la matriz mt orden nt */
    	for(i=1;i<=n;i++)
      	 for(j=1;j<=n;j++)
          		c[i][j]=(1/deter(m,n))*cofact_aij(mt,nt,i,j);
    *nc=n;				  /* adj(A)/det(A)=(cofact(trans(A)))/det */
   }
