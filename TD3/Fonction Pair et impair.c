/* Met les pairs sous les impairs */
STACK* PairImpair(STACK *P1) {

    STACK *P2 = NULL;
    STACK *P3 = NULL;
    int val;

    while(P1 != NULL) {

        val = pop(&P1);

        if(val % 2 == 0)
            push(&P2, val);   // pair
        else
            push(&P3, val);   // impair
    }

    // remettre les impairs au-dessus
    while(P3 != NULL) {
        val = pop(&P3);
        push(&P2, val);
    }

    return P2;
}
