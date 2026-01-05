#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) 

{

    char s[1025];
    int f[10] = {0};
    scanf("%[^\n]", s);
    for (int i = 0; i < strlen(s); i++)
        if (s[i] >= '0' && s[i] <= '9')
            f[s[i] - '0']++;

    for (int i = 0; i < 10; i++)
        printf("%d ", f[i]);
}