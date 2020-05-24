/**
* @file listaMontones.cpp
* @brief Implementa, listaMontones (Clase que representa la estructura lineal para almacenar las listas de números, montones del juego)
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

/** @brief Constructor para crear una listaMontones vacía.
*
*   No hay ningún nodo_listaMontones creado, no hay celdas en la lista, el puntero
*	primero toma valor Null, y la longitud es cero. No hay ningún montón.
*
**/
listaMontones::listaMontones(){
            longitud=0;//no tiene nodos
            primero=NULL;//no apunta a ningún nodo
}








/** @brief Destructor de la clase listaMontones
*
*   Elimina todas las celdas de la listaMontones, eliminando iterativamente el primer nodo, mediante la función resto(),
*   hasta que la lista está vacía, una vez eliminados los nodos se elimina el puntero de la lista 'primero'.
*   @see resto()
*
**/
listaMontones::~listaMontones(){
		cout<<"\nDestructor clase listaMontones, elimina listado de montones: \n";
        while(!es_lista_vacia()){//mientras la lista no esté vacía
        	resto();//eliminamos el primer nodo
            }
            delete(primero);//eliminamos el puntero lista, ya no hay lista.
       
			_getche();
        }
        
        
        
        
        
        
        
/** @brief Añade por la izquierda, iterativamente, un determinado número de montones de un tamaño determinado.  
*   
*   Añade por la izquierda, de forma iterativa, un nuevo objeto de la clase nodo_listaMontones, hasta llegar al número de montones determinado
*   por el valor de la variable numero_de_montones. Al atributo "monton" de la clase Lista, que pertenece al nuevo objeto, nodo_listaMontones , 
*   se le añade una serie de números naturales mediante la función llenarLista(short n) de la clase Lista, la cantidad de números que tiene 
*   el montón parte del valor pasado en la variable elementos_monton y que es pasada a la función llenarLista(short n).
*	@see Lista.llenarLista(short n)
*   
*	@param numero_de_montones Número de montones, cantidad de listas a añadir a la lista de Montones.
*	@param elementos_monton Número máximo de elementos que pueden tener los montones, determinará el número de elementos inicial de cada montón.
**/
void listaMontones::crear_lista(short numero_de_montones, short elementos_monton){
	
	/**
	*Variables:
	**/
	/**- n: almacena el número de montones que serán añadidos a la lista*/
short n;//variable para almacenar el número de montones 
n=numero_de_montones;//asignamos la cantidad de montones a crear.
 while (n>0){//Mientras sea mayor a cero, el número de montones a crear.
           
  nodo_listaMontones*p=new nodo_listaMontones();//Nuevo nodo_listaMontones atributo'monton' lista vacía, pSiguiente=NULL
  p->monton.llenarLista(elementos_monton);//Llenamos la lista, el 'monton', del nuevo nodo con una cantidad determinada de números naturales.
  p->pSiguiente=primero;//El puntero, del nuevo nodo, apunta al primer elemento de la lista, enlazamos con la lista.
  primero=p;//El puntero de lista, primero, apunta al nuevo nodo que pasa a ser así el primero de la lista.      
      
  longitud=longitud+1;//aumentamos la longitud de la lista en uno, un nuevo nodo ha sido añadido.   
   n=n-1;//disminuimos en uno la cantidad de número de montones a crear.
           
           }
     }




//****************************************** OBSERVADORAS *************************************************




/** @brief Comprueba si la listaMontones, está vacía.
*
*   Comprueba si el puntero, primero de la lista, clase nodo_listaMontones, apunta a un nodo o a null.(primero==NULL)
*	si es igual a null devuelve true en caso contrario devuelve false.
*
*	@retval true la listaMontones está vacía.
*	@retval false la listaMontones tiene celdas, no está vacía.
**/
bool listaMontones::es_lista_vacia() //Devuelve true si está vacía, false en caso else
{
     return (primero==NULL);//Si el puntero de la lista apunta null, es true, lista vacia.
}







/** @brief Función para acceder a la longitud de la lista, cantidad de nodos que hay en la lista.
*
*	@retval longitud Un número natural que representa la cantidad de montones que hay en la lista.
**/
short listaMontones::Longitud(){
    return longitud;//Devolvemos el atributo longitud
}








