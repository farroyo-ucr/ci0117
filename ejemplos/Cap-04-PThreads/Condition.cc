/*  Esta clase encapsula las funciones para la utilizacion de semaforos
 *  Se provee las estructuras para realizar la sincronizacion de trabajadores
 *  a traves de los metodos tradicionales Signal (V), Wait (P)
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#include "Condition.h"

/*
 * pthread_cond_init
 */
Condition::Condition() {
}


/*
 * pthread_cond_destroy
 */
Condition::~Condition() {
}


/*
 * pthread_cond_wait
 */
int Condition::Wait( Lock * conditionLock ) {
   return -1;
}


/*
 * pthread_cond_timedwait
 */
int Condition::TimedWait( Lock * conditionLock ) {
   return -1;
}


/*
 * pthread_cond_signal
 */
int Condition::Signal( Lock * conditionLock ) {
   return -1;
}


/*
 * pthread_cond_broadcast
 */
int Condition::Broadcast( Lock * conditionLock ) {
   return -1;
}

