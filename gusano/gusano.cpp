#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
pausa(int x)
{int y;
 for(int i=1;i<=x;i++)
  for(int j=1;j<=pow(10,4);j++)
  y=1;
}

main()
{
 char a;
 int x=1, y=5, d=1;
 do
 {
 if (kbhit())
 	{a=getch();
     if(!a)
       {a=getch();
       switch (a)
        {case 77: d=1; break;
         case 72: d=2; break;
			case 75: d=3; break;
         case 80: d=4; break;
        }
       }
    }
    switch(d)
    {	case 1: x++; if(x>=80) a=27; break;
      case 2: y--; if(y<=1) x=24; break;
      case 3: x--; if(x<=1) x=80; break;
      case 4: y++; if(y>=24) x=1; break;
    }
  pausa(100);
  gotoxy(x,y);
  cout<<"*";
  } while(a!=27);

getch();
return 0;
}
