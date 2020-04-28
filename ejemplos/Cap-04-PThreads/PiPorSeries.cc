/*
  Calcula el numero PI utilizando una serie "infinita"
  Debe recibir la cantidad de iteraciones como parametro
  Version para PThreads

  pi = (-1)^i x 4/(2xi + 1)

*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#include "Mutex.h"

double Pi;		// Valor acumulado para Pi
long hilos = 10;	// Cantidad de hilos a ejecutar
long terminos = 100000;	// Cantidad de terminos a calcular
Mutex * mutex;

/*
   Realiza la acumulacion de terminos desde una posicion inicial hasta un termino final
*/
void * calcularSumaParcialPi( void * args ) {
   long id = (long) args;
   long inicio, final;
   double casiPi = 0;
   double alterna = 4;
   long divisor = 0;
   long termino;

   inicio = id * (terminos/hilos);
   final  = (id + 1) * (terminos/hilos);
   printf("Creating thread %ld : starting value %ld, finish at %ld\n", id, inicio, final - 1 );

   for ( termino = inicio; termino < final; termino++ ) {
      divisor = termino + termino + 1;		// 2 x termino + 1
      casiPi += alterna/divisor;		// 4 / (2xi + 1)
      alterna *= -1;				// Pasa de 4 a -4 y viceversa, para realizar la aproximacion de los terminos
   }

   mutex->Lock();
   Pi += casiPi;				// Acumula el resultado en la variable global y finaliza
   mutex->Unlock();

   pthread_exit( 0 );

}


int main( int argc, char ** argv ) {
   long hilo;
   int pid;
   pthread_t hilos[ 10 ];

   if ( argc > 1 ) {
      terminos = atol( argv[ 1 ] );
   }

   mutex = new Mutex();

   for ( hilo = 0; hilo < 10; hilo++ ) {
      pthread_create( & hilos[ hilo ], NULL, calcularSumaParcialPi, (void *) hilo );
   }

   for ( hilo = 0; hilo < 10; hilo++ ) {
      pthread_join( hilos[ hilo ], NULL );
   }

   printf( "Valor calculado de Pi es \033[91m %.15g \033[0m con %ld terminos\n", Pi, terminos );

   delete mutex;

}

