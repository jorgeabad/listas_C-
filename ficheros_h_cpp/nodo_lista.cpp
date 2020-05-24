/**
* @file nodo_lista.cpp
* @brief Implementación de la clase nodo_Lista. Nodo de una Lista, alamacena un elemento de la lista.
*
*/



#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nodo_lista.h"


/** @brief Constructor para crear una celda unitaria con un número que toma valor 0, y sin nodos adyacentes.
*
*   Solo hay un nodo en el que almacenamos un cero, no valido para el juego, sus punteros no apuntan a ninguna celda.
*
**/
nodo_Lista::nodo_Lista(){
            valor=0;//toma valor cero
            pSiguiente=NULL;//puntero a la siguiente celda
            pAnterior=NULL;//puntero a la celda anterior
                  
                     }



/** @brief Destructor de la clase nodo_lista.
*
*   Eliminamos sus punteros asociados, a la siguiente y ala anterior celda
*
**/
nodo_Lista::~nodo_Lista(){
	cout<<"      Destructor nodo_lista: \n";
	delete(pSiguiente);
	delete(pAnterior);
}
