#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500

struct Node 
{
    char data;
    struct Node* next;
};
struct Node* top;
struct Node* getNewNode( char x)
{
    struct Node* newNodePointer = (struct Node*)malloc(sizeof(struct Node*));
    newNodePointer->data = x;
    newNodePointer->next =NULL;
    return newNodePointer;
}
void push(char x)
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
int isEmpty()
{
    return (!top?0:1);
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
        printf("%c  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}




void askString(char *strArr, int size)
{
    int i;
    printf("\n Give us the string to check :- \t");
    gets(strArr);
    return;
}

int checkPopOrPush(char *paran ,int index)
{
    if(!top)return 1;
    if(index<3)return 1;
    if(top->data == paran[index-3])
    {
        return 0;
    }
    return 1;
}
int checkIfBalanced(char *a ,int size)
{   
    int i , j , index;
    top = NULL;
    char paran[6] = { '(' , '[' , '{' , ')' , ']' , '}' };
    
    for(i=0 ;a[i] != '\0' ;i++)
    {
        for(j=0; j<6 ; j++)
        {
            if(a[i]==paran[j])
            {
                index = j;
                if(checkPopOrPush(paran,index))
                {
                    push(a[i]);
                }
                else
                {
                    pop(a[i]);
                }
                break;
            }
        }
    }
    
    return !isEmpty();
}
int main()
{
    char strArr[MAX_SIZE];
    int i;
    while (1)
    {
        askString(strArr, MAX_SIZE);
        if(checkIfBalanced(strArr,MAX_SIZE))
        {
            printf("\nyes Parantheses are Balanced.\n");
        }
        else
        {
            printf("\n no Parantheses are Not Balanced.\n");
        }
    }
    return 0;
}
