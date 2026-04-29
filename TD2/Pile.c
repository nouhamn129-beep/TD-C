typedef struct stack {
    int data;
    struct stack *next;
} STACK;


/* Empiler (push) */
void push(STACK **head, int value) {

    STACK *node = (STACK*) malloc(sizeof(STACK));

    node->data = value;

    // Ajout en tête
    node->next = *head;
    *head = node;
}


/* Dépiler (pop) */
int pop(STACK **head) {

    STACK *top = *head;

    int value = top->data;

    *head = top->next;

    free(top);

    return value;
}
