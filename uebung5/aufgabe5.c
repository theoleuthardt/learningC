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

int main(){
    // Befüllung mit verschiedenen Daten
    int number1 = 255;
    int number2 = rand() % 500;
    int number3 = rand() % 500;
    int number4 = rand() % 500;
    int number5 = rand() % 500;

    Add(&number1);
    Add(&number2);
    Add(&number3);
    Add(&number4);
    Add(&number5);

    // Ausgabe der Liste
    printf("%s%d\n", "Item 0: ", *(int *) Get(0));
    printf("%s%d\n", "Item 1: ", *(int *) Get(1));
    printf("%s%d\n", "Item 2: ", *(int *) Get(2));
    printf("%s%d\n", "Item 3: ", *(int *) Get(3));
    printf("%s%d\n", "Item 4: ", *(int *) Get(4));

    // Contains Überprüfung
    if(Contains((void *) 255) != -1)
        printf("%d", "Die Zahl 255 ist am Index: ", Contains((void *) 255));

    // Size von list
    printf("Anzahl der Elemente in der Liste: ");
    printf("%d\n", Size( ));

    // Removetest
    Remove(0);
    Remove(4);
    printf("%s%d\n", "Item 0: ", *(int *) Get(0));
    printf("%s%d\n", "Item 1: ", *(int *) Get(1));
    printf("%s%d\n", "Item 2: ", *(int *) Get(2));
    printf("%s%d\n", "Item 3: ", *(int *) Get(3));
    printf("%s%d\n", "Item 4: ", *(int *) Get(4));

}