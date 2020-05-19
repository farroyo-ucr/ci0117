# Programming assignement makefile example
#
# Author: CI0117 Programacion Paralela y Concurrente
# Date: 2020/Abr/23
#

Mutex.o: Mutex.cc Mutex.h
	g++ -g -c Mutex.cc

Semaforo.o: Semaforo.cc Semaforo.h
	g++ -g -c Semaforo.cc

Ascensor.o: Ascensor.cc Ascensor.h
	g++ -g -c Ascensor.cc

Persona.o: Persona.cc Persona.h
	g++ -g -c Persona.cc

Main.o: Main.cc Ascensor.h Persona.h Semaforo.h
	g++ -g -c Main.cc

Main: Main.o Persona.o Ascensor.o Semaforo.o 
	g++ -g Main.o Persona.o Ascensor.o Semaforo.o -o Main -lpthread

clean:
	rm -f *.o

