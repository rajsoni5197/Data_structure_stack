//here is a implementation of stack in linked list .
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* top;

struct Node* getNewNode( int x)
{
    struct Node* newNodePointer = (struct Node*)malloc(sizeof(struct Node*));
    newNodePointer->data = x;
    newNodePointer->next =NULL;
    return newNodePointer;
}

void printStack()
{
    struct Node* temp = top;
    if(!temp)
    {
        printf("\nList is Empty\n");
        return;
    }
    printf("\nTop -> ");
    while(temp)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}
void push(int x)
{
    //simply it is a function of where we are inserting data at start of ll.
    struct Node* newNode = getNewNode(x);
    if(!top)
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top=newNode;
    return;
}
void pop()
{
    if(!top)
    {
        printf("\nError: can't Pop Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return;
}
struct Node* topElement()
{
    if(!top)
    {
        printf("\nError: list is empty no top element\n");
        return 0;
    }
    return top;
}
int isEmpty()
{
    return (!top?0:1);
}

int main () 
{
    int option ,x;
    top = NULL;
    while(1)
    {
        printf("\nGive us the Opration you want to perform 0->push 1->pop 2->topElement 3->isEmpty 4->printStack\t");
        scanf("%d",&option);
        switch (option)
        {
        case 0:
            printf("\nGive us the data to push ->\t");
            scanf("%d",&x);
            push(x);
            break;
        case 1:
            pop();
            break;
        case 2:
            printf("\nTop Element ->%d %d\n",topElement()->data,topElement()->next);
            break;
        case 3:
            printf("\n%s stack is Empty\n",isEmpty()?"No":"Yes");
            break;
        case 4:
            printStack();
            break;            
        default:
            break;
            break;
        }
    }
    return 0;
}
