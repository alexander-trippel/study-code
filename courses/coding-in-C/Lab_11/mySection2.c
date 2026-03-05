/*
*FILE: mySection2.c
*Description: Stacks üben
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int key;
    struct Element *pNext;
}Element;

typedef struct Stack
{
    struct Element *pStart;
}Stack;

Stack *init()
{
    Stack *a = malloc(sizeof(*a));
    a -> pStart = NULL;
    return a;
}

void push(Stack *stack, int key)
{
    Element *neu = malloc(sizeof(*neu));
    neu -> key = key;
    neu -> pNext = stack -> pStart;
    stack -> pStart = neu;
    free(neu);
}

int pop(Stack *stack)
{
    int key = stack -> pStart -> key;
    Element *temp = stack -> pStart;
    stack -> pStart = temp -> pNext;
    return key;
}

void stackAusgabe(Stack *stack)
{
    Element *temp = stack -> pStart;
    while (temp != NULL)
    {
        printf("key: %d\n", temp -> key);
        temp = temp -> pNext;
    }
}

int main()
{
    Stack *stack = init();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    stackAusgabe(stack);

    pop(stack);
    pop(stack);

    stackAusgabe(stack);
}

