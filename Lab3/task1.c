#include <stdio.h>
#include <string.h>

#define STACK_SIZE 50

typedef struct {
    char data[STACK_SIZE];
    int top;                    
} Stack;

void init(Stack *s) { s->top = -1; }

int is_empty(Stack *s) { return s->top == -1; }

int is_full(Stack *s) { return s->top == STACK_SIZE - 1; }

int push(Stack *s, char x)
{
    if (is_full(s))
        return 0;
    s->top++;
    s->data[s->top] = x;
    return 1;
}

int pop(Stack *s, char *x)
{
    if (is_empty(s))
        return 0;
    *x = s->data[s->top];
    s->top--;
    return 1;
}

int peek(Stack *s, char *x)
{
    if (is_empty(s))
        return 0;
    *x = s->data[s->top];
    return 1;
}

int main(void)
{
    Stack st;
    char s[256];
    char c;
    int i, depth = 0, max = 0, ok = 1;

    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) == NULL)
        return 0;
    s[strcspn(s, "\r\n")] = '\0';

    init(&st);
    for (i = 0; s[i] != '\0' && ok; i++)
    {
        if (s[i] == '(')
        {
            if (push(&st, '('))
            {
                depth++;
                if (depth > max)
                    max = depth;
            }
            else
            {
                printf("Error: stack overflow at position %d.\n", i + 1);
                ok = 0;
             }
        }
        else if (s[i] == ')')
        {
            if (pop(&st, &c))
                depth--;
            else
            {
                printf("Error: extra ')' at position %d\n", i + 1);
                ok = 0;
            }
        }
    }

    if (ok && !is_empty(&st))
    {
        printf("Error: there is an unclosed '('.\n");
        ok = 0;
    }
    if (ok)
    {
        printf("The parentheses are balanced\n");
        printf("Maximum nesting depth: %d\n", max);
    }

    while (!is_empty(&st))
        pop(&st, &c);

    return 0;
}