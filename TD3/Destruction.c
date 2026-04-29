void Detruire(LISTE **L) {

    LISTE *tmp;

    while(*L != NULL) {

        tmp = *L;

        // On avance dans la liste
        *L = (*L)->suivant;

        // Libération mémoire
        free(tmp);
    }

    // Complexité : O(n)
}
