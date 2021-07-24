  struct fecha{
char dia[3], mes[4], year[5];
};
//******************************************************************************
struct var{

fecha fechacompra;
char numboleta[8];
char tipoboleta[3];
double cancomprada;
double precio;//por unidad
double preciosugerido;

};
//******************************************************************************
class producto{
private:
char codigo[9];
char grupoproducto[30];
char productoespecifico[60];
char unidad[3]; //lista de unidades
char lugar[6];//change lugar to almacen te bota 3 opciones

double totalcomprado;
int la;
var act[15];

public:
producto(){}
producto(char *cod,char *grup,char *espes,char *unin,
char *lug,double pre,double pre1,char *di,char *me,char *yea,double cancom,
char *nubole,char *tibole){
//codigo=cod;
strcpy(codigo,cod);
strcpy(grupoproducto,grup);
strcpy(productoespecifico,espes);
strcpy(unidad,unin);
strcpy(lugar,lug);

totalcomprado=cancom;
la=0;
act[0].preciosugerido=pre1;
act[0].precio=pre;
strcpy(act[0].fechacompra.dia,di);
strcpy(act[0].fechacompra.mes,me);
strcpy(act[0].fechacompra.year,yea);
act[0].cancomprada=cancom;
strcpy(act[0].numboleta,nubole);
strcpy(act[0].tipoboleta,tibole);

for(int ju=1;ju<=15;ju++){
act[ju].precio=0;
strcpy(act[ju].fechacompra.dia,"ND");
strcpy(act[ju].fechacompra.mes,"ND");
strcpy(act[ju].fechacompra.year,"ND");
act[ju].cancomprada=0;
strcpy(act[ju].numboleta,"ND");
strcpy(act[ju].tipoboleta,"ND");
act[ju].preciosugerido=0;
                           }
}
//**************************************************************************
void setcodigo(char *cod){strcpy(codigo,cod);}

void setgrupoproducto(char *grup){strcpy(grupoproducto,grup);}
void setproductoespecifico(char *espes){strcpy(productoespecifico,espes);}
void setunidad(char *unin){strcpy(unidad,unin);}
void setlugar(char *lug){strcpy(lugar,lug);}

void setprecio(double pre,int l){act[l].precio=pre;}
void setpreciosugerido(double pre1,int l){act[l].preciosugerido=pre1;}
void setfecha(char *di,char *me,char *yea,int l){strcpy(act[l].fechacompra.dia,di);
                                        strcpy(act[l].fechacompra.mes,me);
                                        strcpy(act[l].fechacompra.year,yea);}
void setcancomprada(double cancom,int l){act[l].cancomprada=cancom;}
void setnumboleta(char *nubole,int l){strcpy(act[l].numboleta,nubole);}                
void settipoboleta(char *tibole,int l){strcpy(act[l].tipoboleta,tibole);}
void settotalcomprado(double pr){totalcomprado=pr;}
void setla(int lug){la=lug;}
//*************************************************************************
char *getcodigo(){return codigo;}

char *getgrupoproducto(){return grupoproducto;}
char *getproductoespecifico(){return productoespecifico;}
char *getunidad(){return unidad;}
char *getlugar(){return lugar;}

double getprecio(int l){return act[l].precio;}
double getpreciosugerido(int l){return act[l].preciosugerido;}
fecha getfecha(int l){return act[l].fechacompra;}
double getcancomprada(int l){return act[l].cancomprada;}
char *getnumboleta(int l){return act[l].numboleta;}
char *gettipoboleta(int l){return act[l].tipoboleta;}
double gettotalcomprado(){return totalcomprado;}
int getla(){return la;}
//******************************************************************************
void change(int l);
void lista(int l);

};
void producto::change(int l){char op,opl;
 clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista (l);

cout<<"\n\nIngrese Opcion   :";
    op=getch();int n=0, nl=0;
     switch(op)
     {case'1': do{cout<<"\tCodigo............:";gets(codigo);

                 if(strlen(codigo)!=8){cout<<"\t\t\aDebe tener 8 cifras\n";}
               }while(strlen(codigo)!=8); break;
      case'2': do{cout<<"\tGrupo Producto............:";gets(grupoproducto);
               if(strlen(grupoproducto)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
               }while( strlen(grupoproducto)>30); break;
      case'3':  do{cout<<"\tProducto Especifico.............:";gets(productoespecifico);
                if(strlen(productoespecifico)>60){cout<<"\t\t\aMaximo 60 cifras\n";}
                 }while( strlen(productoespecifico)>60); break;
      case'4':  do{cout<<"\tUnidad........:";gets(unidad);
                 if(strlen(unidad)>2){cout<<"\t\t\aMaximo 2 cifras\n";}
                }while( strlen(unidad)>2); break;
      case'5':  do{cout<<"\tLugar de almacen..:";

                  	cout<<"\n\t\t\t1.- Tienda\n";
                     cout<<"\t\t\t2.- Casa\n";
                     cout<<"\t\t\t3.- Departamento\n"; opl=getch();
                  switch(opl){
                   case '1': strcpy(lugar,"tienda");nl=1;break;
                   case '2': strcpy(lugar,"casa");nl=1;break;
                   case '3': strcpy(lugar,"depa");nl=1;break;
						}
                 }while(nl!=1);break;
      case'6':  cout<<"\tFecha de compra........:";
                do{cout<<"\n\t\tDia....: ";gets(act[l].fechacompra.dia);
              	 if(strlen(act[l].fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
              	 }while( strlen(act[l].fechacompra.dia)>3);
                do{cout<<"\t\tMes....: ";gets(act[l].fechacompra.mes);
      	  			if(strlen(act[l].fechacompra.mes)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
      				}while( strlen(act[l].fechacompra.mes)>8);
     					 do{cout<<"\t\tYear....: ";gets(act[l].fechacompra.year);
      			 if(strlen(act[l].fechacompra.year)>5){cout<<"\t\t\aMaximo 5 cifras\n";}
      			 }while( strlen(act[l].fechacompra.year)>5);
     					cout<<"\n\t\t"<<act[l].fechacompra.dia<<" / "<<act[l].fechacompra.mes;
            	 cout<<" / "<<act[l].fechacompra.year<<"\n\n";  break;

      case'7':  cout<<"\tPrecio ........:";cin>>act[l].precio; break;
      case'8':  cout<<"\tPrecio sugerido.:";cin>>act[l].preciosugerido; break;
       case'9':  cout<<"\tCantidad comprada por "<<gets(unidad)<<" :";cin>>act[l].cancomprada; break;
       case'a':  do{cout<<"\tTipo de documento..:";

                  	cout<<"\n\t\t\t1.- BOLETA\n";
                     cout<<"\t\t\t2.- FACTURA\n";
                     cout<<"\t\t\t3.- OTROS\n"; opl=getch();
                  switch(opl){
                   case '1': strcpy(act[l].tipoboleta,"B");n=1;break;
                   case '2': strcpy(act[l].tipoboleta,"F");n=1;break;
                   case '3': strcpy(act[l].tipoboleta,"SN");n=1;break;
						}
                 }while(n!=1);break;




          case'b':  do{cout<<"\tNumero de Documento........:";gets(act[l].numboleta);
                 if(strlen(act[l].numboleta)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                }while( strlen(act[l].numboleta)>8); break;
      }
     clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista (l);

}


//*************************************************************************
void producto::lista(int l){
cout<<"\n\t[1].- Codigo................:   "<<codigo<<endl;
cout<<"\n\t[2].- Grupo Producto........:   "<<grupoproducto<<endl;
cout<<"\n\t[3].- Producto Especifico...:   "<<productoespecifico<<endl;
cout<<"\n\t[4].- Unidad................:   "<<unidad<<endl;
cout<<"\n\t[5].- Lugar de Almacen......:   "<<lugar<<endl;
cout<<"\n\t[6].- Fecha de compra.......:   ";
cout<<act[la].fechacompra.dia<<" / "<<act[l].fechacompra.mes;
cout<<" / "<<act[l].fechacompra.year<<"\n";
cout<<"\n\t[7].- Precio por "<<unidad<<"  ..:   "<<act[l].precio<<endl;
cout<<"\n\t[8].- Precio de venta sugerido x "<<unidad<<"  ..:   "<<act[l].preciosugerido<<endl;
cout<<"\n\t[9].- Cantidad Comprada.....:   "<<act[l].cancomprada<<endl;
cout<<"\n\t[A].- Tipo de documento.....:   "<<act[l].tipoboleta<<endl;
cout<<"\n\t[B].- Numero de Documento...:   "<<act[l].numboleta<<endl;

}
//*************************************************************************
