#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct node {
    int data;
    struct node *next;
} Node, *Nodeptr;

// Function to delete the first node
Nodeptr deleteFront(Nodeptr head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    Nodeptr toDelete = head; // Node to delete is the head
    head = head->next; // Update head to the second node
    free(toDelete); // Free the deleted node
    return head; // Return the new head
}

// Function to delete the last node
Nodeptr deleteEnd(Nodeptr head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    if (head->next == NULL) { // If there's only one node
        free(head);
        return NULL;
    }
    Nodeptr current = head;
    while (current->next->next != NULL) { // Traverse to the second to last node
        current = current->next;
    }
    free(current->next); // Free the last node
    current->next = NULL; // Update the second to last node's next to NULL
    return head; // Return the head
}

// Function to delete a node at a given position
Nodeptr deleteAt(Nodeptr head, int position) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return head;
    }
    if (position == 1) { // If position is 1, delete the front node
        return deleteFront(head);
    }
    Nodeptr current = head;
    Nodeptr prev = NULL;
    for (int i = 1; current != NULL && i < position; i++) { // Traverse to the position
        prev = current;
        current = current->next;
    }
    if (current == NULL) { // Position is out of bounds
        printf("Position does not exist.\n");
    } else {
        prev->next = current->next; // Update the predecessor's next to skip over the deleted node
        free(current); // Free the deleted node
    }
    return head; // Return the head
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

    // Code to add nodes for demonstration purposes...

    // Print the original list
    printf("Original list: ");
    printList(head);

    // Delete nodes from the list
    head = deleteFront(head); // Delete first node
    printf("After deleting first node: ");
    printList(head);

    head = deleteEnd(head); // Delete last node
    printf("After deleting last node: ");
    printList(head);

    head = deleteAt(head, 2); // Delete node at position 2
    printf("After deleting node at position 2: ");
    printList(head);

    // Free the allocated memory for the remaining nodes...
    // (Similar to the deletion code shown above)

    return 0;
}
