/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Thomas velazco
 */

#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

Passenger* Passenger_new()
{
    Passenger* nuevoPasajero = NULL;
    nuevoPasajero= (Passenger*) malloc(sizeof(Passenger));

    if(nuevoPasajero != NULL)
    {
        nuevoPasajero->id=0;
        strcpy(nuevoPasajero->nombre, " ");
        strcpy(nuevoPasajero->apellido, " ");
        nuevoPasajero->tipoPasajero = 0;
        nuevoPasajero->precio = 0;
        strcpy(nuevoPasajero->codigoVuelo, " ");
    }

    return nuevoPasajero;

}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr){

	Passenger* this;

	int id;
	char tipoPasajero;
	int precio;


	this = Passenger_new();

	id = atoi(idStr);
	Passenger_setId(this,id);

	Passenger_setNombre(this,nombreStr);

	Passenger_setApellido(this,apellidoStr);

	precio = atof(precioStr);
	Passenger_setPrecio(this,precio);

	if(strcmp(tipoPasajeroStr, "FirstClass") == 0){

		tipoPasajero = 1; //1 = First Class

		}
		else{
			if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0){

			 	 tipoPasajero = 2; //2 = Executive Class

			}
				else{
					if(strcmp(tipoPasajeroStr, "EconomyClass") == 0){

						tipoPasajero = 3; //3 = Economy Class

			}
		}
	}
	Passenger_setTipoPasajero(this,tipoPasajero);

	Passenger_setCodigoVuelo(this,codigoVueloStr);

	Passenger_setEstadoVuelo(this,estadoVueloStr);

	if(this != NULL){
		if(Passenger_setId(this, id) == -1 ||
		   Passenger_setNombre(this, nombreStr) == -1||
		   Passenger_setApellido(this, apellidoStr) == -1||
		   Passenger_setPrecio(this, precio) == -1||
		   Passenger_setTipoPasajero(this, tipoPasajero) == -1||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == -1||
		   Passenger_setEstadoVuelo(this, estadoVueloStr) == -1){

				Passenger_delete(this);
				this = NULL;
		}
	}
	return this;
}
int Passenger_setId(Passenger* this,int id){

	int ret = -1;

	if(this != NULL && id > 0){

	this->id = id;
	ret = 1;
	}


	return ret;
}
int Passenger_getId(Passenger* this,int* id){

	int ret = -1;

	if(this != NULL && id != NULL){

	*id = this->id;

	ret = 1;
	}


	return ret;


}

int Passenger_setNombre(Passenger* this,char* nombre){

	int ret = -1;

	if(this != NULL && nombre != NULL){

	strcpy(this->nombre, nombre);

	ret = 1;
	}
	return ret;
}
int Passenger_getNombre(Passenger* this,char* nombre){

	int ret = -1;

	if(this != NULL && nombre != NULL){

	strcpy(nombre, this->nombre);

	ret = 1;
	}
	return ret;

}

int Passenger_setApellido(Passenger* this,char* apellido){

	int ret = -1;

	if(this != NULL && apellido != NULL){

	strcpy(this->apellido, apellido);

		ret = 1;
	}
	return ret;
}
int Passenger_getApellido(Passenger* this,char* apellido){

	int ret = -1;

	if(this != NULL && apellido != NULL){

	strcpy(apellido,this->apellido);

		ret = 1;
	}
	return ret;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int ret = -1;

	if(this != NULL && codigoVuelo != NULL){

	strcpy(this->codigoVuelo, codigoVuelo);

	ret = 1;
	}
	return ret;

}


int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int ret = -1;

	if(this != NULL && codigoVuelo != NULL){

	strcpy(codigoVuelo, this->codigoVuelo);

	ret = 1;
	}
	return ret;

}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){

	int ret = -1;

	if(this != NULL && tipoPasajero > 0){

	this->tipoPasajero = tipoPasajero;

	ret = 1;
	}
	return ret;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){

	int ret = -1;

	if(this != NULL && tipoPasajero != NULL){

	*tipoPasajero = this->tipoPasajero;

	ret = 1;
	}
	return ret;

}

int Passenger_setPrecio(Passenger* this,float precio){

	int ret = -1;

	if(this != NULL && precio > 0){

	this->precio = precio;
	ret = 1;
	}
	return ret;
}

int Passenger_getPrecio(Passenger* this,float* precio){


	int ret = -1;

	if(this != NULL && precio != NULL){

	*precio = this->precio;
	ret = 1;
	}
	return ret;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo){

	int ret = -1;

	if(this != NULL && estadoVuelo != NULL){

	strcpy(this->estadoVuelo, estadoVuelo);

	ret = 1;
	}
	return ret;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo){

	int ret = -1;

	if(this != NULL && estadoVuelo != NULL){

	strcpy(estadoVuelo, this->estadoVuelo);

	ret = 1;
	}
	return ret;

}

