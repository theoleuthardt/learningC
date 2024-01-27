#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/list.h"

void menu() {
    int iteration = 1;
    int option;

    printf("Willkommen im X! Wähle eine Option 1 bis X zum Ausführen.\n");
    printf("(1): Option 1\n");
    printf("(2): Option 2\n");
    printf("(3): Option 3\n");
    printf("(4): Option 4\n");
    printf("(5): Option 5\n");
    printf("(6): Beenden\n");
    printf("Auswahl: ");
    scanf("%d", &option);
    printf("\n");

    switch (option) {
        case 1:
            // Case 1
            printf("\n");
            iteration++;
            break;
        case 2:
            // Case 2
            iteration++;
            break;
        case 3:
            // Case 3
            iteration++;
            break;
        case 4:
            // Case 4
            iteration++;
            break;
        case 5:
            // Case 5
            iteration++;
            break;
        case 6:
            break;
        default:
            printf("Bitte gib eine Zahl zwischen 1 und X ein!");
            break;
    }

    while(iteration > 1) {
        printf("Weitere Option ausführen? \n");
        printf("(1): Option 1\n");
        printf("(2): Option 2\n");
        printf("(3): Option 3\n");
        printf("(4): Option 4\n");
        printf("(5): Option 5\n");
        printf("(6): Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                // Case 1
                printf("\n");
                iteration++;
                break;
            case 2:
                // Case 2
                iteration++;
                break;
            case 3:
                // Case 3
                iteration++;
                break;
            case 4:
                // Case 4
                iteration++;
                break;
            case 5:
                // Case 5
                iteration++;
                break;
            case 6:
                return;
            default:
                iteration++;
                printf("Bitte gib eine Zahl zwischen 1 und X ein!");
        }
    }
}

int main() {
    // Befüllung mit verschiedenen Daten
    int number1 = 255;
    int number2 = rand() % 500;
    int number3 = rand() % 500;
    int number4 = rand() % 500;
    int number5 = rand() % 500;

    Add(&number1);
    Add(&number2);
    Add(&number3);
    Add(&number4);
    Add(&number5);

    // Ausgabe der Liste
    printf("%s%d\n", "Item 0: ", *(int *) Get(0));
    printf("%s%d\n", "Item 1: ", *(int *) Get(1));
    printf("%s%d\n", "Item 2: ", *(int *) Get(2));
    printf("%s%d\n", "Item 3: ", *(int *) Get(3));
    printf("%s%d\n", "Item 4: ", *(int *) Get(4));

    // Contains Überprüfung
    if(Contains((void *) 255) != -1)
        printf("%d", "Die Zahl 255 ist am Index: ", *(int *) Contains((void *) 255));

    // Size von list
    printf("Anzahl der Elemente in der Liste: ");
    printf("%d\n", Size());

    // Removetest
    Remove(0);
    Remove(3);
    printf("%s%d\n", "Item 0: ", *(int *) Get(0));
    printf("%s%d\n", "Item 1: ", *(int *) Get(1));
    printf("%s%d\n", "Item 2: ", *(int *) Get(2));

    return 0;
}
