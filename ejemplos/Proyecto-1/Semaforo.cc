/*  Esta clase encapsula las funciones para la utilizacion de semaforos
 *  Se provee las estructuras para realizar la sincronizacion de trabajadores
 *  a traves de los metodos tradicionales Signal (V), Wait (P)
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "Semaforo.h"

/*
 *  sem_init
 */
Semaforo::Semaforo( int inicial ) {
   int resultado;

   this->semId = (sem_t *) calloc( 1, sizeof( sem_t ) );
   resultado = sem_init( this->semId, 0, inicial );
   if ( -1 == resultado ) {
      perror( "Semaforo::Semaforo" );
      exit( 1 );
   }

}


/*
 *  sem_destroy
 */
Semaforo::~Semaforo() {
   int resultado;

   resultado = sem_destroy( this->semId );
   if ( -1 == resultado ) {
      perror( "Semaforo::Semaforo" );
      exit( 1 );
   }

   free( this->semId );

}


/*
 *  sem_post
 */
int Semaforo::Signal() {
   int resultado;

   resultado = sem_post( this->semId );

   if ( -1 == resultado ) {
      perror( "Semaforo::Signal" );
      exit( 1 );
   }
   return resultado;

}


/*
 *  sem_wait
 */
int Semaforo::Wait() {
   int resultado;

   resultado = sem_wait( this->semId );
   if ( -1 == resultado ) {
      perror( "Semaforo::Wait" );
      exit( 1 );
   }

   return resultado;

}


/*
 *  sem_trywait
 */
int Semaforo::tryWait() {
   int resultado;

   resultado = sem_trywait( this->semId );
   if ( -1 == resultado ) {
      perror( "Semaforo::tryWait" );
      exit( 1 );
   }

   return resultado;

}


/*
 *  sem_timedwait
 */
int Semaforo::timedWait( long sec, long nsec ) {
   int resultado;
   struct timespec lapso;

   lapso.tv_nsec = nsec;
   lapso.tv_sec = sec;
   resultado = sem_timedwait( this->semId, & lapso );
   if ( -1 == resultado ) {
      perror( "Semaforo::timedWait" );
      exit( 1 );
   }

   return resultado;

}

