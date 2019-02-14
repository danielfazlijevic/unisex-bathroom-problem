#include <stdlib.h>
#include <unistd.h>
#include <string.h>


// funkcija koja vraca string 'muskog' ili 'zenskog' u zavisnosti od broja koje mu damo kao parametar
char *imePola(int pol){
    char *ime = malloc(sizeof(char)*7);
    if(pol == 0)
        strcpy(ime, "muskog");
    else
        strcpy(ime, "zenskog");
    return ime;
}

// funkcija koja predstavlja ulazak osobe u wc, ostajanje i izlaz
void ulazak(int pol){
     // random broj od 0 do 9
    int vreme = random() % 10;
   
    printf("Osoba %s pola je usao/la u WC.\n", imePola(pol));
    sleep(vreme);
    printf("Osoba %s pola je izasao/la iz WC-a posle %d sekunde.\n", imePola(pol), vreme);
}

// funkcija za pauziranje 
void pauza(){
   int vreme = random() % 5;
   // printf("Pauza: %d\n", vreme);
   sleep(vreme);
}

// funkcija koja obavestava o dolasku osobe do WC-a
void dolazak(int pol) {
    printf("Osoba %s pola zeli da udje u WC.\n", imePola(pol));
}
