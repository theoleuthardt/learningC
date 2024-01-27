#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int pi(){
    const int pi = (int) 3.1415926535;
    const float Pi = 3.1415926535f;
    const double pI = 3.1415926535;
    const long double pII = 3.1415926535l;
    const char ppi [] =  "3.1415926535";

    printf("%d\n", pi);
    printf("%f\n", Pi);
    printf("%f\n", pI);
    printf("%s\n", ppi);
    printf("%Lf\n", pII);

    return 0;
}

int limits(){
    printf("%d", SHRT_MAX);
    for (short i = 32600; i < 32800; i++) {
        printf("%d\n", i);
    }
    // Beim Überlauf fängt i wieder beim jeweils anderen Extrem an z.B.
    // im negativen Bereich
    return 0;
}

int geradeUngerade(){
    int input = 0;
    scanf("%d", &input);
    if (input % 2 == 0){
        printf("Deine Zahl ist gerade!");
    } else {
        printf("Deine Zahl ist ungerade!");
    }
    return 0;
}

bool primzahl(){
   int n = 0;
   printf("Zahl eingeben: ");
   scanf("%d", &n);
    if(n <= 1){
        printf("Keine Primzahl!");
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if ( n % i == 0) {
             printf("Keine Primzahl!");
             return false;
        }
    }
    printf("Eine Primzahl!");
    return true;
}

struct Orte {
    double breitengrad;
    double laengengrad;
} ort1, ort2;

double abstand(){
    //Abstandsberechnung
    printf("Breitengrad für Ort 1 eingeben: ");
    scanf("%lf", &ort1.breitengrad);
    printf("Längengrad für Ort 1 eingeben: ");
    scanf("%lf", &ort1.laengengrad);

    printf("Breitengrad für Ort 2 eingeben: ");
    scanf("%lf", &ort2.breitengrad);
    printf("Längengrad für Ort 2 eingeben: ");
    scanf("%lf", &ort2.laengengrad);

    double breite1 = ort1.breitengrad * M_PI / 180.0;
    double laenge1 = ort1.laengengrad * M_PI / 180.0;
    double breite2 = ort2.breitengrad * M_PI / 180.0;
    double laenge2 = ort2.laengengrad * M_PI / 180.0;

    double gesamtlaenge = laenge2 - laenge1;
    double gesamtbreite = breite2 - breite1;

    double a = pow(sin(gesamtbreite / 2), 2) + cos(breite1) * cos(breite2) * pow(sin(gesamtlaenge / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double radius = 6371;
    double abstand = radius * c;
    printf("Distanz: ");
    printf("%lf",  abstand);
    printf("%s\n", "km");

    //Auswahl des Verkehrsmittels
    char input2;
    double fahrzeit = 0; // in h
    double Aspeed = 100; // km/h
    double Lspeed = 5; // km/h
    double Fspeed = 800; // km/h

    printf("Auswahlmöglichkeiten: A für Auto, L für Laufen, F für Flugzeug: ");
    scanf("%s", &input2);

    switch (input2)
    {
        case 'A':
            fahrzeit = (double)abstand / Aspeed;
            break;
        case 'L':
            fahrzeit = abstand / Lspeed;
            break;
        case 'F':
            fahrzeit = abstand / Fspeed;
            break;
        default:
            printf("Keine gültige Eingabe!");
    }

    printf("Fahrzeit: ");
    printf("%lf", fahrzeit);
    printf("h");

    return 0;
}

int produktTabelle(){
    int zeilen = 12;
    int spalten = 12;

    for (int i = 1; i <= zeilen; i++) {
        for (int j = 1; j <= spalten; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}

char Benutzer [5][2][20];

int anmeldung(){

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

    // pi();
    // limits();
    // geradeUngerade();
    // primzahl();
    // abstand();
    // produktTabelle();
    anmeldung();

    return 0;
}



