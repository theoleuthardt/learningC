#include <stdio.h>

void reverseCase(char *string){
    while(*string != '\0'){
        if((unsigned char)*string < 91){                            // Falls der aktuelle Buchstabe groß ist,
            *string = (char) ((unsigned char)*string + 32);         // mach ihn klein!
        } else if((unsigned char)*string > 96) {                    // Falls der aktuelle Buchstabe klein ist,
            *string = (char) ((unsigned char)*string - 32);         // mache ihn groß! (BIG WIN)
        }
        string++;
    }

}


int main() {
    // Beispielstring:
    char string[] = "abbcccABBCCC";
    printf("Beispielstring: %s\n", string);

    // Umkehrung der Groß- sowie Kleinbuchstaben
    reverseCase(string);

    // Ausgabe des umgekehrten Strings
    printf("Umgekehrter String: %s\n", string);

    return 0;
}
