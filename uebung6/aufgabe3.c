#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // A3: Lottozahlen ziehen und in einer Datei speichern
    FILE *fptr = fopen("../Lottozahlen.txt", "w");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
        return 1;
    }

    time_t now;
    now = time(0);
    int numbers[10];
   //Normale Zahlen
    fprintf(fptr, "%s", ctime(&now));
    for(int i = 0 ; i < 7 ; i++ ) {
       numbers[i] = rand() % 49 +1;
       for (int n = 0; n < 7; n++) {
           if (numbers[i] == numbers[n]) {
               numbers[i] = rand() % 49 +1;
           }
       }
       fprintf(fptr,"%d ", numbers[i]);
    }

    fprintf(fptr, "\n");
    fclose(fptr);

    return 0;
}
