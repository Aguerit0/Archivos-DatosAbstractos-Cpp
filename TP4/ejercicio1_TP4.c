#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ElijeTuPropiaAventura()
{
	FILE *F1;
	F1=fopen("cuentoInteractivo.txt","wt");

	int opc=0;
	system("cls");
	printf("\t\t\t\tELIGE TU PROPIA HISTORIA");
	printf("\nEn esta historia se sobre las decisiones que tomara Juan a lo largo de un dia de su vida, donde tu creas tu final.");
	printf("\nA medida que vayas avanzando en tu aventura tendras que elegir entre varias opciones, depende que opciones elijas el final de la historia cambiara.");
	
	printf("\n\n~~Comenzar(1)~~");
	printf("\nopc: ");scanf("%d",&opc);
	while(opc!=1)
	{
		printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
		printf("\nopc: ");
		scanf("%d",&opc);	
		system("cls");
	}
	if(opc==1)//OPC: CONTINUAR
	{
		system("cls");
		opc=0;
		printf("\nSon las 10am y Juan sale de la universidad para irse al trabajo, el cual entra a las 11am.\nEste esta indecizo en si tomarse un dia de descanzo o no....\n");
		fputs("\nSon las 10am y Juan sale de la universidad para irse al trabajo, el cual entra a las 11am.\nEste esta indecizo en si tomarse un dia de descanzo o no....\n",F1);
		printf("\nOpcion 1: tomarse un dia de descanzo\nOpcion 2: ir a trabajar");
		printf("\nopc: ");scanf("%d",&opc);
		while(opc!=1 && opc!=2)
		{
			printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
			printf("\nopc: ");scanf("%d",&opc);
			system("cls");
		}	
		if(opc==1)//OPC: TOMARSE UN DIA DE DESCANZO
		{
			system("cls");
			opc=0;
			printf("\nJuan decide descanzar del trabajo por un dia. Por lo cual sale a entrenar al dique el jumeal.\nMientras esta entrenando, se encuentra con un amigo de la escuela que no veia hace mucho tiempo. Este lo invita a salir de fiesta por la noche a lo cual juan debe decidir si aceptar o no");
			fputs("\nJuan decide descanzar del trabajo por un dia. Por lo cual sale a entrenar al dique el jumeal.\nMientras esta entrenando, se encuentra con un amigo de la escuela que no veia hace mucho tiempo. Este lo invita a salir de fiesta por la noche a lo cual juan debe decidir si aceptar o no.",F1);
			printf("\nOpcion 1: aceptar salir de noche \nOpcion 2: rechaza la propuesta");
			printf("\nopc: ");scanf("%d",&opc);
			while(opc!=1 && opc!=2)
			{
				printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
				printf("\nopc: ");scanf("%d",&opc);
				system("cls");
			}
			if(opc==1)//OPC: ACEPTA SALIR DE NOCHE
			{
				system("cls");
				opc=0;
				printf("\nJuan decide salir co su amigo de la escuela, pero aun falta mucho tiempo, asi que siguio trotando hasta volve a su casa.\nUna vez en su casa, se puso a hacer deberes de la casa. Una vez finalizado finalizados los deberes dia se prepara para salir por la noche.Decide ir al centro a comprar ropa para salir, lo cual se encuentra un compañero universitario que le dice que al dia siguiente tienen que rendir un parcial de matematicas. Por ende debe decidir si salir por la noche o quedarse estudiando para el dia siguiente.");
				fputs("\nJuan decide salir co su amigo de la escuela, pero aun falta mucho tiempo, asi que siguio trotando hasta volve a su casa.\nUna vez en su casa, se puso a hacer deberes de la casa. Una vez finalizado finalizados los deberes dia se prepara para salir por la noche.Decide ir al centro a comprar ropa para salir, lo cual se encuentra un compañero universitario que le dice que al dia siguiente tienen que rendir un parcial de matematicas. Por ende debe decidir si salir por la noche o quedarse estudiando para el dia siguiente.",F1);
				printf("\nOpcion1: salir por la noche \nOpcion2: quedarse estudiando para el parcial");
				printf("\nopc: ");scanf("%d",&opc);		
				while(opc!=1 && opc!=2)
				{
					printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
					printf("\nopc: ");scanf("%d",&opc);
					system("cls");
				}
				if(opc==1)//OPC: SALIR POR LA NOCHE
				{
					system("cls");
					opc=0;
					printf("\nUna vez se hizo de noche, Juan se junta con su amigo de la escuela y los amigos de el. Se dirigen al boliche y la pasan bien.\nFalto al parcial de matematicas, desaprobo la materia.\nFIN DE LA AVENTURA");
					fputs("\nUna vez se hizo de noche, Juan se junta con su amigo de la escuela y los amigos de el. Se dirigen al boliche y la pasan bien.\nFalto al parcial de matematicas, desaprobo la materia.\nFIN DE LA AVENTURA",F1);

				}
				else if(opc==2)//OPC: QUEDARSE ESTUDIANDO PARA EL PARCIAL
				{
					system("cls");
					opc=0;
					printf("\nJuan se quedo estudiando toda la noche para el parcial de matematicas, no le alcanzo el tiempo de estudiar todos los temas.\nNo se siente seguro de si presentarse a rendir o no, tiene que tomar una decision.");
					fputs("\nJuan se quedo estudiando toda la noche para el parcial de matematicas, no le alcanzo el tiempo de estudiar todos los temas.\nNo se siente seguro de si presentarse a rendir o no, tiene que tomar una decision.",F1);
					printf("\nOpcion 1: presentarse a rendir \nOpcion 2: no presentarse");
					printf("\nopc: ");scanf("%d",&opc);		
					while(opc!=1 && opc!=2)
					{
						printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
						printf("\nopc: ");scanf("%d",&opc);
						system("cls");
					}
					if(opc==1)//OPC: PRESENTARSE A RENDIR
					{
						opc=0;
						system("cls");
						printf("\nDecidio presentarse a rendir con los temas que sabia y probar suerte.\nEl parcial era muy largo, no lo pudo completar.\nJuan desaprueba el parcial de matematicas\nFIN DE LA AVENTURA.");
						fputs("\nDecidio presentarse a rendir con los temas que sabia y probar suerte.\nEl parcial era muy largo, no lo pudo completar.\nJuan desaprueba el parcial de matematicas\nFIN DE LA AVENTURA.",F1);
						exit(-1);
					}
					else if(opc==2)//OPC: NO PRESENTARSE A RENDIR
					{
						opc=0;
						system("cls");
						printf("\nDecidio no presentarse a rendir porque no se sentia seguro. Volvera para rendir el recuperatorio,\nFIN DE LA AVENTURA.");
						fputs("\nDecidio no presentarse a rendir porque no se sentia seguro. Volvera para rendir el recuperatorio,\nFIN DE LA AVENTURA.",F1);
						exit(-1);
					}
					
				}
			}
			else if(opc==2)//OPC: RECHAZA LA PROPUESTA
			{
				system("cls");
				opc=0;
				printf("\nJuan decidio rechazar la propuesta, asi que siguio trotando hasta volver a su casa.\nUna vez en su casa, Se puso a hacer deberes de la casa en el resto del dia. Se preparo para irse a dormir y seguir con la rutina del siguiente dia.\nFIN DE LA AVENTURA");
				fputs("\nJuan decidio rechazar la propuesta, asi que siguio trotando hasta volver a su casa.\nUna vez en su casa, Se puso a hacer deberes de la casa en el resto del dia. Se preparo para irse a dormir y seguir con la rutina del siguiente dia.\nFIN DE LA AVENTURA",F1);
				exit(-1);
			}
			
		}
		else if(opc==2)//OPC: IR A TRABAJAR
		{
			system("cls");
			opc=0;
			printf("\nDecidio ir a trabajar pero llega tarde porque el colectivo se demoro en pasar.\nUna vez en el trabajo, se encuentra con su jefe, el cual le dice que esta despedido por llegar tarde.\nJuan tiene que decidir en si disculparse por llegar tarde, o tomar sus pertenencias y retirarse.");
			fputs("\nDecidio ir a trabajar pero llega tarde porque el colectivo se demoro en pasar.\nUna vez en el trabajo, se encuentra con su jefe, el cual le dice que esta despedido por llegar tarde.\nJuan tiene que decidir en si disculparse por llegar tarde, o tomar sus pertenencias y retirarse.",F1);
			printf("\nOpcion 1: disculparse por llegar tarde\nOpcion 2: tomar sus pertencias y retirarse");
			printf("\nopc: ");scanf("%d",&opc);		
			while(opc!=1 && opc!=2)
			{
				printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
				printf("\nopc: ");scanf("%d",&opc);
				system("cls");
			}
			if(opc==1)//OPC: DISCULPARSE POR LLEGAR TARDE
			{
				opc=0;
				system("cls");
				printf("\nSe disculpa ante su jefe por llegar tarde al trabajo. Su jefe lo perdona pero le advierte que no debe volver a pasar.\nJuan tene que decidir en si aceptar la advertencia o denegarla.");
				fputs("\nSe disculpa ante su jefe por llegar tarde al trabajo. Su jefe lo perdona pero le advierte que no debe volver a pasar.\nJuan tene que decidir en si aceptar la advertencia o denegarla.",F1);
				printf("\nOpcion 1: aceptar la advertencia\nOpcion 2: denegar la advertencia");
				printf("\nopc: ");scanf("%d",&opc);
				while(opc!=1 && opc!=2)
				{
					printf("\n\n\n\nOpcion ingresada incorrecta, vuelva a intentar");
					printf("\nopc: ");scanf("%d",&opc);
					system("cls");
				}
				if(opc==1)//OPC: ACEPTAR LA ADVERTENCIA
				{
					opc=0;
					system("cls");
					printf("\nAcepta la advertencia y sigue con sus ocupaciones del trabajo.\nEl jefe tambien se retira para continuar con su jornada laboral.\nFIN DE LA AVENTURA,");
					fputs("\nAcepta la advertencia y sigue con sus ocupaciones del trabajo.\nEl jefe tambien se retira para continuar con su jornada laboral.\nFIN DE LA AVENTURA,",F1);
					exit(-1);
				}
				else if(opc==2)//OPC: DENEGAR LA ADVERTENCIA
				{
					opc=0;
					system("cls");
					printf("\nDecide denegar la advertencia de su jefe, por lo cual este lo despide del trabajo por malas actitudes.\nJunta sus pertenencias y se retira del establecimiento.\nJuan se queda sin trabajo.\nFIN DE LA AVENTURA.");
					fputs("\nDecide denegar la advertencia de su jefe, por lo cual este lo despide del trabajo por malas actitudes.\nJunta sus pertenencias y se retira del establecimiento.\nJuan se queda sin trabajo.\nFIN DE LA AVENTURA.",F1);
					exit(-1);
				}
					
			}
			else if(opc==2)//OPC TOMAR SUS PERTENENCIAS Y RETIRARSE
			{
				opc=0;
				system("cls");
				printf("\nDecide tomar sus pertenencias y retirarse del establecimiento.\nEs despedido por malas actitudes.\nJuan se queda sin trabajo.\nFIN DE LA AVENTURA.");
				fputs("\nDecide tomar sus pertenencias y retirarse del establecimiento.\nEs despedido por malas actitudes.\nJuan se queda sin trabajo.\nFIN DE LA AVENTURA.",F1);
				exit(-1);
				
			}
		}	
	}
	fclose(F1);
}


