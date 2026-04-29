/* Définition pile */
typedef struct stack {
    int data;
    struct stack *next;
} STACK;


/* push : empiler */
void push(STACK **top, int v) {

    STACK *e = (STACK*) malloc(sizeof(STACK));

    e->data = v;

    // insertion en tête
    e->next = *top;
    *top = e;
}


/* pop : dépiler */
int pop(STACK **top) {

    STACK *tmp = *top;
    int val = tmp->data;

    *top = tmp->next;

    free(tmp);

    return val;
}
