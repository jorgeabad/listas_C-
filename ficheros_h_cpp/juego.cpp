/**
* @file juego.cpp
* @brief Implementa, juego (m�todos est�ticos, para el funcionamiento del juego)
*/

#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <windows.h>
#include"juego.h"
using namespace std;
 
 
/** @brief M�todo para iniciar, la generaci�n del n�mero aleatorio, mediante la hora del sistema.
*
*	Usa el m�todo srand() para iniciar la aleatoriedad usando el tiempo del sistema en milisegundos
*	como semilla, para impedir que siempre salgan los mismos n�meros.
*
**/	
void Juego::iniciarSemilla(){
	 srand((unsigned)time(0)); 
	//srand(time(NULL));
}





/** @brief M�todo para obtener un n�mero entero aleatorio entre 1 y 9.
*
*   @return num Un n�mero entero entre 1 y 9.
*
**/	
short Juego::obtenerNumero()
{
    /**Variables*/
    /**- num: almacena el n�mero entero obtenido (1-9)*/
	short num;
    //rand();
    num = 1 + rand() % (9);// rand() obtiene un n�mero aleatorio en funci�n de la semilla
    //Mediante la operador m�dulo obtenemos el resto de la operaci�n (numero aleatorio)/9
	//Obligamos a que este dentro del intervalo entre 1 y 9 al sumarle 1 
      
    //Sleep(500);
    return num;//Devolvemos el n�mero.
}


/** @brief M�todo para obtener un n�mero entero aleatorio entre 1 y un n�mero m�ximo dado.
*	
*
*	@param max n�mero m�ximo hasta el cual podemos obtener un n�mero.
*   @return num Un n�mero entero entre 1 y max.
*
**/	
short Juego::obtenerNumeroHasta(short max)
{
    /**Variables*/
    /**- num: almacena el n�mero entero obtenido (1-max)*/
	short num;
    //rand();
    num = 1 + rand() % (max);// rand() obtiene un n�mero aleatorio en funci�n de la semilla
    //Mediante la operador m�dulo obtenemos el resto de la operaci�n (numero aleatorio)/max
	//Obligamos a que este dentro del intervalo entre 1 y max al sumarle 1 
      
    return num;//Devolvemos el n�mero.
}




/** @brief M�todo para obtener un char, que simboliza la operaci�n.
*
*   @retval + Simboliza suma.
*	@retval - Simboliza resta.
*	@retval / Simboliza divisi�n.
*	@retval * Simboliza multiplicaci�n.
*
**/	
char Juego::obtenerOperacion()
{
    /**Variables:*/
    /**- operador: almacena el s�mbolo de la operaci�n*/
	char operador;//almacena el s�mbolo de la operaci�n
    operador='p';//Inicializamos con p
    
  	/**- num: Almacena un n�mero aleatorio del 1 al 4, en funci�n de este num operador toma un valor*/
  	/** si num=1 operador=*, si num=2 operador=/, si num=3 operador=+, si num=4 operador=-. */
    int num; //Almacena un n�mero aleatorio del 1 al 4, en funci�n de este operador toma valor*/
    
        num = 1 + rand() % (4); //obtenemos el n�mero aleatorio
        
        switch (num){// para cada n�mero asignamos una operaci�n.
        	case 1:
        		operador='*';
        		break;
        		case 2:
        		operador='/';
        		break;
        		case 3:
        		operador='+';
        		break;
        		case 4:
        		operador='-';
        		break;
        }
        
    return operador; //Devolvemos el caracter que simboliza la operaci�n. 
	}



/** @brief Funci�n para realizar una operaci�n, pasando dos enteros y el s�mblo del operador.
*
*   En funci�n del s�mbolo del operador aplica una operaci�n matem�tica, a los dos n�meros pasados,
*
*   @param operacion tipo char con el s�mbolo de la operaci�n '+', '-', '*', o '/'.
*   @param numeroCinta tipo short segundo termino de la operaci�n.
*   @param cimaMonton tipo short primer termino de la operaci�n.
*   @return resultado un entero que representa el resultado final de la operaci�n cimaMonton[operacion]numeroCinta*/
short Juego::obtenerResultado(char operacion, short numeroCinta, short cimaMonton){
	/**Variables*/
	/**- resultado: almacena un entero con el resultado de la operaci�n*/
	short resultado=0;
	 switch(operacion){ //En funci�n del char pasado
               
                case('*'):{
                             //Realizamos la operaci�n multiplicaci�n
                             resultado=cimaMonton*numeroCinta;
                             break;
                             }
                case('/'):{
                             //Realizamos la operaci�n divisi�n
                             resultado=cimaMonton/numeroCinta;
                             break;
                             }
                case('-'):{
                             //Realizamos la operaci�n resta
                             resultado=cimaMonton-numeroCinta;
                             if (resultado<0){//Si es menor que cero
                             	//Convertimos a valor absoluto.
                             	resultado=-resultado;
                             }
                             break;
                             }
                case('+'):{
                             //Realizamos la operaci�n suma
                             resultado=cimaMonton+numeroCinta;
                             break;
                             }
           }
	return resultado;//devolvemos el resultado.
}


