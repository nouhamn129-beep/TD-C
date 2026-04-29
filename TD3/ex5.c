/* Libérer toute la mémoire
   Complexité : O(n) */
void Detruire(LISTE **L) {

    LISTE *tmp;

    while(*L != NULL) {

        tmp = *L;

        // avancer
        *L = (*L)->suivant;

        // libération
        free(tmp);
    }
}
