/* UNISEX BATHROOM PROBLEM
 * Projektni rad iz AROS-a
 * Daniel Fazlijevic br. indeksa 22/17
 * Fakultet Organizacionih Nauka
 * 2019.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "pauza.h" // header fajl sa funkcijom za random pauzu

// maksimalni broj osoba u jednom toletu
#define MAX_OSOBA 3

// trenutni brojevi muskaraca i zena u toletu
int brojMuskaraca, brojZena;

// semafori za upravljanje broja za muskarce i zene
sem_t x, y, z;

// semafori za upravljanje 
sem_t muskarac_sem, zena_sem;

// semafor koji sadrzi maksimalni kapacitet toleta
sem_t max_sem; 


int main(void){
  srand(time(NULL)); // da osiguramo prave random vrednosti 	
  printf("Unisex Bathroom problem - projektni rad\n");
  pauza();
  pauza();
  pauza();
  pauza(); 
  return 0;
}


