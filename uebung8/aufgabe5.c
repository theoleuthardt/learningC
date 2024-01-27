#include <stdio.h>

char findMostCommonChar(const char *str) {
    int charCount[256] = {0};  // Ein Array zur Zählung der Vorkommen jedes ASCII-Zeichens, mit 0 initialisiert

    // Zählung der Vorkommen jedes Zeichens im String
    while (*str != '\0') {
        charCount[(unsigned char)*str]++;
        str++;
    }

    // Zählungsvariablen initialisieren BIG WIN INCOMING
    char mostCommonChar = '\0';
    int maxCount = 0;

    // Suche des Zeichens mit dem meisten Vorkommen, rieche ich da BIG WIN?
    for (int i = 0; i < 256; ++i) {
        if (charCount[i] > maxCount) {
            maxCount = charCount[i];
            mostCommonChar = (char)i;
        }
    }

    // BIG WIN ausgeben!!!!
    return mostCommonChar;
}

int main() {
    const char *inputString = "bigwinnnn";

    char mostComChar = findMostCommonChar(inputString);

    if (mostComChar != '\0') {
        printf("Das Zeichen mit dem meisten Vorkommen ist: %c\n BIG WIN!", mostComChar);
    } else {
        printf("Der String ist leer.\n");
    }

    return 0;
}
