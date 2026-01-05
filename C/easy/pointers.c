#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) 

{
    int orig_a = *a;
    int orig_b = *b;

    *a = orig_a + orig_b;
    *b = abs(orig_a - orig_b);
}


int main(void) 

{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}