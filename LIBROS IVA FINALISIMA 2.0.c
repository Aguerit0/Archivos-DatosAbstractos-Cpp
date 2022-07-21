#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*

                    Trabajo de Laboratorio 2022 
	
	ENUNCIADO:
    Realizar un programa de Libros IVA.


    INTEGRANTES                                           M.U

Agüero, Esteban                                      M.U.N°  01649
Miranda, Mauricio                                    M.U.N°  01656
Wu Sosa, Marcelo Exequiel                            M.U.N°  01555

*/





// ########################### ESTRUCTURAS ########################### 

struct fecha {
	int dia;
	int mes;
	int ano;
};
	
struct ventas {
    int COMPRADORES; 
    char Nombre [25];
    int numero_factura ;
    double neto_grabado;
    double exento;
    double importe_total;
    int IVA;
    double IVA_alicuota;
    double CUIT ;
    struct fecha FCH;
};
  
struct compras {
	int VENDEDORES;
    char Nombre[25] ;
    double CUIT ;
    int numero_factura;
    double neto_grabado;
    double exento;
    double importe_total;
    int IVA;
    double IVA_alicuota;
    struct fecha FCH;
};

struct parametros{
	double IVA1;
	double IVA2;
};
  
  

// ########################### PROTOTIPOS DE FUNCIONES/PROCEDIMIENTOS ########################### 

void menu(int *opc); // Menu del programa
void agregar_compra(); // Agrega un registro al archivo Proovedores.dat
void agregar_venta(); // Agrega un registro al archivo Clientes.dat
void modificar_registro(); // Permite modificar un registro dentro de algun archivo
void consultar_historial(); // Consulta el historial de compra/venta de un cliente/proveedor por numero de cuit
void mostrar_historial(); // Muestra todo el contenido de ambos archivos
void mostrar_libros(); // Muestra el libro compra o venta según el mes consultado
void libro_compra(); // Usa el archivo Proovedores para generar el libro IVA de compras
void libro_venta(); // Usa el archivo Clientes para generar el libro IVA de ventas
void generar_libro_venta(FILE* IVA,int mes, int anio); // Crea el archivo de texto del mes que se le indique
void generar_libro_compra(FILE* IVA,int mes, int anio); // Crea el archivo de texto del mes que se le indique
int facturas_iguales_compra(int factura); // Conprueba que el numero de factura ingresaso no se repita en el archivo Proveedores.dat
int facturas_iguales_venta(int factura); // Conprueba que el numero de factura ingresaso no se repita en el archivo Clientes.dat
void parametros_iva(); // Permite configurar a futuro el valor de cada alicuota IVA





// ########################### MAIN (FUNCION PRINCIPAL) ########################### 

int main(){
    int opcion;
    
    FILE *Para = fopen("Parametros IVA.dat", "r+b");
		if(Para == NULL){
			FILE *Paraa = fopen("Parametros IVA.dat", "wb"); // CREA EL ARCHIVO DE LOS PARAMETROS IVA SI ES QUE NO EXISTE DENTRO DE LA CARPETA, PREDETERMINA SUS VALORES
			struct parametros P;                             // SE PUEDEN MODIFICAR EN EL PROGRAMA Y GUARDA LOS CAMBIOS.
			
			P.IVA1 = 10.5;
			P.IVA2 = 21;
			fwrite(&P, sizeof(struct parametros), 1, Paraa);
			fclose(Paraa);
		}
	fclose(Para);
    
    do{
        do{
        	menu(&opcion);
        	switch(opcion){
        		case 1:
        			agregar_compra();
        			break;
        		case 2:
        			agregar_venta();
        			break;
        		case 3:
        			modificar_registro();
        			break;
        		case 4:
        			consultar_historial();
        			break;
        		case 5:
        			mostrar_historial();
        			break;
        		case 6:
        			mostrar_libros();
        			break;
        		case 7:
        			parametros_iva();
        			break;
        		case 8:
        			printf("\n\tEL PROGRAMA SE CERRARA EN 3 SEGUNDOS...");
        			sleep(3);
        			exit(1);
        		default:
        			printf("\n\tSELECCIONE UNA DE LAS OPCIONES DADAS");
        			printf("\n\n\n\t");
        			system("PAUSE");
                	system("CLS");	
			}
	   	}while(opcion<1 || opcion>8);
    }while(opcion);
}



// ########################### MENU DEL PROGRAMA ########################### 

void menu(int *opc){
	int x; 
	
	printf("\n\t----- BIENVENIDO AL MENU DE REGISTRO DE PISCINAS TECNOR -----\n\n\n");
    printf("\t1 - AGREGAR UNA COMPRA AL REGISTRO\n");
	printf("\t2 - AGREGAR UNA VENTA AL REGISTRO\n");
    printf("\t3 - MODIFICAR UN ELEMENTO DEL REGISTRO\n");
    printf("\t4 - CONSULTAR EL HISTORIAL DE UN CLIENTE O PROVEEDOR\n");
    printf("\t5 - MOSTRAR EL HISTORIAL COMPLETO DE COMPRA O VENTA\n");
    printf("\t6 - MOSTRAR EL LIBRO IVA COMPRA O VENTA\n");
    printf("\t7 - CONFIGURAR PARAMETROS IVA\n");
	printf("\t8 - SALIR DEL PROGRAMA\n");
    printf("\n\n\n\tINGRESE OPCION: ");
    scanf("%d",&x); fflush(stdin);
    *opc = x;
    
    printf("\n\n\t");
    system("pause");
    system("cls");
}



// ########################### AGREGAR UN REGISTRO AL ARCHIVO PROVEEDORES.DAT ########################### 

void agregar_compra(){
	int opc, seguir, factura, band, mes, anio, x;
	
	do{
		system("cls");
		FILE *Compra;
        Compra = fopen("Proveedores.dat","a+b");
        if (Compra == NULL){
         	printf("\n\tNO SE HA PODIDO ABRIR EL ARCHIVO.");
	      	exit(1);
        }
        struct compras PROV;
        
        do{
        	printf("\n\tIngrese el Tipo de Vendedor\n  \n\t1: Responsables inscriptos  \n\t2: Monotributistas\n");
        	printf("\n\tRespuesta: ");
            fflush(stdin);
            scanf("%d",&x);
        
	    	PROV.VENDEDORES = x;
        	
        	if (PROV.VENDEDORES == 1 || PROV.VENDEDORES == 2){
        
         	   if(seguir==1){
          	    	printf("\n\tIngrese dia de la compra: ");
           	        fflush(stdin);	
           	        scanf("%d",&PROV.FCH.dia);
         	        PROV.FCH.mes=mes;
         	        PROV.FCH.ano=anio;
                }
                else{
                	printf("\n\tIngrese dia de la compra: ");
                    fflush(stdin);	
                    scanf("%d",&PROV.FCH.dia);
                    printf("\n\tIngrese mes de la compra: ");
                    fflush(stdin);	
                    scanf("%d",&mes);
                    PROV.FCH.mes=mes;
                    printf("\n\tIngrese a%Co de compra: ",164);
                    fflush(stdin);	
                    scanf("%d",&anio);
                    PROV.FCH.ano=anio;
                }
            
                do{
                	factura = 0;
                	printf("\n\tIngrese el numero de factura: 0001-");	
                        fflush(stdin);	
                        scanf("%d",&factura);
                
                    band = facturas_iguales_compra(factura);
	        	}while(band==1);
		
	        	PROV.numero_factura = factura;
            
                printf("\n\tIngrese el importe neto gravado de la compra: $");
                    fflush(stdin);	
                    scanf("%lf",&PROV.neto_grabado); 
                printf("\n\tIngrese el importe neto exento de la compra: $");
                    fflush(stdin);	
                    scanf("%lf",&PROV.exento); 
                printf("\n\tIngrese nombre o razon social del Proveedor: ");
                	fflush(stdin);
                	gets(PROV.Nombre);
                printf("\n\tIngrese numero de CUIT sin guiones del Proveedor: ");	
                    fflush(stdin);	
                    scanf("%lf",&PROV.CUIT); 
            
            	do{
	            	printf("\n\n\tIngrese el tipo de producto: \n\t1) Encargar Insumos de Limpieza \n\t2) Encargar Equipo de Mantenimiento \n\t3) Encargar Fibra de Vidrio para Piletas\n");
                    printf("\n\tRespuesta: "); 
	        	    fflush(stdin);
                    scanf("%d",&opc);
            
                    FILE *Para = fopen("Parametros IVA.dat", "rb");
                    struct parametros P;
                	fread(&P, sizeof(struct parametros), 1, Para);
        
                    switch(opc){
                     	case 1:
                    	    PROV.IVA_alicuota = P.IVA2;
                    		PROV.IVA = 1;
                    		break;
                    	case 2:
                    		PROV.IVA_alicuota = P.IVA2;
                    		PROV.IVA = 2;
                    		break;
                    	case 3:
                     		PROV.IVA_alicuota = P.IVA1;
                    		PROV.IVA = 3;
                    		break;
                    	default:
        	            	printf("\n\tSeleccione una de las opciones dadas.\n\n");
	             	}
	             	fclose(Para);
	     	
            	}while(opc<1 || opc>3);
    	
            	PROV.importe_total = PROV.exento + ((PROV.neto_grabado) * ((PROV.IVA_alicuota/100.0)+1.0));
    	
        
                fwrite(&PROV, sizeof(struct compras), 1, Compra);
            	fclose(Compra);
	            fflush(stdin);
		
	        	libro_compra();  //INCORPORA LOS DATOS DEL REGISTRO AL LIBRO IVA COMPRAS
	        	system("PAUSE");
	        	system("cls");
	       	}
		}while(x<1 || x>2);
        	
		
		printf("\n\n\n\tDESEA SEGUIR CARGANDO LOS DATOS DE UN PROVEEDOR MAS CON EL MISMO MES Y ANIO?    SI = 1 / NO = 2");
		printf("\n\tRESPUESTA: "); fflush(stdin);
		scanf("%d", &seguir);
		
		
	}while(seguir==1);
	
	printf("\n\n\n\tPara volver al menu principal");
   	printf("\n\t");
    system("pause");
    system("cls");
}




