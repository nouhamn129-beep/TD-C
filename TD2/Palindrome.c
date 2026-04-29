#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =======================
   Définition de la pile
   ======================= */
typedef struct stack {
    char data;              // caractère stocké
    struct stack *next;     // pointeur vers l’élément suivant
} STACK;

/* Empiler (push)
   Ajoute un élément au sommet de la pile */
void push(STACK **head, char value) {
    STACK *node = (STACK*) malloc(sizeof(STACK));

    node->data = value;

    // Le nouvel élément pointe vers l’ancien sommet
    node->next = *head;

    // Mise à jour du sommet
    *head = node;
}

/* Dépiler (pop)
   Supprime et retourne le sommet de la pile */
char pop(STACK **head) {
    STACK *top = *head;
    char value = top->data;

    // On avance le sommet
    *head = top->next;

    free(top);

    return value;
}


/* =======================
   Définition de la file
   ======================= */
struct queue_node {
    char data;
    struct queue_node *next;
};

struct queue {
    struct queue_node *first;
    struct queue_node *last;
};

/* Enfiler (enqueue)
   Ajoute un élément à la fin de la file */
void enqueue(struct queue *q, char value) {
    struct queue_node *node =
        (struct queue_node*) malloc(sizeof(struct queue_node));

    node->data = value;
    node->next = NULL;

    if(q->first == NULL) {
        // File vide
        q->first = q->last = node;
    } else {
        q->last->next = node;
        q->last = node;
    }
}

/* Défiler (dequeue)
   Retire l’élément en tête de la file */
char dequeue(struct queue *q) {
    struct queue_node *tmp = q->first;
    char value = tmp->data;

    q->first = q->first->next;

    // Si la file devient vide
    if(q->first == NULL)
        q->last = NULL;

    free(tmp);

    return value;
}


/* =======================
   Fonction palindrome
   ======================= */
int EstPalindrome(char chaine[]) {

    int n = strlen(chaine);
    int i;

    STACK *pile = NULL;          // pile (inverse)
    struct queue file;           // file (ordre normal)

    file.first = NULL;
    file.last = NULL;

    /* Étape 1 :
       remplir pile et file */
    for(i = 0; i < n; i++) {
        push(&pile, chaine[i]);      // inverse
        enqueue(&file, chaine[i]);   // ordre normal
    }

    /* Étape 2 :
       comparaison */
    for(i = 0; i < n; i++) {

        char c1 = pop(&pile);        // dernier caractère
        char c2 = dequeue(&file);    // premier caractère

        // Si différence → pas palindrome
        if(c1 != c2)
            return 0;
    }

    // Si tout est égal → palindrome
    return 1;
}


/* =======================
   Programme principal
   ======================= */
int main() {

    char mot[100];

    printf("Donner un mot : ");
    scanf("%s", mot);

    if(EstPalindrome(mot)) {
        printf("C'est un palindrome\n");
    } else {
        printf("Ce n'est pas un palindrome\n");
    }

    return 0;
}
