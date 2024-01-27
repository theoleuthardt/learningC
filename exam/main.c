#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/list.h"

void gameMenu() {
    int iteration = 1;
    int option;
    char choice1[10];
    char choice2[10];
    int winner = 3;                     // Spielerzahl als Ergebnis (1 oder 2, 0 = unentschieden)

    printf("Willkommen zu Schere-Stein-Papier! Wähle eine Option von 1 bis 4 zum Ausführen.\n");
    printf("(1): Spiel starten\n");
    printf("(2): Ausgabe der Anzahl und Details der bisher gespielten Partien\n");
    printf("(3): Ausgabe einer aktuellen Statistik (Punktesystem)\n");
    printf("(4): Beenden\n");
    printf("Auswahl: ");
    scanf("%d", &option);
    printf("\n");

    switch (option) {
        case 1:
            // Spielstart mit Auswahlmöglichkeiten
            printf("Die Auswahlmöglichkeiten sind Schere, Stein oder Papier!\n");
            printf("Auswahl von Spieler 1:");
            scanf("%s", choice1);
            //printf("%s\n", choice1);
            printf("Auswahl von Spieler 2:");
            scanf("%s", choice2);
            //printf("%s\n", choice2);

            /*
            // StringCompare-Werte testen, kommen sehr weirde Werte raus -> Anpassung der Abfrage
            printf("%d\n", strcmp("Stein", choice1));
            printf("%d\n", strcmp("Schere", choice1));
            printf("%d\n", strcmp("Papier", choice1));
            printf("%d\n", strcmp("Stein", choice2));
            printf("%d\n", strcmp("Schere", choice2));
            printf("%d\n", strcmp("Papier", choice2));
            printf("%d\n", strcmp(choice1, choice2));
            */

            //Spielentscheidung
            if(strcmp("Schere", choice1) == 0 && strcmp("Papier", choice2) == 0) {
                winner = 1;
            } else if(strcmp("Papier", choice1) == 0 && strcmp("Stein", choice2) == 0) {
                winner = 1;
            } else if(strcmp("Stein", choice1) == 0 && strcmp("Schere", choice2) == 0) {
                winner = 1;
            } else if(strcmp("Schere", choice2) == 0 && strcmp("Papier", choice1) == 0) {
                winner = 2;
            } else if(strcmp("Papier", choice2) == 0 && strcmp("Stein", choice1) == 0) {
                winner = 2;
            } else if(strcmp("Stein", choice2) == 0 && strcmp("Schere", choice1) == 0) {
                winner = 2;
            } else if(strcmp(choice1, choice2) == 0) {
                winner = 0;
            }


            // Ergebnisausgabe
            if(winner == 0) {
                printf("\nDas Spiel ging unentschieden aus!\n");
            } else if(winner == 1) {
                printf("\nSpieler 1 hat gewonnen!\n");
            } else if(winner == 2) {
                printf("\nSpieler 2 hat gewonnen!\n");
            } else {
                printf("\nKein Spielergebnis ist bisher vorhanden!\n");
            }

            //Daten speichern
            addGame(choice1, choice2, winner);

            iteration++;
            break;
        case 2:
            printf("\nAnzahl der gespielten Partien: %d\n", countGames());
            printGameData();
            iteration++;
            break;
        case 3:
            statistics();
            iteration++;
            break;
        case 4:
            break;
        default:
            printf("Bitte gib eine Zahl zwischen 1 und 4 ein!");
            break;
    }

    while(iteration > 1) {
        printf("\nWeitere Option ausführen? \n");
        printf("(1): Spiel starten\n");
        printf("(2): Ausgabe der Anzahl und Details der bisher gespielten Partien\n");
        printf("(3): Ausgabe einer aktuellen Statistik (Punktesystem)\n");
        printf("(4): Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                // Spielstart mit Auswahlmöglichkeiten
                printf("Die Auswahlmöglichkeiten sind Schere, Stein oder Papier!\n");
                printf("Auswahl von Spieler 1:");
                scanf("%s", choice1);
                //printf("%s\n", choice1);
                printf("Auswahl von Spieler 2:");
                scanf("%s", choice2);
                //printf("%s\n", choice2);

                /*
                // StringCompare-Werte testen, kommen sehr weirde Werte raus -> Anpassung der Abfrage
                printf("%d\n", strcmp("Stein", choice1));
                printf("%d\n", strcmp("Schere", choice1));
                printf("%d\n", strcmp("Papier", choice1));
                printf("%d\n", strcmp("Stein", choice2));
                printf("%d\n", strcmp("Schere", choice2));
                printf("%d\n", strcmp("Papier", choice2));
                printf("%d\n", strcmp(choice1, choice2));
                */

                //Spielentscheidung
                if(strcmp("Schere", choice1) == 0 && strcmp("Papier", choice2) == 0) {
                    winner = 1;
                } else if(strcmp("Papier", choice1) == 0 && strcmp("Stein", choice2) == 0) {
                    winner = 1;
                } else if(strcmp("Stein", choice1) == 0 && strcmp("Schere", choice2) == 0) {
                    winner = 1;
                } else if(strcmp("Schere", choice2) == 0 && strcmp("Papier", choice1) == 0) {
                    winner = 2;
                } else if(strcmp("Papier", choice2) == 0 && strcmp("Stein", choice1) == 0) {
                    winner = 2;
                } else if(strcmp("Stein", choice2) == 0 && strcmp("Schere", choice1) == 0) {
                    winner = 2;
                } else if(strcmp(choice1, choice2) == 0) {
                    winner = 0;
                }


                // Ergebnisausgabe
                if(winner == 0) {
                    printf("\nDas Spiel ging unentschieden aus!\n");
                } else if(winner == 1) {
                    printf("\nSpieler 1 hat gewonnen!\n");
                } else if(winner == 2) {
                    printf("\nSpieler 2 hat gewonnen!\n");
                } else {
                    printf("\nKein Spielergebnis ist bisher vorhanden!\n");
                }

                //Daten speichern
                addGame(choice1, choice2, winner);

                iteration++;
                break;
            case 2:
                printf("\nAnzahl der gespielten Partien: %d\n", countGames());
                printGameData();
                iteration++;
                break;
            case 3:
                statistics();
                iteration++;
                break;
            case 4:
                return;
            default:
                iteration++;
                printf("Bitte gib eine Zahl zwischen 1 und 4 ein!");
        }
    }
}

int main() {
    gameMenu();
    return 0;
}
