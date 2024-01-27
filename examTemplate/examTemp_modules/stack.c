#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

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