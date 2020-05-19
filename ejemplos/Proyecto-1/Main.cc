/*
 * Esqueleto para el problema del ascensor utilizando PThreads
 * Tenemos el metodo principal encargado de la generacion de los hilos
 * Arrancamos con un hilo para simular el comportamiento del ascensor
 * y oleadas de personas que lo utilizan
 *
 * Author: Programacion Concurrente (Francisco Arroyo)
 * Version: 2020/Abr/23
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#include "Ascensor.h"
#include "Persona.h"


// Shared variables
   Ascensor ** ascensores;


/*
 *  Rutina que ejecutan los hilos ascensor
 *  
 */
void * hiloAscensor( void * param ) {
   long identificacion;
   char  * rotulo;

   identificacion = (long) param;
   rotulo = (char *) calloc( 64, 1 );

   ascensores[ identificacion ] = new Ascensor( identificacion );
//
// Avisar que el ascensor ya esta en funcionamiento (Condition: Broadcast)
// (forks)
//
   ascensores[ identificacion ]->Display( rotulo );
   printf( "%s", rotulo );
   ascensores[ identificacion ]->Ejemplo();

   delete ascensores[ identificacion ];

   free( rotulo );

   return NULL;

}


/*
 *  Rutina que crea los ascensores del edificio, en el caso de esta tarea solo 1
 *  Cada ascensor es representado por un hilo
 */
void Ascensores( long cantidad ) {
   long hilo;
   pthread_t * ascensores;

   ascensores = (pthread_t *) calloc( cantidad, sizeof( pthread_t ) );

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_create( & ascensores[ hilo ], NULL, hiloAscensor, (void *) hilo );
   }

//   for ( hilo = 0; hilo < cantidad; hilo++ ) {
//      pthread_join( ascensores[ hilo ], NULL );
//   }

   free( ascensores );

}


void * hiloPersona( void * param ) {
   Persona * persona;
   char  * rotulo;
   long identificacion;

   identificacion = (long) param;
   persona = new Persona( identificacion );

   // Espera por el ascensor
   // Indicar cuales son los pisos que necesita -> ascensor
   // Espera hasta que el ascensor llegue
   // Montarme (campo?)
   // Esperar por el piso donde me bajo
   // Bajarme del ascensor

   rotulo = (char *) calloc( 64, 1 );
   persona->Display( rotulo );
   printf( "%s", rotulo );
   ascensores[ 0 ]->Registrar( identificacion, persona->getPisoDondeMeSubo(), persona->getPisoDondeMeBajo() );
   free( rotulo );

   delete persona;

   return NULL;

}


/*
 *  Rutina que simula las oleadas de personas para uso del ascensor
 *  Las personas son generadas como hilos
 *
 */
void Personas( long cantidad ) {
   long hilo;
   pthread_t * personas;

   personas = (pthread_t *) calloc( cantidad, sizeof( pthread_t ) );

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_create( & personas[ hilo ], NULL, hiloPersona, (void *) hilo );
   }

   for ( hilo = 0; hilo < cantidad; hilo++ ) {
      pthread_join( personas[ hilo ], NULL );
   }

   free( personas );

}


/*
 *  Rutina principal para la creacion de los ascensores y las personas
 *  Restricciones de este proyecto programado
 *     - Solo un ascensor
 *
 */
int main( int argc, char ** argv ) {
   long hilos;
   clock_t start, finish;
   double used;

   ascensores = (Ascensor **) calloc( 10, sizeof( Ascensor * ) );
   srand( time( NULL ) );	// Puede poner esta linea en comentarios para generar una misma secuencia de numeros
   Ascensores( 1 );
   Personas( 50 );	// Primera oleada

   sleep( 2 );

   Personas( 40 );	// Segunda oleada

   free( ascensores );
}

