#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void sortList(struct Node* head) {
    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data < current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }

            current = current->next;
        }

        last = current;
    } while (swapped);
}


void printList(struct Node* head) {
    struct Node* current = head;

    printf("Liste: [");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

void saveNodeInFile(char filepath[], struct Node *head) {
    FILE *file = fopen(filepath, "w");
    struct Node *item = head->next;
    while (item) {
        fwrite(&(item->data), sizeof(int), 1, file);
        item = item->next;
     }
    fclose(file);
}

struct Node* loadNodeFromFile(char filepath[]) {
    FILE *file = fopen(filepath, "r");
    struct Node *list = NULL;
    while (!feof(file)) {
        int number = 0;
        if (fread(&number, sizeof(int), 1, file))
            insertAtBeginning(list, number);
    }
    fclose(file);
    return list;
}

int main() {
    struct Node* head = NULL;

    // 1000 zufällige Werte hinzufügen
    for (int i = 0; i < 1000; i++) {
        int n = rand() % 1000;
        insertAtBeginning(&head, n);
    }

    // Sortierung der Liste
    sortList(head);

    // Ausgabe der Liste
    printList(head);

    //Speicherung von Node in node.txt Datei
    saveNodeInFile("/home/theo/CLionProjects/uebung6/files/node.txt", head);

    //Laden des Inhalts der node.txt in Node
    loadNodeFromFile("/home/theo/CLionProjects/uebung6/files/node.txt");

    return 0;
}
