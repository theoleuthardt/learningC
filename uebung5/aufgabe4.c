#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
    int data;
    struct list *ptr;
};

struct list *top = NULL;

int isEmpty(){
    return (top == NULL);
}

void Add(int item){
    struct list *temp = (struct list *) malloc(sizeof(struct list));
    temp->ptr = top;
    temp->data = item;
    top = temp;

    if(item >= top->data){
        temp->ptr = top;
        top = temp;
        return;
    }
}

int Get(int index){
    if (isEmpty())
        return 0;
    
    struct list *temp = top;
    for (int i = 0; i < index; i++) {
        if (temp == NULL){
            printf("Element ist nicht enthalten!");
            return -1;
        } else if(i == index){
            return temp->data;
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

void printList(){
    printf("Liste: [");
    for (int i = 0; i <= Size(); i++) {
        printf("%d", Get(i));
        printf(", ");
    }
    printf("]\n");
}

int main(){
    // Hinzufügen von 1000 zufälligen Werten
    for (int i = 0; i < 1000; i++) {
        Add(rand() % 10000);
    }

    // Größe der Liste
    printf("\nGröße von List: ");
    printf("%d\n", Size());

    // Ausgeben der Liste
    printList();

    // Ausgabe eines Elements
    printf("\nElement an der Stelle 100: ");
    printf("%d\n", Get(100));
    return 0;
}