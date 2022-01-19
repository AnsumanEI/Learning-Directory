#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    char op;
    float a, b, result;

    printf("enter first no. : \n");
    scanf("%f", &a);

    printf("enter second no.:\n");
    scanf("%f", &b);

    printf("choose operator [* , + , - , /] : \n ");
    scanf("%s", &op);
    
    if (op == '*')
    {
        printf("the value is : %f \n", (a * b));
    }
    else if (op == '+')
    {
        printf("the value is : %f \n", (a + b));
    }
    else if (op == '-')
    {
        printf("the value is : %f \n", (a - b));
    }
    else if (op == '/')
    {
        printf("the value is : %f \n", (a / b));
    }
    else
    {
        printf("invalid function please try again");
    }

    return 0;
}