#include <math.h>

// Funktionen zur Berechnung der Oberfläche und des Volumens

// Quader
double quaderTeilflaechen(double laenge, double breite, double hoehe) {
    double flaeche1 = laenge * breite;                  // Grundfläche
    double flaeche2 = laenge * hoehe;                   // Seitenfläche 1
    double flaeche3 = breite * hoehe;                   // Seitenfläche 2

    return flaeche1 + 2 * (flaeche2 + flaeche3);       // Gesamte Oberfläche
}

double quaderOberflaeche(double laenge, double breite, double hoehe) {
    return 2 * (laenge * breite + laenge * hoehe + breite * hoehe);
}

double quaderVolumen(double laenge, double breite, double hoehe) {
    return laenge * breite * hoehe;
}

// Quadratische Pyramide
double pyramideTeilflaechen(double seitenlaenge, double hoehe) {
    double grundflaeche = seitenlaenge * seitenlaenge;  // Grundfläche
    double dreiecksflaeche = 0.5 * seitenlaenge * hoehe; // Dreiecksfläche (eine Seite der Pyramide)

    return grundflaeche + 4 * dreiecksflaeche;         // Gesamte Oberfläche
}

double pyramideOberflaeche(double seitenlaenge, double hoehe) {
    return seitenlaenge * seitenlaenge + 2 * seitenlaenge * sqrt((seitenlaenge/2)*(seitenlaenge/2) + hoehe*hoehe);
}

double pyramideVolumen(double seitenlaenge, double hoehe) {
    return (seitenlaenge * seitenlaenge * hoehe) / 3.0;
}

// Kugel
double kugelTeilflaechen(double radius) {
    return 4 * M_PI * radius * radius;                 // Gesamte Oberfläche
}

double kugelOberflaeche(double radius) {
    return 4 * M_PI * radius * radius;
}

double kugelVolumen(double radius) {
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

// Kegel
double kegelTeilflaechen(double radius, double hoehe) {
    double grundflaeche = M_PI * radius * radius;      // Grundfläche
    double mantelflaeche = M_PI * radius * sqrt(radius*radius + hoehe*hoehe); // Mantelfläche

    return grundflaeche + mantelflaeche;               // Gesamte Oberfläche
}

double kegelOberflaeche(double radius, double hoehe) {
    return M_PI * radius * (radius + sqrt(hoehe*hoehe + radius*radius));
}

double kegelVolumen(double radius, double hoehe) {
    return (M_PI * radius * radius * hoehe) / 3.0;
}
