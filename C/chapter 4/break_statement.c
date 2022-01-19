#include <stdio.h  >

int main()
{
    int i;
    printf(" enter the value a no \n ");
    scanf("%d", &i);

    for (int a = 0; a <= i; ++a)
    {
        printf(" ::-->> %d \n ", a);
        printf(" \n ");

        if (i==200){break;}
    }

    return 0;
}