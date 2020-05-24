/**
* @file nodo_listaMontones.cpp
* @brief Implementa, nodo_listaMontones (Clase que representa una celda de una listaMontones, cada celda contiene un montón que es una lista de números)
*/
#include "nodo_listaMontones.h"



/** @brief Constructor para crear una celda vacía sin lista asociada, ni nodos adyacentes.
*
*   No hay lista, monton por defecto es vacío, y su puntero no apunta a ninguna celda. 
*
**/
nodo_listaMontones::nodo_listaMontones(){
            pSiguiente=NULL;
                     }




/** @brief Destructor de la clase nodo_listaMontones.
*
*   Eliminamos el puntero asociado.
*
**/
nodo_listaMontones::~nodo_listaMontones(){
	cout << "\n  Destructor clase nodo_listaMontones: \n";
	delete (pSiguiente);
}




