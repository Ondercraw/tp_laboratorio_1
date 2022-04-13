/*
 * calculos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: ungim
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

float descontarAerolineas(float precioAerolineas);
float descontarLatam(float precioLatam);
float aumentarAerolineas(float precioAerolineas);
float aumentarLatam(float precioLatam);
float bitcoinearAerolineas(float bitcoin,float precioAerolineas);
float bitcoinearLatam(float bitcoin, float precioLatam);
float unitarearAerolineas(float precioAerolineas, float km);
float unitarearLatam(float precioLatam, float km);
float diferenciar(float precioAerolineas, float precioLatam);

#endif /* CALCULOS_H_ */
