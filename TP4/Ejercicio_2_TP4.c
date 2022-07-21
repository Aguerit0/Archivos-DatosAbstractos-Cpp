#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//*NOTAS: EL ARCHIVO ADJUNTO CUENTA CON 40 PERSONAS REGISTRADAS*//
//        AUNQUE EL EJERCICIO NO LO PIDA EL ALGORITMO CUENTA CON UNA OPCION DE AGREGAR MAS PERSONAS AL REGISTRO*//

struct Nacimiento {
	int dia;
	int mes;
	int ano;
	
};
struct Beneficiarios {
  char Nombre [20];
  char Direccion [30];
  int Ingresos;
  int Hijos;
  int Documento; 
  char Sexo [10];
  char Estado_Civil [10];
  struct Nacimiento NAT;
};

void agregar_beneficiario(){
	
	
	FILE *Beneficiarios;
    Beneficiarios= fopen("Beneficiarios.dat","ab");
    if (Beneficiarios==NULL){
		printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
		exit(1);
	}
    struct Beneficiarios BNF;
    
	 
    printf("Ingrese nombre del beneficiario: \n\n");
	fflush(stdin);
	gets(BNF.Nombre);
	    	fflush(stdin);
    printf("Ingrese Direccion del beneficiario: \n\n");
        gets(BNF.Direccion);
    printf("Ingrese Ingresos del beneficiario: \n");
        	fflush(stdin);
        scanf("%d",&BNF.Ingresos);
        fflush(stdin);
    printf("Ingrese numero de Hijos del beneficiario: \n\n");
        	fflush(stdin);
        scanf("%d",&BNF.Hijos);
		fflush(stdin);
    printf("Ingrese Documento del beneficiario: \n\n");
        	fflush(stdin);
        scanf("%d",&BNF.Documento);
        fflush(stdin);
    printf("Ingrese Sexo del beneficiario: M/F \n\n");
        	fflush(stdin);
        gets(BNF.Sexo);
        fflush(stdin);
    printf("Ingrese Estado Civil del beneficiario: C/V/S \n\n");
        	fflush(stdin);
        gets(BNF.Estado_Civil);
        fflush(stdin);
    printf("Ingrese dia de nacimiento del beneficiario: \n\n");
        	fflush(stdin);
        scanf("%d",&BNF.NAT.dia);
        fflush(stdin);
    printf("Ingrese mes de nacimiento del beneficiario: \n\n");
        	fflush(stdin);
        scanf("%d",&BNF.NAT.mes);
        fflush(stdin);
    printf("Ingrese a%Co de nacimiento del beneficiario: \n\n",164);
        	fflush(stdin);
        scanf("%d",&BNF.NAT.ano);
        
    fwrite(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
		printf("\n\n\n");
	fclose(Beneficiarios);
	fflush(stdin);;
		}

void listar_varones(){
    int existe = 0;
    FILE *Beneficiarios;
    Beneficiarios= fopen("Beneficiarios.dat","rb");
    if (Beneficiarios==NULL)
    {
		printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
		exit(1);
	}
    struct Beneficiarios BNF;
	fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
	printf("Nombre        \t       DNI\n\n");
	while(!feof(Beneficiarios)){
		fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
		if (BNF.Ingresos>2500){
			printf("|%-20s|",BNF.Nombre);
			printf("|%-10d|\n",BNF.Documento);
			existe=1;
		}
		fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
	}	    
	if (existe==0)
        printf("No existe un beneficiario con un salario tan alto \n");
    
	printf("\n\n\n");
	fclose(Beneficiarios);
	fflush(stdin);}

void informe_varones(){
	FILE *Beneficiarios;
    Beneficiarios= fopen("Beneficiarios.dat","rb");
    if (Beneficiarios==NULL){
		printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
		exit(1);
	}
	printf("Ingrese el numero del mes de los Beneficiaros a consultar:");
    int mes;
    scanf("%i", &mes);
    struct Beneficiarios BNF;
    int existe=0;
    fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
    printf("Nombre\t\t       Direccion\tDNI\t    Hijos    Estado_Civil  Dia\n\n");
    fflush(stdin);
	while(!feof(Beneficiarios))
    {   fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
        if (mes==BNF.NAT.mes){
		   
    printf("|%-20s|",BNF.Nombre);
	printf("|%-15s|",BNF.Direccion);
	printf("|%-10d|",BNF.Documento);
	printf("|%-8d|",BNF.Hijos);
	printf("|%-12s|",BNF.Estado_Civil);
	printf(" %d\n",BNF.NAT.dia);
		
           existe=1;  
           
        }
       fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
    }
    if (existe==0)
        printf("No existe un beneficiario nacido ese mes \n");
    	printf("\n\n\n");
	fclose(Beneficiarios);
	fflush(stdin);}
    
void aportes(){
	double aporte, aporte_aux, porcentaje;
	char *S = "S"; char *V = "V";
	int e = 0;
	FILE *Beneficiarios;
    Beneficiarios= fopen("Beneficiarios.dat","r+b");
    if (Beneficiarios==NULL){
		printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
		exit(1);
	} 
    struct Beneficiarios BNF;

	fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);

	
	while(!feof(Beneficiarios)){
		aporte_aux = 0.0;
		fread(&BNF, sizeof(struct Beneficiarios), 1, Beneficiarios);
		
		if(BNF.Hijos >= 3 ){
			if ((strcmp(BNF.Estado_Civil, S)==0) || (strcmp(BNF.Estado_Civil, V)==0)){
				aporte_aux = 0.05;}}
	
		if (BNF.Ingresos>5000){
    		porcentaje = 0.05 + aporte_aux;
	    	aporte = BNF.Ingresos * porcentaje;
	    	
		}
	    if (BNF.Ingresos<=5000 && BNF.Ingresos>4500){
	    	porcentaje = 0.08 + aporte_aux;
    		aporte = BNF.Ingresos * porcentaje;
	  		
	    }
	   	if (BNF.Ingresos<=4500 && BNF.Ingresos>4000){
	   		porcentaje = 0.1 + aporte_aux;
	      	aporte = BNF.Ingresos * porcentaje;
	  		
	   	}
	    if (BNF.Ingresos<=4000 && BNF.Ingresos>=3500){
	    	porcentaje = 0.25 + aporte_aux;
	  		aporte = BNF.Ingresos * porcentaje;
	   		
	   	}
	  	if (BNF.Ingresos<3500){
	  		porcentaje = 0.35 + aporte_aux;
     		aporte = BNF.Ingresos * porcentaje;
	        
	    }
        printf("\n\n\t--------------- BENEFICIARIO INGRESADO %d ---------------\n",e+1);
		printf("\tNOMBRE Y APELLIDO: %s\n",BNF.Nombre);
		printf("\tDNI: %d\n",BNF.Documento);
		printf("\tSEXO: %s\n",BNF.Sexo);
		printf("\tINGRESOS: $%d\n",BNF.Ingresos);
		printf("\tPORCENTAJE ASIGNADO: %c%0.2f\n",37,porcentaje*100);
		printf("\tHIJOS: %d\n",BNF.Hijos);
		printf("\tESTADO CIVIL: %s\n",BNF.Estado_Civil);
		printf("\tAPORTE: $%0.2f\n\n",aporte);
	e++;
	}
     	printf("\n\n\n");
	 fclose(Beneficiarios);
     fflush(stdin);
		}



int main(){
  
  int opcion=1;
  while(opcion!=5)
    {   
	    printf("\t--------------- BIENVENIDO AL MENU DE REGISTRO DE (INSERTE ONG)----------------\n\n");
		printf("\nIngrese opci%cn:\n",162);
        printf("1-Agregar Beneficiario\n");
        printf("2-Informe de varones con ingresos mayores a $2500\n");
        printf("3-Listado de los beneficiarios que cumplan a%cos en un mes determinado\n",164);
        printf("4-Listado de aportes\n");
        printf("5-Salir\n");
        printf("\n? ");
        fflush(stdin);
        scanf("%d",&opcion);
        if(opcion==1)agregar_beneficiario();
        if(opcion==2)listar_varones();
        if(opcion==3)informe_varones();
        if(opcion==4)aportes();
    };
    return 0;}
