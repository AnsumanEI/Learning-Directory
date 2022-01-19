#include <stdio.h  >

int main()
{
    int a, b, c, d;

    printf("enter value of 4 numbers by giving space between them %d %d %d %d  \n");
    scanf("%d %d %d %d" , &a , &b , &c  , &d);

    if (a > b && a > c && a > d)
    {
        printf("the greatest integer between these is %d \n", a);
    }
    else if (b > a && b > c && b > d)
    {
        printf("the greatest integer between these is %d \n", b);
    }
    else if (c > b && c > a && c > d)
    {
        printf("the greatest integer between these is %d \n", c);
    }
    else if (d > b && d > c && d > a)
    {
        printf("the greatest integer between these is %d \n", d);
    }
    else
    {
        printf("please enter a value which is a valid integer \n ");
    }

    return 0;
}