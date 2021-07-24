#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<stdio>
#include<fstream.h>
class cobrero{
private:
   int codigo;
   char nombres[31];
   char ocupacion[30];
   double basico;
publicos:
cobrero(){}
void setcodigo(int codigo){this->codigo=codigo;}
int getcodigo(){return codigo;}
void setnombre(char nombre){strcpy(nombres,nombre);}
char getnombre(){return nombres;}
void setocupacion(char ocup){strcpy(ocupacion,ocup);}
char getocupacion(){return ocupacion;}
void setbasico(double basico){this->basico=basico;}
double getbasico(){return basico;}
};


class cobrerosa{
private:
 fstream archivo;
 cobrero unobrero;
 int n,tamreg,error;
public:
       cobrerosa(){
       archivo.open("obreros.dat",ios::in|ios::out|ios::binary);
       if(!archivo){error=1;}
       else {
       error=0;
       tamreg=sizeof(unobrero);
       archivo.seekg(0,ios::end);
       n=archivo.tellg()/tamreg;
       }
       }
      ~cobrero














