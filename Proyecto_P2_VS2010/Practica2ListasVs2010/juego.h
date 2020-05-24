/**
* @file juego.h
* @brief Cabecera, juego (métodos estáticos, para el funcionamiento del juego)
*/


#ifndef JUEGO_H_
#define JUEGO_H_
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <windows.h>


using namespace std;
 
/** @brief Clase que proporciona métodos estáticos, para el funcionamiento del juego.
*
*	Proporciona los métodos necesarios para obtener un numero aleatorio entre 1 y n
*	generar una operación aleatoriamente, y operar para obtener un resultado.
*
**/ 
class Juego {
	
public:
	
static void iniciarSemilla();//Método para iniciar, la generación del número aleatorio, mediante la hora del sistema
static short obtenerNumero();//obtiene un número aleatorio entre 1 y 9 para insertar en los montones y cinta numérica
static short obtenerNumeroHasta(short n);//obtiene un número aleatorio entre 1 y n para limitar el número de elementos con el que se inician los montones
static char obtenerOperacion();//obtiene el caracter de la operación
static short obtenerResultado(char operacion, short numeroCinta, short cimaMonton);//realiza una operación matematica con los parametros pasados y devuelve un resultado.

};

#endif
