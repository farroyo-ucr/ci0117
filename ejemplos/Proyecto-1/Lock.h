/*  Esta clase encapsula las funciones para la utilizacion de semaforos
 *  Se provee las estructuras para realizar la sincronizacion de trabajadores
 *  a traves de los metodos tradicionales Signal (V), Wait (P)
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#ifndef _LOCK_H
#define _LOCK_H

#include "Mutex.h"

class Lock {
   public:
      Lock();
      ~Lock();
      int Acquire();
      int Release();
      Mutex * getLock();

   private:
      Mutex * lock;

};

#endif

