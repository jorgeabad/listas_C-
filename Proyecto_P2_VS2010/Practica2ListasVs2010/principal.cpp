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

valorReferencia=10;//la referencia para sacar y meter en un mont�n ser� 10 compararemos con 'resultado'
cantidadMontones=0;//inicialmente no hay cantidad de montones elegida
elementosPorMonton=0;//inicialmente no hay cantidad de elementos m�ximo por mont�n.
op=' '; //Almacena el s�mbolo de la operaci�n, inicialmente no hay operaci�n
avisoSistema=""; //Almacena cualquier aviso de error o advertencia, para el usuario al interactuar con el programa.
finJuego="fin del programa el jugador sali� de la partida";//Avisa del fin del programa. inicial por el jugador cambiar� seg�n juego
opcion='0';//almacena la opci�n seleccionada por el usuario.Cero no hay opci�n.'s' salimos del programa
numeroCinta=0; //numero primero de la cinta, el que hay que introducir en los montones.0 no hay n�mero sacado de la cinta.
cima=0;//Almacena el n�mero que es cima del monton seleccionado. inicialmente no hay cima.
//resultado de la operacion entre el primero de la cinta y el �ltimo del mont�n/
resultado=0;//Almacena el resultado de la operaci�n inicialmente 0.
montonSeleccionado=0;//inicialmente no hay ning�n mont�n seleccionado, 0.
//Lista cinta;//Creamos una lista vac�a para la cinta num�rica.

};

/** @brief M�todo que permite al usuario elegir el n�mero de montones que quiere para el juego.
*
*   - Modifica el valor de la variable 'cantidadMontones' y le asigna un valor entre 1 y 10
*
**/
void Principal::seleccionarNumeroDeMontones(){
	//Inicialmente 'cantidadMontones'=0
	//Mientras el valor no este entre 1 y 10 hacer:
	while(cantidadMontones<1||cantidadMontones>10)	{
	system("cls");
	cout<<"\n"<<avisoSistema<<"\n";//Se muestra informaci�n del proceso de entrada de datos
	cout<<"\n Eliga cuantos montones quiere para jugar de 1-10: ";

cin>>cantidadMontones; //leer la opci�n elegida y lo almacenamos en la variable 'cantidadMontones'

if(cin.fail())//Si la asignaci�n falla se espera un n�mero y el usuario introduce caracter no num�rico
{
	cin.clear();//borra el indicador de error, para poder usarlo de nuevo
	string s;//almacena temporalmente el valor introducido por el usuario
	cin>>s;//Volcamos el valor que ocasion� el fallo a la variable s

	avisoSistema="!!!!!!! Error: se eperaba un n�mero y se encontr� "+s;//Almacenamos el origen del error para mostrarlo al usuario
	
}else{// no fallo la signaci�n pero el usuario puso valor inferior a 1 o superior a 10
	if(cantidadMontones<1||cantidadMontones>10){//informamos con un nuevo mensaje fuera de rango
	avisoSistema="!!!!!!!! Error: Valor fuera de rango ";
}else{// no fallo la asignaci�n y el n�mero introducido era correcto, 
	avisoSistema=" ";//limpiamos el aviso del sistema para ocasiones futuras.
}
	
}

}

};



/** @brief M�todo que permite al usuario elegir el n�mero m�ximo de elementos que pueden alcanzar los montones del juego.
*
*   - Modifica el valor de la variable 'elementosPorMonton' y le asigna un valor entre 4 y 15
*
**/

