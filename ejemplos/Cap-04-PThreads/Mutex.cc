/*  Implantacion de la clase Mutex utilizando PThreads
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#include <stdlib.h>
#include <pthread.h>

#include "Mutex.h"

Mutex::Mutex() {
   int resultado;
   pthread_mutexattr_t * atributos;

   resultado = pthread_mutex_init( mutex, NULL );
   if ( 0 != resultado ) {
      exit( resultado );
   }

}


Mutex::~Mutex() {
   int resultado;

   resultado = pthread_mutex_destroy( mutex );
   if ( 0 != resultado ) {
      exit( resultado );
   }
}

void Mutex::Lock() {
   int resultado;

   resultado = pthread_mutex_lock( mutex );
   if ( 0 != resultado ) {
      exit( resultado );
   }

}

void Mutex::TryLock() {
   int resultado;

   resultado = pthread_mutex_trylock( mutex );
   if ( 0 != resultado ) {
      exit( resultado );
   }

}
void Mutex::Unlock() {
   int resultado;

   resultado = pthread_mutex_unlock( mutex );
   if ( 0 != resultado ) {
      exit( resultado );
   }

}

