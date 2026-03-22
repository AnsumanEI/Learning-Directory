#include <stdio.h  >

int main()
{
    float income, tax = 0;
    int exit;

    printf("enter the yearly income ");
    scanf("%f", &income);

    if (income >= 250000 && income < 500000)
    {
        tax += 0.05 * (income - 250000);
        printf("the tax u have to pay on your income is %f \n", tax);
    }

    else if (income >= 500000 && income <= 1000000)
    {
        tax += 0.2 * (income - 500000);
        printf("the tax u have to pay on your income is %f \n", tax);
    }

    else if (income > 1000000)
    {
        tax += 0.3 * (income - 1000000);
        printf("the tax u have to pay on your income is %f \n", tax);
    }

    else if (income < 250000)
    {
        tax += 0 * (income);

        printf("the tax you have to pay is %f \n ", tax);
    }

    else {
        printf("please enter a valid income to calculate your tax \n");
    }

    printf("thank you please press one to exit \n");
    scanf("%d", exit);

    if (exit == 1)
    {
        printf("thank you \n");
    }
    else
    {

        printf("if you could press one it would have been great \n");
    }

    return 0;
}