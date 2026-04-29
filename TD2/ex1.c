#include <stdio.h>

/* Recherche de l’indice du minimum */
int min(int tab[], int n) {
    int i, index = 0;

    for(i = 1; i < n; i++) {

        // On compare chaque élément
        if(tab[i] < tab[index]) {
            index = i;
        }
    }

    // On retourne la position du minimum
    return index;
}
