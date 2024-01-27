#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/list.h"

int main() {
    // A2 Liste auslagern und als abgeschlossene Einheit flexibel einsetzbar machen

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
        printf("%d", "Die Zahl 255 ist am Index: ", Contains((void *) 255));

    // Size von list
    printf("Anzahl der Elemente in der Liste: ");
    printf("%d\n", Size( ));

    // Remove Test
    Remove(0);
    Remove(4);
    printf("%s%d\n", "Item 0: ", *(int *) Get(0));
    printf("%s%d\n", "Item 1: ", *(int *) Get(1));
    printf("%s%d\n", "Item 2: ", *(int *) Get(2));
    printf("%s%d\n", "Item 3: ", *(int *) Get(3));
    printf("%s%d\n", "Item 4: ", *(int *) Get(4));
    return 0;
}
