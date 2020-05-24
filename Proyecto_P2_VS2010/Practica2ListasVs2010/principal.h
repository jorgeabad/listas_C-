/**
* @file principal.h
* @brief Cabecera para la clase Principal.
*/

#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "juego.h"
#include "lista.h"
#include "listaMontones.h"
#include <locale.h>
#include <conio.h>



using namespace std;



/** @brief Clase empleada para interactuar con el usuario y para crear objetos de las clases lista y listaMontones.
*
*	Presenta los m�todos p�blicos y atributos privados necesarios para:
*
*-	Instanciar un objeto de la clase lista, para reperesentar la cinta num�rica.
*-	Pedir y almacenar los valores introducidos por el usuario para la cantidad de montones del juego y elementos por mont�n
*-	Instanciar un objeto de la clase listaMontones, una lista de listas num�ricas, para almacenar los montones del juego.
*-	Muestra una interfaz gr�fica que le aparece al usuario, mostrando un men� con las opciones, la lista de montones, y la cinta num�rica.
*-	Almacena y muestra los valores del mont�n elegido, la operaci�n elegida, avisos del sistema y avisos del fin del juego.
*-	Llama a los m�todos de la clase juego, para realizar y obtener las operaciones.
*
**/ 
class Principal{


	 /**@var valorReferencia
	 *@brief N�mero natural=10 que tomamos como valor para decidir si a�adimos o quitamos un n�mero de un mont�n
     *@var cantidadMontones
	 *@brief Almacena la cantidad de montones, del juego. Cantidad de nodo_listaMontones para la listaMontones.
     *@var elementosPorMonton
	 *@brief N�mero m�ximo de elementos al que pueden llegar los montones en el juego.
	 *@var op
	 *@brief Almacena el s�mbolo de la operaci�n
	 *@var avisoSistema
	 *@brief Almacena cualquier aviso de error o mensaje, para el usuario al interactuar con el programa.
	 *@var finJuego
	 *@brief Alamacena la informaci�n de porque se acaba el juego, fin del programa.
	 *@var opcion
	 *@brief Variable que almacena la opci�n seleccionada por el usuario. Cero no hay opci�n.
	 *@var numeroCinta
	 *@brief Almacena el primer numero de la cinta, el que hay que introducir en los montones.Cero no hay n�mero sacado de la cinta.
	 *@var cima
	 *@brief Almacena el n�mero que es cima del monton seleccionado.
	 *@var resultado
	 *@brief Almacena el resultado de la operaci�n de la cima con el numeroCinta, inicialmente 0.
	 *@var montonSeleccionado
	 *@brief Almacena n�mero natrural que representa el monton seleccionado por el usuario, posici�n en la listaMontones.
	 *@var listaM
	 *@brief Almacena una serie de objetos de la clase Lista, se corresponde con los montones del juego.
	 -@var cinta
	 *@brief Almacena los n�meros de la cinta num�rica.
	 */

private:

	 short valorReferencia; //No se permitir� mas de 10 elementos en un mont�n
     short cantidadMontones;
     short elementosPorMonton;
	 char op; //Almacena el s�mbolo de la operaci�n
	 string avisoSistema; //Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa.
	 string finJuego; //Avisa del fin del programa.
	 char opcion;//variable que almacena la opci�n seleccionada por el usuario.Cero no hay opci�n.
	 short numeroCinta;// almacena el primer numero de la cinta, el que hay que introducir en los montones.Cero no hay n�mero sacado de la cinta.
	 short cima;//Almacena el n�mero que es cima del monton seleccionado.
	 short resultado;//Almacena el resultado de la operaci�n inicialmente 0.
	
	 short montonSeleccionado;//representa el monton seleccionado por el usuario
  
     listaMontones listaM;//Almacena objetos de la clase Lista, los montones del juego
	 Lista cinta;//Almacena los n�meros de la cinta num�rica

public:
	 Principal();//Constructor inicializa las variables para el inicio del juego
	 string getFinJuego();//devuelve el valor del atributo 'finjuego'
	 void seleccionarNumeroDeMontones();//Permite elegir al usuario el n�mero de montones que desea para el juego 
	 void seleccionarElementosPorMonton();//Permite seleccionar el n�mero m�ximo de elementos al que pueden llegar los montones.
	 void crearCintaNumerica();//Crea un objeto de la clase lista que representa la cinta num�rica.
	 void crearListaMontones();//Crea un objeto de la clase listaMontones que representa la lista de montones, cada mont�n es una lista.
	 short dado();//Muestra y permite la elecci�n por pantalla, de n�meros que representan las posiciones de la lista de montones.
	 void menuPrincipal();//Muestra por pantalla la informaci�n de la cinta y montones, y se encarga de la E/S de datos al usuario.
	 
};
#endif