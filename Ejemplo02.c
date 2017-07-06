#include <stdio.h>
#include <stdlib.h> /*malloc()*/
#include <string.h> /*atoi()*/
char *MES[]={
  "enero","febrero","marzo","abril","mayo","junio","julio",
  "agosto","septiembre","octubre","noviembre","dicembre"
};/*declaracion por extension*/

struct Fecha{
  int dia;
  int mes;
  int n;
  int *intPt;
};
typedef struct Fecha FechaType;

/**
 Los dos ultimos argumentos deben ser el numero del 
 dia del mes y el numero del mes 0 para enero, 
 1 para febrero, 2 para marzo, etc.
*/
/*
     Julio 2017       
do lu ma mi ju vi sá  
                   1  
 2  3  4  5  6  7  8  
 9 10 11 12 13 14 15  
16 17 18 19 20 21 22  
23 24 25 26 27 28 29  
30 31                 
*/
void set_Fecha(FechaType*,int,int);
void set_Fecha_lunes(FechaType*,int,int);
void set_Fecha_martes(FechaType*,int,int);
void set_Fecha_miercoles(FechaType*,int,int);
void set_Fecha_jueves(FechaType*,int,int);
void set_Fecha_viernes(FechaType*,int,int);
void set_Fecha_sabado(FechaType*,int,int);
void set_Fecha_domingo(FechaType*,int,int);

FechaType* funcion(FechaType* ftPt); 
void FuncionEvaluacion(FechaType *ftPt);
void print_FechaType(FechaType *ftPt);
int cuenta(FechaType *FT,int liminf,int limsup);

int main(int argc,char *argv[]){
  int i;
  FechaType *fecha=(FechaType*)malloc(sizeof(FechaType));
  FechaType *other=(FechaType*)malloc(sizeof(FechaType));
  if(argc<3){
    printf("FORMA DE USO: %s <dia> <mes>\n",argv[0]);
    exit(0);
  }
  set_Fecha(fecha,atoi(argv[1]),atoi(argv[2]));
  for(i=0;i<fecha->n;i++)
    //printf("%i de %i de 2016\n",*(fecha->intPt+i),fecha->mes);
    printf("%i de %s de 2016\n",*(fecha->intPt+i),MES[fecha->mes]);

  printf("\n/*****************************************************/");
  printf("\nETS SOTR Uso de apuntadores y estructuras en lenguaje C");
  printf("\n/*****************************************************/");

  set_Fecha_domingo(fecha,atoi(argv[1]),atoi(argv[2]));
  printf("\nFechas correspondientes a los dias domingo de julio de \
2017.\n");
  for(i=0;i<fecha->n;i++)
    printf("%i de %s de 2017\n",*(fecha->intPt+i),MES[fecha->mes]);

  set_Fecha_lunes(other,atoi(argv[1]),atoi(argv[2]));
  printf("\n");
  printf("\nFechas correspondientes a los dias lunes de julio de \
2017.\n");
  for(i=0;i<fecha->n;i++)
    printf("%i de %s de 2017\n",*(other->intPt+i),MES[fecha->mes]);

  printf("\n");
  FechaType arr[2];
  arr[0]=*fecha;
  arr[1]=*other;
  FuncionEvaluacion(arr);
//  FuncionEvaluacion(funcion(fecha));

  /*Otra forma de inicializar estructuras (gcc)*/
//  struct Fecha fecha1={
//    .dia=18,
//    .mes=1,
//    .n=4,
//    .intPt=(int*)malloc(4*sizeof(int)),
//  };
//  *(fecha1.intPt+0)=4;
//  *(fecha1.intPt+1)=11;
//  *(fecha1.intPt+2)=18;
//  *(fecha1.intPt+3)=25;
//  fecha=&fecha1;
//  printf("/****************************/\n");
//  for(i=0;i<fecha->n;i++)
//    printf("%i de %s de 2016\n",*(fecha->intPt+i),MES[fecha->mes]);

  return 0;
}

void set_Fecha(FechaType* f,int d,int m){
  f->dia=d;f->mes=m;f->n=5;
  f->intPt=(int*)malloc(5*sizeof(int));
  *(f->intPt+0)=1;//f->intPt[0]=1;
  *(f->intPt+1)=8;//f->intPt[1]=8;
  *(f->intPt+2)=15;//f->intPt[2]=15;
  *(f->intPt+3)=22;//f->intPt[3]=22;
  *(f->intPt+4)=29;//f->intPt[4]=29;
}

void set_Fecha_lunes(FechaType*f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=5;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  *(f->intPt+0)=3; 
  *(f->intPt+1)=10;
  *(f->intPt+2)=17;
  *(f->intPt+3)=24;
  *(f->intPt+4)=31;
}
void set_Fecha_martes(FechaType*f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=4;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  f->intPt[0]=4;
  f->intPt[1]=11;  
  f->intPt[2]=18;
  f->intPt[3]=25;
}
void set_Fecha_miercoles(FechaType*f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=4;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  f->intPt[0]=5;
  f->intPt[1]=12;  
  f->intPt[2]=19;
  f->intPt[3]=26;
}
void set_Fecha_jueves(FechaType*f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=4;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  f->intPt[0]=6;
  f->intPt[1]=13;  
  f->intPt[2]=20;
  f->intPt[3]=27;
}
void set_Fecha_viernes(FechaType*f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=4;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  f->intPt[0]=7;
  f->intPt[1]=14;  
  f->intPt[2]=21;
  f->intPt[3]=28;
}
void set_Fecha_sabado(FechaType*f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=5;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  *(f->intPt+0)=1;//f->intPt[0]=1;
  *(f->intPt+1)=8;//f->intPt[1]=8;
  *(f->intPt+2)=15;//f->intPt[2]=15;
  *(f->intPt+3)=22;//f->intPt[3]=22;
  *(f->intPt+4)=29;//f->intPt[4]=29;
}
void set_Fecha_domingo(FechaType* f,int d,int m)
{
  f->dia=d;f->mes=m;f->n=5;
  f->intPt=(int*)malloc((f->n)*sizeof(int));
  f->intPt[0]=2;
  f->intPt[1]=9;  
  f->intPt[2]=16;
  f->intPt[3]=23;
  f->intPt[4]=30;
}

/**
 * Esta funcion espera que el apuntador que recibe como argumento
 * apunte al menos a dos FechaType (struct Fecha).
 */
void FuncionEvaluacion(FechaType* ftPt)
{
  printf("En FuncionEvaluacion:\n");
  print_FechaType(ftPt);
  printf("\n");
  print_FechaType(ftPt+1);
}//end FuncionEvaluacion() 

void print_FechaType(FechaType *ftPt)
{
  int i;
  for(i=0;i<ftPt->n;i++){
    printf("%i de %s de 2017\n",*(ftPt->intPt+i),MES[ftPt->mes]);
  }
}

FechaType *funcion(FechaType *F)
{
  int N1,N2,i;
  N1=cuenta(F,1,15); //N1+N2 debe ser igual a F->n
  N2=cuenta(F,16,31);//i.e. podria calcularse N2=F->n-N1
  FechaType *result=(FechaType*)malloc(2*sizeof(FechaType));
  result->n=N1;
  (result+1)->n=N2;
  result->intPt=(int*)malloc((result->n)*sizeof(int));
  for(i=0;i<N1;i++){//Aqui se esta suponiendo que las "fechas" estan
    *(result->intPt+i)=F->intPt[i];//originalmente en orden ascendente
  }
  //TODO inicializacion de la segunda FechaType
  //...
  return result;
}//end funcion()
































