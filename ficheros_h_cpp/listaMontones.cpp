/**
* @file listaMontones.cpp
* @brief Implementa, listaMontones (Clase que representa la estructura lineal para almacenar las listas de n�meros, montones del juego)
*/


#include <iostream>
#include <string>
#include <stdexcept>      // std::invalid_argument
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaMontones.h"
#include "lista.h"
#include "nodo_listaMontones.h"

/****************************************** CONSTRUCTORAS ****************************************************************/

/** @brief Constructor para crear una listaMontones vac�a.
*
*   No hay ning�n nodo_listaMontones creado, no hay celdas en la lista, el puntero
*	primero toma valor Null, y la longitud es cero. No hay ning�n mont�n.
*
**/
listaMontones::listaMontones(){
            longitud=0;//no tiene nodos
            primero=NULL;//no apunta a ning�n nodo
}








/** @brief Destructor de la clase listaMontones
*
*   Elimina todas las celdas de la listaMontones, eliminando iterativamente el primer nodo, mediante la funci�n resto(),
*   hasta que la lista est� vac�a, una vez eliminados los nodos se elimina el puntero de la lista 'primero'.
*   @see resto()
*
**/
listaMontones::~listaMontones(){
		cout<<"\nDestructor clase listaMontones, elimina listado de montones: \n";
        while(!es_lista_vacia()){//mientras la lista no est� vac�a
        	resto();//eliminamos el primer nodo
            }
            delete(primero);//eliminamos el puntero lista, ya no hay lista.
       
			_getche();
        }
        
        
        
        
        
        
        
/** @brief A�ade por la izquierda, iterativamente, un determinado n�mero de montones de un tama�o determinado.  
*   
*   A�ade por la izquierda, de forma iterativa, un nuevo objeto de la clase nodo_listaMontones, hasta llegar al n�mero de montones determinado
*   por el valor de la variable numero_de_montones. Al atributo "monton" de la clase Lista, que pertenece al nuevo objeto, nodo_listaMontones , 
*   se le a�ade una serie de n�meros naturales mediante la funci�n llenarLista(short n) de la clase Lista, la cantidad de n�meros que tiene 
*   el mont�n parte del valor pasado en la variable elementos_monton y que es pasada a la funci�n llenarLista(short n).
*	@see Lista.llenarLista(short n)
*   
*	@param numero_de_montones N�mero de montones, cantidad de listas a a�adir a la lista de Montones.
*	@param elementos_monton N�mero m�ximo de elementos que pueden tener los montones, determinar� el n�mero de elementos inicial de cada mont�n.
**/
void listaMontones::crear_lista(short numero_de_montones, short elementos_monton){
	
	/**
	*Variables:
	**/
	/**- n: almacena el n�mero de montones que ser�n a�adidos a la lista*/
short n;//variable para almacenar el n�mero de montones 
n=numero_de_montones;//asignamos la cantidad de montones a crear.
 while (n>0){//Mientras sea mayor a cero, el n�mero de montones a crear.
           
  nodo_listaMontones*p=new nodo_listaMontones();//Nuevo nodo_listaMontones atributo'monton' lista vac�a, pSiguiente=NULL
  p->monton.llenarLista(elementos_monton);//Llenamos la lista, el 'monton', del nuevo nodo con una cantidad determinada de n�meros naturales.
  p->pSiguiente=primero;//El puntero, del nuevo nodo, apunta al primer elemento de la lista, enlazamos con la lista.
  primero=p;//El puntero de lista, primero, apunta al nuevo nodo que pasa a ser as� el primero de la lista.      
      
  longitud=longitud+1;//aumentamos la longitud de la lista en uno, un nuevo nodo ha sido a�adido.   
   n=n-1;//disminuimos en uno la cantidad de n�mero de montones a crear.
           
           }
     }




//****************************************** OBSERVADORAS *************************************************




