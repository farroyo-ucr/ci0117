# PThreads makefile example
#
# Author: CI0117 Programacion Paralela y Concurrente
# Date: 2020/Abr/23
#

HelloPT: HelloPT.c
	gcc -g HelloPT.c -o HelloPT -lpthread

Condition.o: Condition.cc Condition.h
	g++ -g -c Condition.cc

Lock.o: Lock.cc Lock.h
	g++ -g -c Lock.cc

Mutex.o: Mutex.cc Mutex.h
	g++ -g -c Mutex.cc

Semaforo.o: Semaforo.cc Semaforo.h
	g++ -g -c Semaforo.cc

PiPorSeries.o: PiPorSeries.cc Mutex.h
	g++ -g -c PiPorSeries.cc

PiPorSeries: PiPorSeries.o Mutex.o
	g++ -g PiPorSeries.o Mutex.o -o PiPorSeries -lpthread

SumaUno: SumaUno.c
	gcc -g SumaUno.c -o SumaUno

SumaUnoPT.o: SumaUnoPT.cc Mutex.h
	g++ -g -c SumaUnoPT.cc

SumaUnoPT: SumaUnoPT.o Mutex.o
	g++ -g SumaUnoPT.o Mutex.o -o SumaUnoPT -lpthread

