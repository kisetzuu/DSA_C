#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNodeToFront(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    newNode -> next = *head;
    *head = newNode;
}

void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int elem1, elem2, elem3;

    printf("Enter Node 1: ");
    scanf("%d", &elem1);

    printf("Enter Node 2: ");
    scanf("%d", &elem2);

    printf("Enter Node 3: ");
    scanf("%d", &elem3);


    addNodeToFront(&head, elem1);
    addNodeToFront(&head, elem2);
    addNodeToFront(&head, elem3);

    printf("The linked list is: ");
    printList(head);
    
    return 0;
}