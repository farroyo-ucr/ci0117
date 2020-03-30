
ipv4-test: ipv4-test.o Socket.o
	g++ -g ipv4-test Socket.o -o ipv4-test

Socket.o: Socket.h Socket.cc
	g++ -g -c Socket.cc

ipv4-test.o: ipv4-test.cc Socket.h
	g++ -g -c ipv4-test.c

ipv6-test: ipv6-test.o Socket.o
	g++ -g ipv6-test Socket.o -o ipv6-test

ipv6-test.o: ipv6-test.cc Socket.h
	g++ -g -c ipv6-test.c

