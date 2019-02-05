#include <stdlib.h>
#include <unistd.h>

void pauza(void){
  // random broj od 0 do 9
  int vreme = random() % 10;
  printf("Pauza: %d sekunde\n", vreme);
  sleep(vreme);
}
