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
