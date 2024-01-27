#include <stdio.h>
#include <stdbool.h>

int main() {

    // A1: Dateien beschreiben
    // a. 10 Strings in eine Datei
    FILE *fptr = fopen("../files/strings.txt", "w");
    if(fptr == NULL){
        printf("Datei kann nicht geoeffnet werden. \n");
        return 1;
    }

    char a[4] = "abc";
    char b[4] = "def";
    char c[4] = "ghi";
    char d[4] = "jkl";
    char e[4] = "mno";
    char f[4] = "pqr";
    char g[4] = "stu";
    char h[4] = "vwx";
    char i[4] = "yza";
    char j[4] = "bcd";

    fprintf(fptr, "%s\n", a);
    fprintf(fptr, "%s\n", b);
    fprintf(fptr, "%s\n", c);
    fprintf(fptr, "%s\n", d);
    fprintf(fptr, "%s\n", e);
    fprintf(fptr, "%s\n", f);
    fprintf(fptr, "%s\n", g);
    fprintf(fptr, "%s\n", h);
    fprintf(fptr, "%s\n", i);
    fprintf(fptr, "%s\n", j);

    fclose(fptr);

    // b. 10 Booleans
    FILE *fptr2 = fopen("../files/booleans.txt", "w");
    if(fptr2 == NULL){
        printf("Datei kann nicht geoeffnet werden. \n");
        return 1;
    }

    bool k = 0;
    bool l = 1;
    bool m = 0;
    bool n = 1;
    bool o = 0;
    bool p = 1;
    bool q = 0;
    bool r = 1;
    bool s = 0;
    bool t = 1;

    fprintf(fptr2, "%d\n", k);
    fprintf(fptr2, "%d\n", l);
    fprintf(fptr2, "%d\n", m);
    fprintf(fptr2, "%d\n", n);
    fprintf(fptr2, "%d\n", o);
    fprintf(fptr2, "%d\n", p);
    fprintf(fptr2, "%d\n", q);
    fprintf(fptr2, "%d\n", r);
    fprintf(fptr2, "%d\n", s);
    fprintf(fptr2, "%d\n", t);

    fclose(fptr2);

    // c. 10 Integers
    FILE *fptr3 = fopen("../files/integers.txt", "w");
    if(fptr3 == NULL){
        printf("Datei kann nicht geoeffnet werden. \n");
        return 1;
    }

    int eins = 1;
    int zwei = 2;
    int drei = 3;
    int vier = 4;
    int funf = 5;
    int sechs = 6;
    int sieben = 7;
    int acht = 8;
    int neun = 9;
    int zehn = 10;

    fprintf(fptr3, "%d\n", eins);
    fprintf(fptr3, "%d\n", zwei);
    fprintf(fptr3, "%d\n", drei);
    fprintf(fptr3, "%d\n", vier);
    fprintf(fptr3, "%d\n", funf);
    fprintf(fptr3, "%d\n", sechs);
    fprintf(fptr3, "%d\n", sieben);
    fprintf(fptr3, "%d\n", acht);
    fprintf(fptr3, "%d\n", neun);
    fprintf(fptr3, "%d\n", zehn);

    fclose(fptr3);

    // d. 10 Long Longs
    FILE *fptr4 = fopen("../files/longlongs.txt", "w");
    if(fptr4 == NULL){
        printf("Datei kann nicht geoeffnet werden. \n");
        return 1;
    }

    long long aa = 0;
    long long ba = 1;
    long long ca = 2;
    long long da = 3;
    long long ea = 4;
    long long fa = 5;
    long long ga = 6;
    long long ha = 7;
    long long ia = 8;
    long long ja = 9;

    fprintf(fptr4, "%lld\n", aa);
    fprintf(fptr4, "%lld\n", ba);
    fprintf(fptr4, "%lld\n", ca);
    fprintf(fptr4, "%lld\n", da);
    fprintf(fptr4, "%lld\n", ea);
    fprintf(fptr4, "%lld\n", fa);
    fprintf(fptr4, "%lld\n", ga);
    fprintf(fptr4, "%lld\n", ha);
    fprintf(fptr4, "%lld\n", ia);
    fprintf(fptr4, "%lld\n", ja);

    fclose(fptr4);

    // e. Zahlen -128 bis 127
    FILE *fptr5 = fopen("../files/short.txt", "w");
    if(fptr5 == NULL){
        printf("Datei kann nicht geoeffnet werden. \n");
        return 1;
    }

    for (int j = -128; j < 128; j++) {
        fprintf(fptr5, "%d\n", j);
    }

    fclose(fptr5);

    return 0;
}
