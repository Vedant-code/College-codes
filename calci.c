#include<stdio.h>
int main()
{
    char operator;
    int a, b, c, n;
    int fact = 1;
    printf("Enter an operator(+, -, *, /): ");
    scanf("%c", &operator);


        printf("enter the value a=");
        scanf("%d", &a);
        printf("enter the value b=");
        scanf("%d", &b);

        switch(operator)
        {
        case '+':
            c = a + b;
            printf("Addition of %d + %d = %d", a, b, c);
            break;
        case '-':
            c = a - b;
            printf("\nSubtraction of %d - %d = %d", a, b, c);
            break;
        case '*':
            c = a * b;
            printf("\nMultiplication of %d * %d = %d", a, b, c);
            break;
        case '/':
            c = a / b;
            printf("\nDivision of %d / %d = %d", a, b, c);
            break;

        default:
            printf("ERROR");
        }
   return 0;
}
