#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int wordCount(const char *string){
    int count = 0;
    bool inWord = false;
    size_t strSize = strlen(string);
    printf("Länge des Strings: ");
    printf("%zu\n", strSize);

    for (; *string != '\0'; string++) {
        if(*string == ' ' || *string == ',' || *string == '.'){
            inWord = false;
        } else {
            if(!inWord){
                count++;
                inWord = true;
            }
        }
    }
    return count;
}

int main() {
    char *string = "Coders are also just human with addictions and needs.";
    printf("String: %s\n", string);
    printf("Anzahl der Wörter im String: %d", wordCount(string));
    return 0;
}
