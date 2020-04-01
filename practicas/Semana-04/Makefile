# Makefile Semana 4
#

MirrorServerTest: MirrorServerTest.o Socket.o
	g++ -g MirrorServerTest.o Socket.o -o MirrorServerTest

MirrorClientTest: MirrorClientTest.o Socket.o
	g++ -g MirrorClientTest.o Socket.o -o MirrorClientTest

Socket.o: Socket.h Socket.cc
	g++ -g -c Socket.cc

MirrorServerTest.o: MirrorServerTest.cc Socket.h
	g++ -g -c MirrorServerTest.c

