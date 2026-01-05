#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)

{
    int a, b;
    scanf("%d %d", &a, &b);

    const char *names[] = 
    
    {
        "", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    for (int n = a; n <= b; n++)
    
    {

        if (n >= 1 && n <= 9)
        {
            printf("%s\n", names[n]);
        }
        
        else
        
        {
            printf("%s\n", (n % 2 == 0) ? "even" : "odd");
        }
    }

}