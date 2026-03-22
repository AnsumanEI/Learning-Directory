#include <stdio.h  >

int main()
{
    int i;
    printf("enter the value  of a number  \n ");
    scanf("%d", &i);

    for (int a = 0; a <= i; a++)
    {
        printf("::--> %d \n ", a);
        printf(" \n ");
    }
    return 0;
}