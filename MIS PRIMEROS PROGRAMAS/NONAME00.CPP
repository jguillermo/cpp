#include <conio.h>
#include <iostream.h>
#include <cstring.h>

struct datos
  { char nombre[15];
    int caja[5];
    };


 void mostrar() ;
 void extraer()  ;
 void cargar()    ;
 char sinmonto()   ;

   main ()
   {
   int total,a,b,c,d,e;
    char opcion;

   do{clrscr();
      gotoxy(30,2);cout<<"MENU CAJERO";
      gotoxy(30,5);cout<<"1.- DEFINA CAJERO";
      gotoxy(30,6);cout<<"2.- CARGAR";
      gotoxy(30,7);cout<<"3.-EXTRAER MONTO";
      gotoxy(30,8);cout<<"4.-MOSTRAR ESTADO DE CAJERO";
      gotoxy(30,9);cout<<"5.-SALIR";
       gotoxy(30,16);cout<<"ingrese opcion==";cin>>opcion;
       switch(opcion)
       {
         case'2':cargar();break;
         //case'3':extraer();break;
         case'4': mostrar();break; }

         }while(opcion!='5');
         }

    void cargar()
    { int a,b,c,d,e;
    a=b=c=d=e=0;
       clrscr();

      cout<<"ingrese cantidad de billetes de $10  :";cin>>a;
      cout<<"ingrese cantidad de billetes de $20  :";cin>>b;
      cout<<"ingrese cantidad de billetes de $50  :";cin>>c;
      cout<<"ingrese cantidad de billetes de $100 :";cin>>d;
      cout<<"ingrese cantidad de billetes de $200 :";cin>>e;
      getch();
      }

      //void extraer()
      //{ int retiro
       //cout<<"ingrese monto a retirar"; cin>>r; }
      void mostrar ()
       { int total,a,b,c,d,e;

       clrscr();

       total=	a*10+ b*20+ c*50 + d*100 + e*200 ;


          if (total=0)
            {gotoxy(15,10);cout<<"no hay dinero ";  }
          else
          {
          cout<<"billetes de $10    = "<<a<<"        total   "<<a*10<<endl;
          cout<<"billetes de $20    = "<<b<<"        total   "<<b*20<<endl;
          cout<<"billetes de $50    = "<<c<<"        total   "<<c*50<<endl;
          cout<<"billetes de $100   = "<<d<<"        total   "<<d*100<<endl;
          cout<<"billetes de $200   = "<<e<<"        total   "<<e*200<<endl;

          cout<<" total ="<<total;  }

          getch();}







