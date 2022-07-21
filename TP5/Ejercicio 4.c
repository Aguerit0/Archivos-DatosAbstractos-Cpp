#include <stdio.h>
#include <stdlib.h>


/* Crear una lista con números enteros permitir mostrar los elementos de la pila sin
perder los valores pasándolas a otra pila. Luego volver los elementos a su lugar
original. */

typedef int Objt, Objt2;

typedef struct{
	Objt *contenido;
	int cima;
	int tammax;
}Pila1;

typedef struct{
	Objt2 *contenido;
	int cima;
	int tammax;
}Pila2;


void presentacion(int *p);
void crear_pila1(Pila1 *pila1, int tam);
void crear_pila2(Pila2 *pila2, int tam);
int pila_llena(Pila1 pila1);
int pila_vacia(Pila1 pila1);
void ingreso_insercion(Pila1 *pila1, int tam);
Objt vaciar(Pila1 *pila1, Pila2 *pila2);
void mostrarpila(Pila1 pila1, Pila2 pila2);
void insertar_nuevamente(Pila1 *pila1, Pila2 *pila2, int tam);





int main(int argc, char *argv[]) {
	int tamaniomax;
	Pila1 pila1;
	Pila2 pila2;

	presentacion(&tamaniomax);
	crear_pila1(&pila1, tamaniomax);
	crear_pila2(&pila2, tamaniomax);
	ingreso_insercion(&pila1, tamaniomax);
	
	mostrarpila(pila1, pila2);
	insertar_nuevamente(&pila1, &pila2, tamaniomax);
	// MOSTRAR OTRA VEZ PARA VER SI LOS DATO SE GUARDARON
	// mostrarpila(pila1, pila2);
	return 0;
}


// PRESENTACION + INGRESO DEL TAMAÑO DEL ARRAY
void presentacion(int *p){
	int x;
	
	printf("\t\t\t---------- BIENVENIDO ----------\n\n\n");
	printf("\tLOS NUMEROS INGRESADOS SE MOSTRARAN EN ORDEN INVERSO EN FORMA DE COLUMNA. \n\n\n");
	printf("\tINGRESE LA CANTIDAD DE NUMEROS A INGRESAR: ");
	scanf("%d", &x);
	*p = x;
	
	printf("\n\n\n\n\t");
	system("PAUSE");
	system("cls");
}



// CREACION DE PILA, SE RESERVA MEMORIA DINAMICAMENTE
//PILA 1
void crear_pila1(Pila1 *pila1, int tam){
	
	// ASIGNACION MEMEORIA DINAMICA
	Objt *elem;
	elem = (Objt *)malloc(sizeof(Objt)*tam);
	//SE VERIFICA QUE SE RESERVÓ MEMORIA
	if (elem==NULL){
		printf("\n\tNO SE PUDO RESERVAR MEMEORIA EN PILA.");
		exit(-1);
	}
	
	pila1->contenido = elem;
	pila1->cima = (-1); 
	pila1->tammax = tam;
}

//PILA2
void crear_pila2(Pila2 *pila2, int tam){
	
	// ASIGNACION MEMEORIA DINAMICA
	Objt2 *elem;
	elem = (Objt2 *)malloc(sizeof(Objt2)*tam);
	//SE VERIFICA QUE SE RESERVÓ MEMORIA
	if (elem==NULL){
		printf("\n\tNO SE PUDO RESERVAR MEMEORIA EN PILA.");
		exit(-1);
	}
	
	pila2->contenido = elem;
	pila2->cima = (-1); 
	pila2->tammax = tam;
}

// VERIFICACION LLENADO DE PILA
int pila_llena(Pila1 pila1){
	if (pila1.cima==(pila1.tammax-1)){
		return 1;
	}else{
		return 0;
	}
}

// VERIFICACION VACIADO DE PILA
int pila_vacia(Pila1 pila1){
	if (pila1.cima==(-1)){
		return 1;
	}else{
		return 0;
	}
}

// INGRESO DE DATOS PARA LA INSERCION EN LA PILA
void ingreso_insercion(Pila1 *pila1, int tam){
	int i; 
	Objt elem;
	
	printf("\n\n\tPOR FAVOR, CARGUE LOS SIGUIENTES DATOS: \n\n");
	for (i=0; i<tam; i++){
		printf("\t%i) NUMERO: ",i+1);
		scanf("%d", &elem);
		
		// SE VERIFICA QUE LA PILA NO ESTE LLENA
		if(pila_llena(*pila1)){
	    	puts("PILA LLENA");
	    	exit(1);
    	}
	
    	pila1->cima++;
    	pila1->contenido[pila1->cima] = elem;
	}
	
	printf("\n\n\n\n\t");
	system("PAUSE");
	system("cls");
}


// EXTRACCION ELEMENTOS DE LA PILA
Objt vaciar(Pila1 *pila1, Pila2 *pila2){
	// SE VERIFICA QUE LA PILA NO ESTE VACIA
	if (pila_vacia(*pila1)){
		puts("\tPILA VACIA");
	}
	
	// SE EXTRAE LOS DATOS DE LA PILA
	Objt temp = pila1->contenido[pila1->cima];
	pila1->cima--;
	
	// INSERCION DE LOS DATOS DE PILA1 A PILA2
    pila2->cima++;
	pila2->contenido[pila2->cima] = temp;
	return temp;
}

// MOSTRAR ELEMENTOS DE LA PILA 1
void mostrarpila(Pila1 pila1, Pila2 pila2){
	printf("\n\n\tLOS ELEMENTOS EXTRAIDOS DE LA PILA SON:\n\n");
	while (!pila_vacia(pila1)){
		printf("\t%d\n",vaciar(&pila1, &pila2));
	}
	
	printf("\n\n\n\n\t");
	system("PAUSE");
	system("cls");
}


// SE INSERTA LOS DATOS ANTIGUOS EN LA PILA ORIGINAL
void insertar_nuevamente(Pila1 *pila1, Pila2 *pila2, int tam){
	
	// INSERCION DE DATOS NUEVAMENTE A LA PILA1
	pila2->cima++;
	Objt2 temp = pila2->contenido[pila2->cima];
	pila1->contenido[pila1->cima] = temp;
}


