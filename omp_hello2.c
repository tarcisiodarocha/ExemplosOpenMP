/* Arquivo:  
 *    omp_hello2.c
 *
 * Propósito:
 *    Demonstrar com comportamento da finalização de cada thread.  
 *
 *
 * Compile:  gcc -g -Wall -fopenmp -o omp_hello2 omp_hello2.c
 * Usage:    ./omp_hello2 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>

void Hello(void);

int main(int argc, char* argv[]) {
   int thread_count = 10;
   
   /* A thread principal executa Hello(). 
      thread_count - 1 threads são criadas e executam Hello().
   */
   # pragma omp parallel num_threads(thread_count) 
   Hello(); 
   
   /* A thread principal aguarda as demais threads concluírem 
      antes de avançar na execução do código posterior à chamada do
      Hello().
   */   
   printf("END!\n");

   return 0; 
}

void Hello(void) {
   int my_rank = omp_get_thread_num(); 
   int thread_count = omp_get_num_threads(); 
   sleep(my_rank);
   printf("Hello from thread %d of %d\n", my_rank, thread_count); 
}