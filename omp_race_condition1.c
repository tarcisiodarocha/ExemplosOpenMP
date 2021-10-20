/* Arquivo:  
 *    omp_hello1.c
 *
 * Propósito:
 *    Demonstrar com comportamento da finalização de cada thread.  
 *
 *
 * Compile:  gcc -g -Wall -fopenmp -o omp_hello2 omp_hello2.c
 * Usage:    ./pth_condition_variable 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>


int publico = 0;

void incPublico(){
   publico++; // Região crítica
}

void Portaria(void);

int main(int argc, char* argv[]) {
   int thread_count = 4;
   
   # pragma omp parallel num_threads(thread_count) 
   Portaria(); 
   
   printf("Ingressos: %d\n", publico);

   return 0; 
}

void Portaria(void) {
   int i;

   for  (i = 1; i <= 1000000; i++){
      incPublico();
   }

} 
