#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include<math.h>

int pruebaintcodigo (char num[30]);
main(){
for(;;){ char num[30];
cout<<"ingrese numero = ";gets(num);
int numero=pruebaintcodigo(num);
if(numero==-1)cout<<"\n\n\a  No es un numero valido\n\n";
else
cout<<"\n el numero es    "<<numero<<"\n\n";
}

}



int pruebaintcodigo(char num[30]){

int i,j,k,tam; j=1;

tam=strlen(num);
for (i=0;i<tam;i++)
{k=toupper(num[i]);
 if (k<48||k>57)j=0;
}
int numero=0;

//***********************************************
if(j==0)numero=-1;
else {


int b;


for (b=0;b<tam;b++){
int op=toupper(num[b]);

if(op==49)numero=numero+1*pow(10,tam-b-1);
if(op==50)numero=numero+2*pow(10,tam-b-1);
if(op==51)numero=numero+3*pow(10,tam-b-1);
if(op==52)numero=numero+4*pow(10,tam-b-1);
if(op==53)numero=numero+5*pow(10,tam-b-1);
if(op==54)numero=numero+6*pow(10,tam-b-1);
if(op==55)numero=numero+7*pow(10,tam-b-1);
if(op==56)numero=numero+8*pow(10,tam-b-1);
if(op==57)numero=numero+9*pow(10,tam-b-1);

							  	}


}
return numero;

}