// ########################### AGREGAR UN REGISTRO AL ARCHIVO CLIENTES.DAT ########################### 

void agregar_venta(){
	int opc, x, seguir, factura, band, mes, anio;
	char *CF = "CONSUMIDOR FINAL";
	
	do{
		system("cls");
   		FILE *Venta;
        Venta = fopen("Clientes.dat","ab");
        if (Venta==NULL){
    		printf("\n\tNO SE HA PODIDO ABRIR EL ARCHIVO.");
    		exit(1);
    	}
        struct ventas CLI;
    
    
        do{
        	printf("\n\tIngrese el Tipo de Comprador\n  \n\t1: Responsables inscriptos  \n\t2: Monotributistas   \n\t3: Exentos  \n\t4: Consumidores Finales\n");
        	printf("\n\tRespuesta: ");
            fflush(stdin);
            scanf("%d",&x);
        
	    	CLI.COMPRADORES = x;
	    	
	    	if (CLI.COMPRADORES == 1 || CLI.COMPRADORES == 2){
	    		if(seguir==1){
                	printf("\n\tIngrese dia de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&CLI.FCH.dia);
                    CLI.FCH.mes=mes;
                    CLI.FCH.ano=anio;
                }
                else{
                	printf("\n\tIngrese dia de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&CLI.FCH.dia);
                printf("\n\tIngrese mes de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&mes);
                    CLI.FCH.mes=mes;
                printf("\n\tIngrese a%Co de la venta: ",164);
                    fflush(stdin);	
                    scanf("%d",&anio);
                    CLI.FCH.ano=anio;
                }
                
                do{
                	factura = 0;
                	printf("\n\tIngrese el numero de factura: 0001-");	
                        fflush(stdin);	
                        scanf("%d",&factura);
                
                    band = facturas_iguales_venta(factura);
	        	}while(band==1);
		
	        	CLI.numero_factura = factura;
                
                printf("\n\tIngrese el importe neto gravado de la venta: $");
	                fflush(stdin);	
                    scanf("%lf",&CLI.neto_grabado);
                printf("\n\tIngrese el importe neto exento de la venta: $");
                    fflush(stdin);	
                    scanf("%lf",&CLI.exento);
            	printf("\n\tIngrese nombre o razon social del cliente: ");
            	    fflush(stdin);
                	gets(CLI.Nombre);
                printf("\n\tIngrese CUIT sin guiones del cliente: ");
                    fflush(stdin);
                    scanf("%lf",&CLI.CUIT);
			}
	    	
	    	if (CLI.COMPRADORES == 3){
	    		
	    		if(seguir==1){
                	printf("\n\tIngrese dia de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&CLI.FCH.dia);
                    CLI.FCH.mes=mes;
                    CLI.FCH.ano=anio;
                }
                else{
                	printf("\n\tIngrese dia de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&CLI.FCH.dia);
                printf("\n\tIngrese mes de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&mes);
                    CLI.FCH.mes=mes;
                printf("\n\tIngrese a%Co de la ventaa: ",164);
                    fflush(stdin);	
                    scanf("%d",&anio);
                    CLI.FCH.ano=anio;
                }
                
                do{
                	factura = 0;
                	printf("\n\tIngrese el numero de factura: 0001-");	
                        fflush(stdin);	
                        scanf("%d",&factura);
                
                    band = facturas_iguales_venta(factura);
	        	}while(band==1);
		
	        	CLI.numero_factura = factura;
	        	CLI.exento = 0.0;
                
                printf("\n\tIngrese el importe total de la venta: $");
	                fflush(stdin);	
                    scanf("%lf",&CLI.importe_total);
            	printf("\n\tIngrese nombre o razon social del cliente: ");
            	    fflush(stdin);
                	gets(CLI.Nombre);
                printf("\n\tIngrese CUIT sin guiones del cliente: ");
                    fflush(stdin);
                    scanf("%lf",&CLI.CUIT);
			}
			
			if (CLI.COMPRADORES == 4){
				if(seguir==1){
                	printf("\n\tIngrese dia de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&CLI.FCH.dia);
                    CLI.FCH.mes=mes;
                    CLI.FCH.ano=anio;
                }
                else{
                	printf("\n\tIngrese dia de la compra: ");
                    fflush(stdin);	
                    scanf("%d",&CLI.FCH.dia);
                printf("\n\tIngrese mes de la venta: ");
                    fflush(stdin);	
                    scanf("%d",&mes);
                    CLI.FCH.mes=mes;
                printf("\n\tIngrese a%Co de la venta: ",164);
                    fflush(stdin);	
                    scanf("%d",&anio);
                    CLI.FCH.ano=anio;
                }
                
                do{
                	factura = 0;
                	printf("\n\tIngrese el numero de factura: 0001-");	
                        fflush(stdin);	
                        scanf("%d",&factura);
                
                    band = facturas_iguales_venta(factura);
	        	}while(band==1);
		
	        	CLI.numero_factura = factura;
	        	CLI.exento = 0.0;
	        	CLI.CUIT = 0.0;
	        	*CLI.Nombre = *CF;
                
                printf("\n\tIngrese el importe total de la venta: $");
	                fflush(stdin);	
                    scanf("%lf",&CLI.importe_total);
                if (CLI.importe_total>10000){
                	
                	printf("\n\tIngrese nombre o razon social del cliente: ");
            	        fflush(stdin);
                    	gets(CLI.Nombre);
                }
			}
    	}while(x<1 || x>4);
    	
        
        do{
	    	printf("\n\n\tIngrese el tipo de producto: \n\t1) Productos de Limpieza \n\t2) Bomba de agua \n\t3) Contrato Personal de Mantenimiento \n\t4) Instalacion de Piletas de Fibra\n");
            printf("\n\tRespuesta: ");
            scanf("%d",&opc); fflush(stdin);
            
            FILE *Para = fopen("Parametros IVA.dat", "rb");
            struct parametros P;
        	fread(&P, sizeof(struct parametros), 1, Para);
            
            if(CLI.COMPRADORES == 1 || CLI.COMPRADORES == 2){
            	switch(opc){
                	case 1:
            	    	CLI.IVA_alicuota = P.IVA2;
            	    	CLI.IVA = 1;
            	    	break;
                 	case 2:
            	    	CLI.IVA_alicuota = P.IVA2;
        	        	CLI.IVA = 2;
        	        	break;
                	case 3:
                		CLI.IVA_alicuota = P.IVA1;
                		CLI.IVA = 3;
                		break;
                	case 4:
                		CLI.IVA_alicuota = P.IVA1;
                		CLI.IVA = 4;
                		break;
                	default:
              	    	printf("\n\tSeleccione unas de las opciones dadas.\n\n");
		    	}
		    	CLI.importe_total = CLI.exento + ((CLI.neto_grabado)*((CLI.IVA_alicuota/100.0)+1.0));
	    	}
	    	
	    	
	    	if(CLI.COMPRADORES == 3){
            	switch(opc){
                	case 1:
            	    	CLI.IVA_alicuota = 0.0;
            	    	CLI.IVA = 1;
            	    	break;
                 	case 2:
            	    	CLI.IVA_alicuota = 0.0;
        	        	CLI.IVA = 2;
        	        	break;
                	case 3:
                		CLI.IVA_alicuota = 0.0;
                		CLI.IVA = 3;
                		break;
                	case 4:
                		CLI.IVA_alicuota = 0.0;
                		CLI.IVA = 4;
                		break;
                	default:
              	    	printf("\n\tSeleccione unas de las opciones dadas.\n\n");
		    	}
		    	CLI.neto_grabado = (CLI.importe_total - CLI.exento)/((CLI.IVA_alicuota/100.0)+1.0);
	    	}
	    	
	    	
	    	if(CLI.COMPRADORES == 4){
            	switch(opc){
                	case 1:
            	    	CLI.IVA_alicuota = P.IVA2;
            	    	CLI.IVA = 1;
            	    	break;
                 	case 2:
            	    	CLI.IVA_alicuota = P.IVA2;
        	        	CLI.IVA = 2;
        	        	break;
                	case 3:
                		CLI.IVA_alicuota = P.IVA2;
                		CLI.IVA = 3;
                		break;
                	case 4:
                		CLI.IVA_alicuota = P.IVA2;
                		CLI.IVA = 4;
                		break;
                	default:
              	    	printf("\n\tSeleccione unas de las opciones dadas.\n\n");
		    	}
		    	CLI.neto_grabado = (CLI.importe_total - CLI.exento)/((CLI.IVA_alicuota/100.0)+1.0);
	    	}
	    	fclose(Para);
	
    	}while(opc<1 || opc>4);
    	
        
        fwrite(&CLI, sizeof(struct ventas), 1, Venta);
        fflush(Venta);
     	fclose(Venta);
     	
     	libro_venta(); //INCORPORA LOS DATOS DEL REGISTRO AL LIBRO IVA VENTAS
     	system("PAUSE");
		system("cls");
     	
		printf("\n\n\n\tDESEA SEGUIR CARGANDO LOS DATOS DE UN CLIENTE MAS CON EL MISMO MES Y ANIO?    SI = 1 / NO = 2");
		printf("\n\tRESPUESTA: "); fflush(stdin);
		scanf("%d", &seguir);
		
	}while(seguir==1);
	
	
	printf("\n\n\n\tPara volver al menu principal");
	printf("\n\t");
    system("pause");
    system("cls");
}




// ########################### COMPRUEBA QUE NO EXISTE UNA FACTURA IGUAL EN EL REGISTRO DE PROVEEDORES ###########################

int facturas_iguales_compra(int factura){
	int band = 0; 
	
	FILE *Compra;
    Compra = fopen("Proveedores.dat","rb");
    struct compras PROV;
        
    fread(&PROV, sizeof(struct compras), 1, Compra);
    while(!feof(Compra)){
        if(PROV.numero_factura==factura){
            printf("\n\n\tYA SE REGISTRO UNA FACTURA IDENTICA. REINTENTE\n");
            band = 1;
            break;
        }
        else{
        	band = 2;
		}
		fread(&PROV, sizeof(struct compras), 1, Compra);
	}
	
	return band;
}




// ########################### COMPRUEBA QUE NO EXISTE UNA FACTURA IGUAL EN EL REGISTRO DE CLIENTES ###########################

int facturas_iguales_venta(int factura){
	int band = 0; 
	
	FILE *Venta;
    Venta = fopen("Clientes.dat","rb");
    struct ventas CLI;
        
    fread(&CLI, sizeof(struct ventas), 1, Venta);
    while(!feof(Venta)){
        if(CLI.numero_factura==factura){
            printf("\n\n\tYA SE REGISTRO UNA FACTURA IDENTICA. REINTENTE\n");
            band = 1;
            break;
        }
        else{
        	band = 2;
		}
		fread(&CLI, sizeof(struct ventas), 1, Venta);
	}
	
	return band;
}




// ########################### CONSULTAR EL HISTORIAL DE UN CLIENTE O PROVEEDOR ###########################

void consultar_historial(){
	int  opc, seguir, band=0;
	double CUIT;
	char *persona;
	
	do{
		do{
			system("cls");
	    	printf("\n\t----------  CONSULTAR HISTORIAL DE UN CLIENTE O PROVEEDOR  -----------\n");
	    	printf("\n\tNOTA: Los Consumidores Finales quedan exentos en esta opcion, \n\tya que no registran numero de CUIT.");
         	printf("\n\n\tCONSULTAR HISTORIAL: \n\n\t\t1 - PROVEEDOR \t2 - CLIENTE\n\n\n\n\tIngrese una opcion: ");
        	fflush(stdin);
        	scanf("%d",&opc);
    	
        	switch(opc){
     	    	case 1:
    		    	persona = "Proveedor";
    		    	break;
    	    	case 2:
    		    	persona = "Cliente";
    	    		break;
    	    	default:
    	    		printf("\n\tLa opcion ingresada es incorrecta, vuelva a intentar...\n");
    	    		printf("\n\n\t");
                    system("pause");
                    system("cls");
	    	}
    	}while(opc<1 || opc>2);
	
    	printf("\n\n\tIngrese el CUIT del %s para consultar:  ", persona);
    	scanf("%lf",&CUIT);
	
    	if(opc == 1){
	    	FILE *compra;
        	compra = fopen("Proveedores.dat","rb");
        	if(compra == NULL){
	        	printf("\nNo se ha podido abrir el archivo Proveedores.dat...");
	         	exit(-1);
        	}
        	system("cls");
	    	struct compras PROV;
		
	        fread(&PROV, sizeof(struct compras), 1, compra);
	        printf("\n\t---------------  HISTORIAL DE COMPRA DEL CUIT '%0.f'----------------", CUIT);
	    	while(!feof(compra)){
	    		
		    	if(CUIT == PROV.CUIT){
		    		
		     		printf("\n\n\t--------------- %d/%d/%d ---------------\n",PROV.FCH.dia,PROV.FCH.mes,PROV.FCH.ano);
		    		printf("\tNOMBRE: %s\n",PROV.Nombre);
		    		printf("\tCUIT: %0.f\n",PROV.CUIT);
			    	printf("\tFACTURA A\n");
			    	printf("\tNUMERO DE FACTURA: 0001-%d\n", PROV.numero_factura);
		      		printf("\tIMPORTE NETO GRAVADO: $%0.2f\n", PROV.neto_grabado);
		      		printf("\tIMPORTE EXENTO: $%0.2f\n", PROV.exento);
		    		printf("\tIVA APLICADO: %0.2f %c\n\n\n", PROV.IVA_alicuota, 37);
		    		printf("\tIMPORTE TOTAL: $%0.2f", PROV.importe_total);
		    		band = 1;		     	
				}
		    	fread(&PROV, sizeof(struct compras), 1, compra);
	    	}
	        fclose(compra);
    	}
	
    	if(opc == 2){
	    	FILE *venta;
        	venta = fopen("Clientes.dat","rb");
	
        	if(venta == NULL){
	         	printf("\nNo se ha podido abrir el archivo Clientes.dat ...");
	        	exit(-1);
        	}
        	system("cls");
    	
	    	struct ventas CLI;
	        fread(&CLI, sizeof(struct ventas), 1, venta);
	      	printf("\n\t---------------  HISTORIAL DE VENTA DEL CUIT '%0.f'----------------",CUIT);
	      	
	    	while(!feof(venta)){
	    		
		    	if(CUIT==CLI.CUIT){
		    		
			    	printf("\n\n\t--------------- %d/%d/%d ---------------\n",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano);
			    	printf("\tNOMBRE: %s\n",CLI.Nombre);
			    	printf("\tCUIT: %0.f\n",CLI.CUIT);
	             	if (CLI.COMPRADORES == 1 || CLI.COMPRADORES ==2){
	             		printf("\tFACTURA A\n");
			    	   }
			    	if(CLI.COMPRADORES == 3 || CLI.COMPRADORES == 4){
			    		printf("\tFACTURA B\n");
		    		}
		    		printf("\tNUMERO DE FACTURA: 0001-%d\n", CLI.numero_factura);
		    		printf("\tIMPORTE NETO GRAVADO: $%0.2f\n", CLI.neto_grabado);
		    		printf("\tIMPORTE EXENTO: $%0.2f\n", CLI.exento);
		     		printf("\tIVA APLICADO: %0.2f %c\n\n\n", CLI.IVA_alicuota, 37);
		     		printf("\tIMPORTE TOTAL: $%0.2f", CLI.importe_total);
		     		band = 1;
	     		}
		    	fread(&CLI, sizeof(struct ventas), 1, venta);
	    	}
	    	fclose(venta);
    	}
    	
    	if(!band){
    		printf("\n\n\tEl numero de CUIT: %0.f. No se encuentra en la base de datos. Reintente.", CUIT);
		}
		
		
    	printf("\n\n\n\tDesea visualizar el historial de un %s mas?    SI = 1 / NO = 2", persona);
		printf("\n\tRESPUESTA: "); fflush(stdin);
		scanf("%d", &seguir);
		
	}while(seguir==1);
	
	
	printf("\n\n\n\tPara volver al menu principal");
	printf("\n\t");
    system("pause");
    system("cls");
}




// ########################### PERMITE MODIFICAR UN REGISTRO DE ALGUN ARCHIVO ###########################

void modificar_registro(){
	int i, x, opc, factura, band, y;	
	int e = 0;
	char *CF = {"CONSUMIDOR FINAL"};
	
	do{
		printf("\n\t----------  CONSULTAR NUMERO DE FACTURA DE UN CLIENTE O PROVEEDOR  -----------\n");
    	printf("\n\n\tCONSULTAR: \n\n\t\t1 - PROVEEDOR \t2 - CLIENTE\n\n\n\n\tIngrese una opcion: ");
    	fflush(stdin);
    	scanf("%d",&opc);
    	if (opc<1 || opc>2){
		    printf("\n\tLa opcion ingresada es incorrecta, vuelva a intentar...\n");
    		printf("\n\n\t");
            system("pause");
            system("cls");}
	}while(opc<1 || opc>2);
    
	if (opc==1){
		
	    FILE *Compra = fopen("Proveedores.dat", "r+b");
	    if (Compra == NULL){
		    printf("\n\n\tNO SE HA PODIDO ABRIR EL ARCHIVO");
		    exit(2);}
	    printf("\n\n\tINGRESE EL NUMERO LA FACTURA: 0001-");
	    scanf("%d", &x);
	    struct compras PROV;
	    
	    fread(&PROV, sizeof(struct compras), 1, Compra);
		while(!feof(Compra)){
		    if (PROV.numero_factura == x){
		    	int opc2;
		        e = 1;
		        
			    system("cls");
			    printf("\n\n\t---------- FACTURA ENCONTRADA ----------\n");
	    	    printf("\n\n\t--------------- %d/%d/%d ---------------\n",PROV.FCH.dia,PROV.FCH.mes,PROV.FCH.ano);
		       	printf("\tNOMBRE: %s\n",PROV.Nombre);
	           	printf("\tCUIT: %0.f\n",PROV.CUIT);
	           	printf("\tFACTURA A\n");
	           	printf("\tNUMERO DE FACTURA: 0001-%d\n", PROV.numero_factura);
	           	printf("\tIMPORTE NETO GRAVADO: $%0.2f\n", PROV.neto_grabado);
		      	printf("\tIMPORTE EXENTO: $%0.2f\n", PROV.exento);
		   		printf("\tIVA APLICADO: %0.2f %c\n\n\n", PROV.IVA_alicuota, 37);
		   		
				printf("\tIMPORTE TOTAL: $%0.2f", PROV.importe_total);
	    	    printf("\n\n\n\t");
        	    system("pause");
        	    system("cls");
        	    
        	    printf("\n\n\t---------- DESEA MODIFICAR LA FACTURA?   1 = SI / 2 = NO  ----------\n");
        	    printf("\n\tNOTA: Si modifica la factura, debera modificar \n\tobligatoriamente el numero de factura. \n");
        	    printf("\n\n\n\tRESPUESTA: ");
        	    scanf("%d", &i);
        	    system("cls");
        	   
			    if (i==1){
			    	
			    	do{
			    		printf("\n\tIngrese el Tipo de Vendedor\n  \n\t1: Responsables inscriptos  \n\t2: Monotributistas\n");
            			printf("\n\tRespuesta: ");
              	    	fflush(stdin);
             		    scanf("%d",&y);
        
	        			PROV.VENDEDORES = y;
	        			
	        			if(PROV.VENDEDORES == 1 || PROV.VENDEDORES == 2){
	        				printf("\n\tIngrese dia de la compra: ");
                 		        fflush(stdin);	
                                scanf("%d",&PROV.FCH.dia);
                            printf("\n\tIngrese mes de la compra: ");
                                fflush(stdin);	
                                scanf("%d",&PROV.FCH.mes);
                            printf("\n\tIngrese a%Co de compra: ",164);
                                fflush(stdin);	
                                scanf("%d",&PROV.FCH.ano);
                        
                            do{
                            	factura = 0;
                            	printf("\n\tIngrese el numero de factura: 0001-");	
                                    fflush(stdin);	
                                    scanf("%d",&factura);
                
                                band = facturas_iguales_compra(factura);
	                    	}while(band==1);
		
	                    	PROV.numero_factura = factura;
		
                            printf("\n\tIngrese el importe neto gravado de la compra: $");
                                fflush(stdin);	
                                scanf("%lf",&PROV.neto_grabado); 
                            printf("\n\tIngrese el importe neto exento de la compra: $");
                                fflush(stdin);	
                                scanf("%lf",&PROV.exento); 
			                printf("\n\tIngrese nombre o razon social del Proveedor: ");
                            	fflush(stdin);
                            	gets(PROV.Nombre);
                            printf("\n\tIngrese numero de CUIT sin guiones del Proveedor: ");	
                                fflush(stdin);	
                                scanf("%lf",&PROV.CUIT);
            
                        	do{
	                        	printf("\n\n\tIngrese el tipo de producto: \n\t1) Encargar Insumos de Limpieza \n\t2) Encargar Equipo de Mantenimiento \n\t3) Encargar Fibra de Vidrio para Piletas\n");
                                printf("\n\tRespuesta: "); 
	             	            fflush(stdin);
                                scanf("%d",&opc2); 
                        
                                FILE *Para = fopen("Parametros IVA.dat", "rb");
                                struct parametros P;
                            	fread(&P, sizeof(struct parametros), 1, Para);
        
                                switch(opc2){
                                 	case 1:
                                		PROV.IVA_alicuota = P.IVA2;
                                		PROV.IVA = 1;
                                		break;
                                   	case 2:
                                 		PROV.IVA_alicuota = P.IVA2;
                                 		PROV.IVA = 2;
                                		break;
                                	case 3:
                                		PROV.IVA_alicuota = P.IVA1;
                                   		PROV.IVA = 3;
                                		break;
                                	default:
                        	    	printf("\n\tSeleccione una de las opciones dadas.\n\n");
	                         	}
	                         	fclose(Para);
	                 	
                         	}while(opc2<1 || opc2>3);
    	
    	                    PROV.importe_total = PROV.exento + ((PROV.neto_grabado) * ((PROV.IVA_alicuota/100.0)+1.0));
     	
						}
					}while(y<1 || y>2);
					
					int posicion = ftell(Compra)-(sizeof(struct compras));
                    fseek(Compra, posicion, SEEK_SET);
                    fwrite(&PROV, sizeof(struct compras), 1, Compra);
		            printf("\n\n\n");
	                fflush(stdin);
			        printf("\tLA FACTURA SE MODIFICO CON EXITO!!!\n");
			        fclose(Compra);
			    	
			        libro_compra();  //INCORPORA LOS DATOS DEL REGISTRO AL LIBRO IVA COMPRAS
			    	
			        printf("\n\tPara volver al menu principal");
                    printf("\n\t");
                    system("pause");
                    system("cls");
	        		break;
				}
				else{
				    printf("\n\n\n\tLA FACTURA NO SE MODIFICARA\n");
				    fclose(Compra);
				    
				    printf("\n\n\n\tPara volver al menu principal");
                	printf("\n\t");
                    system("pause");
                    system("cls");
				    break;
				}
			}
			fread(&PROV, sizeof(struct compras), 1, Compra);
    	}
    }
	
	if (opc == 2){
		
		FILE *Venta;
        Venta = fopen("Clientes.dat","r+b");
        if (Venta==NULL){
	    	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
	    	exit(1);
		}
	    printf("\n\n\tINGRESE EL NUEMRO DE LA FACTURA: 0001-");
	    scanf("%d", &x);
		struct ventas CLI;
		
		fread(&CLI, sizeof(struct ventas), 1, Venta);
	    while(!feof(Venta)){
			if (CLI.numero_factura == x){
				int opc2;
				
				e=1;
			    system("cls");
			    printf("\n\n\t---------- FACTURA ENCONTRADA ----------\n");
			    printf("\n\n\t--------------- %d/%d/%d ---------------\n",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano);
	           	printf("\tNOMBRE: %s\n",CLI.Nombre);
	           	printf("\tCUIT: %0.f\n",CLI.CUIT);
	           	
	           	if (CLI.COMPRADORES == 1 || CLI.COMPRADORES ==2){
	           		printf("\tFACTURA A\n");
				   }
				if(CLI.COMPRADORES == 3 || CLI.COMPRADORES == 4){
					printf("\tFACTURA B\n");
				}
	           	printf("\tNUMERO DE FACTURA: 0001-%d\n", CLI.numero_factura);
	          	printf("\tIMPORTE NETO GRAVADO: $%0.2f\n", CLI.neto_grabado);
		    	printf("\tIMPORTE EXENTO: $%0.2f\n", CLI.exento);
		   		printf("\tIVA APLICADO: %0.2f %c\n\n\n", CLI.IVA_alicuota, 37);
		   		printf("\tIMPORTE TOTAL: $%0.2f", CLI.importe_total);
		   		
		        printf("\n\n\n\t");
        	    system("pause");
        	    system("cls");
        	    
        	    printf("\n\n\t---------- DESEA MODIFICAR LA FACTURA?   1 = SI / 2 = NO  ----------\n");
        	    printf("\n\tNOTA: Si modifica la factura, debera modificar \n\tobligatoriamente el numero de factura. \n");
        	    printf("\n\n\n\tRESPUESTA: ");
        	    scanf("%d", &i);
        	    system("cls");
        	   
			    if (i==1){
			    	
        	   	    do{
            	    	printf("\n\tIngrese el Tipo de Comprador\n  \n\t1: Responsables inscriptos  \n\t2: Monotributistas   \n\t3: Exentos  \n\t4: Consumidores Finales\n");
        	    		printf("\n\tRespuesta: ");
      	    	        fflush(stdin);
          	        	scanf("%d",&x);
        	     	
	    	    		CLI.COMPRADORES = x;
	    	
	    	    		if (CLI.COMPRADORES == 1 || CLI.COMPRADORES == 2){
	    	    			printf("\n\tIngrese dia de la venta: ");
           	    	     	fflush(stdin);	
            	    	        scanf("%d",&CLI.FCH.dia);
            	    	    printf("\n\tIngrese mes de la venta: ");
            	    	        fflush(stdin);
            	    	        scanf("%d",&CLI.FCH.mes);
            	    	    printf("\n\tIngrese a%co de venta: ",164);
         	    	            fflush(stdin);
          	    	            scanf("%d",&CLI.FCH.ano);
          	    	        
          	    	        do{
                            	factura = 0;
                            	printf("\n\tIngrese el numero de factura: 0001-");	
                                    fflush(stdin);	
                                    scanf("%d",&factura);
                
                                band = facturas_iguales_venta(factura);
	                    	}while(band==1);
		
	                    	CLI.numero_factura = factura;
          	    	        
           	    	        printf("\n\tIngrese el importe neto gravado de la venta: $");
	           	    	        fflush(stdin);	
                   	    	    scanf("%lf",&CLI.neto_grabado);
             	    	    printf("\n\tIngrese el importe neto exento de la venta: $");
               	        	    fflush(stdin);	
                 	        	scanf("%lf",&CLI.exento);
          	    	     	printf("\n\tIngrese nombre o razon social del cliente: ");
          	        	  	    fflush(stdin);
           	        	     	gets(CLI.Nombre);
           	        	    printf("\n\tIngrese CUIT sin guiones del cliente: ");
           	    	            fflush(stdin);
           	    	            scanf("%lf",&CLI.CUIT);
		            	}
	    	
	    	    		if (CLI.COMPRADORES == 3){
	    		
	    	    			printf("\n\tIngrese dia de la venta: ");
            	    	    	fflush(stdin);	
            	    	        scanf("%d",&CLI.FCH.dia);
           	  	    	  	printf("\n\tIngrese mes de la venta: ");
       	    	                fflush(stdin);
                                scanf("%d",&CLI.FCH.mes);
                            printf("\n\tIngrese a%co de venta: ",164);
                                fflush(stdin);
                                scanf("%d",&CLI.FCH.ano);
                            
                            do{
                            	factura = 0;
                            	printf("\n\tIngrese el numero de factura: 0001-");	
                                    fflush(stdin);	
                                    scanf("%d",&factura);
                
                                band = facturas_iguales_venta(factura);
	                    	}while(band==1);
		
	                    	CLI.numero_factura = factura;
	                    	CLI.exento = 0.0;
                            
                            printf("\n\tIngrese el importe total de la venta: $");
	                            fflush(stdin);	
                                scanf("%lf",&CLI.importe_total);
                        	printf("\n\tIngrese nombre o razon social del cliente: ");
                        	    fflush(stdin);
                            	gets(CLI.Nombre);
                            printf("\n\tIngrese CUIT sin guiones del cliente: ");
                                fflush(stdin);
                                scanf("%lf",&CLI.CUIT);
		            	}
			
		            	if (CLI.COMPRADORES == 4){
		            		printf("\n\tIngrese dia de la venta: ");
                            	fflush(stdin);	
                                scanf("%d",&CLI.FCH.dia);
                            printf("\n\tIngrese mes de la venta: ");
                                fflush(stdin);
                                scanf("%d",&CLI.FCH.mes);
                            printf("\n\tIngrese a%co de venta: ",164);
                                fflush(stdin);
                                scanf("%d",&CLI.FCH.ano);
                            
                            do{
                            	factura = 0;
                            	printf("\n\tIngrese el numero de factura: 0001-");	
                                    fflush(stdin);	
                                    scanf("%d",&factura);
                
                                band = facturas_iguales_venta(factura);
	                    	}while(band==1);
		
	                    	CLI.numero_factura = factura;
	                    	CLI.exento = 0.0;
	                    	CLI.CUIT = 0.0;
	                    	*CLI.Nombre = *CF;
                            
                            printf("\n\tIngrese el importe total de la venta: $");
	                            fflush(stdin);	
                                scanf("%lf",&CLI.importe_total);
                            if (CLI.importe_total>10000){
                
                            	printf("\n\tIngrese nombre o razon social del cliente: ");
                        	        fflush(stdin);
                                	gets(CLI.Nombre);
                            }
		            	}
                	}while(x<1 || x>4);
    	
        
                    do{
	                	printf("\n\n\tIngrese el tipo de producto: \n\t1) Productos de Limpieza \n\t2) Bomba de agua \n\t3) Contrato Personal de Mantenimiento \n\t4) Instalacion de Piletas de Fibra\n");
                        printf("\n\tRespuesta: ");
                        scanf("%d",&opc); fflush(stdin);
                        
                        FILE *Para = fopen("Parametros IVA.dat", "rb");
                        struct parametros P;
                    	fread(&P, sizeof(struct parametros), 1, Para);
            
                        if(CLI.COMPRADORES == 1 || CLI.COMPRADORES == 2){
                        	switch(opc){
                            	case 1:
                        	    	CLI.IVA_alicuota = P.IVA2; //IVA_2
                        	    	CLI.IVA = 1;
                        	    	break;
                             	case 2:
                        	    	CLI.IVA_alicuota = P.IVA2;
        	                    	CLI.IVA = 2;
        	                    	break;
                            	case 3:
                            		CLI.IVA_alicuota = P.IVA1;  //IVA_1
                            		CLI.IVA = 3;
                            		break;
                            	case 4:
                            		CLI.IVA_alicuota = P.IVA1;
                            		CLI.IVA = 4;
                            		break;
                            	default:
                          	    	printf("\n\tSeleccione unas de las opciones dadas.\n\n");
		                	}
		                	CLI.importe_total = CLI.exento + ((CLI.neto_grabado) * ((CLI.IVA_alicuota/100.0)+1.0));
	                	}
	    	
	    	
	                	if(CLI.COMPRADORES == 3){
                        	switch(opc){
                            	case 1:
                        	    	CLI.IVA_alicuota = 0.0;
                        	    	CLI.IVA = 1;
                        	    	break;
                             	case 2:
                        	    	CLI.IVA_alicuota = 0.0;
        	                    	CLI.IVA = 2;
        	                    	break;
                               	case 3:
                            		CLI.IVA_alicuota = 0.0;
                            		CLI.IVA = 3;
                            		break;
                            	case 4:
                            		CLI.IVA_alicuota = 0.0;
                	            	CLI.IVA = 4;
                	            	break;
                            	default:
              	                	printf("\n\tSeleccione unas de las opciones dadas.\n\n");
		                	}
		                	CLI.neto_grabado = (CLI.importe_total - CLI.exento)/((CLI.IVA_alicuota/100.0)+1.0);
	                	}
	    
	    	
	                	if(CLI.COMPRADORES == 3 || CLI.COMPRADORES == 4){
                        	switch(opc){
                            	case 1:
                       	        	CLI.IVA_alicuota = P.IVA2;
                        	    	CLI.IVA = 1;
                        	    	break;
                             	case 2:
                        	    	CLI.IVA_alicuota = P.IVA2;
        	                    	CLI.IVA = 2;
        	                    	break;
                            	case 3:
                            		CLI.IVA_alicuota = P.IVA2;
                            		CLI.IVA = 3;
                            		break;
                            	case 4:
                            		CLI.IVA_alicuota = P.IVA2;
                            		CLI.IVA = 4;
                            		break;
                            	default:
                          	    	printf("\n\tSeleccione unas de las opciones dadas.\n\n");
		                	}
		                	CLI.neto_grabado = (CLI.importe_total - CLI.exento)/((CLI.IVA_alicuota/100.0)+1.0);
	                	}
	                	fclose(Para);
	    	
                	}while(opc<1 || opc>4);
                    
                    int posicion = ftell(Venta)-(sizeof(struct ventas));
                    fseek(Venta, posicion, SEEK_SET);
                    fwrite(&CLI, sizeof(struct ventas), 1, Venta);
		            printf("\n\n\n");
	               
					printf("\tLA FACTURA SE MODIFICO CON EXITO!!!\n");
					fclose(Venta);
					
					libro_venta(); //INCORPORA LOS DATOS DEL REGISTRO AL LIBRO IVA VENTAS
					
					printf("\n\tPara volver al menu principal");
                	printf("\n\t");
                    system("pause");
                    system("cls");
					break;
				}
				else{
				    printf("\n\n\n\tLA FACTURA NO SE MODIFICARA\n");
				    fclose(Venta);
				    
					printf("\n\n\n\tPara volver al menu principal");
                	printf("\n\t");
                    system("pause");
                    system("cls");	 
				    break;
				}
			}
			fread(&CLI, sizeof(struct ventas), 1, Venta);
		}	
	}
	
	
	
	if (e==0){
		printf("\n\n\n\t");
		printf("\tEL CODIGO NO COINCIDE CON NINGUNA FACTURA EN EL REGISTRO...\n");
		printf("\n\n\n\tPara volver al menu principal");
        printf("\n\t");
        system("pause");
        system("cls");
	}
} 






// ########################### MUESTRA EL CONTENIDO DE AMBOS ARCHIVOS ########################### 

void mostrar_historial(){
    int opc;
    
    do{
    	printf("\n\tCual historial desea ver? \n\n\t1: Compras  \n\t2: Ventas");
    	printf("\n\n\n\tRespuesta: ");
    	scanf("%d",&opc);
    	system("cls");
    	
    	if (opc==1){
    		FILE *Compra;
            Compra = fopen("Proveedores.dat","rb");
            if (Compra==NULL){
         	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
         	exit(1);}
	       	struct compras PROV;
	       	
	       	fread(&PROV, sizeof(struct compras), 1, Compra);
	       	while(!feof(Compra)){
			
	         	printf("\n\n\t--------------- %d/%d/%d ---------------\n",PROV.FCH.dia,PROV.FCH.mes,PROV.FCH.ano);
             	printf("\tNOMBRE: %s\n",PROV.Nombre);
	           	printf("\tCUIT: %0.f\n",PROV.CUIT);
	           	printf("\tFACTURA A\n");
	           	printf("\tNUMERO DE FACTURA: 0001-%d\n", PROV.numero_factura);
	           	printf("\tIMPORTE NETO GRAVADO: $%0.2f\n", PROV.neto_grabado);
		      	printf("\tIMPORTE EXENTO: $%0.2f\n", PROV.exento);
		   		printf("\tIVA APLICADO: %0.2f %c\n\n\n", PROV.IVA_alicuota, 37);
		   		printf("\tIMPORTE TOTAL: $%0.2f", PROV.importe_total);
	           	
	           	fread(&PROV, sizeof(struct compras), 1, Compra);
	        	}	
            fclose(Compra);
        }
        
        
        if(opc==2){
            FILE *Venta;
            Venta = fopen("Clientes.dat","rb");
            if (Venta==NULL){
          	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
        	exit(1);}
	        struct ventas CLI;
	    
            fread(&CLI, sizeof(struct ventas), 1, Venta);
          	while(!feof(Venta)){
	    	
	           	printf("\n\n\t--------------- %d/%d/%d ---------------\n",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano);
	           	printf("\tNOMBRE: %s\n",CLI.Nombre);
	           	printf("\tCUIT: %0.f\n",CLI.CUIT);
	           	
	           	if (CLI.COMPRADORES == 1 || CLI.COMPRADORES ==2){
	           		printf("\tFACTURA A\n");
				   }
				if(CLI.COMPRADORES == 3 || CLI.COMPRADORES == 4){
					printf("\tFACTURA B\n");
				}
	           	printf("\tNUMERO DE FACTURA = 0001-%d\n", CLI.numero_factura);
	          	printf("\tIMPORTE NETO GRAVADO: $%0.2f\n", CLI.neto_grabado);
		    	printf("\tIMPORTE EXENTO: $%0.2f\n", CLI.exento);
		   		printf("\tIVA APLICADO: %0.2f %c\n\n\n", CLI.IVA_alicuota, 37);
		   		printf("\tIMPORTE TOTAL: $%0.2f", CLI.importe_total);
	           	
	           	fread(&CLI, sizeof(struct ventas), 1, Venta);
	      	}
	        fclose(Venta);
	    }
	    if (opc<1 || opc>2){
	    	printf("\n\tSELECCIONE UNA DE LAS OPCIONES DADAS");
        	printf("\n\n\n\t");
       		system("PAUSE");
           	system("CLS");	
		}
		
	}while(opc<1 || opc>2);
	
	printf("\n\n\n\tPara volver al menu principal");
	printf("\n\t");
    system("pause");
    system("cls");	 
}




// ########################### MUESTRA EL CONTENIDO DE AMBOS ARCHIVOS ########################### 

void mostrar_libros(){
    int opc, mes, seguir;
    char Libro_IVA [500];
    FILE *IVA;
    
    do{
    	system("cls");
    	printf("\n\tCual Libro IVA desea ver? \n\n\t1: Compras  \n\t2: Ventas");
    	printf("\n\n\n\tRespuesta: ");
    	scanf("%d",&opc);
    	
    	if (opc==1){
    		
    		do{
		        printf("\n\n\tQue mes asociado al Libro IVA Compra desea ver?   Ej: 1 = Enero");
            	printf("\n\n\n\tRespuesta: ");
            	scanf("%d",&mes);
        	    system("cls");
				
				switch(mes){
					case 1: 
					    IVA = fopen("LIBRO IVA COMPRAS DE ENERO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE ENERO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 2:
                    	IVA = fopen("LIBRO IVA COMPRAS DE FEBRERO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE FEBRERO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                 	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 3:
                    	IVA = fopen("LIBRO IVA COMPRAS DE MARZO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE MARZO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 4:
                    	IVA = fopen("LIBRO IVA COMPRAS DE ABRIL.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE ABRIL NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 5:
                    	IVA = fopen("LIBRO IVA COMPRAS DE MAYO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE MAYO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 6:
                    	IVA = fopen("LIBRO IVA COMPRAS DE JUNIO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE JUNIO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                 	}	
                        fclose(IVA);
                        break;
                    case 7:
                    	IVA = fopen("LIBRO IVA COMPRAS DE JULIO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE JULIO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}
                        fclose(IVA);
                        break;
                    case 8:
                    	IVA = fopen("LIBRO IVA COMPRAS DE AGOSTO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE AGOSTO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 9:
                    	IVA = fopen("LIBRO IVA COMPRAS DE SEPTIEMBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE SEPTIEMBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                    	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	            	    }	
                        fclose(IVA);
                        break;
                    case 10:
                    	IVA = fopen("LIBRO IVA COMPRAS DE OCTUBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE OCTUBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	} 	
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 11:
                    	IVA = fopen("LIBRO IVA COMPRAS DE NOVIEMBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE NOVIEMBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}	
	                    while(!feof(IVA)){
	                    	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 12:
                    	IVA = fopen("LIBRO IVA COMPRAS DE DICIEMBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA COMPRAS DE DICIEMBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                    	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    default:
                    	printf("\n\tINGRESE UN MES DENTRO DEL 1 AL 12.");
                	printf("\n\n\n\t");
       	         	system("PAUSE");
                	system("CLS");
				}		
			}while (mes<1 || mes>12);	
		}
        
        
        if (opc==2){
    		
    		do{
		        printf("\n\n\tQue mes asociado al Libro IVA Venta desea ver?   Ej: 1 = Enero");
            	printf("\n\n\n\tRespuesta: ");
            	scanf("%d",&mes);
        	    system("cls");
				
				switch(mes){
					case 1: 
					    IVA = fopen("LIBRO IVA VENTAS DE ENERO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE ENERO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 2:
                    	IVA = fopen("LIBRO IVA VENTAS DE FEBRERO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE FEBRERO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                 	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 3:
                    	IVA = fopen("LIBRO IVA VENTAS DE MARZO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE MARZO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 4:
                    	IVA = fopen("LIBRO IVA VENTAS DE ABRIL.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE ABRIL NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 5:
                    	IVA = fopen("LIBRO IVA VENTAS DE MAYO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE MAYO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 6:
                    	IVA = fopen("LIBRO IVA VENTAS DE JUNIO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE JUNIO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                 	}	
                        fclose(IVA);
                        break;
                    case 7:
                    	IVA = fopen("LIBRO IVA VENTAS DE JULIO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE JULIO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 8:
                    	IVA = fopen("LIBRO IVA VENTAS DE AGOSTO.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE AGOSTO NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 9:
                    	IVA = fopen("LIBRO IVA VENTAS DE SEPTIEMBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE SEPTIEMBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                    	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	            	    }	
                        fclose(IVA);
                        break;
                    case 10:
                    	IVA = fopen("LIBRO IVA VENTAS DE OCTUBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE OCTUBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	} 	
	                    while(!feof(IVA)){
	                     	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 11:
                    	IVA = fopen("LIBRO IVA VENTAS DE NOVIEMBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE NOVIEMBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}	
	                    while(!feof(IVA)){
	                    	fgets(Libro_IVA, 500, IVA);
	                    	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    case 12:
                    	IVA = fopen("LIBRO IVA VENTAS DE DICIEMBRE.txt","rt");
                        if (IVA==NULL){
                        printf("\n\tEL LIBRO IVA VENTAS DE DICIEMBRE NO EXISTE O NO SE PUDO ABRIR.");
                        break;
	                	}
	                    while(!feof(IVA)){
	                    	fgets(Libro_IVA, 500, IVA);
	                     	puts(Libro_IVA);
	                	}	
                        fclose(IVA);
                        break;
                    default:
                    	printf("\n\tINGRESE UN MES DENTRO DEL 1 AL 12.");
                    	printf("\n\n\n\t");
       	             	system("PAUSE");
                    	system("CLS");
				}		
			}while (mes<1 || mes>12);	
		}
		
		printf("\n\n\n\tDesea visualizar otro Libro IVA Compra/Venta?    SI = 1 / NO = 2");
	    printf("\n\tRESPUESTA: "); fflush(stdin);
	   	scanf("%d", &seguir);
		
	}while(opc<1 || opc>2 || seguir == 1);
	
	
	
	printf("\n\n\n\tPara volver al menu principal");
	printf("\n\t");
    system("pause");
    system("cls");	 
}





// PERMITE CONFIGURAR EL VALOR DE LA ALICUOTA IVA SI ES NECESARIO

void parametros_iva(){
	int opc;
	
	FILE *Para = fopen("Parametros IVA.dat", "r+b");

		if (Para != NULL){
			struct parametros P;
		
           	fread(&P, sizeof(struct parametros), 1, Para);
			
			do{
	    	printf("\n\tEL VALOR DE LAS ALICUOTAS IVA ACTUALMENTE SON: \n\n\tIVA 1 = %0.2f%c\n\tIVA 2 = %0.2f%c", P.IVA1, 37, P.IVA2, 37);
		    printf("\n\n\tATENCION: DESEA MODIFICAR EL VALOR DE LAS ALICUOTAS IVA?   1 = SI / 2 = NO");
	    	printf("\n\n\tRESPUESTA: ");
	    	scanf("%d", &opc);
		
			if(opc == 1){
				printf("\n\tINGRESE EL NUEVO VALOR DE LA ALICUOTA IVA 1: ");
				scanf("%lf", &P.IVA1);
				printf("\n\tINGRESE EL NUEVO VALOR DE LA ALICUOTA IVA 2: ");
				scanf("%lf", &P.IVA2);
			
				int posicion = ftell(Para)-(sizeof(struct parametros));
      	        fseek(Para, posicion, SEEK_SET);
      	        fwrite(&P, sizeof(struct parametros), 1, Para);
			
			
				printf("\n\n\n\tVALORES DE ALICUOTAS IVA MODIFICADAS.");
			}
		
			if(opc == 2){
				printf("\n\n\n\tLOS VALORES DE ALICUOTAS IVA NO SE MODIFICARAN");
			}
		
		
			if(opc<1 || opc>2){
				printf("\n\tINGRESE UNA DE LAS OPCIONES DADAS");
      	        printf("\n\n\n\t");
      	     	system("PAUSE");
      	        system("CLS");
		    }
		
		}while(opc<1 || opc>2);
		
		fflush(Para);
    	fclose(Para);
	}
	
	
	printf("\n\n\n\tPara volver al menu principal");
	printf("\n\t");
    system("pause");
    system("cls");	
	
}






// ########################### USAR AL ARCHIVO PROVEEDORES.DAT PARA GENERAR EL LIBRO IVA COMPRA DEL MES ########################### 

void generar_libro_compra(FILE* IVA,int mes, int anio){
    int i;
	
	double aux, aux2, aux3, aux4, iva_1, iva_2 ,exento,total, gravados;
	    
	FILE* Compra;
    Compra = fopen("Proveedores.dat","r+b");
	if (Compra==NULL){
	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
	exit(1);}
	
	FILE *Para = fopen("Parametros IVA.dat", "rb");
    struct parametros P;
    fread(&P, sizeof(struct parametros), 1, Para);
	
		
	
	fprintf(IVA,"\n\n\t\t\t\t\t\t\t\t**** LIBRO IVA  -- COMPRAS ****\n\n\n"); 
	fprintf(IVA,"\tEMPRESA:PISCINAS TECNOR\t\t\t\t\t\t\t\t\t\t\t\t  FECHA: %d/%d\n",mes,anio);
	fprintf(IVA,"\tC.U.I.T.: 23-39014805-9\n\t");
	 int n = 150;
     
    for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
	fprintf(IVA,"\tFECHA\t          COMPROBANTE\t  CLIENTE\t\t  C.U.I.T.\t    NETO\tEXENTO Y     IVA\tIVA\t  IMPORTE \n");
	fprintf(IVA,"\t\t    TIPO   NUMERO\t\t\t          NRO.\t\t    GRAVADO     NO GRAV.     %0.2f%c\t%0.2f%c\t   TOTAL\n\t", P.IVA2,37,P.IVA1, 37,37);	
	for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
    
	struct compras PROV;
		
	fread(&PROV, sizeof(struct compras), 1, Compra);
	while(!feof(Compra)){
			
			if (mes == PROV.FCH.mes){
				
				if(PROV.VENDEDORES == 1){
					
					fprintf(IVA,"\t%-2d/%-2d/%d | A | 0001-%-10d|%-25s| %-15.f | %-10.2f | %-10.2f",PROV.FCH.dia,PROV.FCH.mes,PROV.FCH.ano,PROV.numero_factura,PROV.Nombre,PROV.CUIT,PROV.neto_grabado,PROV.exento);
           	        if (PROV.IVA==1){
        	            exento = exento + PROV.exento;
        	            gravados = gravados + PROV.neto_grabado;
						aux = (PROV.neto_grabado)*(PROV.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux2,PROV.importe_total);
                        total = total + PROV.importe_total;
        	            iva_2 = iva_2 + aux;
        	            aux = 0;
			    	}
        	           
			        if (PROV.IVA==2){
        	            exento = exento + PROV.exento;
        	            gravados = gravados + PROV.neto_grabado;
						aux2 = (PROV.neto_grabado)*(PROV.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux2,aux,PROV.importe_total);
                        total = total + PROV.importe_total;
        	            iva_2 = iva_2 + aux2;
        	            aux2 = 0;
		    		}
					   
			    	if (PROV.IVA==3){
        	            exento = exento + PROV.exento;
        	            gravados = gravados + PROV.neto_grabado;
						aux = (PROV.neto_grabado)*(PROV.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux2,aux,PROV.importe_total);
                        total = total + PROV.importe_total;
        	            iva_1 = iva_1 + aux;
        	            aux = 0;
		    		}
				}
			  		
					   
		    	
		    	    
	    	}
		fread(&PROV, sizeof(struct compras), 1, Compra);
	}
	 fprintf(IVA,"\t");  	
	fclose(Compra);
	for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
	fprintf(IVA,"\n\n\t**** TRANSPORTE  /  TOTAL ****\t\t\t\t\t            | %-10.2f | %-10.2f| %-8.2f | %-8.2f | %-12.2f |\n\t",gravados ,exento,iva_2,iva_1,total);
	
	for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
	fprintf(IVA,"\n\n\n");
    fprintf(IVA,"\tIVA %0.2f%c = $%0.2f\n", P.IVA2,37,iva_2);
    fprintf(IVA,"\tIVA %0.2f%c = $%0.2f\n",  P.IVA1,37,iva_1);
    fprintf(IVA,"\tIVA TOTAL (NETO) = $%0.2f\n",iva_1 + iva_2);
    
    fclose(Para);
    fclose(IVA);
  
}
	
	
	
// ########################### USA EL ARCHIVO CLIENTES.DAT PARA CREAR EL LIBRO IVA VENTAS DEL MES ########################### 

void generar_libro_venta(FILE* IVA,int mes, int anio){
	int i;
	double aux, aux2, aux3, aux4, iva_1, iva_2 ,exento,total, gravados;
	    
	FILE* Venta;
    Venta = fopen("Clientes.dat","r+b");
	if (Venta==NULL){
	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
	exit(1);}
	
	FILE *Para = fopen("Parametros IVA.dat", "rb");
    struct parametros P;
    fread(&P, sizeof(struct parametros), 1, Para);
		
	
	fprintf(IVA,"\n\n\t\t\t\t\t\t\t\t**** LIBRO IVA  -- VENTAS ****\n\n\n"); 
	fprintf(IVA,"\tEMPRESA:PISCINAS TECNOR\t\t\t\t\t\t\t\t\t\t\t\t  FECHA: %d/%d\n",mes,anio);
	fprintf(IVA,"\tC.U.I.T.: 23-39014805-9\n\t");
	int n = 150;
     
    for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
	fprintf(IVA,"\tFECHA\t          COMPROBANTE\t  CLIENTE\t\t  C.U.I.T.\t    NETO\tEXENTO Y     IVA\tIVA\t  IMPORTE \n");
	fprintf(IVA,"\t\t    TIPO     NUMERO\t\t\t          NRO.\t\t    GRAVADO     NO GRAV.     %0.2f%c\t%0.2f%c\t   TOTAL\n\t",P.IVA2, 37,P.IVA1,37,37);	
	for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
       
	struct ventas CLI;
		
	fread(&CLI, sizeof(struct ventas), 1, Venta);
	while(!feof(Venta)){
			
			if (mes == CLI.FCH.mes){
				
				if(CLI.COMPRADORES==1 || CLI.COMPRADORES==2){
			  		fprintf(IVA,"\t%-2d/%-2d/%d | A | 0001-%-10d|%-25s| %-15.f | %-10.2f | %-10.2f",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano,CLI.numero_factura,CLI.Nombre,CLI.CUIT,CLI.neto_grabado,CLI.exento);
           	        if (CLI.IVA==1){
        	            exento = exento + CLI.exento;
        	            gravados = gravados + CLI.neto_grabado;
						aux = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux2,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_2 = iva_2 + aux;
        	            aux = 0;
			    	}
        	           
			        if (CLI.IVA==2){
        	            exento = exento + CLI.exento;
        	            gravados = gravados + CLI.neto_grabado;
			           	aux2 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux2,aux,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_2 = iva_2 + aux2;
        	            aux2 = 0;
		    		}
					   
			    	if (CLI.IVA==3){
        	            exento = exento + CLI.exento;
        	            gravados = gravados + CLI.neto_grabado;
			           	aux3 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux3,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_1 = iva_1 + aux3;
        	            aux3 = 0;
		    		}
					   
		    		if (CLI.IVA==4){
        	            exento = exento + CLI.exento;
        	            gravados = gravados + CLI.neto_grabado;
		    	       	aux4 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux4,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_1 = iva_1 + aux4;
        	            aux4 = 0;
		    		}
	    		}	
				
		        if(CLI.COMPRADORES==3){
		        	
            	    fprintf(IVA,"\t%-2d/%-2d/%d | B | 0001-%-10d|%-25s| %-15.f | %-10.2f | %-10.2f",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano,CLI.numero_factura,CLI.Nombre,CLI.CUIT,CLI.neto_grabado,CLI.exento);
                    
                        
                    if (CLI.IVA==1){
                        exento = exento + CLI.exento;
                        gravados = gravados + CLI.neto_grabado;
            	        aux = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux2,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_2 = iva_2 + aux;
        	            aux = 0;
		    		}
        	           
                    if (CLI.IVA==2){
                        exento = exento + CLI.exento;
                        gravados = gravados + CLI.neto_grabado;
			    	    aux2 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux2,aux,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_2 = iva_2 + aux2;
        	            aux2 = 0;
		    	    }
			    		
			        if(CLI.IVA==3){
			    		exento = exento + CLI.exento;
						gravados = gravados + CLI.neto_grabado;	
			            aux3 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux3,aux,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_2 = iva_2 + aux3;
        	            aux3 = 0;
            	    }
			    		
		    	    if (CLI.IVA==4){
            	        exento = exento + CLI.exento;   
            	        gravados = gravados + CLI.neto_grabado;
			           	aux4 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                       	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux4,aux,CLI.importe_total);
                        total = total + CLI.importe_total;
        	            iva_2 = iva_2 + aux4;
        	            aux4 = 0;
		    	    }
            	}
					
	    		if(CLI.COMPRADORES==4){
	    			
	    			if(CLI.importe_total>10000){
        	    	
			            fprintf(IVA,"\t%-2d/%-2d/%d | B | 0001-%-10d|%-25s|                 | %-10.2f | %-10.2f",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano,CLI.numero_factura,CLI.Nombre,CLI.neto_grabado,CLI.exento);
                    
                        if (CLI.IVA==1){
        	                exento = exento + CLI.exento;
        	                gravados = gravados + CLI.neto_grabado;
			        	    aux = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux2,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux;
        	                aux = 0;
		    	    	}
		    	    	
		    	    	if (CLI.IVA==2){
                     	    exento = exento + CLI.exento;
                     	    gravados = gravados + CLI.neto_grabado;
					    	aux2 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux2,aux,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux2;
        	                aux2 = 0;
			        	}
			    	    	
			        	if (CLI.IVA==3){
                            exento = exento + CLI.exento;
                            gravados = gravados + CLI.neto_grabado;
					    	aux3 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux3,aux,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux3;
        	                aux3 = 0;
			    	    
			        	}
						
			        	if (CLI.IVA==4){
                            exento = exento + CLI.exento;
                            gravados = gravados + CLI.neto_grabado;
				      		aux4 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux4,aux,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux4;
        	                aux4 = 0;
        	            }
        	            
		           	}else{
		         		fprintf(IVA,"\t%-2d/%-2d/%d | B | 0001-%-10d|CONSUMIDOR FINAL.        |                 | %-10.2f | %-10.2f",CLI.FCH.dia,CLI.FCH.mes,CLI.FCH.ano,CLI.numero_factura,CLI.neto_grabado,CLI.exento);
                    
                        if (CLI.IVA==1){
        	                exento = exento + CLI.exento;
        	                gravados = gravados + CLI.neto_grabado;
			        	    aux = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux,aux2,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux;
        	                aux = 0;
		    	    	}
		    	    	
		    	    	if (CLI.IVA==2){
                     	    exento = exento + CLI.exento;
                     	    gravados = gravados + CLI.neto_grabado;
					    	aux2 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux2,aux,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux2;
        	                aux2 = 0;
			        	}
			    	    	
			        	if (CLI.IVA==3){
                            exento = exento + CLI.exento;
                            gravados = gravados + CLI.neto_grabado;
					    	aux3 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux3,aux,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux3;
        	                aux3 = 0;
			    	    
			        	}
						
			        	if (CLI.IVA==4){
                            exento = exento + CLI.exento;
                            gravados = gravados + CLI.neto_grabado;
				      		aux4 = (CLI.neto_grabado)*(CLI.IVA_alicuota/100.0);
                           	fprintf(IVA,"| %-8.2f | %-8.2f | %-12.2f |\n",aux4,aux,CLI.importe_total);
                            total = total + CLI.importe_total;
        	                iva_2 = iva_2 + aux4;
        	                aux4 = 0;
        	            }
					}
	    		}
	    	}
		fread(&CLI, sizeof(struct ventas), 1, Venta);
	}
	 fprintf(IVA,"\t");  	
	fclose(Venta);
	for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
       fprintf(IVA,"\n");
	fprintf(IVA,"\n\n\t**** TRANSPORTE  /  TOTAL ****\t\t\t\t\t            | %-10.2f | %-10.2f| %-8.2f | %-8.2f | %-12.2f |\n\t",gravados,exento,iva_2,iva_1,total);
	
	
	for(i=n;i>0;i--){
       
          fprintf(IVA,"-");
       }
    fprintf(IVA,"\n");
	fprintf(IVA,"\n\n\n");
    fprintf(IVA,"\tIVA %0.2f%c = $%0.2f\n", P.IVA2,37,iva_2);
    fprintf(IVA,"\tIVA %0.2f%c = $%0.2f\n", P.IVA1,37,iva_1);
    fprintf(IVA,"\tIVA TOTAL (NETO) = $%0.2f\n",iva_1 + iva_2);
    
    
    
    fclose(Para);
    fclose(IVA);
    
  
}





// ########################### USAR AL ARCHIVO PROVEEDORES.DAT PARA GENERAR EL LIBRO IVA COMPRA DEL MES ########################### 

void libro_compra(){
	
    int mes, anio;
	int existe1,existe2,existe3,existe4,existe5,existe6,
	existe7,existe8,existe9,existe10,existe11,existe12;
	
	
	FILE *Compras;
    Compras = fopen("Proveedores.dat","r+b");
    if (Compras==NULL){
	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
	exit(1);}
	FILE *IVA;
	
		
	struct compras PROVE;
	fread(&PROVE, sizeof(struct compras), 1, Compras);
	while(!feof(Compras)){
		
		switch(PROVE.FCH.mes){
			
                                case 1:
                            		if(existe1!=1){	
	                                mes = 1;
									anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE ENERO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe1 = 1;}
                        	    	break;
                             	case 2:
                        	    	if(existe2!=1){	
	                                mes = 2;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE FEBRERO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe2 = 1;}
        	                    	break;
                            	case 3:
                            		if(existe3!=1){	
	                                mes = 3;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE MARZO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe3 = 1;}
                            		break;
                            	case 4:
                            		if(existe4!=1){	
	                                mes = 4;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE ABRIL.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe4 = 1;}
                            		break;
                            	case 5:
                            		if(existe5!=1){	
	                                mes = 5;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE MAYO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe5 = 1;}
                            		break;
								case 6:
                            		if(existe6!=1){	
	                                mes = 6;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE JUNIO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe6 = 1;}
                            		break;
								case 7:
                            		if(existe7!=1){	
	                                mes = 7;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE JULIO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe7 = 1;}
                            		break;
								case 8:
                            		if(existe8!=1){	
	                                mes = 8;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE AGOSTO.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe8 = 1;}
                            		break;
								case 9:
                            		if(existe9!=1){	
	                                mes = 9;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE SEPTIEMBRE.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe9 = 1;}
                            		break;
								case 10:
                            		if(existe10!=1){	
	                                mes = 10;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE OCTUBRE.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe10 = 1;}
                            		break;
								case 11:
                            		if(existe11!=1){	
	                                mes = 11;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE NOVIEMBRE.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe11 = 1;}
                            		break;
								case 12:
                            		if(existe12!=1){	
	                                mes = 12;
	                                anio = PROVE.FCH.ano;
									IVA = fopen("LIBRO IVA COMPRAS DE DICIEMBRE.txt","wt");
	                                generar_libro_compra(IVA,mes,anio);
	                                fclose(IVA);
	                                existe12 = 1;}
                            		break;}
		fread(&PROVE, sizeof(struct compras), 1, Compras);}
	
	
	
	fclose(Compras);	
    printf("\n\n\tDATOS GUARDADOS EN EL LIBRO IVA COMPRA\n");
    printf("\n\t");
}





// ########################### USA EL ARCHIVO CLIENTES.DAT PARA CREAR EL LIBRO IVA VENTAS DEL MES ########################### 

void libro_venta(){
	
    int mes, anio;
	int existe1,existe2,existe3,existe4,existe5,existe6,
	existe7,existe8,existe9,existe10,existe11,existe12;
	
	
	FILE *IVA;
	FILE *Ventas;
    Ventas = fopen("Clientes.dat","r+b");
	if (Ventas==NULL){
	printf("NO SE HA PODIDO ABRIR EL ARCHIVO.");
	exit(1);}
	
	
	struct ventas CLIE;
	fread(&CLIE, sizeof(struct ventas), 1, Ventas);
	while(!feof(Ventas)){
	    switch(CLIE.FCH.mes){
                            	case 1:
                            		if(existe1!=1){	
	                                mes = 1;
									anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE ENERO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe1 = 1;}
                        	    	break;
                             	case 2:
                        	    	if(existe2!=1){	
	                                mes = 2;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE FEBRERO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe2 = 1;}
        	                    	break;
                            	case 3:
                            		if(existe3!=1){	
	                                mes = 3;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE MARZO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe3 = 1;}
                            		break;
                            	case 4:
                            		if(existe4!=1){	
	                                mes = 4;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE ABRIL.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe4 = 1;}
                            		break;
                            	case 5:
                            		if(existe5!=1){	
	                                mes = 5;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE MAYO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe5 = 1;}
                            		break;
								case 6:
                            		if(existe6!=1){	
	                                mes = 6;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE JUNIO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe6 = 1;}
                            		break;
								case 7:
                            		if(existe7!=1){	
	                                mes = 7;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE JULIO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe7 = 1;}
                            		break;
								case 8:
                            		if(existe8!=1){	
	                                mes = 8;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE AGOSTO.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe8 = 1;}
                            		break;
								case 9:
                            		if(existe9!=1){	
	                                mes = 9;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE SEPTIEMBRE.txt","wt");
	                               generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe9 = 1;}
                            		break;
								case 10:
                            		if(existe10!=1){	
	                                mes = 10;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE OCTUBRE.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe10 = 1;}
                            		break;
								case 11:
                            		if(existe11!=1){	
	                                mes = 11;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE NOVIEMBRE.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe11 = 1;}
                            		break;
								case 12:
                            		if(existe12!=1){	
	                                mes = 12;
	                                anio = CLIE.FCH.ano;
									IVA = fopen("LIBRO IVA VENTAS DE DICIEMBRE.txt","wt");
	                                generar_libro_venta(IVA,mes,anio);
	                                fclose(IVA);
	                                existe12 = 1;}
                            		break;}
		fread(&CLIE, sizeof(struct ventas), 1, Ventas);}
		
	
	
	
	fclose(Ventas);	
    printf("\n\n\tDATOS GUARDADOS EN EL LIBRO IVA VENTA\n");
    printf("\n\t");
}





	
	
	
	
	
	
	


	     
  
