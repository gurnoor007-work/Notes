#include <iostream>
#include <format>

struct stack
{
    int size;
    int top; // index of topmost element
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int element)
{
    s->top += 1;
    s->arr[s->top] = element;
    std::cout << std::format("Element added to stack, {} at index {}\n", s->arr[s->top], s->top);
}

void pop(struct stack *s)
{
    if (s->top >= 0)
    {
        s->top -= 1;
    }
}


int main()
{
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    return 0;
}