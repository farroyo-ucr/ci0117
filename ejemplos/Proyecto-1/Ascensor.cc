/*
 *
 *  Esta clase representa al ascensor que da servicio a las personas
 *  Las instancias inicial en el primer piso
 *
 *  Author: Programacion Paralela y Concurrente
 *  Date: 2020/Abr/23
 *
 */

#include <stdio.h>

#include "Ascensor.h"

/*
 *
 */
Ascensor::Ascensor( long identificador ) {

   this->idAscensor = identificador;
   this->pisoActual = 1;
   this->funcionar = new Semaforo( 0 );
   this->sig = 0;

}

Ascensor::~Ascensor() {

   delete this->funcionar;

}

void Ascensor::Display( char * rotulo ) {

   sprintf( rotulo, "Ascensor: %d, piso actual %d \n", this->idAscensor, this->pisoActual );

}


void Ascensor::Registrar( long idPersona, unsigned int pisoDondeSube, unsigned int pisoDondeBaja ) {

   this->funcionar->Signal();	// Despierta al ascensor
   printf( "Ascensor: tenemos una solicitud de la persona %ld para ir del piso %d al piso %d\n", idPersona, pisoDondeSube, pisoDondeBaja );
   this->perso[ sig   ] = idPersona;
   this->bajan[ sig   ] = pisoDondeBaja;
   this->suben[ sig++ ] = pisoDondeSube;
}


void Ascensor::Ejemplo() {
   int i;

   i = 0;
   do {
      this->funcionar->Wait();	// Espera por solicitudes de las personas
      for ( ; i < sig; i++ ) {
         printf( "Lista[ %d ] persona[ %d ]: ( %d -> %d ) \n", i, this->perso[ i ], this->suben[ i ], this->bajan[ i ] );
      }
   } while ( true );

}

