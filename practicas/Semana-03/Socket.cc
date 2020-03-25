
#include "Socket.h"

/* 
   char tipo: el tipo de socket que quiere definir
      's' para "stream
      'd' para "datagram"
   bool ipv6: si queremos un socket para IPv6
 */
Socket::Socket( char tipo, bool ipv6 ){

}


Socket::~Socket(){
    Close();
}


void Socket::Close(){

}

/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   int port: ubicacion del proceso, por ejemplo 80
 */
int Socket::Connect( char * hostip, int port ) {

   return -1;

}


/*
   char * hostip: direccion del servidor, por ejemplo "www.ecci.ucr.ac.cr"
   char * service: nombre del servicio que queremos acceder, por ejemplo "http"
 */
int Socket::Connect( char *host, char *service ) {

   return -1;

}


int Socket::Read( char *text, int len ) {

   return -1;

}


int Socket::Write( char *text ) {

   return -1;

}


int Socket::Listen( int queue ) {

    return -1;

}


int Socket::Bind( int port ) {

    return -1;

}


Socket * Socket::Accept(){

    return -1;

}


int Socket::Shutdown( int mode ) {

    return -1;

}


void Socket::SetIDSocket(int id){

    idSocket = id;

}

