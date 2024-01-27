#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Erstellung der Datenstruktur
struct student {
    char firstN[25];
    char surN[25];
    double math;
    double german;
    double english;
    struct student *next;
};

struct student *top = NULL;

// Funktionen für die Daten<3struktur
int isEmpty() {
    return (top == NULL);
}

int size() {
    if (isEmpty())
        return 0;

    struct student *next = top->next;
    int size = 1;
    for (; next != NULL; next = next->next) {
        size++;
    }
    return size;
}

// Aufgabe 3: Hinzufügen eines Schüler
void addStudent(char firstN[25], char surN[25]) {
    struct student *temp = (struct student *) malloc(sizeof(struct student));
    strcpy(temp->firstN, firstN);
    strcpy(temp->surN, surN);

    if (isEmpty()) {
        temp->next = NULL;
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}

void *getStudentByName(char firstN[25], char surN[25]) { //??? Don't do this!! random party? 🎉
    struct student *temp = top;
    for (int i = 0; i <= size(); i++) {
        if (isEmpty()) {
            printf("Schüler ist nicht im Klassenbuch enthalten!");
            return NULL;
        } else if (strcmp(firstN, temp->firstN) == 0 && strcmp(surN, temp->surN) == 0) {
            return temp;
        } else {
            temp = temp->next;
        }
    }
    return NULL;
}

void *getStudentByIndex(int Index) {
    struct student *temp = top;
    for (int i = 0; i <= Index; i++) {
        if (isEmpty()) {
            printf("Schüler ist nicht im Klassenbuch enthalten!"); //aber häää?
            return NULL;
        } else if (i == Index) {
            return temp;
        } else {
            temp = temp->next;
        }
    }
    return NULL;
}

void printClassbook() {
    printf("Klassenbuch: \n");
    for (int i = 0; i < size(); i++) {
        struct student *student = getStudentByIndex(i);
        if(student == NULL){
            printf("Klassenbuch ist aktuell leer!");
        }
        printf("%s, ", student->firstN);
        printf("%s\n", student->surN);
    }
    printf("\n");
}

// Aufgabe 4: Bearbeitung von Alexanders Noten </3
void refreshOneMark(char firstN[25], char surN[25], int option, double mark) {
    struct student *temp = getStudentByName(firstN, surN);
    if (isEmpty()) {
        return;
    }
    switch (option) {
        case 1:
            temp->math = mark;
            break;
        case 2:
            temp->german = mark;
            break;
        case 3:
            temp->english = mark;
            break;
        default:
            printf("Bitte gib eine Zahl zwischen 1 und 3 ein!");
    }
}

void refreshAllMarks(char firstN[25], char surN[25], double math, double german, double english) {
    struct student *temp = getStudentByName(firstN, surN);
    temp->math = math;
    temp->german = german;
    temp->english = english;
}

//Aufgabe 5: Notendurchschnitt berechnen
double classAverageGrade() {
    double sumOfGrades = 0.0;
    int countIterations = 0;

    for (int i = 0; i < size(); i++) {
        struct student *temp = getStudentByIndex(i);
        sumOfGrades += temp->math;
        countIterations++;
        sumOfGrades += temp->german;
        countIterations++;
        sumOfGrades += temp->english;
        countIterations++;
    }

    return sumOfGrades / countIterations;
}

void classbookMenu() {
    int iteration = 1;
    char firstN[25];
    char surN[25];
    int option;
    int optionS;
    double mark;
    double math;
    double german;
    double english;

    printf("Willkommen im Klassenbuch! Wähle eine Option 1 bis 5 zum Ausführen.\n");
    printf("(1): Hinzufügen eines Schülers\n");
    printf("(2): Aktualisierung einer Note eines Schülers\n");
    printf("(3): Aktualisierung einer Note aller Schüler\n");
    printf("(4): Ausgabe des Notendurchschnitts aller Fächer der Klasse\n");
    printf("(5): Ausgabe des Klassenbuchs\n");
    printf("(6): Beenden\n");
    printf("Auswahl: ");
    scanf("%d", &option);
    printf("\n");
    switch (option) {
        case 1:
            printf("%s\n", "Bitte gib den Vornamen des Schülers ein: ");
            scanf("%24s", firstN);
            printf("%s\n", "Bitte gib den Nachnamen des Schülers ein: ");
            scanf("%24s", surN);
            addStudent(firstN, surN);
            printf("------- Schüler hinzugefügt! -------\n");
            printf("\n");
            iteration++;
            break;
        case 2:
            printf("\nBitte gib den Vornamen des Schülers ein: ");
            scanf("%24s", &firstN);
            printf("Bitte gib den Nachnamen des Schülers ein: ");
            scanf("%24s", &surN);
            printf("Welche Note soll geändert werden?\n");
            printf("(1):Mathe\n");
            printf("(2):Deutsch\n");
            printf("(3):Englisch\n");
            printf("Auswahl:");
            scanf("%d", &optionS);
            printf("Bitte gibt die Note ein (Form: 1.0): ");
            scanf("%f", &mark);
            printf("\n");
            refreshOneMark(firstN, surN, optionS, mark);
            printf("Note aktualisiert!");
            iteration++;
            break;
        case 3:
            printf("\nBitte gib den Vornamen des Schülers ein: ");
            scanf("%24s", &firstN);
            printf("Bitte gib den Nachnamen des Schülers ein: ");
            scanf("%24s", &surN);
            printf("Bitte gibt die Note für Mathe ein (Form: 1.0): ");
            scanf("%d", &math);
            printf("Bitte gibt die Note für Deutsch ein (Form: 1.0): ");
            scanf("%d", &german);
            printf("Bitte gibt die Note für Englisch ein (Form: 1.0): ");
            scanf("%d", &english);
            printf("\n");
            refreshAllMarks(firstN, surN, math, german, english);
            printf("Noten aktualisiert!");
            iteration++;
            break;
        case 4:

        case 5:
            printf("\n");
            printClassbook();
            iteration++;
            break;
        case 6:
            break;
        default:
            printf("Bitte gib eine Zahl zwischen 1 und 5 ein!");
            break;
    }

    while(iteration > 1){
        printf("Weitere Option ausführen? \n");
        printf("(1): Hinzufügen eines Schülers\n");
        printf("(2): Aktualisierung einer Note eines Schülers\n");
        printf("(3): Aktualisierung einer Note aller Schüler\n");
        printf("(4): Ausgabe des Notendurchschnitts aller Fächer der Klasse\n");
        printf("(5): Ausgabe des Klassenbuchs\n");
        printf("(6): Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
            case 1:
                printf("Bitte gib den Vornamen des Schülers ein: ");
                scanf("%24s", &firstN);
                printf("Bitte gib den Nachnamen des Schülers ein: ");
                scanf("%24s", &surN);
                addStudent(firstN, surN);
                printf("------- Schüler hinzugefügt! -------\n");
                printf("\n");
                iteration++;
                break;
            case 2:
                printf("\nBitte gib den Vornamen des Schülers ein: ");
                scanf("%24s", &firstN);
                printf("Bitte gib den Nachnamen des Schülers ein: ");
                scanf("%24s", &surN);
                printf("Welche Note soll geändert werden?\n");
                printf("(1):Mathe\n");
                printf("(2):Deutsch\n");
                printf("(3):Englisch\n");
                printf("Auswahl:");
                scanf("%d", &optionS);
                printf("Bitte gibt die Note ein (Form: 1.0): ");
                scanf("%f", &mark);
                if(mark < 0.9 || mark > 6.0){
                    printf("Keine gültige Note eingegeben!");
                    break;
                }
                printf("\n");
                refreshOneMark(firstN, surN, optionS, mark);
                printf("Note aktualisiert!");
                iteration++;
                break;
            case 3:
                printf("\nBitte gib den Vornamen des Schülers ein: ");
                scanf("%24s", &firstN);
                printf("Bitte gib den Nachnamen des Schülers ein: ");
                scanf("%24s", &surN);
                printf("Bitte gibt die Note für Mathe ein (Form: 1.0): ");
                scanf("%d", &math);
                printf("Bitte gibt die Note für Deutsch ein (Form: 1.0): ");
                scanf("%d", &german);
                printf("Bitte gibt die Note für Englisch ein (Form: 1.0): ");
                scanf("%d", &english);
                printf("\n");
                refreshAllMarks(firstN, surN, math, german, english);
                printf("Noten aktualisiert!");
                iteration++;
                break;
            case 4:

            case 5:
                printClassbook();
                iteration++;
                break;
            case 6:
                return;
            default:
                iteration++;
                printf("Bitte gib eine Zahl zwischen 1 und 5 ein!");
        }
    }
}

int main() {
    classbookMenu();
    //stop alex!!
    return 0;
}


/*   :::ASCII SPAM:::

  Alex:
  ^~^  ,
 ('Y') )
 /   \/
(\|||/)

 Frog
   o
 _`O'_

 Duck
 >o)
 (_>

 Whale
        .
      ":"
    ___:____     |"\/"|
  ,'        `.    \  /
  |  O        \___/  |
~^~^~^~^~^~^~^~^~^~^~^~^~

*/