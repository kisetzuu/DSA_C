#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node* next;
} Node, *Nodeptr;

int main()
{
    Nodeptr head = NULL;

    head = (Nodeptr)malloc(sizeof(Node));
    if(head == NULL)
    {
        return -1;
    }
    head -> data = 10;
    head -> next = NULL;

    head->next = (Nodeptr)malloc(sizeof(Node));
    if(head->next == NULL)
    {
        return 1;
    }

    head->next->data = 20;
    head->next->next = NULL; 

    head->next->next = (Nodeptr)malloc(sizeof(Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    head->next->next->next = (Nodeptr)malloc(sizeof(Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    head->next->next->next->next =(Nodeptr)malloc(sizeof(Node));
    head->next->next->next->next->data = 50;
    head->next->next->next->next->next = NULL;

    Nodeptr current = head;
    while(current != NULL)
    {
       printf("%d -> ", current->data);
       current = current->next;
    }
    printf("NULL\n");

    Nodeptr tmp;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}