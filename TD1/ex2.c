#include <stdio.h>

/* 1) Structure Heure
   Représente une heure complète */
typedef struct {
    int hh; // heures
    int mm; // minutes
    int ss; // secondes
} Heure;


/* 2) Conversion heure → secondes
   Permet de simplifier les calculs */
int HeureEnSecondes(Heure h) {
    return h.hh * 3600 + h.mm * 60 + h.ss;
}


/* 3) Conversion secondes → heure */
Heure SecondesEnHeure(int sec) {
    Heure h;

    h.hh = sec / 3600;      // nombre d’heures
    sec = sec % 3600;

    h.mm = sec / 60;        // minutes restantes
    h.ss = sec % 60;        // secondes restantes

    return h;
}


/* 4) Addition de deux heures */
Heure Addition(Heure h1, Heure h2) {

    // On convertit en secondes pour éviter les erreurs
    int total = HeureEnSecondes(h1) + HeureEnSecondes(h2);

    // Puis on reconvertit
    return SecondesEnHeure(total);
}


/* 5) Différence entre deux heures */
Heure Difference(Heure h1, Heure h2) {

    int s1 = HeureEnSecondes(h1);
    int s2 = HeureEnSecondes(h2);

    int diff = s1 - s2;

    // On prend la valeur absolue pour éviter résultat négatif
    if(diff < 0)
        diff = -diff;

    return SecondesEnHeure(diff);
}
