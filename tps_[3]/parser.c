#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int r;
	int ret = 0;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char tipoPasajero[50];
	char codigoVuelo[8];
	char estadoVuelo[50];

	Passenger* this;

	if(pFile == NULL){
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
		}

	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

	do{

	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

		if(r==7){
			this = Passenger_newParametros(id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoVuelo);
			ll_add(pArrayListPassenger, this);

			ret = 1;
		}

	}while(!feof(pFile));
	fclose(pFile);

    return ret;

}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int r;
	int ret = 0;
	Passenger* this;


	if(pFile == NULL){
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
		}



	do{
	this = Passenger_new();

	r = fread(this,sizeof(Passenger),1,pFile);

		if(r==1){

			ll_add(pArrayListPassenger, this);

			ret = 1;
			}

		}while(!feof(pFile));
		fclose(pFile);

    return ret;
}
