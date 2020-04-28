/*  Esta clase encapsula las funciones para la utilizacion de semaforos
 *  Se provee las estructuras para realizar la sincronizacion de trabajadores
 *  a traves de los metodos tradicionales Signal (V), Wait (P)
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/Abr/23
 */

#ifndef _COND_H
#define _COND_H

#include <pthread.h>
#include "Lock.h"

class Condition {

   public:
      Condition();
      ~Condition();
      int Wait( Lock * conditionLock );
      int TimedWait( Lock * conditionLock );
      int Signal( Lock * conditionLock );
      int Broadcast( Lock * conditionLock );

   private:
      pthread_cond_t * vc;

};

#endif

