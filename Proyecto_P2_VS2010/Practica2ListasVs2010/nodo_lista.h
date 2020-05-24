/**
* @file nodo_lista.h
* @brief Cabecera de la clase nodo_Lista. Nodo de una lista, alamacena un elemento de la lista.
* 
*/

#ifndef NODO_LISTA_H_
#define NODO_LISTA_H_

using namespace std;


/** @brief Representa la celda de una lista, del tipo Lista[naturales], una lista en la que cada celda contiene una número natural.
*
*	Es una celda de una lista, cada celda contiene un puntero de la clase nodo_lista que apunta a la siguiente celda y un
*	atributo, 'valor', que almacena un número natural.
*	@see Lista
*
**/
class nodo_Lista
{

	/**@var valor
	*@brief Un número natural, de los que componen los montones con los que jugaremos.
	*@var pSiguiente
	*@brief Puntero de la clase nodo_lista que apunta a la siguiente celda de la lista, otro objeto nodo_lista
	*@var pAnterior
	*@brief Puntero de la clase nodo_lista que apunta a la anterior celda de la lista, otro objeto nodo_lista*/

   friend class Lista;
  //para que pueda acceder a sus atributos, la clase lista.
      //atributos
             private:
				short valor; //Contiene valor.
				nodo_Lista* pSiguiente; //puntero al siguiente de la clase nodo_lista.
				nodo_Lista* pAnterior; //puntero al anterior de la clase nodo_lista.
             public:
				nodo_Lista();//Constructor un lista vacía
				~nodo_Lista();//destructor de la clase
};
#endif