/** @brief Función que busca un montón en la lista de montones y devuelve el último elemento de su lista.
*
*	La función busca la posición que ocupa un nodo_listaMontones, según el valor de la variable numeroMonton
*	y una vez encontrado, devuelve el valor almacenado en la última celda de su lista correspondiente, atributo monton, 
*	usando el método final() de la clase Lista.
*	@see Lista.final()
*
*	@param numeroMonton Posición que ocupa el monton en la listaMontones, Posición del nodo_listaMontones.
*	@retval natural Número natural almacenado en el último elemento de la lista, que pertenece al montón buscado.
**/
short listaMontones::buscar_cima_monton(short numeroMonton) {
   
/**
	*Variables locales de la función:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: contador de posiciones, se incrementa en uno según avanzamos en la lista hasta llegar a la posición deseada*/
	

try{
	nodo_listaMontones*p = new nodo_listaMontones();//puntero a nodo_listaMontones;
	short pos;//almacena la posición según avanzamos
	if (comprobar_posicion(numeroMonton)){//comprobamos que este dentro rango [1 a longitud]
		p = primero;//p toma el valor del primero de la lista
		pos = 1;//estamos en la posición 1

		while (pos<numeroMonton){//mientras no llegemos a la posición deseada
			pos = pos + 1;// avanzamos una posición
			p = p->pSiguiente;// avanzamos al siguiente nodo
		}//fmientras salimos con la posición deseada y el nodo que ocupa esa posición.

		
	}
	return p->monton.final();//devolvemos el valor del último elemento de la lista asociada al nodo buscado.
}
catch (invalid_argument){//capturamos excepción 
	cout << ("Error posicion inexistente-> ");

	return numeroMonton;//devolvemos el número que ha sido pasado como erroneo.
}

 
}



/** @brief Función que comprueba que una posición pasada es válida, si está entre 1 y la longitud de la lista.
*
*	Cada nodo ocupa una posición en la listaMontones de 1 a la longitud de listaMontones, comprueba si la posición pedida está en este rango
*
*	@param numeroMonton Posición que ocupa el montón en la listaMontones, posición a comprobar.
*	@retval true si es posición valida, si no lanza excepción.
**/
bool listaMontones::comprobar_posicion(short numeroMonton){

	
	if (numeroMonton == 0 || numeroMonton > longitud){//Si la posición pedida es igual a cero o superior a la longitud de la lista

		throw std::invalid_argument("Error posicion inexistente-> ");//lanzamos una excepción
	}
	else{//encaso contrario si es una posición correcta.
		return true;//devolvemos verdadero.
	}
}








/** @brief Función que busca un montón en la lista de montones y devuelve la longitud de su lista, número de elementos en el montón.
*
*	La función, avanzando iterativamente, busca la posición que ocupa un nodo_listaMontones, según el valor
*	de la variable 'numeroMonton' y una vez encontrado, devuelve la longitud correspondiente a su atributo 'monton', 
*	usando el método Lista.Longitud() de la clase Lista.
*   @see Lista.Longitud()
*
*	- Usamos esta función para ver si algún montón ha llegado al límite máximo de elementos que puede tener, juego perdido.
*
*	@param numeroMonton Posición que ocupa el monton en la listaMontones, Posición del nodo_listaMontones.
*	@retval Número natural que representa la cantidad de elementos que hay en la lista de ese monton.
**/
short listaMontones::longitud_del_monton(short numeroMonton){
	/**
	*Variables locales de la función:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno según avanzamos en la lista hasta llegar a la posición deseada*/

nodo_listaMontones*p=new nodo_listaMontones();//var p: puntero a nodo-lista;
try{
	int pos;//para lamacenar la posición según avanzamos
	if (comprobar_posicion(numeroMonton)){//comprobamos que este dentro rango [1 a longitud]
		p = primero;//el puntero toma el valor del primero
		pos = 1;//partimos de la posición uno

		while (pos < numeroMonton){//mientras no llegemos a la posición deseada
			pos = pos + 1;//avanzamos una posición
			p = p->pSiguiente;//avanzamos al siguiente nodo, pasa a apuntar al siguiente
		}//fmientras
		
	}
	return p->monton.Longitud();//devolvemos la longitud de 'monton' objeto de la clase lista
}
catch (invalid_argument){//capturamos excepción posición fuera  de rango devolvemos la posición pasada.
	cout << "posición inexistente-> ";
	return numeroMonton;
}

}//fproc
 

	




/** @brief Comprueba si todos los montones almacenados en la lista están vacios, listas vacias.
*
*   Comprobamos iterativamente que cada nodo_listaMontones tenga su atributo 'monton' como una lista vacía, para ello
*   usamos iterativamente la función comprueba_Monton_vacio(short posicionMonton) pasándole la posición del montón hasta llegar
*   al final de la lista o hasta encontrar un montón que no este vacío.
* 
*   - Usamos esta función para ver si se ha ganado el juego. Todos los montones son lista vacía.
*   
*	@retval true Todos los nodos de la listaMontones tienen su lista vacía.
*	@retval false Algún montón de la listaMontones, tiene una lista que contiene algún elemento.
**/
bool listaMontones::comprueba_todos_vacios(){
	short l=1;//contador incremental para acceder a las posiciones a comprobar desde 1 hasta logitud de la lista +1
	while (l<(Longitud()+1)&&comprueba_Monton_vacio(l)){//Mientras no hallamos alcanzado la longitud y el monton este vacío
		l=l+1;//incrementamos en uno para comprobar la siguiente posición
	}
	//Hemos recorrido todas las posiciones y hemos lacanzado la longitud o hemos encontrado algún monton con elementos y hemos salido.
	return (l==Longitud()+1);//Si todos los montones están vacios l ha de ser igual a la longitud+1, recorrimos todos
}
     




