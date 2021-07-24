#include <time.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <iostream.h>
 main()
{  for(;;){
   time_t timer;
   struct tm *tblock;

   /* gets time of day */
   timer = time(NULL);

   /* converts date/time to a structure */
   tblock = localtime(&timer);

   printf("Local time is: %s", asctime(tblock));  getch();
    }

}