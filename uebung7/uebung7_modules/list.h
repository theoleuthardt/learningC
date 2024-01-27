#ifndef LIST_H
#define LIST_H

int isEmpty();
void Add(void *data);
void *Get(int index);
int Size();
int Contains(void *item);
void Remove(int index);

#endif //LIST_H
