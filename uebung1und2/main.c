#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


int main() {
    aufgabe1(NULL);
    //aufgabe2(NULL);
    //aufgabe3(NULL);
    //aufgabe4(NULL);
    //aufgabe5(NULL);
    //aufgabe6(NULL);
    //aufgabe7(NULL);
    //aufgabe8(NULL);
}

int aufgabe1() {
    // Aufgabe 1: Quadratzahlen bis 20
    // Schleife 1: for

    for(int i = 1;  i <= 20;  i++){
        printf("Die Quadratzahl von ");
        printf("%d", i);
        printf(" ist ");
        printf("%d\n", i*i);
    }

    //Schleife 2: while

    int j = 1;
    while(j <= 20){
        printf("Die Quadratzahl von ");
        printf("%d", j);
        printf(" ist ");
        printf("%d\n", j*j);
       j++;
    }

    //Schleife 3: Do-While

    int k = 0;
    do {
        k++;
        printf("Die Quadratzahl von ");
        printf("%d", k);
        printf(" ist ");
        printf("%d\n", k*k);
    } while (k <= 19);

    return 0;
}

int aufgabe2() {
    //Aufgabe 2: Ratespiel
    srand(time(NULL));
    int input;
    int num = rand() % 100;
    int tries = 0;
    bool erraten;
    // printf("%d\n", num);            // nur zu Testzwecken

    while (erraten == false){
        printf("Versuche die magische Zahl zu erraten: ");
        scanf("%d", &input);
        if(input == num) {
            printf("Zahl erraten\n");
            tries++;
            printf("Rateversuche insgesamt: ");
            printf("%d", tries);
            erraten = true;
        } else {
            if(input < num) {
                printf("Gesuchte Zahl ist höher!\n");
                tries++;
            } else {
                 printf("Gesuchte Zahl ist niedriger!\n");
                 tries ++;
            }
        }
    }
    return 0;
}

int aufgabe3() {
    // Aufgabe 3: Monatsnamen
    int inputM;
    printf("Monatszahl eingeben für Monatsnamen: ");
    scanf("%d", &inputM);
    switch (inputM) {
        case 1:
            printf("Januar");
            break;
        case 2:
            printf("Februar");
            break;
        case 3:
            printf("März");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("Mai");
            break;
        case 6:
            printf("Juni");
            break;
        case 7:
            printf("Juli");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("Oktober");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("Dezember");
            break;
        default :
            printf("Bitte gib eine Zahl zwischen 1 und 12 an");
    }
    return 0;
}

int aufgabe4() {
    int inputYear;
    printf("Welches Jahr soll überprüft werden?:  ");
    scanf("%d", &inputYear);
     if (!(inputYear % 4)) {
         if (!(inputYear % 100)){
             if (!(inputYear % 400)) {
             printf("Ist ein Schaltjahr!");
             } else {
                 printf("Ist kein Schaltjahr");
             }
         } else {
             printf("Ist ein Schaltjahr!");
         }
    } else {
      printf("Ist kein Schaltjahr!");
     }
}

int aufgabe5() {

    char inputChar;

    printf("Buchstabe eingeben: ");
    scanf("%c", &inputChar);

   if(isalpha(inputChar)) {
       if (inputChar == 'a' || inputChar == 'e' || inputChar == 'i' || inputChar == 'o' || inputChar == 'u'){
           printf("Ist ein Vokal!");
       } else if(inputChar == 'A' || inputChar == 'E' || inputChar == 'I' || inputChar == 'O' || inputChar == 'U'){
           printf("Ist ein Vokal!");
       } else {
        printf("Ist ein Konsonant!");
       }
   } else {
       printf("Kein Buchstabe");
   }
    return 0;
}

int aufgabe6() {
    int x;
    int y;

    printf("X-Koordinate eingeben: ");
    if (scanf("%d", &x) == 1) {
        printf("Y-Koordinate eingeben: ");
        if (scanf("%d", &y) == 1) {
            if (x == 0 && y == 0) {
                printf("Der Punkt liegt auf dem Ursprung!");
            } else if (x == 0 && y != 0) {
                printf("Der Punkt liegt auf der y-Achse!");
            } else if (x != 0 && y == 0) {
                printf("Der Punkt liegt auf der x-Achse!");
            } else if (x > 0 && y > 0) {
                printf("Der Punkt liegt im ersten Quadranten");
            } else if (x < 0 && y > 0) {
                printf("Der Punkt liegt im zweiten Quadranten");
            } else if (x < 0 && y < 0) {
                printf("Der Punkt liegt im dritten Quadranten");
            } else if (x > 0 && y < 0) {
                printf("Der Punkt liegt im vierten Quadranten");
            }
        } else {
            printf("Das sind aber keine Koordinaten!");
        }
    } else {
        printf("Das sind aber keine Koordinaten!");
    }
    return 0;
}

int aufgabe7() {
    char inputString[100];
    char array[100];

    printf("String eingeben: ");
    scanf("%99s", &inputString);
    strcpy(array, inputString);

    int l = 0;
    int h = strlen(array) - 1;

    while (h > l) {
        if (array[l++] != array[h--]) {
            printf("%s ist kein Palindrom\n", array);
            return 0;
        }
    }
    printf("%s ist ein Palindrom\n", array);

    return 0;
}

void printSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printTriangle(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printCircle(int size) {
    int radius = size / 2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int x = i - radius;
            int y = j - radius;
            if (x * x + y * y <= radius * radius) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int aufgabe8() {
    int size;
    char shape;

    printf("Geometrische Form eingeben! (q für Quadrat, d für Dreieck, k für Kreis): ");
    scanf(" %c", &shape);

    printf("Größe eingeben: ");
    scanf("%d", &size);

    if (shape == 'q') {
        printSquare(size);
    } else if (shape == 'd') {
        printTriangle(size);
    } else if (shape == 'k') {
        printCircle(size);
    } else {
        printf("Ungültiger Forminput!\n");
    }
    return 0;
}
