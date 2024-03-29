#include <stdio.h>

extern int addition(int a, int b);
extern int subtraction(int a, int b);
extern int multiplication(int a, int b);
extern int division(int a, int b);
extern int remain(int a, int b);

int main()
{
    while (1)
    {
        int op1, op2;
        char operation;
        printf("Welcome to the calculator. Please enter the operation you'd like to perform (example: \"1 + 2\")\n");
        printf("Use only integers for the operands and either +, -, /, or *.\n");
        scanf("%d %c %d", &op1, &operation, &op2);
        switch (operation)
        {
        case '+':
            printf("%d %c %d = %d", op1, operation, op2, addition(op1, op2));
            break;
        case '-':
            printf("%d %c %d = %d", op1, operation, op2, subtraction(op1, op2));
            break;
        case '*':
            printf("%d %c %d = %d", op1, operation, op2, multiplication(op1, op2));
            break;
        case '/':
            printf("%d %c %d = %d r %d", op1, operation, op2, division(op1, op2), remain(op1, op2));
            break;
        default:
            printf("Unrecognized operation!\n");
        }
        char approve;
        scanf("%c", &approve);
        printf("\n\nWould you like to perform another operation? Y/N\n");
        while (1)
        {
            scanf("%c", &approve);
            if (approve == 'Y' || approve == 'N' || approve == 'y' || approve == 'n')
            {
                break;
            }
            printf("Unrecognized input! Please enter either Y or N.\n");
        }
        if (approve == 'N' || approve == 'n')
        {
            break;
        }
    }
}