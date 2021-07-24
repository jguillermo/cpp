 //class productoA
class productoA{
private:
fstream archivo;
producto unproducto;
int n,tamreg,error;
public:
productoA(){
archivo.open("productofinal.dat",ios::in|ios::out|ios::binary);
if(!archivo){error=1;}
else{
error=0;
	tamreg=sizeof(unproducto);
   archivo.seekg(0,ios::end);
   n=archivo.tellg()/tamreg;
}

}
~productoA(){if(!error)archivo.close();}
void addproducto(producto obj){
archivo.seekp(0,ios::end);
archivo.write((char*)& obj,tamreg);
n++;
}

producto getproducto(int i){
archivo.seekg(i*tamreg,ios::beg);
archivo.read((char*)&unproducto,tamreg);
return unproducto;
}

void setproducto(producto obj,int i){
archivo.seekp(i*tamreg,ios::beg);
archivo.write((char*)& obj,tamreg);
}

int numproductos(){return n;}
void setn(int n){this->n=n;}

int buscaproducto(char *busca){ producto productoleido;
for(int p=0;p<n;p++){
archivo.seekg(p*tamreg,ios::beg);
archivo.read((char*)&productoleido,tamreg);
//if(strcmp(productoleido.getgrupoproducto(),busca)==0)return p;
if(strcmp(productoleido.getproductoespecifico(),busca)==0)return p;

}
return -1;
}

int buscaunidad(char *busca){ producto productoleido;
for(int p=0;p<n;p++){
archivo.seekg(p*tamreg,ios::beg);
archivo.read((char*)&productoleido,tamreg);
if(strcmp(productoleido.getunidad(),busca)==0)return p;
}
return -1;
}

//******************************************************************************
int buscatiponum2(char *tipo,char *num,int i){
   int con=0;
   producto   productoleido5=getproducto(i);

       for(int j=0;j<=productoleido5.getla();j++)
       {  con=0;
         if(strcmp(productoleido5.gettipoboleta(j),tipo)==0)con++;
         if(strcmp(productoleido5.getnumboleta(j),num)==0)con++;
            if(con==2){return j;}


		}


   return -1;
}

//**********************************************************************

double sumatotalboleta(char *tipo,char *num){
    int la;
    producto ulproducto;
    double to=0.0;
   for(int i=0;i<n;i++)
       {
         la=buscatiponum2(tipo,num,i);
           if(la!=-1)
              {   ulproducto=getproducto(i);
               to=to+ulproducto.getprecio(la);
              }
         }
  return to;
 }
 //******************************************************************************
int buscafecha(fecha busca,int i){
int con=0;
fecha fbusca;
producto   productoleido5=getproducto(i);

    for(int j=0;j<=productoleido5.getla();j++)
       {  con=0;
       fbusca=productoleido5.getfecha(j);

      if(strcmp(fbusca.mes,busca.mes)==0)con++;
      if(strcmp(fbusca.year,busca.year)==0)con++;
            if(con==2){return j;}


		}

return -1;

}

//******************************************************************************
int buscacodigo(char *cod){ producto productoleido;
for(int p=0;p<n;p++){
archivo.seekg(p*tamreg,ios::beg);
archivo.read((char*)&productoleido,tamreg);
if(strcmp(productoleido.getcodigo(),cod)==0)return p;

}
return -1;}
};