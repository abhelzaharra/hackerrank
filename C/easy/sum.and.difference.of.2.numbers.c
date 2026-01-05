#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int a;
int b;
float c;
float d;

int main(void)
{
    scanf("%d %d", &a, &b);
    scanf("%f %f", &c, &d);

    int sum_int = a + b;
    int min_int = a - b;
    float sum = c + d;
    float min = c - d;

    printf("%d %d\n", sum_int, min_int);
    printf("%.1f %.1f\n", sum, min);
}