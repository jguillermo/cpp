#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <conio.h>
#include <iostream.h>

char *tzstr = "TZ=PST8PDT";

 main()
{  for(;;){
   time_t t;
   struct tm *gmt, *area;



   putenv(tzstr);
   tzset();

   t = time(NULL);
   area = localtime(&t);
    gotoxy(1,10);
   printf("Local time is: %s", asctime(area));


   getch();
   }


}