/**
* @file principal.cpp
* @brief Implementa la clase Principal.
*/

#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <windows.h>
#include"principal.h"


/** @brief Constructor de la clase Principal. Crea elementos para el juego.
*
*   Inicializa las variables necesarias para el desarrollo del juego con los valores necesarios.
*
**/
Principal::Principal(){

valorReferencia=10;//la referencia para sacar y meter en un montón será 10 compararemos con 'resultado'
cantidadMontones=0;//inicialmente no hay cantidad de montones elegida
elementosPorMonton=0;//inicialmente no hay cantidad de elementos máximo por montón.
op=' '; //Almacena el símbolo de la operación, inicialmente no hay operación
avisoSistema=""; //Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa.
finJuego="fin del programa el jugador salió de la partida";//Avisa del fin del programa. inicial por el jugador cambiará según juego
opcion='0';//almacena la opción seleccionada por el usuario.Cero no hay opción.'s' salimos del programa
numeroCinta=0; //numero primero de la cinta, el que hay que introducir en los montones.0 no hay número sacado de la cinta.
cima=0;//Almacena el número que es cima del monton seleccionado. inicialmente no hay cima.
//resultado de la operacion entre el primero de la cinta y el último del montón/
resultado=0;//Almacena el resultado de la operación inicialmente 0.
montonSeleccionado=0;//inicialmente no hay ningún montón seleccionado, 0.
//Lista cinta;//Creamos una lista vacía para la cinta numérica.

};

/** @brief Método que permite al usuario elegir el número de montones que quiere para el juego.
*
*   - Modifica el valor de la variable 'cantidadMontones' y le asigna un valor entre 1 y 10
*
**/
void Principal::seleccionarNumeroDeMontones(){
	//Inicialmente 'cantidadMontones'=0
	//Mientras el valor no este entre 1 y 10 hacer:
	while(cantidadMontones<1||cantidadMontones>10)	{
	system("cls");
	cout<<"\n"<<avisoSistema<<"\n";//Se muestra información del proceso de entrada de datos
	cout<<"\n Eliga cuantos montones quiere para jugar de 1-10: ";

cin>>cantidadMontones; //leer la opción elegida y lo almacenamos en la variable 'cantidadMontones'

if(cin.fail())//Si la asignación falla se espera un número y el usuario introduce caracter no numérico
{
	cin.clear();//borra el indicador de error, para poder usarlo de nuevo
	string s;//almacena temporalmente el valor introducido por el usuario
	cin>>s;//Volcamos el valor que ocasionó el fallo a la variable s

	avisoSistema="!!!!!!! Error: se eperaba un número y se encontró "+s;//Almacenamos el origen del error para mostrarlo al usuario
	
}else{// no fallo la signación pero el usuario puso valor inferior a 1 o superior a 10
	if(cantidadMontones<1||cantidadMontones>10){//informamos con un nuevo mensaje fuera de rango
	avisoSistema="!!!!!!!! Error: Valor fuera de rango ";
}else{// no fallo la asignación y el número introducido era correcto, 
	avisoSistema=" ";//limpiamos el aviso del sistema para ocasiones futuras.
}
	
}

}

};



/** @brief Método que permite al usuario elegir el número máximo de elementos que pueden alcanzar los montones del juego.
*
*   - Modifica el valor de la variable 'elementosPorMonton' y le asigna un valor entre 4 y 15
*
**/

void Principal::seleccionarElementosPorMonton(){
	//Inicialmente 'elementosPorMonton'=0
	//Mientras el valor no este entre 4 y 10 hacer:
while (elementosPorMonton<4||elementosPorMonton>15){
	system("cls");
		cout<<"\n"<<avisoSistema<<"\n";//Se muestra información del proceso de entrada de datos
		cout<<"\n Eliga cuantos elementos para cada montón, (de 4 a 15) ";
		
cin>>elementosPorMonton; //leer la opción elegida y lo almacenamos en la variable opción

if(cin.fail())//Si la asignación falla se espera un número y el usuario introduce caracter no numérico
{
	cin.clear();//borra el indicador de error, para poder usarlo de nuevo
	string s;//almacena temporalmente el valor introducido por el usuario
	cin>>s;//Volcamos el valor que ocasionó el fallo a la variable s

	avisoSistema="!!!!!!! Error: se eperaba un número y se encontró "+s;//Almacenamos el origen del error para mostrarlo al usuario
	
     
}else{// no fallo la signación pero el usuario puso valor inferior a 4 o superior a 15
	if(elementosPorMonton<4||elementosPorMonton>15){
	avisoSistema="!!!!!!!! Error: Valor fuera de rango ";
}else{// no fallo la asignación y el número introducido era correcto, 
	avisoSistema=" ";//limpiamos el aviso del sistema para ocasiones futuras.
}
	
}


}

};



