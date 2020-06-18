

chrono.o: chrono.cc chrono.h
	g++ -g -c chrono.cc

hello.o: hello.c chrono.h
	g++ -g -c hello.c -fopenmp

hello.out:	hello.o chrono.o
	g++ -g -fopenmp chrono.o hello.o -o hello.out


