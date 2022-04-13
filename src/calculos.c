/*
 * calculos.c
 *
 *  Created on: 12 abr. 2022
 *      Author: ungim
 */
#include <stdio.h>
#include <stdlib.h>

float descontarAerolineas(float precioAerolineas){

	float descuento;

	descuento =  precioAerolineas - ( (float) precioAerolineas * 0.10);

	return descuento;
}
float descontarLatam(float precioLatam){

	float descuento;

		descuento =  precioLatam - ( (float) precioLatam * 0.10);

	return descuento;

}
float aumentarAerolineas(float precioAerolineas){

	float interes;

		interes =  precioAerolineas + ( (float) precioAerolineas * 0.25);

	return interes;

}
float aumentarLatam(float precioLatam){

	float interes;

		interes =  precioLatam + ( (float) precioLatam* 0.25);

	return interes;


}
float bitcoinearAerolineas(float bitcoin, float precioAerolineas){

	float precioConBitcoin;

		precioConBitcoin = (float) (precioAerolineas / bitcoin);

	return precioConBitcoin;

}
float bitcoinearLatam(float bitcoin, float precioLatam){

	float precioConBitcoin;

		precioConBitcoin = (float) (precioLatam / bitcoin);

	return precioConBitcoin;



}
float unitarearAerolineas(float precioAerolineas, float km){

	float precioUnitario;

		precioUnitario = (float) (precioAerolineas / km);

	return precioUnitario;


}
float unitarearLatam(float precioLatam, float km){

	float precioUnitario;

	precioUnitario = (float) (precioLatam / km);

	return precioUnitario;

}
float diferenciar(float precioAerolineas, float precioLatam){

	float diferencia;

	diferencia = precioAerolineas - precioLatam;

	return diferencia;

}

