#include <stdio.h>

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int sum = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }

    printf("Sum of all elements: %d\n", sum);
    
    return 0;
}
