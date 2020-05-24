/**
* @file nodo_listaMontones.h
* @brief Cabecera, nodo_listaMontones (Clase que representa una celda de una listaMontones, cada celda contiene un mont�n que es una lista de n�meros)
*/

#ifndef NODO_LISTAMONTONES_H_
#define NODO_LISTAMONTONES_H_
#include "lista.h"

using namespace std;


/** @brief Representa la celda de una lista, listaMontones[Lista], una lista en la que cada celda contiene una lista de n�meros.
*
*	Es una celda de una lista, cada celda contiene un puntero de la clase nodo_listaMontones que apunta a la siguiente celda y un
*	atributo, 'monton', objeto de la clase Lista, que almacena la lista de n�meros naturales que contiene esa celda.
*	@see lista
*	@see listaMontones
**/
class nodo_listaMontones
{
	/**@var monton
	*@brief Es un objeto de la clase Lista que almacena la lista de n�meros que representan un mont�n del juego.
	*@var pSiguiente
	*@brief Puntero de la clase nodo_listaMontones que a la siguiente celda de la lista que es otro objeto nodo_listaMontones*/

   friend class listaMontones;
  //para que pueda acceder a sus atributos, la clase listaMontones.
      //atributos
             private:
			
				Lista monton;
				nodo_listaMontones* pSiguiente; //puntero al siguiente de la clase nodo_lista.
               
             public:
				
				nodo_listaMontones();//Constructor de la clase
				
				~nodo_listaMontones();//Destructor de la clase
};
#endif
