#include <stdio.h>
#include <stdlib.h>

char intToExcel (int num){
    // Umwandlung der Zahl zur Excelform

    long long c = 26;
    char alp[26] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i = 1; i > 0; i++) {
        if (num <= c) {
            printf("Benoetigte Buchstaben: %d\n", i);
            break;
        } else {
            c = c * c;
        }
    }

    if(num < 0){
        printf("Ungültige Zahl zum Umwandeln!");
    }

    char letter;
    char res[5];
    int index = 0;

    while(num > 0){
        int remainder = (num-1) % 26;
        letter = 'A' + remainder;
        res[index++] = letter;
        num = (num - 1) / 26;
    }

    // Rückwärtige Ausgabe der Buchstaben
    printf("Buchstabenfolge: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
    printf("\n");

    return letter;
}

int main() {
    int num = 1;
    // Umwandlung der Zahl ins Buchstabenspaltensystem von Excel
    printf("Zahl eingeben zum Umwandeln: ");
    scanf("%d", &num);
    intToExcel(num);

    return 0;
}