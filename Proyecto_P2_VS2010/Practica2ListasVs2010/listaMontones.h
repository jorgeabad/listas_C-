/**
* @file listaMontones.h
* @brief Cabecera. listaMontones (Clase que representa la estructura lineal para almacenar las listas de n�meros, montones del juego)
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
*   Mediante esta estructura almacenamos los montones, listas de n�meros, cada celda de la lista de montones,
*   contiene una lista de n�meros naturales y un puntero a la siguiente celda.
*
*   La implementaci�n usada es la de celdas enlazadas:
*
*   El tipo Lista es un puntero, que apunta a la primera celda y un n�mero natural que almacena la longitud de la lista.
*   Cada celda es representada por la clase nodo_listaMontones que contiene un objeto de la clase Lista y un puntero a la siguiente celda. 
*
*   - Si la lista est� vac�a, el puntero apunta a NULL, y la longitud de la lista ser� igual a cero.
*	- Si la lista contiene celdas, su puntero apuntar� a la primera celda que contiene el primer mont�n.
*	- El puntero de cada celda, apunta a la siguiente celda. El puntero de la �ltima celda contiene el valor NULL */
class listaMontones
{
	 /**@var longitud
     *@brief Almacena un n�mero natural con el n�mero de nodos de la lista, cantidad de n�meros en un mont�n.
     *@var primero
     *@brief Puntero al primer nodo de la lista de la clase nodo_listaMontones*/
     
	 //Atributos privados
     private:
	       int longitud; //Almacena el n�mero de celdas que contiene la lista, cantidad de montones.
	       nodo_listaMontones* primero; //puntero al primer nodo de la lista de montones.
	      
	       
     //M�todos publicos
     public:
            //CONSTRUCTORAS
            listaMontones(); //Constructor de la lista crear una lista vacia.
            ~listaMontones();//Destructor elimina, cada nodo de la lista y su puntero.
			void crear_lista(short numero_de_montones, short elementos_monton);
			//Crea una lista con con un n�mero determinado de montones y con un n�mero determinado de elementos por mont�n
			
            //OBSERVADORAS
            short Longitud();//Devuelve la longitud de la lista
            bool es_lista_vacia();//Comprueba si la lista tiene montones.
            bool comprobar_posicion (short posicionMonton);//Comprueba si una posici�n se encuentra en la lista
            void imprimir();//Muestra por pantalla la lista, con los montones.
            bool comprueba_Monton_vacio(short posicionMonton);//Comprueba si la lista/mont�n de una determinada posici�n est� vacia.
            bool comprueba_todos_vacios();//Comprueba si todas los montoenes est�n vac�os.
            short buscar_cima_monton(short posicionMonton);//Devuelve el �ltimo elemento del mont�n que se encuentra en la posci�n dada.
            short longitud_del_monton(short posicionMonton);//Devuelve la longitud de un mont�n que se encuentra en una posci�n dada.
           
		    //MODIFICADORAS
            void menter_en_monton(short posicionMonton,short numero);//A�ade por la derecha un n�mero natural, 'numero', en el mont�n de la posici�n 'posicionMonton'
            void sacar_de_monton(short posicionMonton);//Elimina el �ltimo n�mero del monton que se encuentra en la posici�n 'posicionMonton'
            void resto();//Elimina el primer nodo de la listaMontones.

};

#endif
