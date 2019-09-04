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
            printf(" = %d", addition(op1, op2));
            break;
        case '-':
            printf(" = %d", subtraction(op1, op2));
            break;
        case '*':
            printf(" = %d", multiplication(op1, op2));
            break;
        case '/':
            printf(" = %d r %d", division(op1, op2), remain(op1, op2));
        default:
            printf("Unrecognized operation!\n");
        }
        printf("Would you like to perform another operation? Y/N\n");
        char approve;
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