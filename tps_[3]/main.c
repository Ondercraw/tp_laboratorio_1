/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero //
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int validar = 0;
    int contadorId;
    int banderaTex = 0;
    int banderaBin = 0;
    int banderaGuaTex = 0;
    int banderaGuaBin = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	printf(	"\n1- Cargar los datos de los pasajeros desde el archivo data.csv (texto)\n"
				"2- Cargar los datos de los pasajeros desde el archivo data.csv (binario)\n"
				"3- Alta de pasajeros.\n"
				"4- Modificar datos de pasajeros.\n"
				"5- Baja de pasajeros.\n"
				"6- Listar pasajeros.\n"
				"7- Ordenar pasajeros.\n"
				"8- Guardar los datos de los pasajeros en el archivo data.csv (texto).\n"
				"9- Guardar los datos de los pasajeros en el archivo data.csv (binario).\n"
				"10- Salir.\n"
				"\nIngrese la opcion deseada: ");
				fflush(stdin);
				scanf("%d", &option);


        switch(option)
        {

            case 1:
            		if(ll_isEmpty(listaPasajeros) || (banderaTex == 0 && banderaBin == 0)){
							validar = controller_loadFromText("data.csv",listaPasajeros);

							if (validar == 1)
							{
								printf("Los datos se cargaron correctamente \n");
								system("pause");
								banderaTex = 1;
							}
							else
							{
								printf("No se pudieron cargar los datos \n");
								system("pause");
							}
						}
						else
						{
							printf("Los datos ya fueron cargados \n");
							system("pause");
						}
                break;

            case 2:
            		if (ll_isEmpty(listaPasajeros) || (banderaTex == 0 && banderaBin == 0)){
						validar = controller_loadFromBinary("data.bin",listaPasajeros);;

						if (validar == 1)
						{
							printf("Los datos se cargaron correctamente \n");
							system("pause");
						}
						else
						{
							printf("No se pudieron cargar los datos \n");
							system("pause");
						}
					}
					else
					{
						printf("Los datos ya fueron cargados \n");
						system("pause");
					}

            	break;

            case 3:

            	contadorId++;

            	controller_addPassenger(listaPasajeros);
            	banderaGuaTex = 0;
            	banderaGuaBin = 0;

                break;

            case 4:
            	if (!ll_isEmpty(listaPasajeros)){

					controller_editPassenger(listaPasajeros);
					banderaGuaTex = 0;
					banderaGuaBin = 0;

            	}else {

					printf("Error. No hay pasajeros guardados.\n");
					system("pause");

				}

                break;

            case 5:
            	if (!ll_isEmpty(listaPasajeros)){

						controller_removePassenger(listaPasajeros);
						banderaGuaTex = 0;
						banderaGuaBin = 0;

					}else {

						printf("Error. No hay pasajeros guardados.\n");
						system("pause");

					}
                break;

            case 6:

            	if (!ll_isEmpty(listaPasajeros)){

								controller_ListPassenger(listaPasajeros);

							}
							else
							{
								printf("Error. No hay pasajeros Cargados. ");
								system("pause");
							}
						break;

                break;

            case 7:
            	if (!ll_isEmpty(listaPasajeros)){


            	controller_sortPassenger(listaPasajeros);

            	}else{

					printf("Error. No hay pasajeros Cargados. \n");
					system("pause");

				}
                break;

            case 8:

            	validar = controller_saveAsText("data.csv",listaPasajeros);
            	if(validar == 1){
					printf("Los datos se guardaron correctamente \n");
					banderaGuaTex = 1;

				}
				else{
					printf("Los datos no se guardaron \n");
				}
                break;

            case 9:
            	validar = controller_saveAsBinary("data.bin",listaPasajeros);
            	if(validar == 1){
					printf("Los datos se guardaron correctamente \n");
					banderaGuaBin = 1;
				}
				else{
					printf("Los datos no se guardaron \n");
				}
                break;

            case 10:

            	if (banderaGuaTex == 1 && banderaGuaBin == 1)
            	            	{
            	            		printf("Saliendo del programa.");
            	            	}
            	            	else
            	            	{
            	            		printf("Error. Guardar los cambios antes de salir. \n");
            	            		option = 1;
            	            		system("pause");
            	            	}

                break;

            default:
            	printf("Opcion no valida. \n");
                break;
        }
    }while(option != 10);

    return 0;
}

