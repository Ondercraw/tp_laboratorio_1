#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "inputs.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int ret;

	FILE* pFile;

	if(path == NULL && pArrayListPassenger == NULL){

		ret = 0;
		return ret;
	}

	pFile = fopen(path, "r");

	ret = parser_PassengerFromText(pFile, pArrayListPassenger);

	fclose(pFile);

    return ret;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret;

		FILE* pFile;

		if(path == NULL && pArrayListPassenger == NULL){

			ret = 0;
			return ret;
		}

		pFile = fopen(path, "rb");

		ret = parser_PassengerFromBinary(pFile, pArrayListPassenger);

		fclose(pFile);

    return ret;
}


int controller_id(LinkedList* pArrayListPassenger, int contador){

	int retorno = 0;
	int i;
	Passenger* aux;

	int largo = ll_len(pArrayListPassenger);

	if (contador == 0) {
		retorno = 1;
	}
	for (i = 0; i < contador; i++) {

		aux = ll_get(pArrayListPassenger, i);
		Passenger_setId(aux, (largo + i + 1 - contador));
		ll_set(pArrayListPassenger, i, aux);

	}

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){

	int r = 0;
	Passenger* this;

	int auxId;
	char auxIdStr[10];
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxPrecioStr[10];
	char auxCodigoVuelo[8];
	int auxTipoPasajero;
	char auxTipoPasajeroStr[30];
	int auxEstadoVuelo;
	char auxEstadoVueloStr[20];

	fflush(stdin);
	rellenarArray(auxNombre, "\nIngrese el nombre del pasajero: \n");

	rellenarArray(auxApellido, "\nIngrese el apellido del pasajero: \n");

	rellenarFloat(&auxPrecio, "\nIngrese el precio del vuelo: \n");

	rellenarInt(&auxTipoPasajero, "\n 1 si es First Class \n 2 si es Executive Class \n 3 si es Economy Class \n Ingrese el tipo del pasajero: \n");

	rellenarArray(auxCodigoVuelo, "\n Ingrese el codigo del vuelo: \n");

	rellenarInt(&auxEstadoVuelo,"\n1 si el vuelo esta Aterrizado \n 2 si esta En horario \n 3 si esta En vuelo \n 4 si esta Demorado \n Ingrese el estado del vuelo: \n");


	auxId = PassengeridLibre(pArrayListPassenger);

	itoa(auxId, auxIdStr, 10);
	itoa(auxPrecio, auxPrecioStr, 10);

	if(auxTipoPasajero == 1){
			strcpy(auxTipoPasajeroStr, "FirstClass");
		}else
			if(auxTipoPasajero == 2){
				strcpy(auxTipoPasajeroStr, "ExecutiveClass");
			}else
				if(auxTipoPasajero == 3){
					strcpy(auxTipoPasajeroStr, "EconomyClass");
				}

	if(auxEstadoVuelo == 1){
			strcpy(auxEstadoVueloStr, "Aterrizado");
		}else
			if(auxEstadoVuelo == 2){
				strcpy(auxEstadoVueloStr, "En horario");
			}else
				if(auxEstadoVuelo == 3){
					strcpy(auxEstadoVueloStr, "En vuelo");
				}else
					if(auxEstadoVuelo == 4){
						strcpy(auxEstadoVueloStr, "Demorado");
					}



	this = Passenger_newParametros(auxIdStr, auxNombre, auxApellido, auxPrecioStr, auxTipoPasajeroStr, auxCodigoVuelo, auxEstadoVueloStr);

	if (this != NULL)
		{
			ll_add(pArrayListPassenger, this);
			printf("Pasajero guardado correctamente, Su ID es: %d \n",this->id);
			r = 1;
		}


    return r;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){


	int indice;
	int opcion = 0;
	int ret;
	Passenger* this;

	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxPrecioStr[10];
	char auxCodigoVuelo[8];
	int auxTipoPasajero;
	char auxTipoPasajeroStr[30];
	int auxEstadoVuelo;
	char auxEstadoVueloStr[20];

	if (pArrayListPassenger != NULL){

		printf("Modificar pasajero \n\n");
		rellenarInt(&auxId, "Ingrese el id del pasajero a modificar: \n");
		indice = Passenger_buscarId(pArrayListPassenger, auxId);

		while (indice == -1)
			{
				rellenarInt(&auxId, "Error. Ingrese el id de un pasajero existente: \n");
				indice = Passenger_buscarId(pArrayListPassenger, auxId);
			}

		if (indice >= 0)
				{
					do
					{
						printf("Modificar pasajero \n\n"
								"1-Modificar Nombre \n"
								"2-Modificar Apellido \n"
								"3-Modificar Precio \n"
								"4-Modificar Codigo del vuelo \n"
								"5-Modificar Tipo de pasajero \n"
								"6-Modificar Estado del vuelo \n"
								"7-Salir \n\n"
								"Ingrese la opcion deseada: ");
						scanf("%d", &opcion);
						fflush(stdin);


						switch (opcion){

						case 1:

							rellenarArray(auxNombre, "Ingrese el nuevo nombre del pasajero: \n");

							this = (Passenger*) ll_get(pArrayListPassenger, indice);

							if (this != NULL)
									{
										Passenger_setNombre(this, auxNombre);
										ret = 1;
									}

							break;

						case 2:

							rellenarArray(auxApellido, "Ingrese el nuevo apellido del pasajero: \n");

							this = (Passenger*) ll_get(pArrayListPassenger, indice);

							if (this != NULL)
									{
										Passenger_setApellido(this, auxApellido);
										ret = 1;
									}

							break;

						case 3:
							rellenarFloat(&auxPrecio, "Ingrese el nuevo precio del vuelo: \n");

							itoa(auxPrecio, auxPrecioStr, 10);

							this = (Passenger*) ll_get(pArrayListPassenger, indice);

							if (this != NULL)
								{
									Passenger_setPrecio(this, auxPrecio);
									ret = 1;
								}

							break;

						case 4:

							rellenarArray(auxCodigoVuelo, "Ingrese el nuevo codigo del vuelo: ");

							this = (Passenger*) ll_get(pArrayListPassenger, indice);

							if (this != NULL)
								{
									Passenger_setCodigoVuelo(this, auxCodigoVuelo);
									ret = 1;
								}


							break;

						case 5:

							rellenarInt(&auxTipoPasajero, "\n 1 si es First Class \n 2 si es Executive Class \n 3 si es Economy Class \n Ingrese el nuevo tipo del pasajero: \n");

							if(auxTipoPasajero == 1){
										strcpy(auxTipoPasajeroStr, "FirstClass");
									}else
										if(auxTipoPasajero == 2){
											strcpy(auxTipoPasajeroStr, "ExecutiveClass");
										}else
											if(auxTipoPasajero == 3){
												strcpy(auxTipoPasajeroStr, "EconomyClass");
											}

							this = (Passenger*) ll_get(pArrayListPassenger, indice);

							if (this != NULL)
								{
									Passenger_setTipoPasajero(this, auxTipoPasajero);
									ret = 1;
								}


							break;

						case 6:

							rellenarInt(&auxEstadoVuelo,"\n1 si el vuelo esta Aterrizado \n 2 si esta En horario \n 3 si esta En vuelo \n 4 si esta Demorado \n Ingrese el nuevo estado del vuelo: \n");

							if(auxEstadoVuelo == 1){
										strcpy(auxEstadoVueloStr, "Aterrizado");
									}else
										if(auxEstadoVuelo == 2){
											strcpy(auxEstadoVueloStr, "En horario");
										}else
											if(auxEstadoVuelo == 3){
												strcpy(auxEstadoVueloStr, "En vuelo");
											}else
												if(auxEstadoVuelo == 4){
													strcpy(auxEstadoVueloStr, "Demorado");
												}

							this = (Passenger*) ll_get(pArrayListPassenger, indice);

							if (this != NULL)
								{
									Passenger_setEstadoVuelo(this, auxEstadoVueloStr);
									ret = 1;
								}

							break;

						case 7:

							printf("Saliendo del programa");
							break;

						default:

							printf("\nOpcion no valida.\n");

							break;

						}
					}while (opcion != 7);

				}

	}
	return ret;
}
/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int validar;
	int auxId;
	int indice;
	Passenger* this;

	validar = 0;

	printf("Eliminar pasajero \n\n");
	rellenarInt(&auxId, "Ingrese el id del pasajero a eliminar: \n");
	indice = Passenger_buscarId(pArrayListPassenger, auxId);

	while (indice == -1)
		{
			rellenarInt(&auxId, "Error. Ingrese el id de un pasajero existente: \n");
			indice = Passenger_buscarId(pArrayListPassenger, auxId);
		}

	if (indice >= 0)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, indice);
			ll_remove(pArrayListPassenger, indice);
			printf("Pasajero Borrado. \n");
			validar = 1;
		}

	    return validar;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int len;

	Passenger* this;

	len = ll_len(pArrayListPassenger);

	for(int i=0;i<len;i++){

		this = (Passenger*)ll_get(pArrayListPassenger, i);

		listPassenger(this);
			}



    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger){

	    int ret = 0;
	    int opcion;

	    if(pArrayListPassenger!=NULL){

	        printf("Ordenar pasajeros por nombre: \n\n"
	        		"Forma ascendente (1): \n"
	        		"Forma descendente (2): \n");
	        fflush(stdin);
	        scanf("%d",&opcion);

	        switch(opcion){

	             case 1:

	                 ll_sort(pArrayListPassenger,Passenger_compareByName,0);
	                 ret = 0;


	                 break;

	             case 2:

	            	 if(ll_sort(pArrayListPassenger,Passenger_compareByName,1) == 0){
	            	 	 ret=1;
	            	 }
	            	 break;

	        }
	    }
	    return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int ret = 0;

	FILE* pFile;

	if(path == NULL && pArrayListPassenger == NULL){

			ret = 0;
			return ret;
		}

	pFile = fopen(path, "w");

	if(pFile == NULL){

		printf("No se pudo abrir el archivo");
	}

	ret = GuardarTexto(pFile,pArrayListPassenger);

	fclose(pFile);

    return ret;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ret = 0;

		FILE* pFile;

		if(path == NULL && pArrayListPassenger == NULL){

				ret = 0;
				return ret;
			}

		pFile = fopen(path, "wb");

		if(pFile == NULL){

			printf("No se pudo abrir el archivo");
		}

		ret = GuardarBinario(pFile,pArrayListPassenger);

		fclose(pFile);

	    return ret;
}
