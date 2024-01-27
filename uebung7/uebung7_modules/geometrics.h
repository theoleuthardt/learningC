#ifndef GEOMETRICS_H
#define GEOMETRICS_H

// Quader
double quaderTeilflaechen(double laenge, double breite, double hoehe);
double quaderOberflaeche(double laenge, double breite, double hoehe);
double quaderVolumen(double laenge, double breite, double hoehe);

// Quadratische Pyramide
double pyramideTeilflaechen(double seitenlaenge, double hoehe);
double pyramideOberflaeche(double seitenlaenge, double hoehe);
double pyramideVolumen(double seitenlaenge, double hoehe);

// Kugel
double kugelTeilflaechen(double radius);
double kugelOberflaeche(double radius);
double kugelVolumen(double radius);

// Kegel
double kegelTeilflaechen(double radius, double hoehe);
double kegelOberflaeche(double radius, double hoehe);
double kegelVolumen(double radius, double hoehe);

#endif //GEOMETRICS_H
