#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct node {
    int data;
    struct node *next;
} Node, *Nodeptr;

// Function to create a new node
Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data; // Set node's data
    newNode->next = NULL; // Next pointer is initially NULL
    return newNode; // Return the new node
}

// Function to add a node to the front of the list
Nodeptr addFront(Nodeptr head, int data) {
    Nodeptr newNode = createNode(data); // Create a new node with the given data
    newNode->next = head; // Point new node's next to current head
    head = newNode; // Update head to point to the new node
    return head; // Return the new head
}

// Function to add a node to the end of the list
Nodeptr addEnd(Nodeptr head, int data) {
    Nodeptr newNode = createNode(data); // Create a new node with the given data
    if (head == NULL) { // If list is empty, new node is the head
        return newNode;
    }
    Nodeptr current = head;
    while (current->next != NULL) { // Traverse to the end of the list
        current = current->next;
    }
    current->next = newNode; // Point last node's next to new node
    return head; // Return the head (unchanged)
}

// Function to add a node at a specific position in the list
Nodeptr addAt(Nodeptr head, int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return head;
    }

    Nodeptr newNode = createNode(data); // Create a new node with the given data
    if (position == 1) { // Insert at the front
        newNode->next = head;
        return newNode;
    }

    Nodeptr current = head;
    for (int i = 1; current != NULL && i < position - 1; i++) { // Traverse to the position
        current = current->next;
    }

    if (current == NULL) { // If the position is beyond the end of the list
        printf("Position does not exist.\n");
        free(newNode); // Free the newly created node
    } else {
        newNode->next = current->next; // New node points to current node's next
        current->next = newNode; // Current node points to new node
    }
    return head; // Return the head (unchanged)
}

// Function to print the linked list
void printList(Nodeptr head) {
    Nodeptr current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Nodeptr head = NULL; // Start with an empty list

    // Add nodes to the list
    head = addFront(head, 1); // List: 1
    head = addEnd(head, 2);   // List: 1 -> 2
    head = addAt(head, 3, 2); // List: 1 -> 3 -> 2
    head = addFront(head, 0); // List: 0 -> 1 -> 3 -> 2

    // Print the list
    printList(head);

    // Free the allocated memory
    Nodeptr temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
