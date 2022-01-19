#include <stdio.h  >

int main()
{
    int year;
    int even;
    

    printf("enter the year you want to check \n");
    scanf("%d", &year);
    

    if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
    {
        printf("the year you entered is a leap year \n ");
    }
    else
    {
        printf("the year you entered is not a leap year\n ");
    }

    int exit;
    printf(" \n ");
    printf(" \n ");
    printf(" \n ");

    printf(" thank you please press 1 to exit\n");
    scanf("%d", exit);
    // dont forget to use double commas after printf
    if (exit == 1)
    {
        printf("thank you \n");
    }
    else
    {
        printf("not thank you \n");
    }

    return 0;
}