/** @brief Método para llenar la cinta numérica con cinco numeros naturales al azar.
*
*   - Modifica el valor de la variable 'cinta' añadiendo iterativamente por la izquierda 5 números.
*	- Usa el método lista.anadir_izq(short elemento)
*	- Usa el método juego.obtenerNumero() para obtener el número, 'elemento' a añadir (número entre 1 y 9) 
*
*	@see Lista
*	@see Juego
*
**/
void Principal::crearCintaNumerica(){

	//Para cada iteración añade un número a la lista
for (int i=1;i<6;i++){
        cinta.anadir_izq(Juego::obtenerNumero());//obtiene un número aleatorio y lo añade a la lista.
        }


};


/** @brief Método para llenar la lista de montones, listaM, con los diferentes montones del juego.
*
*   - Inicialmente listaM está vacía.
*	- En función de las variables 'cantidadMontones', 'elementosPorMonton' llena la listaMontones listaM.
*	- Usa el método listaMontones.crear_lista(short numero_de_montones, short elementos_monton)
*
*	@see listaMontones
*
**/
void Principal::crearListaMontones(){

	listaM.crear_lista(cantidadMontones, elementosPorMonton);


};

/** @brief Método para acceder al valor del atributo privado 'finJuego'.
*
*   - Lo usamos para acceder al motivo de finalización del juego desde el método main y mostrarlo al usuario.
*
*	@retval mensaje Texto con la información que contiene el atributo finJuego, motivo de finalización.
*
**/
string Principal::getFinJuego(){
	string mensaje=finJuego;
	return mensaje;

};


/** @brief Método que muestra y permite la selección de un número que representa la posción de un montón en la lista.
*
*   Iterativamente mediante un contador, se recorren las posiciones desde el número 1 hasta longitud de la listaM, (lista de los montones),
*   se van almacenando en un objeto Lista, (una lista auxiliar), las posiciones, (valor del contador), que tengan montones que NO estén vacíos,
*   montones elegibles.
*   Posteriormente e iterativamente hasta que el jugador presione un tecla, pasamos el valor de la longitud de la lista de posiciones elegibles,
*   a la función Juego::obtenerNumeroHasta(short n) está función nos devuelve un valor aleatorio 'c', una posición entre 1 y la longitud, 
*   pasamos ese valor a la función Lista.cogerElemento(short posicion) que nos devuelve el elemento que esta en esa posición 'c' de la lista auxiliar, 
*   y que es un número de montón o posición de la listaM, finalmente mostramos este valor por pantalla.
*
*	@retval b Un número que representa el montón seleccionado, una posición en la lista de montones.
*
**/
short Principal::dado(){

	short b=0;//variable para almacenar y mostrar solo las posiciones disponibles, la que tengan montones con elementos.
	Lista listavalidos;//lista auxiliar de naturales para almacenar posiciones validas, aquellas en las que los montones no estén vacíos.

	//Recorremos la lista de montones desde la posicion 1 hasta la longitud añadiendo en una lista auxiliar las posiciones de los
	//montones que no estén vacíos
	for (short i=1;i<listaM.Longitud()+1;i++){
		if(!listaM.comprueba_Monton_vacio(i)){//Si el monton de la posición 'i' no está vacío
		listavalidos.anadir_der(i);//añadimos la posición 'i' a la lista de posiciones validas.
		}
	}

	
	cout<<"\n   Montones Disponibles: ";
	listavalidos.imprimir();//Mostramos al usuario las posiciones de los montones que aun quedan disponibles.
	cout<<"\n";
	cout<<"\n   Pulsa una tecla para parar el dado \n";
	//char ch='1';
	while(!_kbhit ())//hasta que no se apriete un tecla realizamos la secuencia de mostrar números por pantalla
{
	

	short c = Juego::obtenerNumeroHasta(listavalidos.Longitud());//obtenemos una posición de la lista de montones validos 1 a longitud
	b=listavalidos.cogerElemento(c);//buscamos lo que hay en esa posición y almacenamos su valor en 'b'
	cout<<b<<" "<<"\r";//Mostramos por pantalla el valor de 'b'
	Sleep(60);//Tiempo de espera para comenzar de nuevo el bucle while.Velocidad del dado.

}//fin mientras hemos salido porque el usario pulso un tecla
	_getch();
	system("cls");
	return b;//Devolvemos el número del montón elegido valor que tenga b al salir del while.
}





