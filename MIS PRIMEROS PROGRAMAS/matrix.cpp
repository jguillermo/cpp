/***************************************************************
 *    CURSO:COMPUTACION I                                      *
 *    PROGRAMA: SIMULACION DE LA PANTALLA DE LA						*
 *					PELICULA MATRIX, usando arreglos y numeros   	*
 *					aleatorios.													*
 *    PROFESOR: Máximo Obregón Ramos                           *
 *    FECHA: 	Jueves 18/10/2007                               *
 *    Cualquier consulta pueden realizarlo mediante            *
 *    La web o el correo del grupo:                            *
 *     http://es.groups.yahoo.com/group/curso_computacion1     *
 *     curso_computacion2@yahoogroups.com                      *
 ***************************************************************/
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
//la pantalla de matrix es un conjunto de hilos que van callendo
pintar(int x,int y,int c);//pinta un caracter c determinado en x,y
actualizar();// pinta los nuevos caracteres en toda la pantalla
nuevo();//Genera un nuevo hilo
int suerte();//los nuevos hilos se generan aleatoriamente
int c();
pausa(int x);

int h[200][3];//matriz donde se almacena la posicion final de los hilos
int n=0;//cantidad de hilos
int altura=20;// altura de cada hilo

main()
{
randomize();
while (!kbhit())//mientras no se presione ninguna tecla
	{
    if (suerte())  nuevo(); // se genera nuevo hilo si hay suerte
    actualizar();//Imprime la parte final los hilos
	 pausa(100);//para que se pueda ver la animacion 
   }

}

pintar(int x,int y,int c)
	{	 gotoxy(x,y);
       cout<<(char)c;
   }

pausa(int x)
{int y;
for(int i=1;i<=x;i++)
 for(int j=1;j<=pow(10,4);j++)
   y=2;
}
actualizar()
{
for(int i=1;i<=n;i++)
	{
    if ((h[i][2])<=24)
	    pintar(h[i][1],h[i][2],h[i][0]);
    h[i][2]++;
    h[i][0]=c();
	 if (h[i][2]<=24)
     	 pintar(h[i][1],h[i][2],'*');
    if ((h[i][2]>altura)&&(h[i][2]<=(altura+24)))
      pintar(h[i][1],h[i][2]-altura,' ');
    if ((h[i][2])>=(24+altura))
         {for (int j=i;j<=(n-1);j++)
           {h[j][0]=h[j+1][0];
            h[j][1]=h[j+1][1];
            h[j][2]=h[j+1][2];
           }
          n--;
         }
    }
}
nuevo()
{
n++;
h[n][0]=c();//caracter
h[n][1]=random(80)+1;//x
h[n][2]=1;//y
}

int suerte()
{
 if (random(2)==0) return 1;
 	else return 0;
}
int c()
{
return random(30)+65;
}

