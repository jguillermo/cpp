#include<conio.h>
#include<iostream.h>
#include <stdlib.h>

grupo1(int x,int y);
grupo2(int x,int y,int num);
cgrupo2(int x,int y,int num);
marco();
/*grupo3(int x,int y,int num);
grupo4(int x,int y,int num);
grupo5(int x,int y,int num);
grupo6(int x,int y,int num);
grupo7(int x,int y,int num);
/*cgrupo1(int x,int y);
cgrupo2(int x,int y,int num);
cgrupo3(int x,int y,int num);
cgrupo4(int x,int y,int num);
cgrupo5(int x,int y,int num);
cgrupo6(int x,int y,int num);
cgrupo7(int x,int y,int num);  */
tecla(int &x,int &y,int &b);
pausa(int p);
main(){randomize();
int x=15,y=0,c=1;
int b2=1,b=254;marco();
for (;;){

gotoxy(50,5);cout<<"x = "<<x<<"   y = "<<y<<"   num = "<<b2<<"   ";



tecla(x,y,b2);y++;if(b2>=5)b2=1;
if(x<=3)x=4;
gotoxy(x,y);grupo2(x,y,b2);
 pausa(5);
gotoxy(x,y);cgrupo2(x,y,b2);
 if(y>=23)y=0;//clrscr();
}


}
grupo1(int x,int y){
char b=254;
gotoxy(x,y);cout<<b;gotoxy(x,y+1);cout<<b;
gotoxy(x+1,y);cout<<b;gotoxy(x+1,y+1);cout<<b;
}
//************************************************
grupo2(int x,int y,int num){
char b=254;

if(num==1){                     gotoxy(x,y-1);cout<<b;
          gotoxy(x-1,y);cout<<b;gotoxy(x,y);cout<<b;gotoxy(x+1,y);cout<<b;}
if(num==2){                       gotoxy(x,y-1);cout<<b;
        gotoxy(x-1,y);cout<<b;gotoxy(x,y);cout<<b;
                                gotoxy(x,y+1);cout<<b;}
if(num==3){     gotoxy(x-1,y);cout<<b;gotoxy(x,y);cout<<b;gotoxy(x+1,y);cout<<b;
                                  gotoxy(x,y+1);cout<<b;}
if(num==4){         gotoxy(x,y-1);cout<<b;
                                gotoxy(x,y);cout<<b;gotoxy(x+1,y);cout<<b;
                                 gotoxy(x,y+1);cout<<b;}



}
//**********************************************
cgrupo2(int x,int y,int num){
char b=254;

if(num==1){                     gotoxy(x,y-1);cout<<" ";
          gotoxy(x-1,y);cout<<" ";gotoxy(x,y);cout<<" ";gotoxy(x+1,y);cout<<" ";}
if(num==2){                       gotoxy(x,y-1);cout<<" ";
        gotoxy(x-1,y);cout<<" ";gotoxy(x,y);cout<<" ";
                                gotoxy(x,y+1);cout<<" ";}
if(num==3){     gotoxy(x-1,y);cout<<" ";gotoxy(x,y);cout<<" ";gotoxy(x+1,y);cout<<" ";
                                  gotoxy(x,y+1);cout<<" ";}
if(num==4){         gotoxy(x,y-1);cout<<" ";
                                gotoxy(x,y);cout<<" ";gotoxy(x+1,y);cout<<" ";
                                 gotoxy(x,y+1);cout<<" ";}



}
//**********************************************
marco(){
 int i,j;
char h=177,v=177;
  for(i=2;i<=30;i++)
   { gotoxy(i,24); cout<<h; //gotoxy(i,1); cout<<h;
   }
  for(j=1;j<=24;j++)
   {gotoxy(2,j); cout<<v; gotoxy(30,j); cout<<v;}
}
//**********************************************
tecla(int &x,int &y,int &b)
{ char a;
  if (kbhit())
 	 {a=getch();
     if(!a)
       {a=getch();
       switch (a)
        {case 77: x++; break;
         case 72: b++; break;
			case 75:x--; break;
         case 80: y++; break;
        }
       }
    }
}
//*****************************************************
pausa(int p){
int l=0;
for(int h=0;h<=p*1000;h++){gotoxy(75,1);cout<<"-"; }



}
//********************************************

