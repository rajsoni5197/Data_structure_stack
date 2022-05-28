//here is the code to calculate a postfix expression.
// need to give input in space seprated form i.e. a b + c d e * -z -u + \ (for example only);
//here is how we evaluate postfix expression given via string.
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 500
#define MAX_EXPRESSION_SIZE 500
//implementation of a stack in c
int stack[MAX_STACK_SIZE], top = -1;
void clearStack()
{
    top = -1;
    return;
}
void printStack()
{
    int i;
    if (top < 0)
    {
        printf("\nlist is empty\n");
        return;
    }
    printf("\n");
    for (i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return;
}
void push(int x)
{
    if (top == MAX_STACK_SIZE)
    {
        printf("\nError: stack overflow\n");
        return;
    }
    stack[++top] = x;
    printStack();
    return;
}
void pop()
{
    if (top < 0)
    {
        printf("\nError: list is empty Can't pop \n");
        return;
    }
    top--;
    printStack();
    return;
}

int isEmpty()
{
    return top < 0 ? 0 : 1;
}
//stack implementation end here.

//postfix part starts.
void askExpression(char *expre)
{
    printf("give us the Expressio \n");
    gets(expre);
    return;
}

int ctoi(char ch)
{
    return (int)(ch - '0');
}
int evaluate(char *chArray)
{
    int digit = 0, length = 2, place = 1, i, j;
    for (i = 0; chArray[i] != '\0'; i++)
    {
        switch (chArray[i])
        {
        case '*':
            stack[top - 1] = stack[top] * stack[top - 1];
            pop();
            break;
        case '/':
            stack[top - 1] = stack[top - 1] / stack[top];
            pop();
            break;
        case '+':
            stack[top - 1] = stack[top] + stack[top - 1];
            pop();
            break;
        case '-':
            if (chArray[i + 1] == ' ')
            {
                stack[top - 1] = stack[top - 1] - stack[top];
                pop();
            }
            break;
        default:
            if (chArray[i] == ' ')
                continue;
            if (chArray[i + 1] == ' ' || chArray[i + 1] == '\0')
            {
                --length;
                j = i;
                while (length--)
                {
                    digit += ctoi(chArray[j--]) * place;
                    place *= 10;
                }
                chArray[j] == '-' ? digit *= -1 : digit;
                push(digit);
                digit = 0;
                length = 1;
                place = 1;
            }
            length++;
            break;
        }
    }
    if (isEmpty() && !top)
    {
        return 1;
    }
    return 0;
}
int main()
{
    while (1)
    {
        clearStack();
        char expression[MAX_EXPRESSION_SIZE];
        askExpression(expression);
        int bool = evaluate(expression);
        bool ? printf("\n The Answer of this postFix expression is \t%d \n", stack[top]) : printf("\nError:The Expression is wrong");
    }
    return 0;
}
