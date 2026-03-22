#include <stdio.h  >
//sum of first n natural no using while loop
int main()
{
    int num, sum = 0;
    int a = 0;

    printf("enter the no till which the the sum is required \n");
    scanf("%d", &num);

    for (int a = 0; a <= num; a++)
    {
        sum = sum + a;
    }
    // by using while loop
    while ( a <= num)
    {
        a++;
        sum = sum + a;
    }


    printf("the total sum is :: %d \n ", sum);
    return 0;
}