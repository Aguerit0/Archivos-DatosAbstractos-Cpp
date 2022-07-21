#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Elemento
{
  char nombre[20];
  char descripcion[20];
  double precio;
  int cantidad;
  struct Elemento *abajo;
} Nodo;

int menu();
int Push(Nodo **cima);
void Pop(Nodo **cabeza);
void imprimirNodos(Nodo **cabeza, int cant);
void cantidadNodos(Nodo **cabeza);
void intercambiarNodos(Nodo **cabeza);

int main(){
  Nodo *cima;
  cima = NULL;
  int opc = 0, cant;
  do{
    opc = menu();
    switch (opc)
    {
    case 1:
      system("cls");
      cant = cant + Push(&cima);
      break;
    case 2:
      system("cls");
      Pop(&cima);
      break;
    case 3:
      system("cls");
      imprimirNodos(&cima, cant);
      break;
    case 4:
      system("cls");
      cantidadNodos(&cima);
      break;
    case 5:
      exit(-1);
    }
  } while (opc < 5);
  system("PAUSE");
  return 0;
}

int menu(){
  system("cls");
  int opc;
  printf("\n\t----------  MENU PRINCIPAL  ----------");
  printf("\n\n1- PUSH PILA");
  printf("\n2- POP PILA");
  printf("\n3- MOSTRAR PILA");
  printf("\n4- CANTIDAD DE PRODUCTOS");
  printf("\n5- SALIR");
  printf("\n\nSeleccione una opcion: ");
  scanf("%d", &opc);
  return opc;
}

int Push(Nodo **cima){
  int n, cant = 0;
  printf("\n\t----------  PUSH PILA  ----------");
  printf("\n\nCuantos productos desea agregar? ...");
  printf("\nIngresar cantidad: ");
  scanf("%d", &n);
  system("cls");
  printf("\n\t----------  PUSH PILA  ----------");
  do{
    Nodo *a;
    a = (Nodo *)malloc(sizeof(Nodo)); // Asigna nuevo nodo
    if (a == NULL){
      printf("\n\nNo hay espacio suficiente en la memoria...");
      exit(-1);
    }
    printf("\n\n*****  PRODUCTO %d  *****", cant + 1);
    printf("\nNombre: ");
    fflush(stdin);
    gets(a->nombre);
    fflush(stdin);
    printf("\nDescripcion: ");
    gets(a->descripcion);
    fflush(stdin);
    printf("\nPrecio: ");
    scanf("%lf", &a->precio);
    fflush(stdin);
    printf("\nCantidad: ");
    scanf("%d", &a->cantidad);
    cant++;
    a->abajo = NULL;
    if (cima != NULL){
      a->abajo = *cima;
    }
    *cima = a;
  }while (cant < n);
  return n;
}


void Pop(Nodo **cima){
  system("cls");
  Nodo *elem;
  printf("\n\t----------  POP PILA  ----------");
  if (*cima == NULL){
    printf("\n\nLA PILA ESTA VACIA, NO SE PUEDEN ELIMINAR ELEMENTOS\n");
    system("PAUSE");
  }
  else{
    elem = *cima;
    *cima = elem->abajo;
    printf("\n\n*****  DATOS EXTRAIDOS DE LA PILA *****");
    printf("\nNombre: %s", elem->nombre);
    printf("\nDescripcion: %s", elem->descripcion);
    printf("\nPrecio: %lf", elem->precio);
    printf("\nCantidad: %d", elem->cantidad);
    if (*cima == NULL){
        printf("\n\n*****  ELEMENTO TOPE DE LA PILA  *****");
        printf("\n\nElemento del tope de la pila: NULL\n");
        system("PAUSE");
    }
    else{
      printf("\n\n*****  ELEMENTO TOPE DE LA PILA  *****");
      printf("\nNombre: %s", (*cima)->nombre);
      printf("\nDescripcion: %s", (*cima)->descripcion);
      printf("\nPrecio: %lf", (*cima)->precio);
      printf("\nCantidad: %d\n", (*cima)->cantidad);
      system("PAUSE");
    }
    free(elem);
}
}

void cantidadNodos(Nodo **cima){
    printf("\n\t----------  CANTIDAD NODOS  ----------");
    Nodo *a;
    a = *cima;
    int cant=0;
    while(a!=NULL){
        cant++;
        a = a->abajo;
    }
    printf("\n\nLa cantidad de nodos es: %d\n",cant);
    system("PAUSE");
}


void imprimirNodos(Nodo **cima, int cant){
    Nodo *a;
    printf("\n\t----------  IMPRIMIR PILA  ----------");
    if(*cima==NULL){
        printf("\n\nLa lista esta vacia ...\n");
        system("PAUSE");
    }
    a=*cima;
    while(a!=NULL){
        printf("\n\n*****  ELEMENTO %d  *****",cant);
        printf("\nNombre: %s", a->nombre);
        printf("\nDescripcion: %s", a->descripcion);
        printf("\nPrecio: %lf", a->precio);
        printf("\nCantidad: %d\n", a->cantidad);
        cant--;
        a = a->abajo;
    }
    printf("\n");
    system("PAUSE");
}

void intercambiarNodos(Nodo **cima){
    
}