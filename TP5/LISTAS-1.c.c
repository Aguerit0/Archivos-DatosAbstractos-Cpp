#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct nodo{
	char codigo[20];
	char descripcion[20];
	double precio;
	double cantidad;
	struct nodo *sgte;
};
typedef struct nodo *producto;
producto inicio, fin;


//FUNCION PARA AGREGAR PRODUCTOS A LA LISTA
void agregarProducto(producto *inicio, producto *fin){
	producto p;
	p = (struct nodo*)malloc(sizeof(struct nodo));
	printf("\n\t----------  AGREGAR PRODUCTO  ----------");
	//fflush(stdout) --> para vaciar el buffer de escritura
	printf("\n\nCodigo: ");fflush(stdin);
	gets(p->codigo);
	printf("\nDescripcion: ");fflush(stdin);
	gets(p->descripcion);
	printf("\nPrecio: ");fflush(stdin);
	scanf("%lf",&p->precio);
	printf("\nCantidad: ");fflush(stdin);
	scanf("%lf",&p->cantidad);
	if(*inicio==NULL){
		p->sgte = *inicio;
		*inicio=p;
		*fin=p;
	}
	else{
		p->sgte = (*fin)->sgte;
		(*fin)->sgte = p;
		*fin = p;
	}
	printf("\nLista de productos cargada... ");
}


//FUNCION PARA MOSTRAR PRODUCTOS DE LA LISTA
void mostrarLista(producto inicio, int ord){
	int i=0;
	if(ord==0){
		printf("\n\t----------  PRODUCTOS DE LA LISTA  ----------");
		while(inicio != NULL){	
			printf("\n\n*** PRODUCTO %d ***",i+1);
			printf("\nCodigo: %s",inicio->codigo);
			printf("\nDescripcion: %s",inicio->descripcion);
			printf("\nPrecio: %0.2f",inicio->precio);
			printf("\nCantidad: %0.2f",inicio->cantidad);
			i++;
			inicio = inicio->sgte;
		}
		if(i==0){
			printf("\n\nLa lista esta vacia...");
		}
	}
	else if(ord==1){
		printf("\n\tPRODUCTO \tCODIGO \t\tDESCRIPCION \t\tPRECIO \t\tCANTIDAD\n");
		while(inicio!=NULL){
			printf("\n\t   %i \t\t%s \t\t%s \t\t\t%0.2f \t\t%0.2f", i+1, inicio->codigo, inicio->descripcion, inicio->precio, inicio->cantidad);
			inicio=inicio->sgte;
			i++;
		}
		if(i==0){
			printf("\n\nLa lista esta vacia...");
		}
	}
	
}

int ordenasLista(){
	int opc;
	system("cls");
	printf("\nDesea ordenar los productos por campo?     SI = 1 / NO = 2");
	printf("\nSeleccione una opcion: "); fflush(stdin);
	scanf("%d", &opc);
	
	if (opc==1){
		system("cls");
		printf("\nLa lista se ordeno con exito.\nVuelva al menu principal y seleccione la opcion de 'Mostrar lista'...");
     	return 1;
		getch();
	}
	if (opc==2){
	    system("cls");
	   	printf("\nLa lista se mostrara en el orden registrado.\nVuelva al menu principal y seleccione la opcion de 'Mostrar Lista'...");	
        return 0;
      	getch();
    }
}


void menu(){
	system("cls");
	printf("\n\n\t\t----------  MENU PRINCIPAL  ----------");
	printf("\n\n1- Agregar productos");
	printf("\n2- Ordenar productos");
	printf("\n3- Mostrar productos");
	printf("\n4- Salir");
	printf("\n\nElige una opcion: ");
}

int main(){
	inicio = NULL;
	fin = NULL;
	int opc, ord;
	do{
		menu();
		scanf("%d", &opc);
		switch(opc){
		case 1: system("cls");
				agregarProducto(&inicio, &fin);
				break;
		case 2: ord = ordenasLista();
				break;
		case 3: system("cls");
				mostrarLista(inicio, ord);
				break;
		case 4: exit(-1);
		}
		printf("\n\n");
		getch();
	}while(opc!=4);
	exit(-1);
}
