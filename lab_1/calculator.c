#include <stdio.h>

extern int addition(int a, int b);
extern int subtraction(int a, int b);
extern int multiplication(int a, int b);
extern int division(int a, int b);
extern int remainder(int a, int b);

int main()
{
    int a = 10;
    int b = 62;
    printf("1 + 2 = %d\n", addition(a, b));
    printf("2 - 1 = %d\n", subtraction(b, a));
    printf("2 * 2 = %d\n", multiplication(b, b));
    printf("2 / 1 = %d r %d\n", division(b, a), remainder(b, a));
}