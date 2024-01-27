#include <stdio.h>
#include <time.h>

int secondsSinceMonthBegin(){
    // Aktuelle Zeit erhalten
    time_t currentTime;
    time(&currentTime);

    // Lokale Zeitzone des Systems erhalten
    struct tm *localTime;
    localTime = localtime(&currentTime);

    int secondsSinceMonthBegin = localTime->tm_sec +  // Sekunden
                               localTime->tm_min * 60 +  // Minuten
                               localTime->tm_hour * 3600 +  // Stunden
                               (localTime->tm_mday - 1) * 86400;  // Tage

    // Berücksichtigung der Zeitzone
    secondsSinceMonthBegin += timezone;

    return secondsSinceMonthBegin;
}

int main() {
    // Ausgabe der Sekunden seit Monatsbeginn:
    printf("Anzahl der Sekunden seit Monatsbeginn: %d", secondsSinceMonthBegin());
    return 0;
}
