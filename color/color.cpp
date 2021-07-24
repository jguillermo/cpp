#include <conio.h>
#include<iostream.h>
int main(void)
{
   int i, j;

   clrscr();
   for (i=0; i<15; i++)
   {
        //cout<<"hola";
         cprintf(" textcolor");
       cprintf("\r\n");
       //textcolor(i+1);
       textcolor(3);
       //textbackground(i);
   }
      getch();
   return 0;
}