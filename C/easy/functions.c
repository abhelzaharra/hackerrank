#include <stdio.h>

int sum_of_four(int a, int b, int c, int d);
int max_of_four(int a, int b, int c, int d);

int main(void)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int sum = sum_of_four(a, b, c, d);
    int ans = max_of_four(a, b, c, d);
    printf("%d\n", ans);
    return 0;
}

int sum_of_four(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int max_of_four(int a, int b, int c, int d)
{
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}