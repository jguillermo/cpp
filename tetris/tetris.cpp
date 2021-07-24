#include<conio.h>
#include<iostream.h>
grupo1(int x,int y);
grupo2(int x,int y,int num);
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
main(){
int j=1,x=15,y=15;
char b;
for (;;){
b=getch();
grupo2(15,15,b);
}

getch();
}
grupo1(int x,int y){
char b=254,c=223;
gotoxy(x,y);cout<<b;gotoxy(x,y+1);cout<<b;
gotoxy(x+1,y);cout<<b;gotoxy(x+1,y+1);cout<<b;
}
grupo2(int x,int y,char num){
char b=254;
switch(num){
case '1':                       gotoxy(x,y);cout<<b;
          gotoxy(x-1,y+1);cout<<b;gotoxy(x,y+1);cout<<b;gotoxy(x+1,y+1);cout<<b;break;
case '2':                       gotoxy(x,y);cout<<b;
        gotoxy(x-1,y+1);cout<<b;gotoxy(x,y+1);cout<<b;
                                gotoxy(x,y+2);cout<<b;break;
case '3':                       gotoxy(x,y);cout<<b;
                                gotoxy(x,y+1);cout<<b;gotoxy(x+1,y+1);cout<<b;
                                 gotoxy(x,y+2);cout<<b;break;
case '4': gotoxy(x,y);cout<<b;gotoxy(x+1,y);cout<<b;gotoxy(x+2,y);cout<<b;
          gotoxy(x,y+1);cout<<b;break;

}

}













