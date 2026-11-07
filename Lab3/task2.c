#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;
 
typedef struct {
    Node *top;                  
} Stack;
 
void init(Stack *s) { s->top = NULL; }
 
int is_empty(Stack *s) { return s->top == NULL; }
 
int is_full(Stack *s)
{
    (void)s;
    return 0;
}

int push(Stack *s, char x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        return 0;
    n->data = x;
    n->next = s->top;
    s->top = n;
    return 1;
}

int pop(Stack *s, char *x)
{
    Node *n;
    if (is_empty(s))
        return 0;
    n = s->top;
    *x = n->data;
    s->top = n->next;
    free(n);                    
    return 1;
}

int peek(Stack *s, char *x)
{
    if (is_empty(s))
        return 0;
    *x = s->top->data;
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
                if (is_full(&st))
                    printf("Error: stack overflow at position %d.\n", i + 1);
                else
                    printf("Error: failed to allocate memory for a new node (position %d).\n", i + 1);
                ok = 0;
            }
        }
        else if (s[i] == ')')
        {
            if (pop(&st, &c))
                depth--;
            else
            {
                printf("Error: extra ')' at position %d.\n", i + 1);
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
        printf("The parentheses are balanced.\n");
        printf("Maximum nesting depth: %d\n", max);
    }
 
    while (!is_empty(&st))
        pop(&st, &c);
 
    return 0;
}