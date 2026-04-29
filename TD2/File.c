struct queue_node {
    int data;
    struct queue_node *next;
};

struct queue {
    struct queue_node *first;
    struct queue_node *last;
};


/* Enfiler */
void enqueue(struct queue *q, int value) {

    struct queue_node *node =
        (struct queue_node*) malloc(sizeof(struct queue_node));

    node->data = value;
    node->next = NULL;

    if(q->first == NULL) {
        q->first = q->last = node;
    } else {
        q->last->next = node;
        q->last = node;
    }
}


/* Défiler */
int dequeue(struct queue *q) {

    struct queue_node *tmp = q->first;

    int val = tmp->data;

    q->first = q->first->next;

    free(tmp);

    return val;
}
