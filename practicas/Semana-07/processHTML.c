/*  Programa para procesar un archivo de texto linea por linea
 *
 *  Autor: Programacion Paralela y Concurrente
 *  Fecha: 2020/May/21
 */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <regex>
#include <iostream>


void processLine( const char * line ) {
   char * token;
   std::regex texto( ">[^<]*<" );
   std::string ecci;

   ecci = regex_replace( line, texto, "> <" );
//   std::cout << "ecci = " << ecci << std::endl;

   token = strtok( (char * ) line, "< >\t\n" );
   printf( "Lista de tokens: " );
   while ( NULL != token ) {
      printf( "%s, ", token );
      token = strtok( NULL, "< >\t\n" );
   }
   printf( "\n" );
}


int main( int argc, char ** argv ) {
   FILE * fileId;
   int chars;
   size_t size;
   char * line;

   if ( argc < 2 ) {
      printf( "No indico el archivo a utilizar, salimos\n" );
      exit( 1 );
   }

   size = 512;
   line = (char *) calloc( 512, 1 );

   fileId = fopen( argv[ 1 ], "r" );
   if ( NULL == fileId ) {
      perror( "El archivo no se pudo abrir");
      exit( 2 );
   }

   do {
      chars = getline( & line, & size, fileId );
      processLine( line );
   } while ( chars > 0 );

   free( line );

   fclose( fileId );

}

