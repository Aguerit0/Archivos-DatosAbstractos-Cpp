#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct {
    int codigo;
    char descripcion[41];
    float precio;
    int borrado;
} tproducto;




void continuar()
{
    printf("\n\nPresione una tecla para continuar");
    getch();
}

void crear()
{
    FILE *arch;
    arch=fopen("productos.dat","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
    printf("\nEl archivo se creo exitosamente !!!");
    continuar();
}


void cargar()
{
    FILE *arch;
    arch=fopen("productos.dat","ab");
    if (arch==NULL)
        exit(1);
    tproducto producto;
    printf("\n\t--------------  CARGAR PRODUCTO  --------------");
    printf("\n\nCodigo: ");
    scanf("%i",&producto.codigo);fflush(stdin);
    printf("\nDescripcion: ");
    gets(producto.descripcion);
    printf("\nPrecio: ");
    scanf("%f",&producto.precio);fflush(stdin);
    fwrite(&producto, sizeof(tproducto), 1, arch);
    fclose(arch);
    continuar();
}

void listado()
{
    FILE *arch;
    arch=fopen("productos.dat","rb");
    if (arch==NULL)
        exit(1);
    tproducto producto;
    fread(&producto, sizeof(tproducto), 1, arch);
    printf("\n\t--------------  LISTADO DE PRODUCTOS  --------------");
    int i=1;
    while(!feof(arch))
    {
        printf("\n\n*** PRODUCTO %d ***",i);
        i++;
        printf("\nCodigo: %i",producto.codigo);
        printf("\nDescripcion: %s",producto.descripcion);
        printf("\nPrecio: %0.2f",producto.precio);
        fread(&producto, sizeof(tproducto), 1, arch);
    }
    fclose(arch);
    continuar();
}

void consulta()
{
    FILE *arch;
    arch=fopen("productos.dat","rb");
    if (arch==NULL)
        exit(1);
    printf("\n\t--------------  CONSULTAR PRODUCTO  --------------");
    printf("\n\nIngrese el codigo de producto a consultar: ");
    int cod;
    scanf("%i", &cod);
    tproducto producto;
    int existe=0;
    fread(&producto, sizeof(tproducto), 1, arch);
    while(!feof(arch))
    {
        if (cod==producto.codigo)
        {
           	printf("\n\n*** PRODUCTO ENCONTRADO ***");
        	printf("\nCodigo: %i",producto.codigo);
        	printf("\nDescripcion: %s",producto.descripcion);
        	printf("\nPrecio: %0.2f",producto.precio);
           	existe=1;
           	break;
        }
        fread(&producto, sizeof(tproducto), 1, arch);
    }
    if (existe==0)
        printf("\n\nEl codigo ingresado no coincide con ningun producto");
    fclose(arch);
    continuar();
}

void modificacion()
{
    FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    printf("\n\t--------------  MODIFICAR PRODUCTO  --------------");
    printf("\n\nIngrese el codigo de producto a modificar: ");
    int cod;
    scanf("%i", &cod);
    tproducto producto;
    int existe=0;
    fread(&producto, sizeof(tproducto), 1, arch);
    while(!feof(arch))
    {
        if (cod==producto.codigo)
        {
           	printf("\n\n*** PRODUCTO ENCONTRADO ***");
        	printf("\nCodigo: %i",producto.codigo);
        	printf("\nDescripcion: %s",producto.descripcion);
        	printf("\nPrecio: %0.2f",producto.precio);
           	printf("\n\nIngrese nuevo precio: ");
           scanf("%f",&producto.precio);
           int pos=ftell(arch)-sizeof(tproducto);
           fseek(arch,pos,SEEK_SET);
           fwrite(&producto, sizeof(tproducto), 1, arch);
           printf("\nEl precio se modifico correctamente...");
           existe=1;
           break;
        }
        fread(&producto, sizeof(tproducto), 1, arch);
    }
    if (existe==0)
        printf("\n\nEl codigo ingresado no coincide con ningun producto...");
    fclose(arch);
    continuar();
}

void bajaLogica(){
    FILE *arch;
    arch=fopen("productos.dat","wb");
    if (arch==NULL){
    	printf("\nEl archivo no existe");
        exit(1);
	}
    printf("\n\t--------------  BAJA LOGICA  --------------");
    printf("\n\nIngrese el codigo de producto: ");
    int cod;
    scanf("%i", &cod);
    tproducto producto;
    fread(&producto, sizeof(tproducto), 1, arch);
    while(!feof(arch))
    {
        if (cod==producto.codigo)
        {
        	printf("\nSe realizo la baja fisica exitosamente !!!");
            fseek(arch, cod, SEEK_SET);
            fread(&producto, sizeof(tproducto),1,arch);
            producto.borrado = 0;
            fseek(arch, cod, SEEK_SET);
            fwrite(&arch, sizeof(tproducto),1,arch);
            system("pause");
        }
        else{
            printf("\n\nEl codigo ingresado no coincide con ningun producto");
            return;
        }
    }
    fclose(arch);
    continuar();
}
void menu(){
		int opcion;
        system("cls");
        printf("\n\t--------------  MENU PRINCIPAL  ---------------");
        printf("\n\n1 - CREAR UN ARCHIVO BINARIO: \"productos.dat\"\n");
        printf("2 - CARGAR UN PRODUCTO\n");
        printf("3 - LISTAR TODOS LOS PRODUCTOS\n");
        printf("4 - CONSULTAR UN PRODUCTO\n");
        printf("5 - MODIFICAR UN PRODUCTO \n");
        printf("6 - BAJA FISICA\n");
        printf("7 - Salir\n\n");
        printf("\n\nIngrese una opcion: ");
}
int main()
{
    int opcion;
    do {
    	menu();
    	scanf("%i",&opcion);
        switch (opcion) {
            case 1:
                
                crear();
                break;
            case 2:
                system("cls");
                cargar();
               break;
            case 3:
                system("cls");
                listado();
               break;
            case 4:
                system("cls");
                consulta();
                break;
            case 5:
                system("cls");
                modificacion();
                break;
            case 6:
                system("cls");
                bajaLogica();
                break;
        }
        	
    } while (opcion!=7);
    return 0;
} 
