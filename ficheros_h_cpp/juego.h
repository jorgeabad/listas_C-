/**
* @file juego.h
* @brief Cabecera, juego (m�todos est�ticos, para el funcionamiento del juego)
*/


#ifndef JUEGO_H_
#define JUEGO_H_
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <windows.h>


using namespace std;
 
/** @brief Clase que proporciona m�todos est�ticos, para el funcionamiento del juego.
*
*	Proporciona los m�todos necesarios para obtener un numero aleatorio entre 1 y n
*	generar una operaci�n aleatoriamente, y operar para obtener un resultado.
*
**/ 
class Juego {
	
public:
	
static void iniciarSemilla();//M�todo para iniciar, la generaci�n del n�mero aleatorio, mediante la hora del sistema
static short obtenerNumero();//obtiene un n�mero aleatorio entre 1 y 9 para insertar en los montones y cinta num�rica
static short obtenerNumeroHasta(short n);//obtiene un n�mero aleatorio entre 1 y n para limitar el n�mero de elementos con el que se inician los montones
static char obtenerOperacion();//obtiene el caracter de la operaci�n
static short obtenerResultado(char operacion, short numeroCinta, short cimaMonton);//realiza una operaci�n matematica con los parametros pasados y devuelve un resultado.

};

#endif
