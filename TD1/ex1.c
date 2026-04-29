#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 1) Définition de la structure Point
   On regroupe deux coordonnées dans une seule structure */
typedef struct {
    int abs;  // abscisse (x)
    int ord;  // ordonnée (y)
} Point;


/* 2) Fonction de saisie
   Permet de lire les coordonnées d’un point */
Point SaisirPoint() {
    Point p;

    printf("Donner x et y : ");
    scanf("%d %d", &p.abs, &p.ord);

    // On retourne la structure remplie
    return p;
}


/* 3) Fonction d’affichage
   Affiche un point sous forme (x,y) */
void AfficherPoint(Point p) {
    printf("(%d,%d)\n", p.abs, p.ord);
}


/* 5) Calcul de distance
   Distance entre le point et l’origine (0,0)
   formule : sqrt(x² + y²) */
float distance(Point p) {
    return sqrt(p.abs * p.abs + p.ord * p.ord);
}


/* 6) Fonction de tri
   On trie les points selon leur distance à l’origine
   Algorithme : tri simple (comparaison + échange) */
void trier(Point T[], int n) {
    int i, j;
    Point tmp;

    // double boucle => on compare tous les éléments
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {

            // si le point i est plus loin que j → on échange
            if(distance(T[i]) > distance(T[j])) {

                tmp = T[i];   // sauvegarde
                T[i] = T[j];  // échange
                T[j] = tmp;
            }
        }
    }

    // Complexité : O(n²) car double boucle
}


/* 7) Programme principal */
int main() {

    Point T[3];  // tableau de 3 points
    int i;

    // Remplissage du tableau
    for(i = 0; i < 3; i++) {
        T[i] = SaisirPoint();
    }

    // Affichage avant tri
    printf("Avant tri:\n");
    for(i = 0; i < 3; i++) {
        AfficherPoint(T[i]);
    }

    // Tri du tableau
    trier(T, 3);

    // Affichage après tri
    printf("Apres tri:\n");
    for(i = 0; i < 3; i++) {
        AfficherPoint(T[i]);
    }

    return 0;
}