void Passenger_delete(Passenger* this){

	if(this != NULL){
		free(this);
		this = NULL;

	}
}

int Passenger_compareByName(void* p1, void* p2){

	    int retorno = -1;
	    char nombreUno[50];
	    char nombreDos[50];

	    if(p1 != NULL && p2 != NULL)
	    {
	    	if(Passenger_getNombre(p1,nombreUno) == 1)
	        {
	            if(Passenger_getNombre(p2,nombreDos) == 1)
	            {
	                 retorno=strcmp(nombreUno,nombreDos);
	            }
	        }
	    }
	    return retorno;
}

void listPassenger(Passenger* this){

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[50];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this,apellido);
	Passenger_getPrecio(this,&precio);
	Passenger_getTipoPasajero(this,&tipoPasajero);
	Passenger_getCodigoVuelo(this,codigoVuelo);
	Passenger_getEstadoVuelo(this,estadoVuelo);

	printf("\n ID: %d \n Nombre: %s \n Apellido: %s \n Precio: %.2f \n Tipo de pasajero: %d \n Codigo del vuelo: %s \n Estado del vuelo: %s \n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoVuelo);

}


int GuardarTexto(FILE* pFile, LinkedList* pArrayListPassenger){

	int len;
	Passenger* this;
	int tipoPasajero;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajeroStr[50];
	char codigoVuelo[8];
	char estadoVuelo[50];

	int ret = 0;

	if(pFile == NULL && pArrayListPassenger == NULL){

		printf("No existe el archivo.");
		exit(1);
	}
	len = ll_len(pArrayListPassenger);


	if(len > 0){

		fprintf(pFile, "Id,Nombre,Apellido,Precio,Codigo del vuelo,Tipo de pasajero, Estado del vuelo \n");

		for(int i=0;i < len; i++){

			this = (Passenger*) ll_get(pArrayListPassenger, i);

			if(this != NULL){

					Passenger_getId(this, &id);
					Passenger_getNombre(this, nombre);
					Passenger_getApellido(this,apellido);
					Passenger_getPrecio(this,&precio);
					Passenger_getTipoPasajero(this,&tipoPasajero);
					Passenger_getCodigoVuelo(this,codigoVuelo);
					Passenger_getEstadoVuelo(this,estadoVuelo);

					if(tipoPasajero == 1){
								strcpy(tipoPasajeroStr, "FirstClass");
							}else
								if(tipoPasajero == 2){
									strcpy(tipoPasajeroStr, "ExecutiveClass");
								}else
									if(tipoPasajero == 3){
										strcpy(tipoPasajeroStr, "EconomyClass");
									}

					fprintf(pFile, "%d, %s, %s, %2.f, %s, %s, %s \n", id,nombre,apellido,precio,tipoPasajeroStr,codigoVuelo,estadoVuelo);

					ret = 1;
			}
		}
	}

	return ret;
}

int GuardarBinario(FILE* pFile, LinkedList* pArrayListPassenger){

	int len;
	Passenger* this;
	int ret = 0;

		if(pFile == NULL && pArrayListPassenger == NULL){

			printf("No existe el archivo.");
			exit(1);
		}
		len = ll_len(pArrayListPassenger);

		if(len > 0){

			for(int i=0;i < len; i++){

				this = (Passenger*) ll_get(pArrayListPassenger, i);
				if(this != NULL){

						fwrite(this,sizeof(Passenger),1,pFile);

						ret = 1;
				}
			}
		}

		return ret;
}


int PassengeridLibre(LinkedList* pArrayListPassenger){

    Node* indice;
	indice = pArrayListPassenger->pFirstNode;
    Passenger *ultimo;

    int ret = 0;

    if (ll_len(pArrayListPassenger) == 0) {
        ret = 1;
    } else {
        for (; indice != NULL; indice = indice->pNextNode) {
            ultimo = indice->pElement;
        }
        ret = ultimo->id + 1;
    }

    return ret;
}

int Passenger_buscarId(LinkedList* pArrayListPassenger, int id)
{
	int indice;
	int i;
	int len;
	Passenger* this;

	indice = -1;

	if (pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);

		if (len > 0)
		{
			for (i = 0; i < len; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);

				if (this->id == id)
				{
					indice = i;
					break;
				}
			}
		}
	}

	return indice;
}
