#include <cstdio>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define STACK_SIZE 10

typedef struct {
    int *top;
    int *base;
    int stack_size;
}STACK;

int stack_init(STACK *s)
{
    s->base = (int *)malloc(STACK_SIZE * sizeof(int));
    if (s->base == NULL)
    {
        return -1;
    }
    s->top = s->base;
    s->stack_size = STACK_SIZE;

    return 0;
}

void stack_destroy(STACK *s)
{
    free(s->base);
    s->base = s->top = NULL;
    s->stack_size = 0;
}

int stack_length(STACK *s)
{
    int length = 0;

    length = s->top - s->base;

    return length;
}

int stack_empty(STACK *s)
{
    if (s->top == s->base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_push(STACK *s, int e)
{
    if (stack_length(s) >= s->stack_size)
    {
        return -1;
    }

    *(s->top) = e;
    s->top++;

    return 0;
}

int stack_pop(STACK *s, int *e)
{
    if (stack_length(s) == 0)
    {
        return -1;
    }

    s->top--;
    *e = *(s->top);

    return 0;
}

int main()
{
    STACK *s;
    int elem;
    int test = 0;
    while(cin>>test)
    {
        s = (STACK *)malloc(sizeof(STACK));
        if (s == NULL)
        {
            return -1;
        }
        stack_init(s);

        while(test > 0)
        {
            stack_push(s, test % 8);
            test  = test / 8;
        }

        while(stack_empty(s) == 0)
        {
            stack_pop(s, &elem);
            cout<<elem;
        }
        cout<<endl;
    }

    return 0;
}
