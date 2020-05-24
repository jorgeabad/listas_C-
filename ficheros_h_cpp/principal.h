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
*	Presenta los métodos públicos y atributos privados necesarios para:
*
*-	Instanciar un objeto de la clase lista, para reperesentar la cinta numérica.
*-	Pedir y almacenar los valores introducidos por el usuario para la cantidad de montones del juego y elementos por montón
*-	Instanciar un objeto de la clase listaMontones, una lista de listas numéricas, para almacenar los montones del juego.
*-	Muestra una interfaz gráfica que le aparece al usuario, mostrando un menú con las opciones, la lista de montones, y la cinta numérica.
*-	Almacena y muestra los valores del montón elegido, la operación elegida, avisos del sistema y avisos del fin del juego.
*-	Llama a los métodos de la clase juego, para realizar y obtener las operaciones.
*
**/ 
class Principal{


	 /**@var valorReferencia
	 *@brief Número natural=10 que tomamos como valor para decidir si añadimos o quitamos un número de un montón
     *@var cantidadMontones
	 *@brief Almacena la cantidad de montones, del juego. Cantidad de nodo_listaMontones para la listaMontones.
     *@var elementosPorMonton
	 *@brief Número máximo de elementos al que pueden llegar los montones en el juego.
	 *@var op
	 *@brief Almacena el símbolo de la operación
	 *@var avisoSistema
	 *@brief Almacena cualquier aviso de error o mensaje, para el usuario al interactuar con el programa.
	 *@var finJuego
	 *@brief Alamacena la información de porque se acaba el juego, fin del programa.
	 *@var opcion
	 *@brief Variable que almacena la opción seleccionada por el usuario. Cero no hay opción.
	 *@var numeroCinta
	 *@brief Almacena el primer numero de la cinta, el que hay que introducir en los montones.Cero no hay número sacado de la cinta.
	 *@var cima
	 *@brief Almacena el número que es cima del monton seleccionado.
	 *@var resultado
	 *@brief Almacena el resultado de la operación de la cima con el numeroCinta, inicialmente 0.
	 *@var montonSeleccionado
	 *@brief Almacena número natrural que representa el monton seleccionado por el usuario, posición en la listaMontones.
	 *@var listaM
	 *@brief Almacena una serie de objetos de la clase Lista, se corresponde con los montones del juego.
	 -@var cinta
	 *@brief Almacena los números de la cinta numérica.
	 */

private:

	 short valorReferencia; //No se permitirá mas de 10 elementos en un montón
     short cantidadMontones;
     short elementosPorMonton;
	 char op; //Almacena el símbolo de la operación
	 string avisoSistema; //Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa.
	 string finJuego; //Avisa del fin del programa.
	 char opcion;//variable que almacena la opción seleccionada por el usuario.Cero no hay opción.
	 short numeroCinta;// almacena el primer numero de la cinta, el que hay que introducir en los montones.Cero no hay número sacado de la cinta.
	 short cima;//Almacena el número que es cima del monton seleccionado.
	 short resultado;//Almacena el resultado de la operación inicialmente 0.
	
	 short montonSeleccionado;//representa el monton seleccionado por el usuario
  
     listaMontones listaM;//Almacena objetos de la clase Lista, los montones del juego
	 Lista cinta;//Almacena los números de la cinta numérica

public:
	 Principal();//Constructor inicializa las variables para el inicio del juego
	 string getFinJuego();//devuelve el valor del atributo 'finjuego'
	 void seleccionarNumeroDeMontones();//Permite elegir al usuario el número de montones que desea para el juego 
	 void seleccionarElementosPorMonton();//Permite seleccionar el número máximo de elementos al que pueden llegar los montones.
	 void crearCintaNumerica();//Crea un objeto de la clase lista que representa la cinta numérica.
	 void crearListaMontones();//Crea un objeto de la clase listaMontones que representa la lista de montones, cada montón es una lista.
	 short dado();//Muestra y permite la elección por pantalla, de números que representan las posiciones de la lista de montones.
	 void menuPrincipal();//Muestra por pantalla la información de la cinta y montones, y se encarga de la E/S de datos al usuario.
	 
};
#endif