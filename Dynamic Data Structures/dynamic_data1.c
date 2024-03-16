#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray = NULL; // Pointer to int, initially pointing to nothing
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array dynamically based on the user input
    dynamicArray = (int*) malloc(size *sizeof(int));

    if (dynamicArray == NULL) {
        // Check if the memory allocation failed
        printf("Memory allocation failed\n");
        return -1; // Return an error code
    }

    // Initialize the array with values
    for (i = 0; i < size; i++) {
        dynamicArray[i] = i * 10; // Assign each element a value
    }

    // Print the array
    printf("Dynamic Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Free the allocated memory when done
    free(dynamicArray);

    return 0;
}
