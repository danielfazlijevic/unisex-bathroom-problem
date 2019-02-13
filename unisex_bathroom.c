/* * Daniel Fazlijevic br. indeksa 22/17
 * <danielfazlijevic98@gmail.com>
 * https://danielfazlijevic.me
 * Fakultet Organizacionih Nauka
 * 2019.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "osobe.h" // fajl sa prototipom funkcija za muskarce i zene
#include "pauza.h" // header fajl sa funkcijom za random pauzu

// maksimalni broj osoba u jednom toletu
#define MAX_OSOBA 3

// trenutni brojevi muskaraca i zena u toaletu
int broj_muskaraca, broj_zena;

// semafori za upravljanje broja za muskarce i zene
// ovi semafori nam omogucuju sigurno menjanje semafora za broj osoba
sem_t x, y, z;

// semafori za upravljanje dozvoljenog pola toaleta
sem_t muskarac_sem, zena_sem;

// semafor koji sadrzi maksimalni kapacitet toaleta
sem_t max_sem; 


int main(void){
    srand(time(NULL)); // da osiguramo prave random vrednosti 	
    printf("Unisex Bathroom problem - projektni rad\n");
    broj_muskaraca = 0;
    broj_zena = 0;
    int broj_zaposlenih_muskaraca = 10;
    int broj_zaposlenih_zena = 9;
    int ukupan_broj_zaposlenih = broj_zaposlenih_muskaraca + broj_zaposlenih_zena;
    printf("U firmi ima %d zaposlenih muskaraca, %d zena, ukupno %d zaposlenih\n",
	    broj_zaposlenih_muskaraca, broj_zaposlenih_zena, ukupan_broj_zaposlenih);
    sem_init(&x, 0, 1);  // postavljamo semafore na default vrednosti
    sem_init(&y, 0, 1);
    sem_init(&z, 0, 1);
    sem_init(&muskarac_sem, 0, 1);
    sem_init(&zena_sem, 0, 1);
    sem_init(&max_sem, 0, MAX_OSOBA);  // postavljamo kapacitet toaleta

    pthread_t *tid;
    tid = malloc(80 * sizeof(pthread_t));
    int i;
    for(i = 0; i < broj_zaposlenih_zena; i++){
	pthread_create(&tid[i], NULL, zena, NULL);
    }
    for(i = broj_zaposlenih_zena; i < ukupan_broj_zaposlenih; i++){     
	pthread_create(&tid[i], NULL, muskarac, NULL);
    }
    for(i = 0; i < ukupan_broj_zaposlenih; i++){     
	pthread_join(tid[i], NULL);
    }
    return 0;
}

void *zena(void *param)
{
    sem_wait(&z);
    sem_wait(&zena_sem);
    sem_wait(&y);
    broj_zena++;
    if(broj_zena==1)
	sem_wait(&muskarac_sem); 
    sem_post(&y);
    sem_post(&zena_sem);
    sem_post(&z);

    sem_wait(&max_sem);

   // printf("Osoba zenskog pola je usla u wc\n");
    pauza(1);
   // printf("Osoba zenskog pola je izasla iz wc-a.\n");

    sem_post(&max_sem);     

    sem_wait(&y);
    broj_zena--;
    if(broj_zena==0)
	sem_post(&muskarac_sem); 
    sem_post(&y);
}

void *muskarac(void *param)
{
    sem_wait(&z);
    sem_wait(&muskarac_sem);
    sem_wait(&x);
    broj_muskaraca++;
    if(broj_muskaraca==1)
	sem_wait(&zena_sem); // jedan muskarac je u wc-u, wc dostupan samo muskarcima
    sem_post(&x);
    sem_post(&muskarac_sem);
    sem_post(&z);

    sem_wait(&max_sem); // ukoliko je kapacitet wc-a popunjen, cekaj

    // printf("Osoba muskog pola je usla u wc\n");
    pauza(0);
    // printf("Osoba muskog pola je izasla iz wc-a.\n");

    sem_post(&max_sem);

    sem_wait(&x);
    broj_muskaraca--;
    if(broj_muskaraca==0)
	sem_post(&zena_sem);
    sem_post(&x);
}
