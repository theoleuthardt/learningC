#include <stdio.h>

int main(){
    int i = 10;
    int *j = &i;
    char a = 'a';
    char *b = &a;
    double d = 9.23334;
    double *e = &d;

    printf("%p\n", j);
    printf("%d\n", *j);
    printf("%p\n", b);
    printf("%c\n", *b);
    printf("%p\n", e);
    printf("%f\n", *e);
    return 0;
}