# Compila la version sin clases de enviar
enviarSinClases: enviarSinClases.c
	gcc enviarSinClases.c -g -o enviarSinClases

# Compila la version sin clases de recibir
recibirSinClases: t0-recibe.c
	gcc recibirSinClases.c -g -o recibirSinClases

# Compila la clase Buzon
Buzon.o: Buzon.h Buzon.cc
	g++ -g -c Buzon.cc

# Enlaza los archivos t0-envia y Buzon para crear el ejecutable
# Compila la version con clases de enviar
enviarConClases.o: enviarConClases.cc Buzon.h
	g++ -g -c enviarConClases.cc

enviarConClases: t0-envia.o Buzon.o
	g++ enviarConClases Buzon.o -o enviarConClases

# Enlaza los archivos t0-recibe y Buzon para crear el ejecutable
recibirConClases: recibirConClases.o Buzon.o
	g++ recibirConClases.o Buzon.o -o recibirConClases

pruebaSem: pruebaSem.o Semaphore.o
	g++ -g pruebaSem.o Semaphore.o -o pruebaSem

pruebaSem.o: pruebaSem.cc
	g++ -c -g pruebaSem.cc

Semaphore.o: Semaphore.cc Semaphore.h
	g++ -c -g Semaphore.cc

