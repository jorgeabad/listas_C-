/**
* @file lista.cpp
* @brief Implementa la Clase Lista . (Clase que representa la estructura lineal para almacenar los números de los montones y de la cinta)
*/


#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"
#include "nodo_lista.h"
#include "juego.h"

/****************************************** CONSTRUCTORAS ****************************************************************/

/** @brief Constructor para crear una lista vacía.
*
*   No hay ningún nodo_Lista creado, no hay celdas en la lista, el puntero
*	primero y ultimo toman valor Null, y la longitud es cero. No hay ningún elemento en la lista.
*
**/
Lista::Lista(){
            longitud=0;//no tiene nodos
            primero=NULL;//no apunta a ningún nodo
            ultimo=NULL;//no apunta a ningún nodo
            
}

/** @brief Destructor de la clase lista
*
*   Elimina todas las celdas de la lista, eliminando iterativamente el primer nodo, mediante la función resto(),
*   hasta que la lista está vacía, una vez eliminados los nodos se eliminan los punteros de la lista primero y ultimo.
*   @see resto()
*
**/
Lista::~Lista(){
		cout<<"\n     Destructor clase lista:";//Mostramos una aviso para comprobar que el destructor es llamado.
        while(!es_lista_vacia()){//mientras la lista no esté vacía
            cout<<"\n     ";imprimir();//mostramos como va quedando el contenido de la lista
            resto();//eliminamos el primer nodo
            
            }
        
        delete(primero);//eliminamos el puntero.
        delete(ultimo);//eliminamos el puntero, ya no hay lista.
       
        
        }

/** @brief Llena la lista, con un número aleatorio de objetos nodo_Lista, dentro de un rango determinado. Llena inicialmente los montones.
*   
*   Añade por la izquierda, de forma iterativa, objetos de la clase nodo_Lista, hasta llegar a un número de elementos determinado.
*   Para hallar la cantidad de elementos que ha de tener la lista, 'elementosMonton', usamos la función Juego::obtenerNumeroHasta(short n)
*   de la clase Juego, que nos devuelve un número entero aleatorio entre 1 y n, donde 'n' toma el valor del resultado de la operación: (maxElementos-2), 
*   es decir, la cantidad máxima de elementos que pueden tener los montones menos dos.
*
*   Por último se llama a la función anadir_izq(short n), iterativamente, tantas veces como indique el valor 'elementosMonton', para cada iteración 
*   'n' toma el valor pasado por la función Juego::obtenerNumero() que devuelve un número entre 1 y 9, para que dicho número se añada por la izquierda a la lista.
*
*	@see anadir_izq(short n)
*  
*	@param maxElementos Número máximo de elementos que pueden alcanzar los montones, determinará el número de elementos inicial de cada montón al restarle dos y pasar ese valor a la función Juego::obtenerNumeroHasta(short n).
**/
void Lista::llenarLista(short maxElementos){
	short numElementos=maxElementos-2;//almacenamos el número máximo de elementos que puede tener la lista al principio
	short elementosMonton=Juego::obtenerNumeroHasta(numElementos);//obtenemos el número de elementos que tendrá la lista (entre 1 y numElementos)
	while(!elementosMonton==0){//repetimos tantas veces
		elementosMonton=elementosMonton-1;//vamos descontando uno de la cantidad total de elementos
		anadir_izq(Juego::obtenerNumero());//para cada iteración añadimos un nuevo número a la lista
	}
}

/** @brief Añade por la izquierda un objeto de la clase nodo_Lista.  
*   
*   Añade por la izquierda un nuevo objeto de la clase nodo_Lista en la lista, asignando al atributo 'valor', el número dado por 'elemento' que 
*   recoge la función, se incrementa en 1 el atributo 'longitud' y se asignana los punteros dependiendo de si la lista esta vacía o no.
*	
*	@param elemento Número natural a añadir a la lista.
**/
void Lista::anadir_izq(short elemento) 
{
     
     nodo_Lista*p=new nodo_Lista();//Nuevo nodo_lista
     p->valor=elemento;//Se asigna el atributo valor que es igual que el valor elemento que se pasa a la funcion.
     p->pSiguiente=primero;//El puntero siguiente, del nuevo nodo, apunta al primer elemento de la lista.
     p->pAnterior=NULL;//El puntero anterior, del nuevo nodo, apunta a nulo
     
     if(es_lista_vacia()){//Si la lista está vacía
     	primero=p;//el primero será p
     	ultimo=p;//En este caso NULL
     }else{//Si la lista no está vacía
     	primero->pAnterior=p;//Se asigna el puntero anterior del primer nodo de la lista al nuevo nodo
     	primero=p;//A continuacion el puntero primero de la lista apunta al nodo nuevo
     }
    
     longitud=longitud+1;//aumentamos la longitud de la lista en uno, un nuevo nodo ha sido añadido.          
     
                          
}

