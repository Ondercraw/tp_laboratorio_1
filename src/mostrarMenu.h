/*
 * mostrarMenu.h
 *
 *  Created on: 12 abr. 2022
 *      Author: ungim
 */

#ifndef MOSTRARMENU_H_
#define MOSTRARMENU_H_

int mostrarMenu(int opcionIngresada);

/// @fn float mostrarMenu(int)
/// @brief Se encarga de mostrar el menu de opciones.
/// @param opcionIngresada
/// @return la opcion ingresada del menu

float mostrarResultados(float km, float precioAerolineas, float precioLatam, float descuentoA, float interesA, float precioConBitcoinA, float precioUnitarioA, float descuentoL, float interesL, float precioConBitcoinL, float precioUnitarioL, float diferencia);

/// @fn float mostrarResultados(float , float , float , float , float , float , float , float , float , float , float , float)
/// @brief Se encarga de mostrar los resultados de todos los calculos.
/// @param km
/// @param precioAerolineas
/// @param precioLatam
/// @param descuentoA
/// @param interesA
/// @param precioConBitcoinA
/// @param precioUnitarioA
/// @param descuentoL
/// @param interesL
/// @param precioConBitcoinL
/// @param precioUnitarioL
/// @param diferencia
/// @return todos los precios ya calculados



#endif /* MOSTRARMENU_H_ */
