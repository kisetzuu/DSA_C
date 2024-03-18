#include <stdio.h>
#include <stdlib.h>

#define ARRAY 11
#define SIZE 15

typedef struct {
    int items[SIZE];
    int noOfElem;
} Array;

// Function to initialize the number of elements to 0
void initializeNoOfElem(Array *a) {
    a->noOfElem = 0;
}

// Function to add an item if there's room
void addItem(int x, Array *a) {
    if(a->noOfElem < SIZE) {
        a->items[a->noOfElem] = x;
        a->noOfElem++;
    }
}

// Function to read elements from the user and add them to the array
void readArray(Array *a) {
    int x;
    for(int i = 0; i < SIZE; ++i) {
        printf("\nEnter number %d: ", i + 1);
        scanf("%d", &x);
        addItem(x, a);
    }
}

int main() {
    Array myArray;
    initializeNoOfElem(&myArray);
    readArray(&myArray);
    // Further operations with myArray...
    return 0;
}
