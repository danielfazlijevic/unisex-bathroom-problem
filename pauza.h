#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void pauza(int pol){
    // random broj od 0 do 9
    int vreme = random() % 10;
    //  char *pol = "nepoznatog";
    //  printf("pauza");
    char *imePola = malloc(sizeof(char)*7);
    if(pol == 0)
	strcpy(imePola, "muskog");
    else
	strcpy(imePola, "zenskog");
    printf("Osoba %s pola je usao/la u WC.\n", imePola);
    // printf("Pauza: %d sekunde\n", vreme);
    sleep(vreme);
    printf("Osoba %s pola je izasao/la iz WC-a posle %d sekunde.\n", imePola, vreme);
    //  printf("Osoba je provela u WC-u %d sekunde\n", vreme);
}
