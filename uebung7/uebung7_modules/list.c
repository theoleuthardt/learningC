#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
    void *data;
    struct list *ptr;
};

struct list *top = NULL;

int isEmpty(){
    return (top == NULL);
}

void Add(void *data){
    struct list *temp = (struct list *) malloc(sizeof(struct list));
    temp->data = data;
    if(top == NULL){
        temp->ptr = NULL;
        top = temp;
        return;
    }
    temp->ptr = top;
    top = temp;
}

void *Get(int index){
    if (top == NULL)
        return NULL;

    struct list *temp = top;
    for (int i = 0; i <= index; i++) {
        if (temp == NULL){
            printf("Element ist nicht enthalten!");
            return NULL;
        } else if(i == index){
            return temp->data;
        } else{
            temp = temp->ptr;
        }
    }
    return NULL;
}

int Size(){
    if (isEmpty())
        return 0;

    struct list *next = top->ptr;
    int size = 1;
    for (; next != NULL; next = next->ptr) {
        size++;
    }
    return size;
}

int Contains(void *item){
    if (top == NULL) {
        return -1;
    }
    struct list *temp = top;
    for (int i = 0; i < Size(); i++) {
        if (temp == NULL){
            printf("Element ist nicht enthalten!");
            return -1;
        } else if(item == temp->data){
            return i;
        } else{
            temp = temp->ptr;
        }
    }
    return -1;
}

void Remove(int index){
    if(isEmpty())
        return;

    struct list *temp = top->ptr;
    struct list *next = top;

    if(index == 0){
        free(top);
        top = temp;
        return;
    }

    for(int i = 1; i <= index; i++){
        if (temp == NULL)
            return;
        else if (i == index){
            next->ptr = temp->ptr;
            free(temp);
            return;
        } else
            next = temp;
            temp = temp->ptr;
    }
}