/** @brief Comprueba si un montón de una determinada posición está vacío.
*
*   La función, avanzando iterativamente, busca la posición que ocupa un nodo_listaMontones, según el valor
*	de la variable numeroMonton y una vez encontrado, devuelve un valor lógico correspondiente al método es_lista_vacia() 
*   de su atributo 'monton', de la clase Lista.
*   @see Lista.es_lista_vacia()
* 
*   - Usamos esta función para solo mostrar las posiciones que están llenas cuando se ejecuta la elección del montón mediante el dado.
*	y junto a la función listaMontones.comprueba_todos_vacios() para ver si todos los montones están vacios y se ha ganado el juego.

*   @param numeroMonton posición que ocupe el montón que queremos buscar.
*	@retval true El nodo que ocupa la posición= 'numeroMonton' de listaMontones tienen su lista vacía.
*	@retval false El nodo que ocupa la posición= 'numeroMonton' de listaMontones NO tienen su lista vacía.
**/
bool listaMontones::comprueba_Monton_vacio(short numeroMonton){
/**
	*Variables locales de la función:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno según avanzamos en la lista hasta llegar a la posición deseada*/

try{
	nodo_listaMontones*p = new nodo_listaMontones();//var p: puntero a nodo_listaMontones;
	int pos;//para lamacenar la posición según avanzamos
	if (comprobar_posicion(numeroMonton)){//comprobamos que este dentro rango (1 a longitud) posición válida
		p = primero;//el puntero toma el valor del primero
		pos = 1;//la posición empieza en uno.
		
		while (pos<numeroMonton){//mientras no llegemos a la posición deseada
			pos = pos + 1;//avanzamos una posición
			p = p->pSiguiente;//avanzamos al siguiente nodo, pasa a apuntar al siguiente
		}//fmientras
		
	}
	return p->monton.es_lista_vacia();//devolvemos booleano si la lista 'monton' está o no vacía.
}
catch(invalid_argument){//capturamos excepción posición fuera de rango
	cout << "error posición inexistente-> "<<numeroMonton;
	return false;
}
}//fproc
     
     
     
     
        
     
     
     
/** @brief Muestra por pantalla la información contenida en la lista de montones.
*
*   Muestra  por pantalla la posición del nodo_listaMontones en la listaMontones y a su vez imprime la lista de números
*	mediante el método Lista.imprimir() de la clase Lista de su atributo 'monton'.
* 
*   - Usamos esta función para mostrar la lista de montones con su contenido.
*
*	@see Lista.imprimir()
**/
void listaMontones::imprimir(){
	/*Variables locales de la función:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: contador de posiciones, se incrementa en uno según avanzamos en la lista hasta llegar a la posición deseada*/
nodo_listaMontones*p=new nodo_listaMontones();//var p: puntero a nodo-lista; 
short pos=0;//pos, n: nat
if (es_lista_vacia()){//si es_lista_vacia(l) 
cout<<" no hay datos error lista vacia";//entonces error(Lista vacia)
}else{//si no
p=primero;//p <- l.primero; el puntero toma el valor del primero de la lista
while (p!=NULL){//mientras que haya lista
pos=pos+1;//avanzamos uno en la posición
cout<<"\n MONTON "<<pos<<"->";//imprimioms el valor de la posición
p->monton.imprimir();//imprimimos la lista de numero que contiene el objeto de la clase lista monton
cout<<"\n";

p=p->pSiguiente;// p <- p^.sig avanzamos pasando a ser el siguiente nodo.
}//fmientras
}
}//ffun
     
     
     
     







//***********************************************  MODIFICADORAS ********************************************************************




