#include <stdio.h>

extern int addition(int a, int b);

int main()
{
    int a = 1;
    int b = 2;
    printf("%d", addition(a, b));
}