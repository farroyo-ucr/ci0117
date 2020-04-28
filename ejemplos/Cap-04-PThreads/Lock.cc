/*  Esta clase encapsula las funciones para la utilizacion de semaforos
 *  Se provee las estructuras para realizar la sincronizacion de trabajadores
 *  a traves de los metodos tradicionales Signal (V), Wait (P)
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#include "Lock.h"


/*
 *
 */
Lock::Lock() {
}


/*
 *
 */
Lock::~Lock() {
}


/*
 *
 */
int Lock::Acquire() {
   return -1;
}


/*
 *
 */
int Lock::Release() {
   return -1;
}

/*
 *
 */
pthread_mutex_t * Lock::getLock() {

   return this->lock;

}

