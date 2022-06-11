/*
 ============================================================================
 Name        : tp_programacion1.c
 Author      : Thomas Velazco
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico 1 programacion/laboratorio 1
 ============================================================================

Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "mostrarMenu.h"




int opcionIngresada;
float km;
float precioAerolineas;
float precioLatam;
float bitcoin;

int opcion;

float descuentoA;
float descuentoL;


float interesA;
float interesL;


float precioConBitcoinA;
float precioConBitcoinL;


float precioUnitarioA;
float precioUnitarioL;


float diferencia;



int main(void)
{

	setbuf(stdout, NULL);

	bitcoin = 4606954.55;

		do{

		opcion = mostrarMenu(opcionIngresada);

		switch(opcion){

			case 1:


				printf("Ingrese los kilometros del vuelo: ");

				scanf("%f", &km);

				while(km < 0){
					printf("Error. Ingrese un kilometraje valido: ");
					scanf("%f", &km);
				}
			break;

			case 2:


					printf("Ingrese el precio del vuelo (AEROLINEAS): ");

					scanf("%f", &precioAerolineas);


					printf("Ingrese el precio del vuelo (LATAM): ");

					scanf("%f", &precioLatam);

				while(precioAerolineas < 0 ){
					printf("Error. Ingrese un precio valido para AEROLINEAS: ");
					scanf("%f", &precioAerolineas);
				}
				while(precioLatam < 0 ){
					printf("Error. Ingrese un precio valido para LATAM: ");
					scanf("%f", &precioLatam);
				}
			break;


		case 3:
			descuentoA = descontarAerolineas(precioAerolineas);
			descuentoL = descontarLatam(precioLatam);
			interesA = aumentarAerolineas(precioAerolineas);
			interesL = aumentarLatam(precioLatam);
			precioConBitcoinA = bitcoinearAerolineas(bitcoin, precioAerolineas);
			precioConBitcoinL = bitcoinearLatam(bitcoin, precioLatam);
			precioUnitarioA = unitarearAerolineas(precioAerolineas, km);
			precioUnitarioL = unitarearLatam(precioLatam, km);
			diferencia = diferenciar(precioAerolineas, precioLatam);

		break;

		 case 4:

			if (precioAerolineas > 0 || precioLatam > 0)
			{
				mostrarResultados(km,  precioAerolineas,  precioLatam,  descuentoA,  interesA,  precioConBitcoinA,  precioUnitarioA,  descuentoL,  interesL,  precioConBitcoinL,  precioUnitarioL, diferencia);
			}
			else
			{
				printf("\nNo se ingresó ningun valor para Aerolineas o Latam\n");
			}


		break;


		case 5:
			km = 7090;
			precioAerolineas = 162965;
			precioLatam = 159339;

			descuentoA = descontarAerolineas(precioAerolineas);
			descuentoL = descontarLatam(precioLatam);
			interesA = aumentarAerolineas(precioAerolineas);
			interesL = aumentarLatam(precioLatam);
			precioConBitcoinA = bitcoinearAerolineas(bitcoin, precioAerolineas);
			precioConBitcoinL = bitcoinearLatam(bitcoin, precioLatam);
			precioUnitarioA = unitarearAerolineas(precioAerolineas, km);
			precioUnitarioL = unitarearLatam(precioLatam, km);
			diferencia = diferenciar(precioAerolineas, precioLatam);


			mostrarResultados(km,  precioAerolineas,  precioLatam,  descuentoA,  interesA,  precioConBitcoinA,  precioUnitarioA,  descuentoL,  interesL,  precioConBitcoinL,  precioUnitarioL, diferencia);



		break;


		case 6:
			printf("Gracias por usar el programa!!!");
		break;

		default:
			printf("Opcion incorrecta");
		break;
			}

		}while(opcion != 6);//SI PRESIONA 6 TERMINA EL PROGRAMA


	return 0;
}