/** @brief Añade por la derecha un objeto de la clase nodo_Lista.  
*   
*   Añade por la derecha un nuevo objeto de la clase nodo_Lista en la lista, asignando al atributo 'valor' el número dado por 'elemento' que 
*   recoge la función, se icrementa en 1 el atributo longitud y se asignana los punteros dependiendo de si la lista esta vacía o no.
*
*	@param elemento Número natural a añadir a la lista.
**/
void Lista::anadir_der(short elemento) 
{
     
     nodo_Lista*p=new nodo_Lista();//Nuevo nodo_Lista
     
     p->valor=elemento;//Se asigna el atributo valor que es igual que el valor elemento que se pasa a la funcion.
     p->pSiguiente=NULL;//El puntero siguiente, del nuevo nodo, apunta a nulo
     p->pAnterior=ultimo;//El puntero anterior, del nuevo nodo, es igual a ultimo
     if (es_lista_vacia()){//Si la lista está vacía
     primero=p;//el primero será p
     ultimo=p; //En este caso NULL
     }else{//Si la lista no está vacía
           ultimo->pSiguiente=p;//Se asigna el puntero siguiente del ultimo nodo de la lista al nuevo nodo
           ultimo=p;//A continuacion el puntero ultimo de la lista apunta al nodo nuevo
           }
     longitud=longitud+1;//aumentamos la longitud de la lista en uno, un nuevo nodo ha sido añadido.
     
     }




//******************OBSERVADORAS*************************************************

/** @brief Comprueba si la lista, está vacía. Si hay objetos nodo_Lista, en la lista.
*
*   Comprueba si el atributo longitud es igual a 0
*	si es igual a 0 devuelve true en caso contrario devuelve false.
*
*	@retval true la lista está vacía.
*	@retval false la lista tiene celdas, no está vacía.
**/
bool Lista::es_lista_vacia() //Devuelve true si está vacía, false en caso else
{
     
      return (longitud==0);
         
}

/** @brief Muestra el primer elemento de la lista.
*
*   Muestra el valor del atributo 'valor' del nodo_Lista al que apunta el puntero 'primero' de la lista. 
*
*	@retval e Número natural que se encuentra en el primer nodo de la lista
**/
int Lista::inicial() //Muestra el primer elemento de la lista.prim
{
	short e=0;
	try{
		
		if (es_lista_vacia()){ //Si está vacía devuelve el mensaje de lista vacía.

			throw invalid_argument("lista vacía");

		}

		else/*Si está llena devuelve el atributo valor del nodo al que apunta
			el puntero primero de la lista*/
		{
			e=primero->valor;	

		}//felse
		return e;
		}//fif
	catch(invalid_argument){
		cout << "La lista está vacía";
		return e;
	}
	       
}//fvoid




/** @brief Muestra el último elemento de la lista.
*
*   Muestra el valor de atributo 'valor' del nodo al que apunta el puntero 'ultimo' de la lista. 
*
*  @retval e Número natural con el valor del último elemento de la lista
**/
short Lista::final()
{
	short e=0;
	try{

		if (es_lista_vacia()){ //Si está vacía devuelve el mensaje de lista vacía.

			throw(es_lista_vacia());

		}

		else/*Si está llena devuelve el atributo valor del nodo al que apunta
			el puntero ultimo de la lista*/
		{
			e = ultimo->valor;

		}//felse

	}//fif
	catch (bool){
		cout << "La lista está vacía";

	}
	return e;         
                      
}//ffun



/** @brief Función para acceder a la longitud de la lista, cantidad de nodos que hay en la lista.
*
*	@retval n Un número natural que representa la cantidad de elementos que hay en la lista.
**/
short Lista::Longitud(){
    short n=longitud;
    return n;
}


//********************* MODIFICADORAS ****************************

/** @brief Elimina el primer nodo de la lista, primera celda, dejando el resto de la lista.
*
*   Un puntero auxiliar de la clase nodo_Lista toma el valor de 'primero', luego la función actualiza el puntero 'primero' pasando a apuntar al siguiente elemento de la lista, 
*   segundo, este elemento pasa a ser el primero de la lista y como tal su puntero a la anterior celda, 'pAnterior' apuntara a 'NULL', después liberamos el puntero auxiliar borrando así el 
*   que antes era el primer nodo.
* 
**/

void Lista::resto(){
nodo_Lista*aux=new nodo_Lista();//var p: puntero a nodo_Lista
if (es_lista_vacia()){//si es_lista_vacia(l) entonces
cout<<"error lista vacía";//error(Lista vacia)
}else{//si no
aux=primero;//aux pasa a ser el primero
primero=aux->pSiguiente;//el puntero 'primero' de la lista pasa a apuntar al siguiente, segundo.
if(primero==NULL){//si el 'primero' es NULL la lista ya está vacía y 'ultimo' también será NULL
	ultimo=NULL;
}else{
	primero->pAnterior=NULL;//Antes del primero no hay elementos
}

aux->pSiguiente=NULL;//por seguridad rompemos enlace
delete(aux);//liberar(p)
longitud=longitud-1;//incrementamos en uno la longitud.
}//fsi
}//fproc


