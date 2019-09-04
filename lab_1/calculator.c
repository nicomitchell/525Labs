#include <stdio.h>

extern int addition(int a, int b);
extern int subtraction(int a, int b);
extern int multiplication(int a, int b);
typedef struct
{
    int result;
    int remainder;
} division_result;

extern division_result division(int a, int b);

int main()
{
    int a = 1;
    int b = 2;
    printf("1 + 2 = %d\n", addition(a, b));
    printf("2 - 1 = %d\n", subtraction(b, a));
    printf("2 * 2 = %d\n", multiplication(b, b));
    division_result res = division(b, a);
    printf("2 / 1 = %d r %d\n", res.result, res.remainder);
}