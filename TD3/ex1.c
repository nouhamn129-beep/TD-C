#include <stdio.h>
#include <stdlib.h>

/* Définition d’un noeud */
typedef struct Element {
    int val;                  // valeur stockée
    struct Element *suivant;  // pointeur vers l’élément suivant
} LISTE;


/* Insertion en tête
   Complexité : O(1) */
int InsererEnTete(LISTE **L, int v) {

    LISTE *e = (LISTE*) malloc(sizeof(LISTE));

    if(e == NULL)
        return 0;

    e->val = v;

    // Le nouvel élément pointe vers l’ancienne liste
    e->suivant = *L;

    // La tête devient le nouvel élément
    *L = e;

    return 1;
}


/* Affichage de la liste */
void Afficher(LISTE *L) {

    while(L != NULL) {
        printf("%d -> ", L->val);
        L = L->suivant;
    }

    printf("NULL\n");
}
