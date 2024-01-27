#ifndef EXAMTEMPLATE_LIST_H
#define EXAMTEMPLATE_LIST_H

struct list{
    void *data;
    struct list *ptr;
};

void Add(void *data);
void *Get(int index);
int Size();
int Contains(void *item);
void Remove(int index);


#endif //EXAMTEMPLATE_LIST_H