/** @brief Comprueba si la listaMontones, est� vac�a.
*
*   Comprueba si el puntero, primero de la lista, clase nodo_listaMontones, apunta a un nodo o a null.(primero==NULL)
*	si es igual a null devuelve true en caso contrario devuelve false.
*
*	@retval true la listaMontones est� vac�a.
*	@retval false la listaMontones tiene celdas, no est� vac�a.
**/
bool listaMontones::es_lista_vacia() //Devuelve true si est� vac�a, false en caso else
{
     return (primero==NULL);//Si el puntero de la lista apunta null, es true, lista vacia.
}







/** @brief Funci�n para acceder a la longitud de la lista, cantidad de nodos que hay en la lista.
*
*	@retval longitud Un n�mero natural que representa la cantidad de montones que hay en la lista.
**/
short listaMontones::Longitud(){
    return longitud;//Devolvemos el atributo longitud
}








/** @brief Funci�n que busca un mont�n en la lista de montones y devuelve el �ltimo elemento de su lista.
*
*	La funci�n busca la posici�n que ocupa un nodo_listaMontones, seg�n el valor de la variable numeroMonton
*	y una vez encontrado, devuelve el valor almacenado en la �ltima celda de su lista correspondiente, atributo monton, 
*	usando el m�todo final() de la clase Lista.
*	@see Lista.final()
*
*	@param numeroMonton Posici�n que ocupa el monton en la listaMontones, Posici�n del nodo_listaMontones.
*	@retval natural N�mero natural almacenado en el �ltimo elemento de la lista, que pertenece al mont�n buscado.
**/
short listaMontones::buscar_cima_monton(short numeroMonton) {
   
/**
	*Variables locales de la funci�n:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: contador de posiciones, se incrementa en uno seg�n avanzamos en la lista hasta llegar a la posici�n deseada*/
	

try{
	nodo_listaMontones*p = new nodo_listaMontones();//puntero a nodo_listaMontones;
	short pos;//almacena la posici�n seg�n avanzamos
	if (comprobar_posicion(numeroMonton)){//comprobamos que este dentro rango [1 a longitud]
		p = primero;//p toma el valor del primero de la lista
		pos = 1;//estamos en la posici�n 1

		while (pos<numeroMonton){//mientras no llegemos a la posici�n deseada
			pos = pos + 1;// avanzamos una posici�n
			p = p->pSiguiente;// avanzamos al siguiente nodo
		}//fmientras salimos con la posici�n deseada y el nodo que ocupa esa posici�n.

		
	}
	return p->monton.final();//devolvemos el valor del �ltimo elemento de la lista asociada al nodo buscado.
}
catch (invalid_argument){//capturamos excepci�n 
	cout << ("Error posicion inexistente-> ");

	return numeroMonton;//devolvemos el n�mero que ha sido pasado como erroneo.
}

 
}



/** @brief Funci�n que comprueba que una posici�n pasada es v�lida, si est� entre 1 y la longitud de la lista.
*
*	Cada nodo ocupa una posici�n en la listaMontones de 1 a la longitud de listaMontones, comprueba si la posici�n pedida est� en este rango
*
*	@param numeroMonton Posici�n que ocupa el mont�n en la listaMontones, posici�n a comprobar.
*	@retval true si es posici�n valida, si no lanza excepci�n.
**/
bool listaMontones::comprobar_posicion(short numeroMonton){

	
	if (numeroMonton == 0 || numeroMonton > longitud){//Si la posici�n pedida es igual a cero o superior a la longitud de la lista

		throw std::invalid_argument("Error posicion inexistente-> ");//lanzamos una excepci�n
	}
	else{//encaso contrario si es una posici�n correcta.
		return true;//devolvemos verdadero.
	}
}








