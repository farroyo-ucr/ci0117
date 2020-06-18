/* File:     omp_hello.c
 *
 * Purpose:  A parallel hello, world program that uses OpenMP
 *
 * Compile:  gcc -g -Wall -fopenmp -o omp_hello omp_hello.c
 * Run:      ./omp_hello <number of threads>
 * 
 * Input:    none
 * Output:   A message from each thread
 *
 * IPP:      Section 5.1 (pp. 211 and ff.)
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>   
#include "chrono.h"

void Hello(void);  /* Thread function */

/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   Chrono ini, fin;
   int thread_count = 5;

   if ( argc > 1 ) {
    thread_count = strtol( argv[1], NULL, 10 ); 
   }

   ini.readTime();

#  pragma omp parallel num_threads(thread_count) 
   Hello();

   fin.readTime();
   fin -= ini;
   printf( "Time consumed: %ld.%ld sec.\n", fin.getSecs(), fin.getnSecs() );
   return 0; 
}  /* main */

/*-------------------------------------------------------------------
 * Function:    Hello
 * Purpose:     Thread function that prints message
 */
void Hello(void) {
   int my_rank = omp_get_thread_num();
   int thread_count = omp_get_num_threads();

   printf("Hello from thread %d of %d\n", my_rank, thread_count);

}  /* Hello */

