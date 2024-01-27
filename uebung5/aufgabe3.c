#include <stdio.h>
#include <stdlib.h>


struct Stack{
    int data;
    struct Stack *ptr;
};

struct Stack *top = NULL;

int isEmpty(){
    return (top == NULL);
}

void Push(int item){
    struct Stack *temp = (struct Stack *) malloc(sizeof(struct Stack));
    temp->ptr = top;
    temp->data = item;
    top = temp;
}

int Pop(){
    if (top == NULL){
        printf("Stack ist leer!\n");
        return -1;
    }
    struct Stack *temp = top->ptr;
    int popped = top->data;
    free(top);
    top = temp;
    return popped;
}

int Top(){
    if(isEmpty()) {
        printf("Stack ist leer!\n");
        return -1;
    }
    return top->data;
}

int Size(){
    if(isEmpty())
        return 0;

    struct Stack *next = top->ptr;
    int size = 1;
    for (; next != NULL; next = next->ptr) {
        size++;
    }
    return size;
}

int main(){
    // Hinzufügen von Beispieldaten
    Push(1);
    Push(2);
    Push(3);

    // Anzeige des obersten Elements und der Größe vom Stack
    printf("Top-Element: %d\n", Top());
    printf("Stack-Größe: %d\n", Size());

    // Entfernung eines Elements
    int popped = Pop();
    if (popped != -1) {
        printf("Entferntes Element: %d\n", popped);
    }

    // Anzeige des obersten Elements und der Größe vom Stack nach der Entfernung
    printf("Top-Element nach Pop: %d\n", Top());
    printf("Stack-Größe nach Pop: %d\n", Size());

    return 0;
}