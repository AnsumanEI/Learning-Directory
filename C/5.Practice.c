#include <stdio.h>
int main()
{
    int a = 8;
    int b = 6;
    int c = 5;

    printf("the value of a+b+C is equal to %d \n", a + b + c);
    printf("the value of a*b*c is equal to  %d \n", a * b * c);
    printf("the vallue of 2 mulltiplid by four is %d \n", a);
    int d, e, f;

    printf("enter the first value \n ");
    scanf("%d", &d);

    printf("enter the second value \n");
    scanf("%d", &e);

    printf("enter the third value \n");
    scanf("%d", &f);

    printf("the sum of the three no is %d \n", d + e + f);
    printf("the multiplication of the three no is  %d \n", d * e * f);

    char g; 

    printf("press any numerical to terminate  \n");
    scanf("%d", &g);

    printf("thank you %d \n", g);

    return 0;
}
