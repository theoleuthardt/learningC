#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    // Aktuelle Zeit erhalten:
    time_t now;
    now = time(0);
    char *strNow = ctime(&now);

    // Umformung des Strings
    char day[3];
    char mon[3];
    char year[5];
    char hour[3];
    char min[3];
    char sec[3];

    memcpy(day, strNow + 8, 2);
    day[2] = '\0';

    memcpy(mon, strNow + 4, 3);
    mon[3] = '\0';

    memcpy(year, strNow + 20, 4);
    year[4] = '\0';

    memcpy(hour, strNow + 11, 2);
    hour[2] = '\0';

    memcpy(min, strNow + 14, 2);
    min[2] = '\0';

    memcpy(sec, strNow + 17, 2);
    sec[2] = '\0';


    // Umwandlung des Monats in eine Zahl
    switch (mon[0]) {
        case 'J':
            if (mon[1] == 'a') {
                strcpy(mon, "01");
                break;
            } else if (mon[1] == 'u' && mon[2] == 'n') {
                strcpy(mon, "06");
                break;
            } else if (mon[1] == 'u' && mon[2] == 'l') {
                strcpy(mon, "07");
                break;
            }
            break;
        case 'F':
            if (mon[1] == 'e') {
                strcpy(mon, "02");
                break;
            }
            break;
        case 'M':
            if (mon[1] == 'a' && mon[2] == 'r') {
                strcpy(mon, "03");
                break;
            } else if (mon[1] == 'a' && mon[2] == 'y') {
                strcpy(mon, "05");
                break;
            }
        case 'A':
            if (mon[1] == 'p') {
                strcpy(mon, "04");
                break;
            } else if (mon[1] == 'u' && mon[2] == 'g') {
                strcpy(mon, "08");
                break;
            }
        case 'S':
            if (mon[1] == 'e' && mon[2] == 'p') {
                strcpy(mon, "09");
                break;
            }
        case 'O':
            if (mon[1] == 'c' && mon[2] == 't') {
                strcpy(mon, "10");
                break;
            }
        case 'N':
            if (mon[1] == 'o' && mon[2] == 'v') {
                strcpy(mon, "11");
                break;
            }
        case 'D':
           if (mon[1] == 'e' && mon[2] == 'c') {
               strcpy(mon, "12");
               break;
           }
        default:
            printf("Ungueltiges Monatskuerzel!");
            break;
    }

    // Ausgabe des Strings
    printf("Heute ist der %s.%s.%s und es ist %s:%s Uhr und %s Sekunden.\n", day, mon, year, hour, min, sec);

    return 0;
}
