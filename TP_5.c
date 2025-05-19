#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

void push(Noeud **top, int valeur) {
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = *top;
    *top = nouveau;
}

int pop(Noeud **top) {
    if (*top == NULL) {
        return -1;
    }
    Noeud *temp = *top;
    int valeur = temp->valeur;
    *top = (*top)->suivant;
    free(temp);
    return valeur;
}

int peek(Noeud *top) {
    if (top == NULL) {
        return -1;
    }
    return top->valeur;
}

void afficher(Noeud *top) {
    Noeud *current = top;
    while (current != NULL) {
        printf("%d ", current->valeur);
        current = current->suivant;
    }
    printf("\n");
}

int taille(Noeud *top) {
    int count = 0;
    Noeud *current = top;
    while (current != NULL) {
        count++;
        current = current->suivant;
    }
    return count;
}

void Enfiler(Noeud **tete, Noeud **queue, int valeur) {
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    if (*queue == NULL) {
        *tete = *queue = nouveau;
    } else {
        (*queue)->suivant = nouveau;
        *queue = nouveau;
    }
}

int Defiler(Noeud **tete, Noeud **queue) {
    if (*tete == NULL) {
        return -1;
    }
    Noeud *temp = *tete;
    int valeur = temp->valeur;
    *tete = (*tete)->suivant;
    if (*tete == NULL) {
        *queue = NULL;
    }
    free(temp);
    return valeur;
}

void viderFile(Noeud **tete, Noeud **queue) {
    while (*tete != NULL) {
        Defiler(tete, queue);
    }
}

int main() {
    Noeud *pile = NULL;
    push(&pile, 10);
    push(&pile, 20);
    push(&pile, 30);
    afficher(pile);
    printf("Sommet: %d\n", peek(pile));
    printf("Taille: %d\n", taille(pile));
    pop(&pile);
    pop(&pile);
    afficher(pile);

    Noeud *tete = NULL;
    Noeud *queue = NULL;
    Enfiler(&tete, &queue, 10);
    Enfiler(&tete, &queue, 20);
    Enfiler(&tete, &queue, 30);
    afficher(tete);
    Defiler(&tete, &queue);
    afficher(tete);
    Enfiler(&tete, &queue, 40);
    Enfiler(&tete, &queue, 50);
    viderFile(&tete, &queue);
    afficher(tete);
    return 0;
}