/** @brief Funci�n que busca un mont�n en la lista de montones y devuelve la longitud de su lista, n�mero de elementos en el mont�n.
*
*	La funci�n, avanzando iterativamente, busca la posici�n que ocupa un nodo_listaMontones, seg�n el valor
*	de la variable 'numeroMonton' y una vez encontrado, devuelve la longitud correspondiente a su atributo 'monton', 
*	usando el m�todo Lista.Longitud() de la clase Lista.
*   @see Lista.Longitud()
*
*	- Usamos esta funci�n para ver si alg�n mont�n ha llegado al l�mite m�ximo de elementos que puede tener, juego perdido.
*
*	@param numeroMonton Posici�n que ocupa el monton en la listaMontones, Posici�n del nodo_listaMontones.
*	@retval N�mero natural que representa la cantidad de elementos que hay en la lista de ese monton.
**/
short listaMontones::longitud_del_monton(short numeroMonton){
	/**
	*Variables locales de la funci�n:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno seg�n avanzamos en la lista hasta llegar a la posici�n deseada*/

nodo_listaMontones*p=new nodo_listaMontones();//var p: puntero a nodo-lista;
try{
	int pos;//para lamacenar la posici�n seg�n avanzamos
	if (comprobar_posicion(numeroMonton)){//comprobamos que este dentro rango [1 a longitud]
		p = primero;//el puntero toma el valor del primero
		pos = 1;//partimos de la posici�n uno

		while (pos < numeroMonton){//mientras no llegemos a la posici�n deseada
			pos = pos + 1;//avanzamos una posici�n
			p = p->pSiguiente;//avanzamos al siguiente nodo, pasa a apuntar al siguiente
		}//fmientras
		
	}
	return p->monton.Longitud();//devolvemos la longitud de 'monton' objeto de la clase lista
}
catch (invalid_argument){//capturamos excepci�n posici�n fuera  de rango devolvemos la posici�n pasada.
	cout << "posici�n inexistente-> ";
	return numeroMonton;
}

}//fproc
 

	




/** @brief Comprueba si todos los montones almacenados en la lista est�n vacios, listas vacias.
*
*   Comprobamos iterativamente que cada nodo_listaMontones tenga su atributo 'monton' como una lista vac�a, para ello
*   usamos iterativamente la funci�n comprueba_Monton_vacio(short posicionMonton) pas�ndole la posici�n del mont�n hasta llegar
*   al final de la lista o hasta encontrar un mont�n que no este vac�o.
* 
*   - Usamos esta funci�n para ver si se ha ganado el juego. Todos los montones son lista vac�a.
*   
*	@retval true Todos los nodos de la listaMontones tienen su lista vac�a.
*	@retval false Alg�n mont�n de la listaMontones, tiene una lista que contiene alg�n elemento.
**/
bool listaMontones::comprueba_todos_vacios(){
	short l=1;//contador incremental para acceder a las posiciones a comprobar desde 1 hasta logitud de la lista +1
	while (l<(Longitud()+1)&&comprueba_Monton_vacio(l)){//Mientras no hallamos alcanzado la longitud y el monton este vac�o
		l=l+1;//incrementamos en uno para comprobar la siguiente posici�n
	}
	//Hemos recorrido todas las posiciones y hemos lacanzado la longitud o hemos encontrado alg�n monton con elementos y hemos salido.
	return (l==Longitud()+1);//Si todos los montones est�n vacios l ha de ser igual a la longitud+1, recorrimos todos
}
     




