#include <stdio.h>
#include "modules/geometrics.h"

int main() {
    // Beispielwerte für die Körpergrößen
    double quaderLaenge = 3.0, quaderBreite = 4.0, quaderHoehe = 5.0;
    double pyramideSeitenlaenge = 3.0, pyramideHoehe = 4.0;
    double kugelRadius = 2.0;
    double kegelRadius = 2.0, kegelHoehe = 3.0;

    // Berechnungen
    printf("Quader:\n");
    printf("Teilflächen: %.2f\n", quaderTeilflaechen(quaderLaenge, quaderBreite, quaderHoehe));
    printf("Oberflaeche: %.2f\n", quaderOberflaeche(quaderLaenge, quaderBreite, quaderHoehe));
    printf("Volumen: %.2f\n", quaderVolumen(quaderLaenge, quaderBreite, quaderHoehe));

    printf("\nQuadratische Pyramide:\n");
    printf("Teilflächen: %.2f\n", pyramideTeilflaechen(pyramideSeitenlaenge, pyramideHoehe));
    printf("Oberflaeche: %.2f\n", pyramideOberflaeche(pyramideSeitenlaenge, pyramideHoehe));
    printf("Volumen: %.2f\n", pyramideVolumen(pyramideSeitenlaenge, pyramideHoehe));

    printf("\nKugel:\n");
    printf("Teilflächen: %.2f\n", kugelTeilflaechen(kugelRadius));
    printf("Oberflaeche: %.2f\n", kugelOberflaeche(kugelRadius));
    printf("Volumen: %.2f\n", kugelVolumen(kugelRadius));

    printf("\nKegel:\n");
    printf("Teilflächen: %.2f\n", kegelTeilflaechen(kegelRadius, kegelHoehe));
    printf("Oberflaeche: %.2f\n", kegelOberflaeche(kegelRadius, kegelHoehe));
    printf("Volumen: %.2f\n", kegelVolumen(kegelRadius, kegelHoehe));
    return 0;
}
