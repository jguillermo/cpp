#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
marco();
nave(int x,int y);
main(){
nave(15,15);
marco();
getch();
}
marco(){
 int i,j;
char h=177,v=177;
  for(i=2;i<=79;i++)
   {gotoxy(i,1); cout<<h; gotoxy(i,24); cout<<h;}
  for(j=1;j<=24;j++)
   {gotoxy(2,j); cout<<v; gotoxy(79,j); cout<<v;}
}
//***********
nave(int x,int y){
char c=94,cu=202,d=47,is=92,cn=197,co=205;
                   gotoxy(x,y-2);cout<<c;
                   gotoxy(x,y-1);cout<<cu;
gotoxy(x-1,y);cout<<d;                    gotoxy(x+1,y);cout<<is;
                    gotoxy(x,y);cout<<cn;
                    gotoxy(x,y+1);cout<<co;
}







