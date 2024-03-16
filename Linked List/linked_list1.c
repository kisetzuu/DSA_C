#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *createNode(int data) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set the data for the new node
    newNode->data = data;
    // Initially, the next pointer of the new node doesn't point to any node
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the front of the list
void addNodeToFront(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = createNode(data);
    // The new node should point to the current first node of the list
    newNode->next = *head;
    // Now, head points to the new node, making it the first node in the list
    *head = newNode;
}

// Function to traverse the list and print the data of each node
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next; // Move to the next node
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL; // Start with an empty list

    // Add nodes to the list
    addNodeToFront(&head, 10); // List: 10
    addNodeToFront(&head, 20); // List: 20 -> 10
    addNodeToFront(&head, 30); // List: 30 -> 20 -> 10

    // Print the list
    printf("The linked list is: ");
    printList(head);

    return 0;
}
