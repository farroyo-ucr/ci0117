/*
 *
 *  Esta clase representa al ascensor que da servicio a las personas
 *  El ascensor tiene reglas de comportamiento establecidas en el enunciado
 *     - No cambiar de sentido hasta estar vacio
 *     - Capacidad limitada: 10 personas
 *
 *  Author: Programacion Paralela y Concurrente
 *  Date: 2020/Abr/23
 *
 */

#include "Semaforo.h"

class Ascensor {
   public:
      Ascensor( long );
      ~Ascensor();
      void Display( char * );
      void Registrar( long, unsigned int, unsigned int );
      void Ejemplo();

   private:
      long idAscensor;
      unsigned int pisoActual;
      Semaforo * funcionar;
      unsigned int perso[ 128 ];
      unsigned int bajan[ 128 ];
      unsigned int suben[ 128 ];
      int sig;
};

