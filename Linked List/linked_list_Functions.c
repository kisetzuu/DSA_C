#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node* next;
} Node, *Nodeptr;

// Function to create a linked list
Nodeptr createList() {
    Nodeptr head = NULL;
    Nodeptr ptr = NULL;

    head = (Nodeptr)malloc(sizeof(Node)); // Allocate the first node
    if (!head) {
        exit(EXIT_FAILURE); // If malloc fails, exit the program
    }

    head->data = 10; // Initialize the first node
    ptr = head;

    for (int i = 2; i <= 5; i++) {
        ptr->next = (Nodeptr)malloc(sizeof(Node)); // Allocate the next node
        if (!ptr->next) {
            exit(EXIT_FAILURE); // If malloc fails, exit the program
        }
        ptr->next->data = i * 10; // Set data for the new node
        ptr = ptr->next;          // Move to the new node
    }

    ptr->next = NULL; // Last node's next is NULL
    return head;
}

// Function to display the linked list
void display(Nodeptr head) {
    Nodeptr ptr = head;

    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    Nodeptr head = createList(); // Create the linked list
    display(head);               // Display the linked list

    // Free the linked list memory
    Nodeptr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
