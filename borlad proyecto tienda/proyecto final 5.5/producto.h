struct fecha{
char dia[3], mes[4], year[5];
};
//******************************************************************************
class producto{
private:
char codigo[9];
char grupoproducto[30];
char productoespecifico[60];
char unidad[3]; //lista de unidades
char lugar[6];//change lugar to almacen te bota 3 opciones

double precio;//por unidad
double preciosugerido;
fecha fechacompra;
double cancomprada;
char numboleta[8];
char tipoboleta[3];


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

precio=pre;
preciosugerido=pre1;
strcpy(fechacompra.dia,di);
strcpy(fechacompra.mes,me);
strcpy(fechacompra.year,yea);
cancomprada=cancom;
strcpy(numboleta,nubole);
strcpy(tipoboleta,tibole);

}
//**************************************************************************
void setcodigo(char *cod){strcpy(codigo,cod);}

void setgrupoproducto(char *grup){strcpy(grupoproducto,grup);}
void setproductoespecifico(char *espes){strcpy(productoespecifico,espes);}
void setunidad(char *unin){strcpy(unidad,unin);}
void setlugar(char *lug){strcpy(lugar,lug);}

void setprecio(double pre){precio=pre;}
void setpreciosugerido(double pre1){preciosugerido=pre1;}
void setfecha(char *di,char *me,char *yea){strcpy(fechacompra.dia,di);
                                        strcpy(fechacompra.mes,me);
                                        strcpy(fechacompra.year,yea);}
void setcancomprada(double cancom){cancomprada=cancom;}
void setnumboleta(char *nubole){strcpy(numboleta,nubole);}
void settipoboleta(char *tibole){strcpy(tipoboleta,tibole);}
//*************************************************************************
char *getcodigo(){return codigo;}

char *getgrupoproducto(){return grupoproducto;}
char *getproductoespecifico(){return productoespecifico;}
char *getunidad(){return unidad;}
char *getlugar(){return lugar;}

double getprecio(){return precio;}
double getpreciosugerido(){return preciosugerido;}
fecha getfecha(){return fechacompra;}
double getcancomprada(){return cancomprada;}
char *getnumboleta(){return numboleta;}
char *gettipoboleta(){return tipoboleta;}
//******************************************************************************
void change();
void lista();

};
void producto::change(){char op,opl;
 clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista ();

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
                do{cout<<"\n\t\tDia....: ";gets(fechacompra.dia);
              	 if(strlen(fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
              	 }while( strlen(fechacompra.dia)>3);
                do{cout<<"\t\tMes....: ";gets(fechacompra.mes);
      	  			if(strlen(fechacompra.mes)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
      				}while( strlen(fechacompra.mes)>8);
     					 do{cout<<"\t\tYear....: ";gets(fechacompra.year);
      			 if(strlen(fechacompra.year)>5){cout<<"\t\t\aMaximo 5 cifras\n";}
      			 }while( strlen(fechacompra.year)>5);
     					cout<<"\n\t\t"<<fechacompra.dia<<" / "<<fechacompra.mes;
            	 cout<<" / "<<fechacompra.year<<"\n\n";  break;

      case'7':  cout<<"\tPrecio ........:";cin>>precio; break;
      case'8':  cout<<"\tPrecio sugerido.:";cin>>preciosugerido; break;
       case'9':  cout<<"\tCantidad comprada.:";cin>>cancomprada; break;
       case'a':  do{cout<<"\tTipo de documento..:";

                  	cout<<"\n\t\t\t1.- BOLETA\n";
                     cout<<"\t\t\t2.- FACTURA\n";
                     cout<<"\t\t\t3.- OTROS\n"; opl=getch();
                  switch(opl){
                   case '1': strcpy(tipoboleta,"B");n=1;break;
                   case '2': strcpy(tipoboleta,"F");n=1;break;
                   case '3': strcpy(tipoboleta,"SN");n=1;break;
						}
                 }while(n!=1);break;




          case'b':  do{cout<<"\tNumero de Documento........:";gets(numboleta);
                 if(strlen(numboleta)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                }while( strlen(numboleta)>8); break;
      }
     clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista ();

}


//*************************************************************************
void producto::lista(){
cout<<"\n\t[1].- Codigo................:   "<<codigo<<endl;
cout<<"\n\t[2].- Grupo Producto........:   "<<grupoproducto<<endl;
cout<<"\n\t[3].- Producto Especifico...:   "<<productoespecifico<<endl;
cout<<"\n\t[4].- Unidad................:   "<<unidad<<endl;
cout<<"\n\t[5].- Lugar de Almacen......:   "<<lugar<<endl;
cout<<"\n\t[6].- Fecha de compra.......:   ";
cout<<fechacompra.dia<<" / "<<fechacompra.mes;
cout<<" / "<<fechacompra.year<<"\n";
cout<<"\n\t[7].- Precio por "<<unidad<<"  ..:   "<<precio<<endl;
cout<<"\n\t[8].- Precio de venta sugerido x "<<unidad<<"  ..:   "<<preciosugerido<<endl;
cout<<"\n\t[9].- Cantidad Comprada.....:   "<<cancomprada<<endl;
cout<<"\n\t[A].- Tipo de documento.....:   "<<tipoboleta<<endl;
cout<<"\n\t[B].- Numero de Documento...:   "<<numboleta<<endl;

}
//*************************************************************************