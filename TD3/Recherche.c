int Recherche(LISTE *L, int v) {

    while(L != NULL) {

        if(L->val == v)
            return 1;

        L = L->suivant;
    }

    return 0;

    // Complexité : O(n)
}
