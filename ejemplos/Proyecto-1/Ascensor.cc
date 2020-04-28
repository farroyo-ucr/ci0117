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

}

Ascensor::~Ascensor() {
}

void Ascensor::Display( char * rotulo ) {

   sprintf( rotulo, "Ascensor: %d, piso actual %d \n", this->idAscensor, this->pisoActual );

}

