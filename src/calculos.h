/*
 * calculos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: ungim
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

float descontarAerolineas(float precioAerolineas);

/// @fn float descontarAerolineas(float)
/// @brief Se encarga de calcular el descuento del precio de Aerolineas en un 10%.
/// @param precioAerolineas
/// @return el descuento del precio del vuelo

float descontarLatam(float precioLatam);

/// @fn float descontarLatam(float)
/// @brief Se encarga de calcular el descuento del precio de Latam en un 10%.
/// @param precioLatam
/// @return el descuento del precio del vuelo

float aumentarAerolineas(float precioAerolineas);

/// @fn float aumentarAerolineas(float)
/// @brief Se encarga de calcular el interes del precio de Aerolineas en un 25%.
/// @param precioAerolineas
/// @return el interes del precio del vuelo

float aumentarLatam(float precioLatam);

/// @fn float aumentarLatam(float)
/// @brief Se encarga de calcular el interes del precio de Latam en un 25%.
/// @param precioLatam
/// @return el interes del precio del vuelo

float bitcoinearAerolineas(float bitcoin,float precioAerolineas);

/// @fn float bitcoinearAerolineas(float, float)
/// @brief Se encarga de calcular precio del vuelo con bitcoins en Aerolineas.
/// @param precioAerolineas
/// @param bitcoin
/// @return el precio del vuelo en bitcoin

float bitcoinearLatam(float bitcoin, float precioLatam);

/// @fn float bitcoinearLatam(float, float)
/// @brief Se encarga de calcular precio del vuelo con bitcoins en Latam.
/// @param precioLatam
/// @param bitcoin
/// @return el precio del vuelo en bitcoin

float unitarearAerolineas(float precioAerolineas, float km);

/// @fn float unitarearAerolineas(float, float)
/// @brief Se encarga de calcular precio del vuelo unitario de Aerolineas.
/// @param precioAerolineas
/// @param km
/// @return el precio del vuelo unitario

float unitarearLatam(float precioLatam, float km);

/// @fn float unitarearAerolineas(float, float)
/// @brief Se encarga de calcular precio del vuelo unitario de Latam.
/// @param precioLatam
/// @param km
/// @return el precio del vuelo unitario

float diferenciar(float precioAerolineas, float precioLatam);

/// @fn float diferenciar(float, float)
/// @brief Se encarga de calcular la diferencia entre dos precios y devuelve el valor.
/// @param precioAerolineas
/// @param precioLatam
/// @return la diferencia entre los dos numeros


#endif /* CALCULOS_H_ */
