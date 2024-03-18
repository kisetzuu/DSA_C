#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list.
typedef struct node {
    int data;
    struct node* next;
} Node, *Nodeptr;

// Function prototypes.
Nodeptr createList(int num_nodes);
int computeSum(Nodeptr head);
int count(Nodeptr head);
int countPos(Nodeptr head);
int countNeg(Nodeptr head);
int countEven(Nodeptr head);
int countOdd(Nodeptr head);
void display(Nodeptr head);
void freeList(Nodeptr head);

int main() {
    // Create a linked list with 5 nodes for demonstration.
    Nodeptr head = createList(5);

    // Display the linked list.
    display(head);

    // Compute and print the sum of all elements in the list.
    printf("Sum of elements: %d\n", computeSum(head));
    // Count and print various properties of the list.
    printf("Total number of elements: %d\n", count(head));
    printf("Number of positive elements: %d\n", countPos(head));
    printf("Number of negative elements: %d\n", countNeg(head));
    printf("Number of even elements: %d\n", countEven(head));
    printf("Number of odd elements: %d\n", countOdd(head));

    // Free the memory allocated for the list.
    freeList(head);

    return 0;
}

// Function to create and return a linked list with 'num_nodes' nodes.
Nodeptr createList(int num_nodes) {
    Nodeptr head = NULL, ptr = NULL;

    if (num_nodes <= 0) {
        return NULL; // Return an empty list if 'num_nodes' is 0 or negative.
    }

    // Allocate and initialize the first node.
    head = (Nodeptr)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    ptr = head;

    // Create the rest of the nodes, assigning consecutive integers as data.
    for (int i = 2; i <= num_nodes; i++) {
        ptr->next = (Nodeptr)malloc(sizeof(Node));
        ptr = ptr->next;
        ptr->data = i;
        ptr->next = NULL;
    }

    return head;
}

// Function to calculate and return the sum of data in the linked list.
int computeSum(Nodeptr head) {
    int sum = 0;
    Nodeptr ptr = head;

    while (ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }

    return sum;
}

// Function to count and return the total number of elements in the linked list.
int count(Nodeptr head) {
    int ctr = 0;
    Nodeptr ptr = head;

    while (ptr != NULL) {
        ctr++;
        ptr = ptr->next;
    }

    return ctr;
}

// Function to count and return the number of positive elements in the linked list.
int countPos(Nodeptr head) {
    int ctr = 0;
    Nodeptr ptr = head;

    while (ptr != NULL) {
        if (ptr->data > 0) {
            ctr++;
        }
        ptr = ptr->next;
    }

    return ctr;
}

// Function to count and return the number of negative elements in the linked list.
int countNeg(Nodeptr head) {
    int ctr = 0;
    Nodeptr ptr = head;

    while (ptr != NULL) {
        if (ptr->data < 0) {
            ctr++;
        }
        ptr = ptr->next;
    }

    return ctr;
}

// Function to count and return the number of even elements in the linked list.
int countEven(Nodeptr head) {
    int ctr = 0;
    Nodeptr ptr = head;

    while (ptr != NULL) {
        if (ptr->data % 2 == 0) {
            ctr++;
        }
        ptr = ptr->next;
    }

    return ctr;
}

// Function to count and return the number of odd elements in the linked list.
int countOdd(Nodeptr head) {
    int ctr = 0;
    Nodeptr ptr = head;

    while (ptr != NULL) {
        if (ptr->data % 2 != 0) {
            ctr++;
        }
        ptr = ptr->next;
    }

    return ctr;
}

// Function to display the elements of the linked list.
void display(Nodeptr head) {
    Nodeptr ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list.
void freeList(Nodeptr head) {
    Nodeptr temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
