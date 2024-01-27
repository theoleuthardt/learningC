#include <stdio.h>
#include <math.h>

double winkelBerechnungUhr(int minuten, int stunden){
    // Stunde in Restklasse 12:  [0, 11] bringen
    stunden = stunden % 12;

    // Winkel des Stundenzeigers pro Stunde (360 Grad / 12 Stunden)
    double stundenWinkelProStunde = 360.0 / 12.0;

    // Winkel des Minutenzeigers pro Minute (360 Grad / 60 Minuten)
    double minutenWinkelProMinute = 360.0 / 60.0;

    // Berechnung der Winkel für Stunden- und Minutenzeiger
    double stundenWinkel = stunden * stundenWinkelProStunde + minuten * (stundenWinkelProStunde / 60.0);
    double minutenWinkel = minuten * minutenWinkelProMinute;

    // Berechnung des absoluten Winkelsunterschieds
    double winkelUnterschied = fabs(stundenWinkel - minutenWinkel);

    // Winkelunterschied auf den kleinsten Winkel (0-180 Grad) reduzieren
    if (winkelUnterschied > 180.0) {
        winkelUnterschied = 360.0 - winkelUnterschied;
    }

    return winkelUnterschied;
}

int main() {
    // Beispielaufruf der Funktion mit Stunden und Minuten
    int stunden = 3;
    int minuten = 15;

    // Berechnung des Winkels und Ausgabe
    double winkel = winkelBerechnungUhr(stunden, minuten);
    printf("Der Winkel zwischen Stunden- und Minutenzeiger betraegt: %.2f Grad\n", winkel);

    return 0;
}
