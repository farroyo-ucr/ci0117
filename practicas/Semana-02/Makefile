# CI0117 Programación Paralela y Concurrente
# 2020-i
#

# Enlaza los archivos objeto y genera el archivo ejecutable
enviarConClases: enviarConClases.o Buzon.o
	g++ -g enviarConClases.o Buzon.o -o enviarConClases

# Genera el archivo objeto a partir del fuente de enviarConClases
enviarConClases.o: enviarConClases.cc Buzon.h
	g++ -g -c enviarConClases.cc

# Genera el archivo objecto a partir del fuente Buzon
Buzon.o: Buzon.h Buzon.cc
	g++ -g -c Buzon.cc

# Enlazar los archivos objeto y genera el archivo ejecutable
recibirConClases: recibirConClases.o Buzon.o
	g++ -g recibirConClases.o Buzon.o -a recibirConClases

# Genera el archivo objeto a partir del fuente de recibirConClases
recibirConClase.o: recibirConClases.cc Buzon.h
	g++ -g -c recibirConClases.cc

# Compila la version sin clases
enviarSinClases: enviarSinClases.c
	gcc -g enviarSinClases.c -o enviarSinClases

recibirSinClases: recibirSinClases.c
	gcc -g recibirSinClases.c -o recibirSinClases

