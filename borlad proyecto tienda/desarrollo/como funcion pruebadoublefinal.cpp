#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include<math.h>

double pruebadouble(char num[30]);
main(){
for(;;){ char num[30];
cout<<"ingrese numero = ";gets(num);
double numero=pruebadouble(num);
if(numero==9232.8719)cout<<"\n\n\a  No es un numero valido\n\n";
else
cout<<"\n el numero x 2 es =    "<<(numero*2)<<"\n\n";
}

}



double pruebadouble(char num[30]){

int i,j,k,tam,tam2=0,emp=0,jo=0,punto=0; j=1;

tam=strlen(num);
for (i=0;i<tam;i++)
{k=toupper(num[i]);
 if (k<46||k>57||k==47)j=0;
 if(k==45&&i==0){j=1;emp=1;}
 if(k==45&&tam==1)j=0;
 if(k==46){tam2=i; jo=1;punto++;}
 if(k!=46&&jo==0)tam2=tam;

 }
double numero=0.0;
if(punto>1)j=0;
if(j==0)numero=9232.8719;
else {


int cam=0,b,decimal=0;


for (b=emp;b<tam;b++){
int op=toupper(num[b]);  if(cam==1)decimal++;

if(op==49){if(cam==0)numero=numero+1*pow(10,tam2-b-1);if(cam==1) numero=numero+1/pow(10,decimal);}
if(op==50){if(cam==0)numero=numero+2*pow(10,tam2-b-1);if(cam==1) numero=numero+2/pow(10,decimal);}
if(op==51){if(cam==0)numero=numero+3*pow(10,tam2-b-1);if(cam==1) numero=numero+3/pow(10,decimal);}
if(op==52){if(cam==0)numero=numero+4*pow(10,tam2-b-1);if(cam==1) numero=numero+4/pow(10,decimal);}
if(op==53){if(cam==0)numero=numero+5*pow(10,tam2-b-1);if(cam==1) numero=numero+5/pow(10,decimal);}
if(op==54){if(cam==0)numero=numero+6*pow(10,tam2-b-1);if(cam==1) numero=numero+6/pow(10,decimal);}
if(op==55){if(cam==0)numero=numero+7*pow(10,tam2-b-1);if(cam==1) numero=numero+7/pow(10,decimal);}
if(op==56){if(cam==0)numero=numero+8*pow(10,tam2-b-1);if(cam==1) numero=numero+8/pow(10,decimal);}
if(op==57){if(cam==0)numero=numero+9*pow(10,tam2-b-1);if(cam==1) numero=numero+9/pow(10,decimal);}
if(op==46)cam=1;
							  	}

if(emp==1)numero=-numero;
}
return numero;

}
