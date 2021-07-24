//*************************************************************
//*    CURSO:COMPUTACION I - ARREGLOS UNA DIMENSION           *
//*    PROGRAMA: MANEJO DE POLINOMIOS                         *
//*    PROFESOR: Máximo Obregón Ramos                         *
//*    FECHA: 	Miércoles 30/mayo/2007                         *
//*    Cualquier consulta pueden realizarlo mediante          *
//*    La web o el correo del grupo:                          *
//*     http://es.groups.yahoo.com/group/curso_computacion1   *
//*     curso_computacion1@yahoogroups.com                    *
//*************************************************************
#include <ctype.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#define M 100
//Prototipo de funciones
leer(int &n, float a[M]);
float evaluar(int n, float a[M],float x);
derivar(int n, float a[M],int &m,float b[M]);
derivarn(int n, float a[M],int veces,int &m,float b[M]);//derivada enesima normal
derivarnr(int n, float a[M],int veces,int &m,float b[M]);//derivada enesima recursiva
ver(int n, float a[M]);
pasar(int n, float a[M],int &m,float b[M]);
suma(int na, float a[M], int nb, float b[M],int &nc, float c[M]);
resta(int na, float a[M], int nb, float b[M],int &nc, float c[M]);
mult(int na, float a[M], int nb, float b[M],int &nc, float c[M]);
int menu();

//PROGRAMA PRINCIPAL
main()
{int np=3,nq,nr,nt,op,i;
 float p[M]={1,2,3,4},q[M],r[M],t[M],x;
 nq=nr=0;
 do
  { op=toupper(menu());
    clrscr();
    switch(op)
  	 {
    case '1':leer(np,p);break;
    case '2':leer(nq,q);break;
    case '3':cout<<"P(x):";ver(np,p);getch();break;
    case '4':cout<<"Q(x):";ver(nq,q);getch();break;
    case '5':cout<<"R(x):";ver(nr,r);getch();break;
    case '6':suma(np,p,nq,q,nr,r);break;
    case '7':resta(np,p,nq,q,nr,r);break;
    case '8':mult(np,p,nq,q,nr,r);break;
    case '9':pasar(nr,r,np,p);break;
    case 'A':derivarnr(np,p,1,nr,r);break;
    case 'C':cout<<"Ingrese el valor a evaluar:"; cin>>x;
				 cout<<"P(x)="<<evaluar(np,p,x)<<endl;
             getch();
             break;
    case 'D':for (i=1;i<=(np+1);i++)
    			  {derivarn(np,p,i,nt,t);
               cout<<"Derivada "<<i<<": ";
               ver(nt,t);
               }
             getch();
             break;

    }
  }while (op!='S');
}
//DESARROLLO DE FUNCIONES
pasar(int n, float a[M],int &m,float b[M])
  	{int i;
    m=n;
    for (i=0;i<=n;i++)
    	b[i]=a[i];
   }
int menu()
	{clrscr();
    cout<<"OPERACIONES DE POLINOMIO\n\n";
    cout<<" 1.-LEER POLINOMIO P(x)\n";
    cout<<" 2.-LEER POLINOMIO Q(x)\n";
    cout<<" 3.-MOSTRAR P(x)\n";
    cout<<" 4.-MOSTRAR Q(x)\n";
    cout<<" 5.-MOSTRAR R(x)\n";
    cout<<" 6.-HACER R(x)=P(x)+Q(x)\n";
    cout<<" 7.-HACER R(x)=P(x)-Q(x)\n";
    cout<<" 8.-HACER R(x)=P(x)*Q(x)\n";
    cout<<" 9.-HACER P(x)=R(x)\n";
    cout<<" A.-HACER R(x)=P'(x)\n";
    cout<<" B.-HACER R(x)=integral(P(x))\n";
    cout<<" C.-EVALUAR P(x))\n";
    cout<<" D.-MOSTRAR TODAS LAS DERIVADAS DE P(x))\n";
    cout<<" S.-SALIR\n";
    cout<<"\nINGRESE OPCION:";
    return toupper(getch());
   }

leer(int &n, float a[M])
	{int i;
    cout<<"Ingrese el grado del polinomio:";
 	 cin>>n;
 	 for (i=0;i<=n;i++)
	  {cout<<"	a"<<i<<" =";
	   cin>>a[i];
	  }
  	}

float evaluar(int n, float a[M],float x)
	{float d,s;
    int i;
 	 for(i=0;i<=n;i++)
 		{d=a[i]*pow(x,i);
	    s=s+d;
      }
    return s;
    }

derivar(int n, float a[M],int &m,float b[M])
 	{int i;
    if (n>0)  m=n-1;
			else m=n;
	 for(i=1;i<=n;i++)
 		b[i-1]=a[i]*i;
    if (n==0)
    	{m=0;
       b[0]=0;
      }
    }
ver(int n, float a[M])
 	{int i;
	 for(i=0;i<=n;i++)
    	{if (i==0) cout<<a[i];
       if (i==1) cout<<"+"<<a[i]<<"x";
     	 if (i>1) cout<<"+"<<a[i]<<"x^"<<i;
	   }
     cout<<endl;
    }
derivarn(int n, float a[M],int veces,int &m,float b[M])
	{int i,j,nt;
    float t[M];
    pasar(n,a,nt,t);
    for (i=1;i<=veces;i++)
      {derivar(nt,t,m,b);
       pasar(m,b,nt,t);
      }
   }
derivarnr(int n, float a[M],int veces,int &m,float b[M])
	{int i,j,nt;
    float t[M];
     if (veces==1) derivar(n,a,m,b);
     else
     	{derivar(n,a,m,b);
       pasar(m,b,nt,t);
       derivarnr(nt,t,veces-1,m,b);
      }
   }

suma(int na, float a[M], int nb, float b[M],int &nc, float c[M])
	{int i,m;
    if(na<nb)
    	{nc=nb;
    	for((m=na+1);m<=nb;m++)
    	a[m]=0;
      }
    else
    	{nc=na;
    	for((m=nb+1);m<=na;m++)
    	b[m]=0;
    	}
    for(i=0;i<=nc;i++)
    	c[i]=a[i]+b[i];
  	}

resta(int na, float a[M], int nb, float b[M],int &nc, float c[M])
	{int i,m;
    if(na<nb)
    	{nc=nb;
    	for((m=na+1);m<=nb;m++)
    	a[m]=0;
      }
    else
    	{nc=na;
    	for((m=nb+1);m<=na;m++)
    	b[m]=0;
    	}
    for(i=0;i<=nc;i++)
    	c[i]=a[i]-b[i];
  	}

mult(int na, float a[M], int nb, float b[M],int &nc, float c[M])
	{int i,j,m,nt;
    float t[M];
    if(na<nb)
    	{
    	for((m=na+1);m<=nb;m++)
    	a[m]=0;
      }
    else
    	{
    	for((m=nb+1);m<=na;m++)
    	b[m]=0;
    	}
    for(i=0;i<=(nb+na);i++)
    	c[i]=0;
    for(i=0;i<=nb;i++)
    	{for(j=0;j<=na;j++)
       c[i+j]=c[i+j]+a[i]*b[j];
       }
    nc=na+nb;
    }


