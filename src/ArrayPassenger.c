/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: ungim
 */

#include "ArrayPassenger.h"
#include <string.h>
#include <stdio.h>

int idIncremental = 0;

int initPassengers(Passenger* list, int len)
{
	int i = 0;

	//Hacemos un for con un indice (i), en la que, para cada posicion
	//de la estructura, dejando todas las flags isEmpty en VACIO (en el .h hay un
	// define que lo iguala a -1
	for(; i < len; i++)
	{
		list[i].isEmpty = VACIO;
	}

	return 0;
}

int generadorId(){

	idIncremental++;

	return idIncremental;
}

Passenger getPassenger()
{
	Passenger unPasajero;

	unPasajero.id = generadorId();

	printf("Ingrese nombre: \n");
	scanf("%s",unPasajero.name);
	printf("Ingrese Apellido: \n");
	scanf("%s", unPasajero.lastName);
	printf("Ingrese precio: \n");
	fflush(stdin);
	scanf("%f",&unPasajero.price);
	printf("Ingrese codigo de vuelo:\n");
	fflush(stdin);
	gets(unPasajero.flycode);
	printf("Ingrese tipo de pasajero: \n");
	fflush(stdin);
	scanf("%d",&unPasajero.typePassenger);
	printf("Ingrese el estado de vuelo: \n");
	fflush(stdin);
	scanf("%d",&unPasajero.statusFlight);


	unPasajero.isEmpty=LLENO;

	return unPasajero;

}

int buscarEspacioLibre(Passenger lista[], int len){

	int indice;
	indice = -1;

	for(int i = 0; i < len; i++){
		if(lista[i].isEmpty == VACIO){
			indice = i;
			break;
		}

	}

	return indice;
}

int addPassenger(Passenger* list, int len)
{
	int i = 0;
	int indice;

	indice = buscarEspacioLibre(list, len);

	if(indice != LLENO)
	{

		list[indice] = getPassenger();

		list[i].isEmpty = LLENO;

	}

	return indice;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int i;
	int posicionDevuelta;

	for(i = 0 ;i < len; i++)
	{
		if(list[i].id == id)
		{
		posicionDevuelta = i;

		i = len + 1;

		}
	}
	return posicionDevuelta;
}

int removePassenger(Passenger* list, int len, int id)
{
	int posicionVaciar;

	posicionVaciar = findPassengerById(list, len, id);

	list[posicionVaciar].isEmpty = -1 ;

	return 0;
}

int sortByLastName(Passenger *list, int len, int order)
{
	int i;
	int j;
	int value = 0;

	Passenger listAux;

	for(i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{
				if (order == 1)
				{
					if(list[i].typePassenger > list[j].typePassenger)
					{
						value = 1;
					}
					else
					{
						if(list[i].typePassenger == list[j].typePassenger)
						{
							value = strcmp(list[i].lastName, list[j].lastName);

						}
					}
				}

				else
				{
					if(list[i].typePassenger < list[j].typePassenger)
					{
						value = 1;
					}
					else
					{
						if(list[i].typePassenger == list[j].typePassenger)
						{
							value = strcmp(list[j].lastName, list[i].lastName);
						}
					}
				}


				if (value == 1)
				{
					value = 0;

					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flycode, list[i].flycode);
					listAux.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;

					j = i+1;
				}
			}
		}
	}
	return 0;
}
int printPassenger(Passenger* list, int length)
{
	printf(
			"\nLos ID son: \tLos nombres son: \tLos apellidos son: \tLos codigos de vuelo son: \t Los precios son : \tLos tipo de pasajero son: \tLos estados de vuelo son: \n");
	printf(
			"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t1.Ejecutivo 2.Turista\t\t1.Activo2.Cancelado\n\n\n");
	for(int i=0;i<length;i++)
	{
		if(list[i].isEmpty != -1){

			printf(
					"\t%d\t\t %s\t \t\t%s\t \t\t%s\t \t\t%f\t \t\t\t%d \t\t\t%d \n",
					list[i].id, list[i].name, list[i].lastName, list[i].flycode,
					list[i].price, list[i].typePassenger, list[i].statusFlight);
		} else {
			break;
		}
	}

	return 0;
}

int informData (Passenger* list, int len)
{
	int option;
	int subOption;
	int order;

	option = 0;
	subOption = 0;
	order = 0;

	do
	{
		printf(" Seleccione una opcion \n\n");
		printf("\n1 Informar PASAJEROS  ");
		printf("\n2 Informar PROMEDIO y TOTAL ");
		printf("\n3 SALIR |->\n");

		printf("\nIngrese opcion:");

		fflush(stdin);
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf(" Seleccione una opcion \n\n");
				printf("\n1 Ordenados ALFABETICAMENTE y por TIPO DE PASAJERO  ");
				printf("\n2 Ordenados por CODIGO DE VUELO ");
				printf("\n3 SALIR \n");

				printf("\nIngrese opcion:");

				fflush(stdin);
				scanf("%d", &subOption);

				switch (subOption)
				{
					case 1:
						printf(" Seleccione una opcion \n\n");
						printf("\n1 Ordenar de MAYOR a MENOR  ");
						printf("\n2 Ordenar de MENOR a MAYOR ");

						printf("\nIngrese opcion:");

						fflush(stdin);
						scanf("%d", &order);

						sortByLastName(list, len, order);
						printPassenger(list, len);
					break;
					case 2:
						printPassenger(list, len);
					break;
					case 3:
					break;
					default:
					break;
				}

			break;
			case 2:

			break;
			case 3:
			break;
			default:
			break;
		}
	}while (option != 3);

	return 0;
}


