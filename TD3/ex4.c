/* Insertion en fin (utile pour fusion) */
void InsererFin(LISTE **L, int v) {

    LISTE *e = (LISTE*) malloc(sizeof(LISTE));
    e->val = v;
    e->suivant = NULL;

    if(*L == NULL) {
        *L = e;
    } else {
        LISTE *p = *L;

        while(p->suivant != NULL)
            p = p->suivant;

        p->suivant = e;
    }
}


/* Fusion en alternance
   Complexité : O(n + m) */
LISTE* Fusion(LISTE *L1, LISTE *L2) {

    LISTE *res = NULL;

    while(L1 != NULL && L2 != NULL) {

        InsererFin(&res, L1->val);
        InsererFin(&res, L2->val);

        L1 = L1->suivant;
        L2 = L2->suivant;
    }

    // ajouter le reste
    while(L1 != NULL) {
        InsererFin(&res, L1->val);
        L1 = L1->suivant;
    }

    while(L2 != NULL) {
        InsererFin(&res, L2->val);
        L2 = L2->suivant;
    }

    return res;
}