void mostrar(){
	int opc;
	char cadena [1000];
	
	FILE* F1 = fopen("cuentoInteractivo.txt","rt");
	sleep(5);
    system("cls");
	printf("\nDesea ver como quedo finalizado el cuento interactivo?\nopc: si(1) - no(2)");
	scanf("%d",&opc);
	while(opc!=1 && opc!=2)
		{
		opc=0;
		system("cls");
		printf("\nSe ingreso una opcion incorrecta, vuelva a intentar");
		printf("\nDesea ver como quedo finalizado el cuento interactivo?\nopc: si(1) - no(2)");
		scanf("%d",&opc);
		}
		if(opc==1)
		{
			while(feof(F1)==0)
			{
				fgets(cadena,1000,F1);
				printf("%s",cadena);
			}
						
		exit(-1);
		}
		else if(opc==2)
		{
		    exit(-1);
		}
	fclose(F1);
}
int main()
{
	int continuar=0;
	printf("\n\n\t\t\tELIJE TU PROPIA AVENTURA\n");
	printf("\n\n\nA CONTINUACION COMENZARAS CON EL CUENTO, PARA CONTINUAR CON LA HISTORIA DEBES SELECCIONAR LA OPCION POR LA CUAL QUIERES SEGUIR.\nDESEA CONTINUAR?:SI:1 - NO:2\n");
	printf("\nopc: ");scanf("%d", &continuar);
	while(continuar!=1 && continuar!=2)
	{
		printf("\n OPCION INGRESADA INCORRECTA, VUELVA A INTENTAR: ");
		scanf("%d", &continuar);	
		system("cls");
	}
	if(continuar==2)
	{
		printf("\n FIN DEL PROGRAMA ...");
		exit(-1);
	}
	else
	{
		//COMIENZA EL CUENTO INTERACTIVO
		ElijeTuPropiaAventura();
		mostrar();		
	}
	
	
}
