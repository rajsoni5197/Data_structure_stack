//here is how we inplement array based stack in c 
//also we have operation on it like push ,pop and print.
#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void printStack()
{
    for(int i = 0 ; i <= top ; i++)
    {
        printf("%d ",A[i]);
    }
}
void push(int x)
{
    if(top >= MAX_SIZE-1)
    {
        printf("Error: Stack Overflow \n");
        return;
    }
    A[++top] = x;
}
void pop()
{
    if(top == -1){
        printf("Error: Sorry list is Empty Cant pop now\n");
        return;
    }
    --top;
}
int main()
{
    int pip,x ;
    while(1)
    {
        printf("\n What do you want to do print stack print(0) insert(1) pop (2)\t");
        scanf("%d",&pip);
        switch (pip)
        {
        case 0:
            printf("\n");
            printStack();
            break;
        case 1:
            printf("Give us the value to push \t");
            scanf("%d",&x);
            push(x);
            break;
        case 2:
            pop();
            break;
        default:
            return 0;
        }
    }
}