void Principal::seleccionarElementosPorMonton(){
	//Inicialmente 'elementosPorMonton'=0
	//Mientras el valor no este entre 4 y 10 hacer:
while (elementosPorMonton<4||elementosPorMonton>15){
	system("cls");
		cout<<"\n"<<avisoSistema<<"\n";//Se muestra informaci�n del proceso de entrada de datos
		cout<<"\n Eliga cuantos elementos para cada mont�n, (de 4 a 15) ";
		
cin>>elementosPorMonton; //leer la opci�n elegida y lo almacenamos en la variable opci�n

if(cin.fail())//Si la asignaci�n falla se espera un n�mero y el usuario introduce caracter no num�rico
{
	cin.clear();//borra el indicador de error, para poder usarlo de nuevo
	string s;//almacena temporalmente el valor introducido por el usuario
	cin>>s;//Volcamos el valor que ocasion� el fallo a la variable s

	avisoSistema="!!!!!!! Error: se eperaba un n�mero y se encontr� "+s;//Almacenamos el origen del error para mostrarlo al usuario
	
     
}else{// no fallo la signaci�n pero el usuario puso valor inferior a 4 o superior a 15
	if(elementosPorMonton<4||elementosPorMonton>15){
	avisoSistema="!!!!!!!! Error: Valor fuera de rango ";
}else{// no fallo la asignaci�n y el n�mero introducido era correcto, 
	avisoSistema=" ";//limpiamos el aviso del sistema para ocasiones futuras.
}
	
}


}

};



/** @brief M�todo para llenar la cinta num�rica con cinco numeros naturales al azar.
*
*   - Modifica el valor de la variable 'cinta' a�adiendo iterativamente por la izquierda 5 n�meros.
*	- Usa el m�todo lista.anadir_izq(short elemento)
*	- Usa el m�todo juego.obtenerNumero() para obtener el n�mero, 'elemento' a a�adir (n�mero entre 1 y 9) 
*
*	@see Lista
*	@see Juego
*
**/
void Principal::crearCintaNumerica(){

	//Para cada iteraci�n a�ade un n�mero a la lista
for (int i=1;i<6;i++){
        cinta.anadir_izq(Juego::obtenerNumero());//obtiene un n�mero aleatorio y lo a�ade a la lista.
        }


};


/** @brief M�todo para llenar la lista de montones, listaM, con los diferentes montones del juego.
*
*   - Inicialmente listaM est� vac�a.
*	- En funci�n de las variables 'cantidadMontones', 'elementosPorMonton' llena la listaMontones listaM.
*	- Usa el m�todo listaMontones.crear_lista(short numero_de_montones, short elementos_monton)
*
*	@see listaMontones
*
**/
void Principal::crearListaMontones(){

	listaM.crear_lista(cantidadMontones, elementosPorMonton);


};

/** @brief M�todo para acceder al valor del atributo privado 'finJuego'.
*
*   - Lo usamos para acceder al motivo de finalizaci�n del juego desde el m�todo main y mostrarlo al usuario.
*
*	@retval mensaje Texto con la informaci�n que contiene el atributo finJuego, motivo de finalizaci�n.
*
**/
string Principal::getFinJuego(){
	string mensaje=finJuego;
	return mensaje;

};