/** @brief Función que busca un montón y añade por la derecha un número natural a la lista de ese montón .  
*   
*   La función busca la posición que ocupa un nodo_listaMontones, según el valor de la variable 'numeroMonton'
*	y una vez encontrado, a su lista, atributo 'monton', le añade por la derecha un número natural que ha sido pasado 
*   en la variable 'numero', usando el método anadir_der(short elemento) de la clase Lista.
*
*	@see Lista
*	@see Lista.anadir_der(short elemento)
*
*	- Usamos esta función cuando por las reglas del juego sea necesario añadir un número como último elemento de un montón determinado.
*   
*	@param numeroMonton Posición del montón en la listaMontones. Posición del nodo_listaMontones donde queremos añadir el número.
*	@param numero Número natural que se quiere añadir a la lista del nodo_listaMontones buscado.
**/
void listaMontones::menter_en_monton(short numeroMonton,short numero ){
/**
	*Variables locales de la función:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno según avanzamos en la lista hasta llegar a la posición deseada*/
	
nodo_listaMontones*p=new nodo_listaMontones();//puntero auxiliar a nodo_listaMontones para recorrer la lista
short pos;//contador de posiciones
if (numeroMonton==0||numeroMonton>longitud){//si queremos acceder a una posición fuera de rango error
cout<<"error posicion inexistente";//error(posicion inexistente)
}else{//si no
p=primero;//apuntamos al primer elemento de la lista
pos=1;//inicializamos el contador
while (pos<numeroMonton){//si no hemos llegado a la posición deseado, montón deseado.
pos=pos+1;//Incrementamos en uno el contador de la posición
p=p->pSiguiente;//El puntero auxiliar apunta al siguiente nodo de la lista.
}//fmientras
//Hemos encontrado el nodo buscado pos es igual a numeroMonton
p->monton.anadir_der(numero);//Añadimos al objeto monton, (clase lista), del nodo buscado, el número natural pasado.
}//fproc
 }
 
 
 
 
 
 
 
 
 
 
 
/** @brief Elimina el último elemento de la lista que corresponde a un número de mónton determinado.
*
*   La función, avanzando iterativamente, busca la posición que ocupa un nodo_listaMontones, según el valor
*	de la variable 'numeroMonton' y una vez encontrado, mediante el método Lista.eult() de su atributo 'monton', clase Lista,
*	elimina el último elemento de la lista.
*   @see Lista.eult()
* 
*   - Usamos esta función cuando por las reglas del juego sea necesario eliminar la cima, último elemento, de un montón determinado.
*
*   @param numeroMonton posición que ocupa el montón del cuál que queremos sacar un elemento.
**/
void listaMontones::sacar_de_monton(short numeroMonton){
	/**
	*Variables locales de la función:
	**/
	/**- p: puntero auxiliar a nodo_listaMontones para recorrer la lista*/
	/**- pos: natural contador de posiciones, se incrementa en uno según avanzamos en la lista hasta llegar a la posición deseada*/

     nodo_listaMontones*p=new nodo_listaMontones();//var p: puntero a nodo_listamontones;
int pos;//para lamacenar la posición según avanzamos
if (numeroMonton==0||numeroMonton>longitud){//si (n = 0) o (n > l.longitud) si la posición buscada está fuera de rango
cout<<"error posicion inexistente";//error(posicion inexistente)
}else{//si no
p=primero;//p <-l.primero;  el puntero toma el valor del primero
pos=1;//pos <-1 la posición empieza en 1
while (pos<numeroMonton){//mientras no llegemos a la posición deseada
pos=pos+1;//pos<-pos+1 avanzamos uno en la posición
p=p->pSiguiente;//p<-p^.sig avanzamos al siguiente nodo, pasa a apuntar al siguiente
}//fmientras
p->monton.eult();//Actuamos sobre la lista del nodo buscado eliminando su último elemento.
     
     }
}








/** @brief Elimina el primer montón de la lista de Montones, primera celda dejando el resto.
*
*   La función elimina el primer nodo_listaMontones, a la que apunta el puntero de la lista, primero.
* 
*   - Usamos esta función para destruir los nodos de la lista a la hora de salir del juego mediante el destructor ~listaMontones()
*
*	@see  ~listaMontones()
**/
void listaMontones::resto(){
	/**
	*Variables locales de la función:
	**/
	/**- aux: puntero auxiliar a nodo_listaMontones para recorrer la lista*/

nodo_listaMontones*aux=new nodo_listaMontones();//var p: puntero a nodo_listaMontones
if (es_lista_vacia()){//si es_lista_vacia(l) entonces
cout<<"error lista vacía";//error(Lista vacia)
}else{//si no
aux=primero;//El puntero auxiliar a nodo toma el valor del primero de la lista
primero=aux->pSiguiente;//El puntero primero de la lista pasa a apuntar al siguiente, segundo elemento de la lista, que pasa a ser el primero
aux->pSiguiente=NULL;// por seguridad, rompemos el enlace del antiguo nodo que era el primero de la lista.
delete(aux);//liberar(p) Eliminamo el antiguo nodo que antes era el primero.
longitud=longitud-1;//disminuimos en uno la longitud.
}//fsi
}//fproc









