/*
 *  Esqueleto para la clase Socket
 */
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

/*
 *  Lee caracteres por medio del socket y los guarda en "text" cuya capacidad máxima es "len"
 */
int Socket::Read( char *text, int len ) {

   return -1;

}


/*
 *  Escribe la tira de caracteres a traves de socket
 */
int Socket::Write( char *text ) {

   return -1;

}


/*
 *  Indica al sistema operativo que el socket va a actuar de manera pasiva
 *  Utilizara conexiones establecidas por medio de Accept
 */
int Socket::Listen( int queue ) {

    return -1;

}

/*
 *  Asocia al socket con el puerto indicado como parametro
 */
int Socket::Bind( int port ) {

    return -1;

}

/*
 *  Acepta conexiones desde los clientes
 *  Devuelve una nueva instancia de la clase Socket para manejar la conexion de un cliente
 */
Socket * Socket::Accept(){

    return -1;

}

/*
 *  Cierra parcialmente la conectividad de un socket, puede ser por escrituras o lecturas
 *  El parametro "mode" indica el tipo de cierre que se quiere efectuar
 */
int Socket::Shutdown( int mode ) {

    return -1;

}

/*
 *  Cambia la variable de instancia
 */
void Socket::SetIDSocket(int id){

    idSocket = id;

}