/** @brief M�todo que muestra y permite la selecci�n de un n�mero que representa la posci�n de un mont�n en la lista.
*
*   Iterativamente mediante un contador, se recorren las posiciones desde el n�mero 1 hasta longitud de la listaM, (lista de los montones),
*   se van almacenando en un objeto Lista, (una lista auxiliar), las posiciones, (valor del contador), que tengan montones que NO est�n vac�os,
*   montones elegibles.
*   Posteriormente e iterativamente hasta que el jugador presione un tecla, pasamos el valor de la longitud de la lista de posiciones elegibles,
*   a la funci�n Juego::obtenerNumeroHasta(short n) est� funci�n nos devuelve un valor aleatorio 'c', una posici�n entre 1 y la longitud, 
*   pasamos ese valor a la funci�n Lista.cogerElemento(short posicion) que nos devuelve el elemento que esta en esa posici�n 'c' de la lista auxiliar, 
*   y que es un n�mero de mont�n o posici�n de la listaM, finalmente mostramos este valor por pantalla.
*
*	@retval b Un n�mero que representa el mont�n seleccionado, una posici�n en la lista de montones.
*
**/
short Principal::dado(){

	short b=0;//variable para almacenar y mostrar solo las posiciones disponibles, la que tengan montones con elementos.
	Lista listavalidos;//lista auxiliar de naturales para almacenar posiciones validas, aquellas en las que los montones no est�n vac�os.

	//Recorremos la lista de montones desde la posicion 1 hasta la longitud a�adiendo en una lista auxiliar las posiciones de los
	//montones que no est�n vac�os
	for (short i=1;i<listaM.Longitud()+1;i++){
		if(!listaM.comprueba_Monton_vacio(i)){//Si el monton de la posici�n 'i' no est� vac�o
		listavalidos.anadir_der(i);//a�adimos la posici�n 'i' a la lista de posiciones validas.
		}
	}

	
	cout<<"\n   Montones Disponibles: ";
	listavalidos.imprimir();//Mostramos al usuario las posiciones de los montones que aun quedan disponibles.
	cout<<"\n";
	cout<<"\n   Pulsa una tecla para parar el dado \n";
	//char ch='1';
	while(!_kbhit ())//hasta que no se apriete un tecla realizamos la secuencia de mostrar n�meros por pantalla
{
	

	short c = Juego::obtenerNumeroHasta(listavalidos.Longitud());//obtenemos una posici�n de la lista de montones validos 1 a longitud
	b=listavalidos.cogerElemento(c);//buscamos lo que hay en esa posici�n y almacenamos su valor en 'b'
	cout<<b<<" "<<"\r";//Mostramos por pantalla el valor de 'b'
	Sleep(60);//Tiempo de espera para comenzar de nuevo el bucle while.Velocidad del dado.

}//fin mientras hemos salido porque el usario pulso un tecla
	_getch();
	system("cls");
	return b;//Devolvemos el n�mero del mont�n elegido valor que tenga b al salir del while.
}





