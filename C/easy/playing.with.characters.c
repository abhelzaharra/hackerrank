#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char ch = 'C';
char s[20] = "Language";
char sen[100] = "Welcome To C!!";

int main(void)

{
    scanf("%c", &ch);
    scanf("%s", s);
    scanf(" %[^\n]%*c", sen);

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
}