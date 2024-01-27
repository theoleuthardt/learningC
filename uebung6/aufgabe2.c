#include <stdio.h>
#include <string.h>

// Uebung 3 Aufgabe 8:
char Benutzer [5][2][20];

int anmeldung(){
    // Protokolldatei öffnen
    FILE *fptr = fopen("../files/protokoll.txt", "w");
    if(fptr == NULL){
        printf("Datei kann nicht geoeffnet werden!");
        return 1;
    }

    printf("Registrierung als Benutzer1: \n");
    printf("Benutzername festlegen: ");
    scanf("%19s", &Benutzer[0][0]);
    printf("Passwort festlegen: ");
    scanf("%19s", &Benutzer[0][1]);

    char benutzername_inp [20];
    char passwort_inp [20];
    printf("Anmeldung als Benutzer1: \n");
    printf("Benutzername eingeben: ");
    scanf("%s", &benutzername_inp);
    int userID = 0;

    int zeilen = 5;
    for (int i = 0; i < zeilen; ++i) {
        if(strcmp(&Benutzer[i][0],benutzername_inp) == 0){
            userID = i;
            i = 10;
        } else if(i == zeilen-1) {
            printf("Benutzer nicht gefunden!");
            userID = 6;
        }
    }

    if (userID != 6) {
        int anmeldeversuche = 3;
        while (anmeldeversuche > 0) {
            printf("Passwort eingeben: ");
            scanf("%s", &passwort_inp);
            if (0 != strcmp(&Benutzer[userID][1], passwort_inp)) {
                printf("Benutzereingabe falsch\n");
                fprintf(fptr, "Anmeldeversuch von Benutzer %s fehlgeschlagen!\n", Benutzer[userID][0]);
                anmeldeversuche--;
            } else {
                printf("Sie sind angemeldet!");
                break;
            }
        }
        if(anmeldeversuche == 0) printf("Zu viele Anmeldeversuche!");
    }
    return 0;
}

int main() {
    anmeldung();
    return 0;
}
