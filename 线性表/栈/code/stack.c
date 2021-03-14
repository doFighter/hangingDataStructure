#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Stack
{
    ElemType elem;
    struct Stack *next;
} stack;
