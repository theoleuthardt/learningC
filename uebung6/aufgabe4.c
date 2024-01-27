#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // A4: Datei einlesen zum Auslesen von Lottozahlen zu einem bestimmten Datum
    FILE *fptr = fopen("../Lottozahlen.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }
    char input[11];
    char s[11];
    char m[11];
    printf("Datum eingeben: ");
    gets(input);
    while (fgets(s, 11, fptr)) {
        if (strcmp(s, input)==0) {
            printf("Datum gefunden\n");
            printf("Lottozahlen vom %s: ", s);
            fgets(m, 99, fptr);
            fgets(m, 99, fptr);
            printf("%s", m);
            break;
        } else {
        }
    }
    fclose(fptr);
    return 0;
}
