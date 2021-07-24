#include<iostream.h>
 #include<conio.h>
 struct notas
 { float nota1;
 	float nota2; };
   float calcula_prom (float p1, float p2);

   void main()
   { notas n;
     clrscr();
     cout<<"ingerese primera nota  =  ";cin >>n.nota1;
     cout<<"ingerese segunda nota  =  ";cin >>n.nota2;
     cout<<"el promedio es  =  "<<calcula_prom(n.nota1,n.nota2);
     getch();
     }
    float calcula_prom (float p1, float p2)
   {float prom;
     prom=(p1+p2)/2.0;
     return (prom);}


