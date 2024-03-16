#include <stdio.h>

int sumArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
void reverseArray(int arr[], int size);


int sumArray(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int findMax(int arr[], int size)
{
    if(size <= 0) return -1;

    int max = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int findMin(int arr[], int size)
{
    if(size <= 0) return -1;

    int min = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while(start < end)
    {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end]=  temp;

        start++;
        end--;
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Sum: %d\n", sumArray(arr, size));
    printf("Max: %d\n", findMax(arr, size));
    printf("Min: %d\n", findMin(arr, size));

    reverseArray(arr, size);
    printf("Reversed array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}