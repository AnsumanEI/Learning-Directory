#include <stdio.h  >

int main()
{
    int num =1, rem, sum;

    for (int i = 0; i <num; i++)
    {

        rem = num % i;
        if (rem == 0)
        {

            sum += i;

            printf(" :: %d \n" , num);
        }


    }

    return 0;
}