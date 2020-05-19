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

   this->lock = new Mutex();

}


/*
 *
 */
Lock::~Lock() {

   delete this->lock;

}


/*
 *
 */
int Lock::Acquire() {

   return this->lock->Lock();

}


/*
 *
 */
int Lock::Release() {

   return this->lock->Unlock();

}

/*
 *
 */
Mutex * Lock::getLock() {

   return this->lock;

}

