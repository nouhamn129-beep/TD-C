#include <stdio.h>
#include <stdlib.h>

/* Définition d’un noeud */
typedef struct Element {
    int val;
    struct Element *suivant;
} LISTE;


/* Insertion en tête */
int Inserer(LISTE **L, int v) {

    LISTE *e = (LISTE*) malloc(sizeof(LISTE));

    if(e == NULL)
        return 0;

    e->val = v;

    // Le nouvel élément pointe vers l’ancienne tête
    e->suivant = *L;

    // La tête devient le nouvel élément
    *L = e;

    return 1;

    // Complexité : O(1)
}
