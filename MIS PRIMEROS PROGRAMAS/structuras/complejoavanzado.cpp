//Elaborado por MAXIMO OBREGON RAMOS
//Aqui tienen un programa mas desarrollado
//de numeros complejos, espero que les sea de mejor entendimiento
//cualquier consulta no dudar de enviar sus comentarios por este medio.

#include<iostream.h>
#include<conio.h>
#include<math.h>
//declaracion de la clase
class complejo{
	private:
	float r,i;
	public:
	void leer();
	void ver();
	float modulo();
	complejo pot(int n);
	complejo conjugada();
	complejo operator+(complejo x);
	complejo operator-(complejo x);
	complejo operator*(complejo x);
	complejo operator/(complejo x);
	complejo operator*(float x);
	complejo operator/(float x);
	complejo operator^(int n);
	};

//prototipo o desarrollo de la clase
void complejo::leer()
	{cout<<"Ingrese parte real: ";cin>>r;
	 cout<<"Ingrese parte imaginaria: ";cin>>i;}

void complejo::ver()
	{cout<<r<<" + "<<i<<"i\n";}

float complejo::modulo()
	{return sqrt(r*r+i*i);}

complejo complejo::operator+(complejo x)
	{complejo temp;
	temp.r=r+x.r;
	temp.i=i+x.i;
	return(temp);}

complejo complejo::operator-(complejo x)
	{complejo temp;
	temp.r=r-x.r;
	temp.i=i-x.i;
	return(temp);}

complejo complejo::operator*(complejo x)
	{complejo temp;
	temp.r=r*x.r-i*x.i;
	temp.i=r*x.i+i*x.r;
	return temp;}

complejo complejo::operator*(float x)
	{complejo temp;
	temp.r=r*x;
	temp.i=i*x;
	return temp;}

complejo complejo::operator/(complejo x)
	{complejo temp;
    float t1;
    t1=x.r*x.r+x.i*x.i;
	temp.r=(r*x.r+i*x.i)/t1;
	temp.i=(i*x.r-r*x.i)/t1;
	return temp;}

complejo complejo::operator/(float x)
	{complejo temp;
	temp.r=r/x;
	temp.i=i/x;
	return temp;}

complejo complejo::operator^(int n)
	{complejo t1,t2;
	t1.r=1;t1.i=0;
	t2.r=r;t2.i=i;
	for (int ii=1;ii<=n;ii++)
	 t1=t1*t2;
	return t1;}

complejo complejo::pot(int n)
	{complejo t1,t2;
	t1.r=1;t1.i=0;
	t2.r=r;t2.i=i;
	for (int ii=1;ii<=n;ii++)
	 t1=t1*t2;
	return t1;}

complejo complejo::conjugada()
	{complejo temp;
	temp.r=r;
	temp.i=-i;
	return temp;}



//funcion principal

void main()
{
clrscr();
complejo a,b,c;
float k=5;
int n=2;
cout<<"\nIngresar los datos del complejo a:"<<endl;a.leer();
cout<<"\nIngresar los datos del complejo b:"<<endl;b.leer();
cout<<"\n\na=";a.ver();
cout<<"Modulo de a=: "<<a.modulo();
cout<<"\n\nb=";b.ver();
cout<<"Modulo de b=: "<<b.modulo();
cout<<"\na+b= ";c=a+b;c.ver();
cout<<"\na-b= ";c=a-b;c.ver();
cout<<"\na*b= ";c=a*b;c.ver();
cout<<"\na/b= ";c=a/b;c.ver();
cout<<"\nSea k="<<k<<endl;
cout<<"\na*k= ";c=a*k;c.ver();
cout<<"\na/k= ";c=a/k;c.ver();
cout<<"\nSea n="<<n<<endl;
cout<<"\na^n= ";c=a^n;c.ver();
cout<<"\na^n= ";c=a.pot(n);c.ver();
cout<<"\nLa conjugada de a = ";a.conjugada().ver();
getch();
cout<<"La evaluacion de esta expresion"<<endl;
cout<<"      -      -"<<endl;
cout<<"  Ú ((a+b)^3-c^2))^2¿^3"<<endl;
cout<<"  ³-----------------³"<<endl;
cout<<"  ³        -        ³"<<endl;
cout<<"  À     (a-b)^4     Ù"<<endl;
cout<<"Forma 1\n= ";
((((((a.conjugada()+b)^3)-c.pot(2)).pot(2))
  /( (a-b.conjugada())^6)).pot(3)).ver();

cout<<"Forma 2\n= ";
((((((a.conjugada()+b)^3)-c.pot(2)).pot(2))
  /( (a-b.conjugada())^6))^3).ver();

getch();
}
