#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(void)

{
    int n;
    scanf("%d", &n);
    int d = 2 * n - 1;
    for (int i = 0; i < d; i++)
    
    {
        for (int j = 0; j < d; j++)
        
        {
            int top = i, left = j, bottom = d - 1 - i, right = d - 1 - j;
            int m = top < left ? top : left;
            m = m < bottom ? m : bottom;
            m = m < right ? m : right;
            printf("%d ", n - m);
        }
        
        printf("\n");
    }
}