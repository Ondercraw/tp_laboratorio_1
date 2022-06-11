/*
 * inputs.c
 *
 *  Created on: 11 jun. 2022
 *      Author: ungim
 */

#include <stdio.h>
#include <string.h>
#include "inputs.h"

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



