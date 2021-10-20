/* Arquivo:  
 *    omp_race_condition2.c
 *
 * Propósito:
 *    Demonstrar uma solução para os efeitos do
 *    Race Condition usando OpenMP.    
 *
 * Compile:  gcc -g -Wall -fopenmp -o omp_race_condition2 omp_race_condition2.c
 * Usage:    ./omp_race_condition2
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>


int publico = 0;

void incPublico(){
   # pragma omp critical
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
