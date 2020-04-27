/* Esta clase encapsula las funciones para la utilizacion de semaforos
   en UNIX, se proveen metodos para realizar la sincronizacion de procesos
   a traves de los metodos tradicionales Signal, Wait
*/

#ifndef _SEM_H
#define _SEM_H

class Semaforo {
public:
   Semaforo( int n = 1 );
   ~Semaforo();
   void Signal();
   void Wait();

private:
   int id, nsems;
};

#endif