/** @brief M�todo para interactuar con el usuario durante el juego, controla y almacana las E/S por teclado.
*
*   - Permite visualizar la cinta num�rica y la lista de los montones
*	- Permite seleccionar las diferentes opciones del juego, elegir mont�n, elegir operaci�n, salir.
*	- Permite elegir y almacenar un n�mero que representa la posici�n de un mont�n, en la lista de montones. Solo posiciones con montones no vac�os.
*	- Permite introducir un caracter entre (+, -, *, /) para luego realizar operaci�n. 
*	- Usa los m�todos necesarios de la clase lista, para a�adir un nuevo numero a la cinta anadir_der(short elemento),
*	  eliminar el primer elemento de la cinta resto() y acceder al primer elemento de la cinta inicial().
*	- Usa los m�todos de la clase listaMontones necesarios para actuar sobre un mont�n determinado de la listaM: a�adiendo un elemento, eliminando un elemento, 
*	  comprobando si esta vacio y averiguando su longitud. Comprueba si todos los montones de la 'listaM' est�n o no vac�os.
*	- Llama a los m�todos de la clase juego, para realizar y obtener las operaciones.
*
**/
void Principal::menuPrincipal(){

/*Mientras la opci�n seleccionada no sea 's' se limpia la pantalla y de nuevo se muestra la situaci�n actual 
   y valor actual de las variables oportunas. Mostrar� situaci�n actual de la cinta, de los montones, el monton
   elegido, la operaci�n generada, un men� de opciones, y un mensaje de aviso para interactuar con el juego.*/
while (opcion != 's')
    {
    
   system ("cls"); //limpiamos la pantalla.

/*Cabecera presentaci�n.*/
cout<<endl<<"                       |* NUMBERIS  -  PRACTICA2 *|                       "<<endl;
    
system("color 0B");//color del fondo y del texto de la consola.

numeroCinta=cinta.inicial(); //Almacenamos el el primer n�mero de la cinta.

/*Mostramos por pantalla todos los elementos de la cinta, m�todo mostrar() de la clase cola*/
cout<<" Cinta num�rica: ";
cout<<"\n --------------\n";
/*Mostramos por pantalla el primer y el resto de n�meros de la cinta, cola*/
	cout<<"   Primero: "<<numeroCinta
	<<"      Resto: ";cinta.imprimirResto(); //Mostramos el primer numero de la cinta.
	cout<<"\n";
	
	stringstream m;//variable para almacenar el valor del monton seleccionado y luego cnvertirlo a string
	m<<montonSeleccionado;//alamacenamos el valor del mont�n elegido.
    
	if (m.str()=="0"){//si es igual a string cero, caso inicial montonSeleccionado=0
	m.str().clear();//borramos el contenido de la cadena
	m.str("");//En lugar de mostrar "0" mostramos vac�o el string para no representar un mont�n 0 por pantalla
    }

/*Mostramos informaci�n, con el men�, los valores seleccionados y generados para cada vez que el usuario 
seleccina una opci�n y pulsa intro. Se mostrar� el mont�n elegido por el usuario y la operaci�n que se genera*/
cout<<"\n=====================================================================\n";
cout<<"         OPERACION-> "<<op<<"     MONTON SELECCIONADO-> "+m.str()+"\n";
cout<<"=====================================================================\n";

            	
    /*Mostramos por pantalla el contenido de la lista de montones mediante el metodo imprimir() de la 
	   clase listaMontones*/
		listaM.imprimir();
 
	

/*Saca por pantalla las opciones del men�.  */
cout<<"\n     Opciones: \n";   
cout<<"     --------\n";
cout<<"     0- Generar la elecci�n del mont�n "<<endl<<endl;   
cout<<"     1- Introducir la operaci�n:"<<endl<<

"\n     s- Salir "<<endl;

/*Mostramos un aviso del sistema con otro color de fuente, verde*/
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
cout<<"Mensaje del Sistema: ";
SetConsoleTextAttribute(console, 10);/*Fuente de color verde para el siguiente cout<<*/
cout<<avisoSistema;//Mostrara el contenido de la variable para advertir de cualquier error.
SetConsoleTextAttribute(console, 11);/*volvemos a poner letras en azul claro*/
cout<<"\n Eliga una opci�n: ";
cin>>opcion; //leer la opci�n elegida y lo almacenamos en la variable opci�n
cin.ignore(10000,'\n');//ignoramos el resto del buffer





system("cls");//despues de leer la opci�n elegida limpiamos pantalla
system("color 0A");  //color del fondo y del texto de la consola.
	
	

/*En funci�n del valor de opcion y de valores anteriores de las variables op y montonSeleccionado, 
seleccionaremos un mont�n, generaremos una operaci�n o realizamos la operaci�n
con primero de la cinta y la cima de un mont�n**/
    switch (opcion)
    {
    	/*Si opcion es '0', lanzamos la simulaci�n del dado de 1 al numero de montones**/
    	case '0':{
    		
    	 if (!montonSeleccionado==0){//si la variable montonSeeleccionado es diferente a 0 ya hay un mont�n elegido
    	 avisoSistema="Ya hay un mont�n elegido no puede seleccionar otro.";
    	 }else{//si no hay monton seleccionado previamente es decir montonSeleccionado=0
    	//Elegimos un n�mero de mont�n mediante la funci�n dado()	
    	montonSeleccionado=dado();//Asignamos el resultado de la funci�n dado a la variable montonSeleccionado.
		
		avisoSistema="Monton seleccionado, pulse 1 para elegir operaci�n";//Actualizamos informaci�n del juego.
	
		}

    		
    	
			break;
			}
    		
    	/*Opciones para seleccionar una operaci�n*/
    	
    	  /*opcion es igual a '1'*/
           case '1':{
           	if(montonSeleccionado==0){//Si no hay mont�n avisamos del error.
           		avisoSistema="Opci�n erronea ha de elegir un mont�n. Pulse la opci�n 0";
           		break;
           	}
           	
           	//Mientras no introduzca una operaci�n correcta no salimos del while
           	while (op!='+' && op!='-' && op!='*' && op!='/'){
           			system("cls");//limpiamos pantalla y volvemos a pedir
           			cout<<"Introduzca una operaci�n correcta (+,-,/,*): ";
           			cin>>op;//almacenamos la informaci�n en la variable op operaci�n
           	}
           	
			
			//Una vez elegida operaci�n actualizamos mensaje sistema.	
            avisoSistema="\n Mont�n elegido y operaci�n creada.\nPulse una tecla diferente a: s, 1, 0, para continuar la partida.";
                break;
                
                }
         	
           
                /*opcion es igual a otro valor diferente de '0','1'*/
            	default:{
            		/*si no hay monton ni operaci�n, montonSeleccionado, op, son cero o vacio respectivamente, salimos*/
                	if (montonSeleccionado==0 || op==' '){
                		avisoSistema="No hay mont�n seleccionado o una operaci�n creada eliga otra opci�n";
                		
                		
                	}else{
                	/*Hay un mont�n seleccionado, montonSeleccionado es diferente de cero y una operaci�n, op es diferente de ' '*/	
                	/*Para cada mont�n seleccionado, determinado por el valor montonSeleccionado, actuamos*/
                	stringstream s, c;//variable para hacer una posterior conversi�n de short a string e integrarlo en un string 
					s << montonSeleccionado;//almacenamos el valor del monto�n seleccionado para mostrarlo en el avisoSistema

                	cima=listaM.buscar_cima_monton(montonSeleccionado);//Buscamos el �ltimo elemento del monton seleccionado y lo
                	//asignamos a la variable cima.

					c << numeroCinta;//almacenamos el valor del numeroCinta para mostrarlo en el avisoSistema
                	
					resultado=Juego::obtenerResultado(op,numeroCinta,cima);//Realizamos la operaci�n con la cima del monton y el de la cinta
                		
					if (resultado<valorReferencia){//resultado es menor de 10
            					/*Quitamos el �ltimo elemento de la lista que se corresponde con el monton seleccionado */
            					listaM.sacar_de_monton(montonSeleccionado);
            					avisoSistema=" La cima del mont�n "+s.str()+" ha sido eliminada"; //informamos de la acci�n
            				}else{
            					/*En caso contrario a�adimos el numero de la cinta por la parte derecha a la lista del mont�n seleccionado*/
            				    listaM.menter_en_monton(montonSeleccionado,numeroCinta);
            				    avisoSistema=" Se ha colocado el n�mero "+c.str()+" en el monton "+s.str();//informamos de la acci�n
            				}

            		/*Una vez a�adido o eliminado un elemento de un monton determinado*/
					/*Comprobamos si es mont�n ha llegado a su n�mero m�ximo de elementos*/
            		if (listaM.longitud_del_monton(montonSeleccionado)==elementosPorMonton){
            			/*Al llegar al limite alamacenamos un mensje en la var finJuego*/	
            			finJuego="PERDISTE MONTON->"+s.str()+" EST� LLENO ";
            			/*Provocamos la salida del while, asignando el valor 's' a la var opcion */
            				opcion='s';
            		}
                	
                	
            
        	/*Despues de actuar sobre un mont�n, comprobamos si todos los montones est�n ya vacios*/
            if(listaM.comprueba_todos_vacios())	{
						/*Al estar todos vac�os el juego se gana almacenamos el valor adecuado en la var finJuego*/
						finJuego="Ganaste el juego todos los montones vacios";
						/*Provocaremos la salida del while asignando el valor 's' a la opci�n*/
						opcion='s';
					}else{
						/*Si no est�n vacios reiniciamos las variables con los valores adecuados*/
						avisoSistema=avisoSistema+".\n Seleccione un mont�n para continuar jugando";
			            montonSeleccionado=0;
			            op=' ';
			            /*Actuamos sobre la cinta, quitando y poniendo n�mero*/
			            /*Quitamos el primero de la cinta*/
			            cinta.resto();
			            /*A�adimos un nuevo numero a la cinta por el final.*/
			            cinta.anadir_der(Juego::obtenerNumero());
					}
            
            
          
            
        }
                }
     
    
}
           
      
    
    
   
               

    }




};