/** @brief Elimina el último nodo de la lista, última celda de la lista.
*
*   Un puntero auxiliar de la clase nodo_Lista toma el valor de 'ultimo' luego la función actualiza el puntero 'ultimo' pasando a apuntar al anterior elemento de la lista, 
*   penúltimo, este elemento pasa a ser el último de la lista y como tal su puntero a la siguiente celda, 'pSiguiente' apuntara a 'NULL', después liberamos el puntero auxiliar borrando así el 
*   que antes era el último nodo.
* 
**/
void Lista::eult(){

nodo_Lista*aux=new nodo_Lista();//var p, aux: puntero a nodo-lista
if (es_lista_vacia()){//si es_lista_vacia(l) entonces
cout<<"error lista vacía";//error(Lista vacia)
}else{//si hay elementos
aux=ultimo;//aux toma el valor de 'ultimo'
ultimo=ultimo->pAnterior;//el puntero 'ultimo' ahora apunta al anterior nodo pasando a ser el último de la lista
if (ultimo==NULL){//si solo hay un elemento en la lista, (pAnterior apuntaba a null)
primero=NULL;//el puntero primero toma valor null ya no hay elementos
}else{//En caso contrario mas de un elemento
	ultimo->pSiguiente=NULL;//Como es el último elemento el puntero a la siguiente celda sera null
}
aux->pAnterior=NULL;//rompemos el enlace con el resto de la lista
delete(aux);//liberar(aux)
longitud=longitud-1;//incrementamos en uno la longitud


}//fsi

}//fproc

/** @brief Imprime en orden todos los elementos de la lista.
*
*   La función imprime todos los elementos de la lista y si está vacia muestra un mensaje. Mediante un puntero auxiliar de la clase nodo_Lista
*	recorremos la lista desde el primero al último elemento, mostrando por pantalla para cada nodo el valor contenido en el atributo 'valor', 
*	al final se muestra por pantalla también el número de elementos que tiene la lista.
* 
**/
void Lista::imprimir(){
nodo_Lista*p=new nodo_Lista();//puntero a nodo_lista para recorrer la lista

if (es_lista_vacia()){//si es_lista_vacia(l) 
cout<<" Montón vacío, !!!!!";//entonces error(Lista vacia)
}else{//si no
p=primero;//p toma el valor del puntero 'primero'
while (p!=NULL){//mientras (p diferente nil) hacer 
cout<<p->valor<<", ";//Mostramos el número almacenado en 'valor' para ese nodo, y una coma.
p=p->pSiguiente;// p pasa a apuntar a la siguiente celda avanzamos
}//fmientras

cout<<"   (E="<<Longitud()<<")";//mostramos la cantidad de elementos que hay en la lista
delete(p);//ya llegamos al final y vale null
}
}//ffun


/** @brief Muestra un elemento que esta en una posición concreta de la lista.
*
*   La función recorre la lista hasta que alcanza la posición deseada, devolviendo el valor del número
*	almacenado en ese nodo, atributo 'valor'.
*	
*	@param posicion Número natural, que indica la posición de la celda, nodo del cual queremos obtener el valor.
*	@retval natural El número que se encuentra alamacenado en el nodo que ocupa la posición pedida 'posicion'.
**/
short Lista::cogerElemento(short posicion){

	nodo_Lista*p = new nodo_Lista();//var p: puntero a nodo_lista;
	short pos;//para almacenar la posición según avanzamos
	if (posicion!=0||!(posicion>longitud)){//comprobamos que este dentro rango (1 a longitud) posición válida
		p = primero;//el puntero toma el valor del primero
		pos = 1;//la posición empieza en uno.
		
		while (pos<posicion){//mientras no llegemos a la posición deseada
			pos = pos + 1;//avanzamos una posición
			p = p->pSiguiente;//avanzamos al siguiente nodo, pasa a apuntar al siguiente
		}//fmientras
		
	}
	return p->valor;//devolvemos valor si la lista está o no vacía.

}//fproc


/** @brief Imprime en orden todos los elementos de la lista menos el primero. Usado para imprimir el resto de la cinta numérica.
*
*   La función imprime todos los elementos de la lista menos el primero. Mediante un puntero de la clase nodo_Lista
*	recorremos la lista desde el primero al último elemento, mostrando por pantalla para cada nodo, menos para el primero, el valor contenido
*	en el atributo 'valor', al final se muestra por pantalla también el número de elementos que tiene la lista.
* 
**/
void Lista::imprimirResto(){
nodo_Lista*p=new nodo_Lista();//puntero a nodo-lista; 

if (es_lista_vacia()){//si es_lista_vacia(l) 
cout<<" no hay datos error lista vacia";//entonces error(Lista vacia)
}else{//si no
p=primero->pSiguiente;//empezamos a imprimir desde el segundo nodo.
while (p!=NULL){//mientras (p diferente nil) hacer
cout<<p->valor<<", ";//mostramo valor del atributo 'valor' del nodo.
p=p->pSiguiente;//avanzamos, pasando a tomar el valor de la siguiente celda.
}//fmientras

cout<<"   (E="<<Longitud()<<")";// mostramos el número de lelementos que tiene la lista.
delete(p);//ahora vale null y lo eliminamos.
}
}//ffun
