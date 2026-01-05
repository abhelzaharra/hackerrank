#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++)
    
    {
        scanf("%d", arr + i);
    }


    for (int l = 0, r = num - 1; l < r; l++, r--)
        
    {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
    }


    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
}