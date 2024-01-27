#include <stdio.h>
#include "palindromLIB/palindrom.h"

int main() {
    // A1: Übung 2 Aufgabe 7 auslagern in ein Modul
    char inputString[100];
    printf("String eingeben: ");
    scanf("%99s", &inputString);

    palindrom(inputString);

    return 0;
}
