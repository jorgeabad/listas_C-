/**
* @file main.cpp
* @brief cpp. Contiene la funcion que ejecuta el programa.
* @author Jorge Abad
*/
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "juego.h"
#include "lista.h"
#include "listaMontones.h"
#include "principal.h"
#include <locale.h>
#include <conio.h>



using namespace std;




/** @brief Funcion que representa el punto de inicio de ejecución del programa. 
*
*-	Instancia un objeto de la clase Lista, para reperesentar la cinta.
*-	Instancia un objeto de la clase listaMontones, una lista de listas numéricas, para almacenar los montones del juego.
*-	Llama a los metodos de la clase Juego, para realizar  y obtener las operaciones.
*-	Muestra la interfaz grafica que le aparece al usuario mostrando un menú con opciciones.
*-	Crea las variables locales necesarias para interactuar con el usuario, como mensajes de aviso y opciones elegidas.
*
**/
int main(int argc, char *argv[])
{
    

    setlocale(LC_ALL, "spanish");  /*poder representar acentos*/
	Juego::iniciarSemilla(); /*iniciamos la semilla para generar los números aleatorios*/


	Principal miJuego;//Creamos un objeto clase principal para eniciar el juego.
	
	//Creamos los elementos necesarios para empezar la partida.
	miJuego.crearCintaNumerica();//La cinta nmérica.
	miJuego.seleccionarNumeroDeMontones();//El número de montones que queremos para el juego.
	miJuego.seleccionarElementosPorMonton();//El numero máximo de elementos para los montones.
	miJuego.crearListaMontones();//En función de lo anterior creamos una lista de montones. 

	//Lanzamos el menu para empezar a jugar
	miJuego.menuPrincipal();
   
	//Cuando el juego termina limpiamos y mostramos avisos.
    system("cls");
    
    
    
    //Final del programa
    cout<<"###################################################"<<endl<<
            miJuego.getFinJuego()<<"*"<<endl<<//Mostramos el mensaje de fin del juego motivo por el que termino.
          "###################################################"<<endl;
    _getche();
    

}



