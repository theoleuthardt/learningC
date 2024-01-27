#include <stdio.h>
#include <time.h>
#include <limits.h>

struct LargeDataStructure {
    int bigINT;
    long bigLONG;
    float bigFLOAT;
    long double bigLongDOUBLE;
    unsigned long long bigUnsLONG;
};

void DatastructureProcessByValue(struct LargeDataStructure daten){
    long double oneStep = daten.bigLongDOUBLE;
}

void DatastructureProcessByPointer(struct LargeDataStructure *pdaten){
    long double oneStep = pdaten->bigLongDOUBLE;
}

int main(){
    struct LargeDataStructure BIG;
    clock_t start, end;

    // Befüllung von BIG
    BIG.bigINT = INT_MAX;
    BIG.bigLONG = LONG_MAX;
    BIG.bigFLOAT = 213.2131313342534545;
    BIG.bigLongDOUBLE = LONG_MAX;
    BIG.bigUnsLONG = ULLONG_MAX;


    // 10000-Mal einer Prozedur eine große Datenstruktur übergeben als Wert
    start = clock();
    for (int i = 0; i < 10000; i++) {
        DatastructureProcessByValue(BIG);
    }
    end = clock();
    printf("Zeit für die Verarbeitung als regulärer Parameter: %f Sekunden\n", ((double)(end - start)) / CLOCKS_PER_SEC);



    // 10000-Mal einer Prozedur eine große Datenstruktur übergeben als Pointer
    start = clock();
    for (int i = 0; i < 10000; i++) {
        DatastructureProcessByPointer(&BIG);
    }
    end = clock();
    printf("Zeit für die Verarbeitung als Pointer: %f Sekunden\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Fazit: byValueTime=0.00095sec und byPointerTime=0.000056sec → Verarbeitung geht schneller mit Pointern!
    return 0;
}