#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

main(){

int i,j,k,tam,ll;char *num;
for(;;){ j=1;
cout<<"ingrese numero = ";gets(num);
tam=strlen(num);
for (i=0;i<tam;i++)
{k=toupper(num[i]);//cout<<k;getch();
 if (k<46||k>57||k==47)j=0;
}
if(j==0)cout<<"\n\n\ano es un numero valido\n\n";
else
cout<<"\n\nel numero es "<<num<<"\n\n";
}
}