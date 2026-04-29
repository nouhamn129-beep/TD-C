/* Recherche d’une valeur dans la liste
   Complexité : O(n) */
int Recherche(LISTE *L, int v) {

    while(L != NULL) {

        // Si trouvé
        if(L->val == v)
            return 1;

        L = L->suivant;
    }

    return 0;
}
