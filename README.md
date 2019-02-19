# Unisex Bathroom Problem
## Projektni rad iz Arhitekture racunara i operativnih sistema



### O projektu
Mentor: Ivan Milenkovic

Student: Daniel Fazlijevic br. indeksa 22/17

Fakultet Organizacionih Nauka, Univerzitet u Beogradu.


### Opis problema
Problem se nalazi u knjizi 'The Little Book Of Semaphores'

Muski toalet se pretvara u uniseks toalet. Uslovi su sledeci:
- Osobe istog pola ne mogu istovremeno biti u toaletu
- Najvise 3 osobe mogu biti istovremeno u toaletu


### Resenje problema
Resenje ovog problema dobicemo koristeci programski jezik C, koristeci POSIX threadove i semafore. 


### Opis fajlova
- `unisex_bathroom.c` - fajl koji sadrzi glavne funkcije za resavanje problema, pokretanje niti i slicno
- `pauza.h` - header fajl sa funkcijama za dolazak i odlazak iz WC-a, pauzu i slicno
- `osobe.h` - header fajl sa prototipom funkcija za muskarce i zene
- `Makefile` - fajl za kompilaciju (make kompilacija)
- `cnr.sh` - bash skripta za kompilaciju i pokretanje
	- preko terminala `./cnr.sh`
- `greske.log` - fajl koji ce cuvati poslednju gresku prilikom kompilacije
- `resenje` - kompajlovan fajl koji pokrecemo
	- preko terminala `./resenje`
