/**
* @file lista.h
* @brief Cabecera. Clase Lista (Clase que representa la estructura lineal para almacenar los n�meros de los montones y de la cinta)
*/

#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "nodo_lista.h"
using namespace std;

/** @brief Sirve para la representaci�n de montones y de la cinta num�rica. Lista[naturales] mediante celdas doblemente enlazadas.
*
*   La implementaci�n usada es la de celdas doblemente enlazadas:
*   El tipo lista son dos punteros, uno de ellos apuntando a la primera celda y el otro a la �ltima, y un n�mero natural que almacena su longitud.
*   Cada celda es representada por la clase nodo_Lista y contiene un n�mero natural y dos punteros, apuntando uno a la siguiente celda y el 
*   otro a la anterior celda.
*   Si la lista est� vac�a, los dos punteros de la lista apuntan a NULL, y la longitud de la lista ser� igual a cero.
*
*   Si la lista tiene una sola celda, uno de sus punteros apunta a la celda, primera, y el otro puntero apunta a NULL.
*   Los punteros de la celda, es decir del nodo_Lista, apuntar�n a NULL.
* 
*	Si la lista contiene m�s de una celda, uno de sus punteros apuntar� a la primera celda y el otro, a la �ltima celda de la lista,
*	Uno de los punteros de cada celda apuntara a la celda anterior y el otro a la siguiente celda. Para la celda �ltima uno de sus
*   punteros, (siguiente), contiene el valor NULL y para la primera celda uno de sus punteros, (anterior), contiene el valor NULL */ 

class Lista
{
	
     /**@var longitud
     *@brief Almacena un n�mero natural con el n�mero de nodos de la lista, cantidad de n�meros en un mont�n.
     *@var primero
     *@brief Puntero al primer nodo de la lista de la clase nodo_Lista
     *@var ultimo
     *@brief Puntero al �ltimo nodo de la lista de la clase nodo_Lista*/
    
     private:
          
	       short longitud;//n�mero de nodos  
           nodo_Lista* primero;//nodo al primer nodo de la lista
	       nodo_Lista* ultimo;//nodo al �ltimo de la lista
        
           
     //M�todos p�blicos
     public:
            //CONSTRUCTORAS
            Lista(); //Constructor de la lista crear una lista vacia.
            ~Lista();//Destructor, elimina celdas y punteros.
            void anadir_izq(short elemento); //a�adir un elemento por la izquierda
            void anadir_der(short elemento); //a�adir un elemento por la derecha.
            void llenarLista(short n);//llena una lista con 'n' celdas a�adiendolas por la izquierda.
           
            //OBSERVADORAS
            int inicial();//Devuelve el n�mero natural almacenado en el primer nodo de la lista.
            short final();//Devuelve el n�mero natural almacenado en el �ltimo nodo de la lista.
            short Longitud();//Devuelve la longitud de la lista
            bool es_lista_vacia();//Comprueba si la lista est� vac�a.
            void imprimir();//Imprime por pantalla los n�meros n�turales que hay en cada nodo de la lista.
            void imprimirResto();//Imprime por pantalla los n�meros n�turales que hay en cada nodo de la lista menos el primer nodo.
            short cogerElemento(short posicion);//Devuelve el valor de un lemento que se encuentra en una posici�n de la lista
            
            //MODIFICADORAS
            void resto();//Elimina el primer nodo de la lista.
            void eult();//Elimina el �ltimo nodo de la lista.
           
};

#endif
