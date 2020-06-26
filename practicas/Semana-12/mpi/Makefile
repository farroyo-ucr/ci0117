################################################################################
#  Universidad de Costa Rica
#  Escuela de Ciencias de la Computación e Informática (ECCI)
#  CI0117 Programación paralela y concurrente
#
#  Makefile para fuentes MPI
#  Fecha: 2020/Jun/26
#  Autor: Francisco Arroyo
################################################################################

PATH := /usr/lib64/mpi/bin/:$(PATH)

CC       = mpicc
CPP	= mpic++
OBJ     = o
EXE	= out
RUN     =

CCFLAGS  = -g
CPPFLAG	=
ACCFLAGS = 

all: build run verify

%: %.cc
	%(CPP) $(CPPFLAGS) $< -o $@.$(EXE)

%: %.c 
	$(CC) $(CCFLAGS) $< -o $@.$(EXE)
	
build:

run: $2.$(EXE)
	$(RUN) ./.$*.$(EXE)

verify:

clean:
	@echo 'Cleaning up...'
	@rm -rf *.$(EXE) *.$(OBJ) *.dwf *.pdb prof

