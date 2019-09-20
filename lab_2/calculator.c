// Demo 1 
// Spalding, Abby
// CECS 525

#include <stdio.h>

extern int add(int a,int b);
extern int sub(int a, int b);
extern int mult(int a, int b);
extern int divide(int a, int b);
extern int div2(int a, int b);

int main()
{
int s;

int s1;
int s2;
	
while(s != 5){
		printf("\n");
		printf("MENU: \n");
		printf("Select (1) for Addition\n");
		printf("Select (2) for Subtraction\n");
		printf("Select (3) for Multiplication\n");
		printf("Select (4) for Division\n");
		printf("Select (5) to Exit\n");
		printf("Which operation would you like to perform?: ");
		scanf("%d",&s);
		printf("\n");
	
		if(s == 1)
		{
			printf("Let's Add!");
			printf("\n");
			printf("Enter first number: ");
			scanf("%d", &s1);
			printf("Enter second number: ");
			scanf("%d", &s2);
			
			printf("The sum is: %d", add(s1,s2));

			printf("\n");
		}
		
		if(s == 2)
		{
			printf("Let's Subtract!");
			printf("\n");
			printf("Enter first number: ");
			scanf("%d", &s1);
			printf("Enter second number: ");
			scanf("%d", &s2);
		
			printf("The difference is: %d", sub(s1,s2));

			printf("\n");
		}
		
		if(s == 3)
		{
			printf("Let's Multiply!");
			printf("\n");
			printf("Enter first number: ");
			scanf("%d", &s1);
			printf("Enter second number: ");
			scanf("%d", &s2);
		
			printf("The product is: %d", mult(s1,s2));

			printf("\n");
		}
		
		if(s == 4)
		{
			printf("Let's Divide!");
			printf("\n");
			printf("Enter first number: ");
			scanf("%d",&s1);
		
			printf("Enter second number: ");
			scanf("%d",&s2);
			
			if(s2==0){
				printf("Please enter a number that is not zero for the divisor: ");
				scanf("%d",&s2);
			}
			
			if(s1<0 && s2<0){
				int a = -1*s1;
				int b = -1*s2;
				printf("The quotient is %d\n", divide(a,b));
				printf("The remainder is %d", div2(a,b));
				printf("\n");
			}
			else if(s1<0){
				int a = -1*s1;
				printf("The quotient is %d\n", -1*divide(a,s2));
				printf("The remainder is %d", div2(a,s2));
			}
			else if(s2<0){
				int b = -1*s2;
				printf("The quotient is %d\n", -1*divide(s1,b));
				printf("The remainder is %d", div2(s1,b));
			}

			else{
			printf("The quotient is %d\n", divide(s1,s2));
			printf("The remainder is %d", div2(s1,s2));
			printf("\n");
			}

		}
}
	if(s == 5){}

}

