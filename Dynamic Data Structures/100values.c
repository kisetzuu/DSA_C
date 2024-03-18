#include <stdio.h>
#include <stdlib.h>
#define size 10

int main()
{
    int *ptr, i;

    ptr = (int*)malloc(sizeof(int) *size);
    
    for(i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for(i = 0; i < size; i++)
    {
        printf("%d", &ptr[i]);
    }
    int sum = 0;
    for(i = 0; i < size; i++)
    {
        sum += ptr[i];
        printf("Sum = %d", sum);
    }

    return 0;


}