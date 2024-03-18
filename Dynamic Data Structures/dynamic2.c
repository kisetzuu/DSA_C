#include <stdio.h>
#include <stdlib.h> // Required for malloc and free functions

int main() {
    int *dynamicArray; // Pointer to int, will be used to allocate an array dynamically
    int n; // Size of the array

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' integers
    // The sizeof(int) is multiplied by 'n' to calculate the total size required
    dynamicArray = (int*) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (dynamicArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Return with error code
    }

    // Initializing array elements
    for(int i = 0; i < n; i++) {
        dynamicArray[i] = i + 1; // Just an example initialization
    }

    // Using the dynamic array
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Don't forget to free the memory once done to prevent memory leaks
    free(dynamicArray);

    return 0;
}
