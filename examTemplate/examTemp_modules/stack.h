#ifndef EXAMTEMPLATE_STACK_H
#define EXAMTEMPLATE_STACK_H

struct Stack{
    int data;
    struct Stack *ptr;
};

int isEmpty();
void Push(int item);
int Pop();
int Top();
int Size();

#endif //EXAMTEMPLATE_STACK_H
