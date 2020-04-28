# Programming assignement makefile example
#
# Author: CI0117 Programacion Paralela y Concurrente
# Date: 2020/Abr/23
#

Mutex.o: Mutex.cc Mutex.h
	g++ -g -c Mutex.cc

Ascensor.o: Ascensor.cc Ascensor.h
	g++ -g -c Ascensor.cc

Persona.o: Persona.cc Persona.h
	g++ -g -c Persona.cc

Main.o: Main.cc Ascensor.h Persona.h
	g++ -g -c Main.cc

Main: Main.o Persona.o Ascensor.o
	g++ -g Main.o Persona.o Ascensor.o -o Main -lpthread

