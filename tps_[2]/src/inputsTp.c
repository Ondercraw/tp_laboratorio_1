<<<<<<< HEAD:tps_[2]/src/inputsTp.c
/*
 * inputsTp.c
 *
 *  Created on: 12 may. 2022
 *      Author: ungim
 */

#include <stdio.h>
#include <string.h>

void rellenarInt(int* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	scanf("%d", variableRecibida);
	fflush(stdin);
}

void rellenarFloat(float* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}

void rellenarArray(char arrayRecibido[], char textoAMostrar[])
{
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}
=======
/*
 * inputsTp.c
 *
 *  Created on: 12 may. 2022
 *      Author: ungim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "inputsTp.h"

void rellenarInt(int* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	scanf("%d", variableRecibida);
	fflush(stdin);
}

void rellenarFloat(float* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}

void rellenarArray(char arrayRecibido[], char textoAMostrar[])
{
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}

int countPassengers (Passenger* list, int size)
{
	int countPassenger;
	int i;

	countPassenger = 0;

	for (i = 0; i < size; i++)
	{
		if(list[i].isEmpty == LLENO)
		{
			countPassenger++;
		}
	}

	return countPassenger;
}

int countPassengersPrices (Passenger* list, int size)
{
	int countPassengerPrices;
	int i;

	countPassengerPrices = 0;

	for (i = 0; i < size; i++)
	{
		if(list[i].isEmpty == LLENO)
		{
			countPassengerPrices = countPassengerPrices + list[i].price;
		}
	}

	return countPassengerPrices;
}

int calculateAveragePrice (Passenger* list, int size)
{
	int average;
	int totalPassengers = countPassengers (list, size);
	int totalPassengerPrices = countPassengersPrices (list, size);

	average = totalPassengerPrices / totalPassengers;

	return average;
}

int countPassengrOverAveragePrice (Passenger* list, int size)
{
	int average;
	int i;
	int countPassengersOverAveragePrice;

	countPassengersOverAveragePrice = 0;

	average = calculateAveragePrice(list, size);

	for (i = 0; i < size; i++)
	{
		if (list[i].isEmpty == LLENO)
		{
			if (list[i].price > average)
			{
				countPassengersOverAveragePrice++;
			}
		}
	}

	return countPassengersOverAveragePrice;
}
>>>>>>> 71321bc (tp2recu):src/inputsTp.c