/** @brief Comprueba si un mont�n de una determinada posici�n est� vac�o.
*
*   La funci�n, avanzando iterativamente, busca la posici�n que ocupa un nodo_listaMontones, seg�n el valor
*	de la variable numeroMonton y una vez encontrado, devuelve un valor l�gico correspondiente al m�todo es_lista_vacia() 
*   de su atributo 'monton', de la clase Lista.
*   @see Lista.es_lista_vacia()
* 
*   - Usamos esta funci�n para solo mostrar las posiciones que est�n llenas cuando se ejecuta la elecci�n del mont�n mediante el dado.
*	y junto a la funci�n listaMontones.comprueba_todos_vacios() para ver si todos los montones est�n vacios y se ha ganado el juego.

*   @param numeroMonton posici�n que ocupe el mont�n que queremos buscar.
*	@retval true El nodo que ocupa la posici�n= 'numeroMonton' de listaMontones tienen su lista vac�a.
*	@retval false El nodo que ocupa la posici�n= 'numeroMonton' de listaMontones NO tienen su lista vac�a.
**/
bool listaMontones::comprueba_Monton_vacio(short numeroMonton){
/**
	*Variables locales de la funci�n:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno seg�n avanzamos en la lista hasta llegar a la posici�n deseada*/

try{
	nodo_listaMontones*p = new nodo_listaMontones();//var p: puntero a nodo_listaMontones;
	int pos;//para lamacenar la posici�n seg�n avanzamos
	if (comprobar_posicion(numeroMonton)){//comprobamos que este dentro rango (1 a longitud) posici�n v�lida
		p = primero;//el puntero toma el valor del primero
		pos = 1;//la posici�n empieza en uno.
		
		while (pos<numeroMonton){//mientras no llegemos a la posici�n deseada
			pos = pos + 1;//avanzamos una posici�n
			p = p->pSiguiente;//avanzamos al siguiente nodo, pasa a apuntar al siguiente
		}//fmientras
		
	}
	return p->monton.es_lista_vacia();//devolvemos booleano si la lista 'monton' est� o no vac�a.
}
catch(invalid_argument){//capturamos excepci�n posici�n fuera de rango
	cout << "error posici�n inexistente-> "<<numeroMonton;
	return false;
}
}//fproc
     
     
     
     
        
     
     
     
/** @brief Muestra por pantalla la informaci�n contenida en la lista de montones.
*
*   Muestra  por pantalla la posici�n del nodo_listaMontones en la listaMontones y a su vez imprime la lista de n�meros
*	mediante el m�todo Lista.imprimir() de la clase Lista de su atributo 'monton'.
* 
*   - Usamos esta funci�n para mostrar la lista de montones con su contenido.
*
*	@see Lista.imprimir()
**/
void listaMontones::imprimir(){
	/*Variables locales de la funci�n:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: contador de posiciones, se incrementa en uno seg�n avanzamos en la lista hasta llegar a la posici�n deseada*/
nodo_listaMontones*p=new nodo_listaMontones();//var p: puntero a nodo-lista; 
short pos=0;//pos, n: nat
if (es_lista_vacia()){//si es_lista_vacia(l) 
cout<<" no hay datos error lista vacia";//entonces error(Lista vacia)
}else{//si no
p=primero;//p <- l.primero; el puntero toma el valor del primero de la lista
while (p!=NULL){//mientras que haya lista
pos=pos+1;//avanzamos uno en la posici�n
cout<<"\n MONTON "<<pos<<"->";//imprimioms el valor de la posici�n
p->monton.imprimir();//imprimimos la lista de numero que contiene el objeto de la clase lista monton
cout<<"\n";

p=p->pSiguiente;// p <- p^.sig avanzamos pasando a ser el siguiente nodo.
}//fmientras
}
}//ffun
     
     
     
     







//***********************************************  MODIFICADORAS ********************************************************************




/** @brief Funci�n que busca un mont�n y a�ade por la derecha un n�mero natural a la lista de ese mont�n .  
*   
*   La funci�n busca la posici�n que ocupa un nodo_listaMontones, seg�n el valor de la variable 'numeroMonton'
*	y una vez encontrado, a su lista, atributo 'monton', le a�ade por la derecha un n�mero natural que ha sido pasado 
*   en la variable 'numero', usando el m�todo anadir_der(short elemento) de la clase Lista.
*
*	@see Lista
*	@see Lista.anadir_der(short elemento)
*
*	- Usamos esta funci�n cuando por las reglas del juego sea necesario a�adir un n�mero como �ltimo elemento de un mont�n determinado.
*   
*	@param numeroMonton Posici�n del mont�n en la listaMontones. Posici�n del nodo_listaMontones donde queremos a�adir el n�mero.
*	@param numero N�mero natural que se quiere a�adir a la lista del nodo_listaMontones buscado.
**/
void listaMontones::menter_en_monton(short numeroMonton,short numero ){
/**
	*Variables locales de la funci�n:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno seg�n avanzamos en la lista hasta llegar a la posici�n deseada*/
	
nodo_listaMontones*p=new nodo_listaMontones();//puntero auxiliar a nodo_listaMontones para recorrer la lista
short pos;//contador de posiciones
if (numeroMonton==0||numeroMonton>longitud){//si queremos acceder a una posici�n fuera de rango error
cout<<"error posicion inexistente";//error(posicion inexistente)
}else{//si no
p=primero;//apuntamos al primer elemento de la lista
pos=1;//inicializamos el contador
while (pos<numeroMonton){//si no hemos llegado a la posici�n deseado, mont�n deseado.
pos=pos+1;//Incrementamos en uno el contador de la posici�n
p=p->pSiguiente;//El puntero auxiliar apunta al siguiente nodo de la lista.
}//fmientras
//Hemos encontrado el nodo buscado pos es igual a numeroMonton
p->monton.anadir_der(numero);//A�adimos al objeto monton, (clase lista), del nodo buscado, el n�mero natural pasado.
}//fproc
 }
 
 
 
 
 
 
 
 
 
 
 
