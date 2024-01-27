#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


struct gameData *top = NULL;

int isEmpty(){
    return (top == NULL);
}

int size(){
    if (isEmpty())
        return 0;

    struct gameData *next = top->next;
    int size = 1;
    for (; next != NULL; next = next->next) {
        size++;
    }
    return size;
}

void addGame(char choice1[10], char choice2[10], int winner){
    struct gameData *temp = (struct gameData *) malloc(sizeof(struct gameData));
    strcpy(temp->choice1, choice1);
    strcpy(temp->choice2, choice2);
    temp->winner = winner;

    if(top == NULL){
        temp->next = NULL;
        top = temp;
        return;
    }

    temp->next = top;
    top = temp;
}

void *getGameData(int index){
    if (top == NULL)
        return NULL;

    struct gameData *temp = top;
    for (int i = 0; i <= index; i++) {
        if (temp == NULL){
            printf("Element ist nicht enthalten!");
            return NULL;
        } else if(i == index){
            return temp;
        } else{
            temp = temp->next;
        }
    }
    return NULL;
}

int countGames() {
    int count = 0;

    for (int i = 0; i < size(); ++i) {
        struct gameData *temp = getGameData(i);
        count++;
    }

    return count;
}

void printGameData() {
    printf("Ausgabe der Spieleergebnisse:\n");
    printf("\n");

    for (int i = 0; i < size(); ++i) {
        struct gameData *temp = getGameData(i);
        printf("Spiel %d:\n", i+1);
        printf("Auswahl Spieler 1: %s\n", temp->choice1);
        printf("Auswahl Spieler 2: %s\n", temp->choice2);
        printf("Gewinner des Spiels: Spieler %d\n", temp->winner);
        printf("\n");
    }
}

void statistics() {
    double points1 = 0.0;
    double avgPoints1;
    double points2 = 0.0;
    double avgPoints2;
    double gameNum = (double)countGames();

    printf("Ausgabe der Spielstatistik:\n");
    printf("\n");

    // Zählung der Punkte
    for (int i = 0; i < size(); ++i) {
        struct gameData *temp = getGameData(i);

        if(temp->winner == 0) {
            points1+=1.0;
            points2+=1.0;
        } else if(temp->winner == 1) {
            points1+=2.0;
        } else if(temp->winner == 2) {
            points2+=2.0;
        }
    }

    // Berechnung der Punktedurchschnitte
    avgPoints1 = points1 / gameNum;
    avgPoints2 = points2 / gameNum;

    // Ausgabe
    printf("Punkte von Spieler 1: %f\n", points1);
    printf("Punktedurchschnitt von Spieler 1: %f\n", avgPoints1);
    printf("Punkte von Spieler 2: %f\n", points2);
    printf("Punktedurchschnitt von Spieler 2: %f\n", avgPoints2);
}