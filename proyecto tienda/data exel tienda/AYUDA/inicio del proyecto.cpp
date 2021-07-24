#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<stdio>
#include<fstream.h>
char menu();
operacionmenu();
verprecios();
cargardatos();

main(){

char op;

 operacionmenu();
}
//******************************************************************************
char menu(){char op
gotoxy(15,3);cout<<"TIENDA GUILLE";
gotoxy(15,4);cout<<"-------------";
gotoxy(12,8);cout<<"1.- Ver precios";
gotoxy(12,10);cout<<"2.- Cargar datos"
gotoxy(12,12);cout<<"3.- "
gotoxy(12,14);cout<<"4.- salir"
gotoxy(12,16);cout<<"Ingrese opcion";cin>>op;
return op;
}
//******************************************************************************
opreracionmenu(){
char op;
int i,j;
do{op=menu();
switch(op){
case '1':{verprecios();}
case '2':{cargardatos();}
//case '3':{}


}
while(op!='4')

}
 //***************************************************************************
verprecios();
//***************************************************************************
cargardatos(){




}


