/** @brief Método para interactuar con el usuario durante el juego, controla y almacana las E/S por teclado.
*
*   - Permite visualizar la cinta numérica y la lista de los montones
*	- Permite seleccionar las diferentes opciones del juego, elegir montón, elegir operación, salir.
*	- Permite elegir y almacenar un número que representa la posición de un montón, en la lista de montones. Solo posiciones con montones no vacíos.
*	- Permite introducir un caracter entre (+, -, *, /) para luego realizar operación. 
*	- Usa los métodos necesarios de la clase lista, para añadir un nuevo numero a la cinta anadir_der(short elemento),
*	  eliminar el primer elemento de la cinta resto() y acceder al primer elemento de la cinta inicial().
*	- Usa los métodos de la clase listaMontones necesarios para actuar sobre un montón determinado de la listaM: añadiendo un elemento, eliminando un elemento, 
*	  comprobando si esta vacio y averiguando su longitud. Comprueba si todos los montones de la 'listaM' están o no vacíos.
*	- Llama a los métodos de la clase juego, para realizar y obtener las operaciones.
*
**/
void Principal::menuPrincipal(){

/*Mientras la opción seleccionada no sea 's' se limpia la pantalla y de nuevo se muestra la situación actual 
   y valor actual de las variables oportunas. Mostrará situación actual de la cinta, de los montones, el monton
   elegido, la operación generada, un menú de opciones, y un mensaje de aviso para interactuar con el juego.*/
while (opcion != 's')
    {
    
   system ("cls"); //limpiamos la pantalla.

/*Cabecera presentación.*/
cout<<endl<<"                       |* NUMBERIS  -  PRACTICA2 *|                       "<<endl;
    
system("color 0B");//color del fondo y del texto de la consola.

numeroCinta=cinta.inicial(); //Almacenamos el el primer número de la cinta.

/*Mostramos por pantalla todos los elementos de la cinta, método mostrar() de la clase cola*/
cout<<" Cinta numérica: ";
cout<<"\n --------------\n";
/*Mostramos por pantalla el primer y el resto de números de la cinta, cola*/
	cout<<"   Primero: "<<numeroCinta
	<<"      Resto: ";cinta.imprimirResto(); //Mostramos el primer numero de la cinta.
	cout<<"\n";
	
	stringstream m;//variable para almacenar el valor del monton seleccionado y luego cnvertirlo a string
	m<<montonSeleccionado;//alamacenamos el valor del montón elegido.
    
	if (m.str()=="0"){//si es igual a string cero, caso inicial montonSeleccionado=0
	m.str().clear();//borramos el contenido de la cadena
	m.str("");//En lugar de mostrar "0" mostramos vacío el string para no representar un montón 0 por pantalla
    }

/*Mostramos información, con el menú, los valores seleccionados y generados para cada vez que el usuario 
seleccina una opción y pulsa intro. Se mostrará el montón elegido por el usuario y la operación que se genera*/
cout<<"\n=====================================================================\n";
cout<<"         OPERACION-> "<<op<<"     MONTON SELECCIONADO-> "+m.str()+"\n";
cout<<"=====================================================================\n";

            	
    /*Mostramos por pantalla el contenido de la lista de montones mediante el metodo imprimir() de la 
	   clase listaMontones*/
		listaM.imprimir();
 
	

/*Saca por pantalla las opciones del menú.  */
cout<<"\n     Opciones: \n";   
cout<<"     --------\n";
cout<<"     0- Generar la elección del montón "<<endl<<endl;   
cout<<"     1- Introducir la operación:"<<endl<<

"\n     s- Salir "<<endl;

/*Mostramos un aviso del sistema con otro color de fuente, verde*/
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
cout<<"Mensaje del Sistema: ";
SetConsoleTextAttribute(console, 10);/*Fuente de color verde para el siguiente cout<<*/
cout<<avisoSistema;//Mostrara el contenido de la variable para advertir de cualquier error.
SetConsoleTextAttribute(console, 11);/*volvemos a poner letras en azul claro*/
cout<<"\n Eliga una opción: ";
cin>>opcion; //leer la opción elegida y lo almacenamos en la variable opción
cin.ignore(10000,'\n');//ignoramos el resto del buffer





system("cls");//despues de leer la opción elegida limpiamos pantalla
system("color 0A");  //color del fondo y del texto de la consola.
	
	

/*En función del valor de opcion y de valores anteriores de las variables op y montonSeleccionado, 
seleccionaremos un montón, generaremos una operación o realizamos la operación
con primero de la cinta y la cima de un montón**/
    switch (opcion)
    {
    	/*Si opcion es '0', lanzamos la simulación del dado de 1 al numero de montones**/
    	case '0':{
    		
    	 if (!montonSeleccionado==0){//si la variable montonSeeleccionado es diferente a 0 ya hay un montón elegido
    	 avisoSistema="Ya hay un montón elegido no puede seleccionar otro.";
    	 }else{//si no hay monton seleccionado previamente es decir montonSeleccionado=0
    	//Elegimos un número de montón mediante la función dado()	
    	montonSeleccionado=dado();//Asignamos el resultado de la función dado a la variable montonSeleccionado.
		
		avisoSistema="Monton seleccionado, pulse 1 para elegir operación";//Actualizamos información del juego.
	
		}

    		
    	
			break;
			}
    		
    	/*Opciones para seleccionar una operación*/
    	
    	  /*opcion es igual a '1'*/
           case '1':{
           	if(montonSeleccionado==0){//Si no hay montón avisamos del error.
           		avisoSistema="Opción erronea ha de elegir un montón. Pulse la opción 0";
           		break;
           	}
           	
           	//Mientras no introduzca una operación correcta no salimos del while
           	while (op!='+' && op!='-' && op!='*' && op!='/'){
           			system("cls");//limpiamos pantalla y volvemos a pedir
           			cout<<"Introduzca una operación correcta (+,-,/,*): ";
           			cin>>op;//almacenamos la información en la variable op operación
           	}
           	
			
			//Una vez elegida operación actualizamos mensaje sistema.	
            avisoSistema="\n Montón elegido y operación creada.\nPulse una tecla diferente a: s, 1, 0, para continuar la partida.";
                break;
                
                }
         	
           
                /*opcion es igual a otro valor diferente de '0','1'*/
            	default:{
            		/*si no hay monton ni operación, montonSeleccionado, op, son cero o vacio respectivamente, salimos*/
                	if (montonSeleccionado==0 || op==' '){
                		avisoSistema="No hay montón seleccionado o una operación creada eliga otra opción";
                		
                		
                	}else{
                	/*Hay un montón seleccionado, montonSeleccionado es diferente de cero y una operación, op es diferente de ' '*/	
                	/*Para cada montón seleccionado, determinado por el valor montonSeleccionado, actuamos*/
                	stringstream s, c;//variable para hacer una posterior conversión de short a string e integrarlo en un string 
					s << montonSeleccionado;//almacenamos el valor del montoón seleccionado para mostrarlo en el avisoSistema

                	cima=listaM.buscar_cima_monton(montonSeleccionado);//Buscamos el último elemento del monton seleccionado y lo
                	//asignamos a la variable cima.

					c << numeroCinta;//almacenamos el valor del numeroCinta para mostrarlo en el avisoSistema
                	
					resultado=Juego::obtenerResultado(op,numeroCinta,cima);//Realizamos la operación con la cima del monton y el de la cinta
                		
					if (resultado<valorReferencia){//resultado es menor de 10
            					/*Quitamos el último elemento de la lista que se corresponde con el monton seleccionado */
            					listaM.sacar_de_monton(montonSeleccionado);
            					avisoSistema=" La cima del montón "+s.str()+" ha sido eliminada"; //informamos de la acción
            				}else{
            					/*En caso contrario añadimos el numero de la cinta por la parte derecha a la lista del montón seleccionado*/
            				    listaM.menter_en_monton(montonSeleccionado,numeroCinta);
            				    avisoSistema=" Se ha colocado el número "+c.str()+" en el monton "+s.str();//informamos de la acción
            				}

            		/*Una vez añadido o eliminado un elemento de un monton determinado*/
					/*Comprobamos si es montón ha llegado a su número máximo de elementos*/
            		if (listaM.longitud_del_monton(montonSeleccionado)==elementosPorMonton){
            			/*Al llegar al limite alamacenamos un mensje en la var finJuego*/	
            			finJuego="PERDISTE MONTON->"+s.str()+" ESTÁ LLENO ";
            			/*Provocamos la salida del while, asignando el valor 's' a la var opcion */
            				opcion='s';
            		}
                	
                	
            
        	/*Despues de actuar sobre un montón, comprobamos si todos los montones están ya vacios*/
            if(listaM.comprueba_todos_vacios())	{
						/*Al estar todos vacíos el juego se gana almacenamos el valor adecuado en la var finJuego*/
						finJuego="Ganaste el juego todos los montones vacios";
						/*Provocaremos la salida del while asignando el valor 's' a la opción*/
						opcion='s';
					}else{
						/*Si no están vacios reiniciamos las variables con los valores adecuados*/
						avisoSistema=avisoSistema+".\n Seleccione un montón para continuar jugando";
			            montonSeleccionado=0;
			            op=' ';
			            /*Actuamos sobre la cinta, quitando y poniendo número*/
			            /*Quitamos el primero de la cinta*/
			            cinta.resto();
			            /*Añadimos un nuevo numero a la cinta por el final.*/
			            cinta.anadir_der(Juego::obtenerNumero());
					}
            
            
          
            
        }
                }
     
    
}
           
      
    
    
   
               

    }




};