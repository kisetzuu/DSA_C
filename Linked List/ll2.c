#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node, *Nodeptr;

int main() {
    Nodeptr head = NULL;

    // Allocate memory for the first node
    head = (Nodeptr)malloc(sizeof(Node));
    if (head == NULL) {
        return 1; // Memory allocation failed
    }
    head->data = 10; // Set data for the first node
    head->next = NULL; // Next pointer is initially NULL

    // Allocate memory for the second node and link it to the first node
    head->next = (Nodeptr)malloc(sizeof(Node));
    if (head->next == NULL) {
        return 1; // Memory allocation failed
    }
    head->next->data = 20; // Set data for the second node
    head->next->next = NULL; // Next pointer is initially NULL

    // Repeat the process for the remaining nodes
    head->next->next = (Nodeptr)malloc(sizeof(Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    head->next->next->next = (Nodeptr)malloc(sizeof(Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    head->next->next->next->next = (Nodeptr)malloc(sizeof(Node));
    head->next->next->next->next->data = 50;
    head->next->next->next->next->next = NULL;

    // Print the list
    Nodeptr current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Free the list
    Nodeptr tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
