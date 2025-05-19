#include <stdio.h>
#include <stdlib.h>

void exercice1() {
    FILE *fichier = fopen("donnees.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    char nom[50];
    int age;
    printf("Entrez votre nom: ");
    scanf("%s", nom);
    printf("Entrez votre age: ");
    scanf("%d", &age);
    fprintf(fichier, "Nom: %s\nAge: %d\n", nom, age);
    fclose(fichier);
}

void exercice2() {
    FILE *fichier = fopen("donnees.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }
    fclose(fichier);
}

void exercice3() {
    FILE *source = fopen("source.txt", "r");
    if (source == NULL) {
        printf("Erreur lors de l'ouverture du fichier source.\n");
        return;
    }
    FILE *destination = fopen("destination.txt", "w");
    if (destination == NULL) {
        printf("Erreur lors de l'ouverture du fichier destination.\n");
        fclose(source);
        return;
    }
    int c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, destination);
    }
    fclose(source);
    fclose(destination);
}

void exercice4() {
    FILE *fichier = fopen("texte.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    int caracteres = 0;
    int mots = 0;
    int lignes = 0;
    int precedent = ' ';
    int c;
    while ((c = fgetc(fichier)) != EOF) {
        caracteres++;
        if (c == '\n') {
            lignes++;
        }
        if ((c == ' ' || c == '\n' || c == '\t') && (precedent != ' ' && precedent != '\n' && precedent != '\t')) {
            mots++;
        }
        precedent = c;
    }
    if (precedent != ' ' && precedent != '\n' && precedent != '\t') {
        mots++;
    }
    printf("Caracteres: %d\nMots: %d\nLignes: %d\n", caracteres, mots, lignes);
    fclose(fichier);
}

int main() {
    exercice1();
    exercice2();
    exercice3();
    exercice4();
    return 0;
}