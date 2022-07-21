#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

struct nodo{
	int codigo;
	char descripcion[20];
	double precio;
	int cantidad;
	struct nodo *sgte;
};
typedef struct nodo *producto;
producto inicio, fin;


void agregarProducto(producto *inicio, producto *fin){
	producto p;
	p = (struct nodo*)malloc(sizeof(struct nodo));//asigna un nodo nuevo
	printf("\n\t----------  AGREGAR PRODUCTO  ----------");
	printf("\n\nCodigo: ");fflush(stdin);
	scanf("%d",p->codigo);
	printf("\nDescripcion: ");fflush(stdin);
	gets(p->descripcion);
	printf("\nPrecio: ");fflush(stdin);
	scanf("%lf",&p->precio);
	printf("\nCantidad: ");fflush(stdin);
	scanf("%d",&p->cantidad);
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
	printf("\nProducto agregeado correctamente... ");
}


int cantidadRegistros(producto inicio){
	int cant=0;
	while(inicio!=NULL){
		cant++;
		inicio = inicio->sgte;
	}
	printf("\n\t----------  CANTIDAD DE PRODUCTOS  ----------");
	printf("\n\nCANTIDAD DE REGISTROS: %d", cant);
	return cant;
}

void mostrarLista(producto inicio){
	int i=0;
		printf("\n\t----------  MOSTRAR PRODUCTOS  ----------");
		while(inicio != NULL){	
			printf("\n\n*** PRODUCTO %d ***",i+1);
			printf("\nCodigo: %d",inicio->codigo);
			printf("\nDescripcion: %s",inicio->descripcion);
			printf("\nPrecio: %0.2f",inicio->precio);
			printf("\nCantidad: %d",inicio->cantidad);
			i++;
			inicio = inicio->sgte;
		}
		if(i==0){
			printf("\n\nPrimero debe agregar un producto...");
		}
}

void ordenarLista(producto inicio){
	printf("\n\t----------  ORDENAR PRODUCTOS  ----------");
	if(inicio==NULL){
		printf("\nPrimero debe agregar un producto...");
	}
	while(inicio!=NULL){
		producto p;
		p = inicio->sgte;
		while(p!=NULL){
			if(inicio->cantidad > p->cantidad){
				int auxCodigo, auxCantidad; double auxPrecio; char auxDescripcion[20];
				//codigo
				auxCodigo = p->codigo;
				p->codigo = inicio->codigo;
				inicio->codigo = auxCodigo;
				//descripcion
				strcpy(auxDescripcion, p->descripcion);
				strcpy(p->descripcion, inicio->descripcion);
				strcpy(inicio->descripcion, auxDescripcion);
				//precio
				auxPrecio = p->precio;
				p->precio = inicio->precio;
				inicio->precio = auxPrecio;
				//cantidad
				auxCantidad = p->cantidad;
				p->cantidad = inicio->cantidad;
				inicio->cantidad = auxCantidad;
			}
			p = p->sgte;
		}
		inicio = inicio->sgte;
	}
	printf("\nSe ordenaron los productos correctamente...");
	printf("\nVuelva al menu principal y seleccione la opcion 'MOSTRAR PRODUCTOS'");
}

void menu(){
	system("cls");
	printf("\n\n\t\t----------  MENU PRINCIPAL  ----------");
	printf("\n\n1- AGREGAR PRODUCTO");
	printf("\n2- ORDENAR PRODUCTOS");
	printf("\n3- MOSTRAR PRODUCTOS");
	printf("\n4- CANTIDAD DE PRODUCTOS");
	printf("\n5- SALIR");
	printf("\n\nElige una opcion: ");
}

int main(){
	inicio = NULL;
	fin = NULL;
	int opc, ord, cant;
	do{
		menu();
		scanf("%d", &opc);
		switch(opc){
		case 1: system("cls");
				agregarProducto(&inicio, &fin);
				break;
		case 2: 
				system("cls");
				ordenarLista(inicio);
				break;
		case 3: system("cls");
				mostrarLista(inicio);
				break;
		case 4:
				system("cls");
				cantidadRegistros(inicio);
				break;
		case 5: exit(-1);
		}
		printf("\n\n");
		getch();
	}while(opc!=6);
	exit(-1);
}