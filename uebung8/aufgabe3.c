#include <stdio.h>

#define SIZE 50

int upperLetterCount(const char *input){
    int count = 0;
    for (int i = 0; i < SIZE && input[i] != '\0'; ++i) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int main() {
    char test[SIZE];
    // test mit As befüllen
    for (int i = 0; i < SIZE; i++) {
        test[i] = 'A';
    }
    // Änderung der Elemente in test
    for (int j = 0; j < SIZE; ++j) {
        if (j*2 < SIZE) {
            test[j*2] = 'b';
        }
        if (j*3 < SIZE) {
            test[j*3] = 'c';
        }
    }
    // Ausgabe des Arrays test
    printf("Testarray: [");
    for (int k = 0; k < SIZE; ++k) {
        if(k < SIZE-1){
            printf("%c, ", test[k]);
        } else {
            printf("%c", test[k]);
        }
    }
    printf("]\n");

    printf("Anzahl der Großbuchstaben im String: %d", upperLetterCount(test));
    return 0;
}