/** @brief Elimina el �ltimo elemento de la lista que corresponde a un n�mero de m�nton determinado.
*
*   La funci�n, avanzando iterativamente, busca la posici�n que ocupa un nodo_listaMontones, seg�n el valor
*	de la variable 'numeroMonton' y una vez encontrado, mediante el m�todo Lista.eult() de su atributo 'monton', clase Lista,
*	elimina el �ltimo elemento de la lista.
*   @see Lista.eult()
* 
*   - Usamos esta funci�n cuando por las reglas del juego sea necesario eliminar la cima, �ltimo elemento, de un mont�n determinado.
*
*   @param numeroMonton posici�n que ocupa el mont�n del cu�l que queremos sacar un elemento.
**/
void listaMontones::sacar_de_monton(short numeroMonton){
	/**
	*Variables locales de la funci�n:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno seg�n avanzamos en la lista hasta llegar a la posici�n deseada*/

     nodo_listaMontones*p=new nodo_listaMontones();//var p: puntero a nodo_listamontones;
int pos;//para lamacenar la posici�n seg�n avanzamos
if (numeroMonton==0||numeroMonton>longitud){//si (n = 0) o (n > l.longitud) si la posici�n buscada est� fuera de rango
cout<<"error posicion inexistente";//error(posicion inexistente)
}else{//si no
p=primero;//p <-l.primero;  el puntero toma el valor del primero
pos=1;//pos <-1 la posici�n empieza en 1
while (pos<numeroMonton){//mientras no llegemos a la posici�n deseada
pos=pos+1;//pos<-pos+1 avanzamos uno en la posici�n
p=p->pSiguiente;//p<-p^.sig avanzamos al siguiente nodo, pasa a apuntar al siguiente
}//fmientras
p->monton.eult();//Actuamos sobre la lista del nodo buscado eliminando su �ltimo elemento.
     
     }
}








/** @brief Elimina el primer mont�n de la lista de Montones, primera celda dejando el resto.
*
*   La funci�n elimina el primer nodo_listaMontones, a la que apunta el puntero de la lista, primero.
* 
*   - Usamos esta funci�n para destruir los nodos de la lista a la hora de salir del juego mediante el destructor ~listaMontones()
*
*	@see  ~listaMontones()
**/
void listaMontones::resto(){
	/**
	*Variables locales de la funci�n:
	**/
	/**- aux: puntero auxiliar a nodo_listaMontones para recorrer la lista*/

nodo_listaMontones*aux=new nodo_listaMontones();//var p: puntero a nodo_listaMontones
if (es_lista_vacia()){//si es_lista_vacia(l) entonces
cout<<"error lista vac�a";//error(Lista vacia)
}else{//si no
aux=primero;//El puntero auxiliar a nodo toma el valor del primero de la lista
primero=aux->pSiguiente;//El puntero primero de la lista pasa a apuntar al siguiente, segundo elemento de la lista, que pasa a ser el primero
aux->pSiguiente=NULL;// por seguridad, rompemos el enlace del antiguo nodo que era el primero de la lista.
delete(aux);//liberar(p) Eliminamo el antiguo nodo que antes era el primero.
longitud=longitud-1;//disminuimos en uno la longitud.
}//fsi
}//fproc









