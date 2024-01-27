#include <stdio.h>
#include <string.h>
#include "palindrom.h"

void palindrom(char array[]){
    int l = 0;
    int h = strlen(array) - 1;

    while (h > l) {
        if (array[l++] != array[h--]) {
            printf("%s ist kein Palindrom\n", array);
        }
    }
    printf("%s ist ein Palindrom\n", array);
}