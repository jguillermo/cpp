#include<conio.h>
#include<iostream.h>
 #include <stdlib.h>
 #include<math.h>
line(double x1,double y1,double x2,double y2);
puntof(double x1,double y1,double l,double h,double &x2,double &y2);

main(){  randomize();
double x1,y1,x2,y2,l;int an;
cout<<"x1 ";cin>>x1;
cout<<"\ny1 ";cin>>y1;
cout<<"angle ";cin>>an;
cout<<"lon ";cin>>l;
for(;;){
for(int h=0;h<=an;h++)
{ puntof(x1,y1,l,h,x2,y2);
  line(x1,y1,x2,y2);
  getch();clrscr();
}
}







  clrscr();
/*x1=random(75)+1;
y1=random(20)+1;
x2=random(75)+1;
y2=random(20)+1;
line(x1,y1,x2,y2);

gotoxy(1,25);cout<<x1<<","<<y1<<" "<<x2<<","<<y2<<"  "; */



}


line(double x1,double y1,double x2,double y2){
double tem,ag,y;
if(x2<x1){tem=x1;x1=x2;x2=tem;}
if(y1<y2){tem=y1;y1=y2;y2=tem;}
if(x2!=x1)ag=((y1-y2)/(x2-x1));
else ag=0;


//cout<<"ag = "<<ag<<endl;
 int m=1,h;
int j=random(15);
for(h=x1;h<=x2;h++)
{y=ag*m;
    textcolor(j);
 gotoxy(h,y1-y);cprintf("*");
 m++;
}
//******************
m=1; double x;
for(h=y2;h<=y1;h++)
{if(ag!=0)x=m/ag;else x=0;
    textcolor(j);
 gotoxy(x2-x,h);cprintf("*");
 m++;
}
}
//******************************************
puntof(double x1,double y1,double l,double h,double &x2,double &y2){
x2=x1+l*cos((h*2*3.14159)/360);
y2=y1-l*sin((h*2*3.14159)/360);
}





