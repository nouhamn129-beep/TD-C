/* Suppression du plus petit élément
   Complexité : O(n) */
int SupprimerMin(LISTE **L) {

    if(*L == NULL)
        return 0;

    LISTE *ptr = *L;
    LISTE *minPrec = NULL;   // pointeur vers précédent du min
    LISTE *prec = NULL;
    int min = ptr->val;

    // Recherche du minimum
    while(ptr != NULL) {
        if(ptr->val < min) {
            min = ptr->val;
            minPrec = prec;
        }
        prec = ptr;
        ptr = ptr->suivant;
    }

    // Suppression
    if(minPrec == NULL) {
        // le minimum est en tête
        ptr = *L;
        *L = (*L)->suivant;
    } else {
        ptr = minPrec->suivant;
        minPrec->suivant = ptr->suivant;
    }

    free(ptr);
    return 1;
}
