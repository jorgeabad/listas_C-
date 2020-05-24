/**
* @file listaMontones.h
* @brief Cabecera. listaMontones (Clase que representa la estructura lineal para almacenar las listas de números, montones del juego)
*/

#ifndef LISTAMONTONES_H_
#define LISTAMONTONES_H_
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "nodo_listaMontones.h"
#include "lista.h"
using namespace std;

/** @brief Estructura para almacenar los montones del juego. Almacena objetos de la clase Lista: listaMontones[Lista].
*
*   Mediante esta estructura almacenamos los montones, listas de números, cada celda de la lista de montones,
*   contiene una lista de números naturales y un puntero a la siguiente celda.
*
*   La implementación usada es la de celdas enlazadas:
*
*   El tipo Lista es un puntero, que apunta a la primera celda y un número natural que almacena la longitud de la lista.
*   Cada celda es representada por la clase nodo_listaMontones que contiene un objeto de la clase Lista y un puntero a la siguiente celda. 
*
*   - Si la lista está vacía, el puntero apunta a NULL, y la longitud de la lista será igual a cero.
*	- Si la lista contiene celdas, su puntero apuntará a la primera celda que contiene el primer montón.
*	- El puntero de cada celda, apunta a la siguiente celda. El puntero de la última celda contiene el valor NULL */
class listaMontones
{
	 /**@var longitud
     *@brief Almacena un número natural con el número de nodos de la lista, cantidad de números en un montón.
     *@var primero
     *@brief Puntero al primer nodo de la lista de la clase nodo_listaMontones*/
     
	 //Atributos privados
     private:
	       int longitud; //Almacena el número de celdas que contiene la lista, cantidad de montones.
	       nodo_listaMontones* primero; //puntero al primer nodo de la lista de montones.
	      
	       
     //Métodos publicos
     public:
            //CONSTRUCTORAS
            listaMontones(); //Constructor de la lista crear una lista vacia.
            ~listaMontones();//Destructor elimina, cada nodo de la lista y su puntero.
			void crear_lista(short numero_de_montones, short elementos_monton);
			//Crea una lista con con un número determinado de montones y con un número determinado de elementos por montón
			
            //OBSERVADORAS
            short Longitud();//Devuelve la longitud de la lista
            bool es_lista_vacia();//Comprueba si la lista tiene montones.
            bool comprobar_posicion (short posicionMonton);//Comprueba si una posición se encuentra en la lista
            void imprimir();//Muestra por pantalla la lista, con los montones.
            bool comprueba_Monton_vacio(short posicionMonton);//Comprueba si la lista/montón de una determinada posición está vacia.
            bool comprueba_todos_vacios();//Comprueba si todas los montoenes están vacíos.
            short buscar_cima_monton(short posicionMonton);//Devuelve el último elemento del montón que se encuentra en la posción dada.
            short longitud_del_monton(short posicionMonton);//Devuelve la longitud de un montón que se encuentra en una posción dada.
           
		    //MODIFICADORAS
            void menter_en_monton(short posicionMonton,short numero);//Añade por la derecha un número natural, 'numero', en el montón de la posición 'posicionMonton'
            void sacar_de_monton(short posicionMonton);//Elimina el último número del monton que se encuentra en la posición 'posicionMonton'
            void resto();//Elimina el primer nodo de la listaMontones.

};

#endif
