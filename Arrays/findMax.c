#include <stdio.h>

void findMaximum(int array[], int size, int *maxValue, int *maxIndex)
{
    if(size <= 0) return;

    *maxValue = array[0];
    *maxIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] > *maxValue)
        {
            *maxValue =  array[i];
            *maxIndex = i;
        }
    }
}

int main(void)
{
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(num) / sizeof(num[0]);
    int maxValue;
    int maxIndex;

    findMaximum(num, size, &maxValue, &maxIndex);
    
    printf("Maximum value found at the array is %d.\nMax index: %d", maxValue, maxIndex);
}
