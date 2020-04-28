/*  Esta clase encapsula las funciones para la utilizacion de semaforos
 *  Se provee las estructuras para realizar la sincronizacion de trabajadores
 *  a traves de los metodos tradicionales Signal (V), Wait (P)
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#include "Semaforo.h"

/*
 *  sem_init
 */
Semaforo::Semaforo( int inicial ) {
}


/*
 *  sem_destroy
 */
Semaforo::~Semaforo() {
}


/*
 *  sem_post
 */
int Semaforo::Signal() {
   return -1;
}


/*
 *  sem_wait
 */
int Semaforo::Wait() {
   return -1;
}


/*
 *  sem_trywait
 */
int Semaforo::tryWait() {
   return -1;
}


/*
 *  sem_timedwait
 */
int Semaforo::timedWait() {
   return -1;
}

