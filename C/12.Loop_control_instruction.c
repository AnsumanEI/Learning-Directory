#include <stdio.h  >

int main()
{
    int a;
    int i;

    printf(" enter the first digit  \n");
    scanf("%d %d ", &i , &a);

    while (a > 100 && a < 300)
    {

        printf(" %d \n", a);

        a++; //print then increment
             //increment then print ++a
        a % 5 == 0;
    }

    do
    {
        printf("the value of i is %d \n ", i);
        i += 10;
    } while (i > 10 && i < 100);

    return 0;
}

    //do while loop example 
    //write first n natural numbers 
//  #include<stdio.h  > 
 
// int main() { 
//     int i = 0 ;
//     int n;
// printf("enter the first the number \n");
// scanf("%d" , &n );

// do{
//     printf(" ::--> %d \n " , i );
//     i++;
// }
// while(i<=n);


//for loop 
// #include <stdio.h  >

// int main()
// {
//     int i;
//     printf("enter the value  of a number  \n ");
//     scanf("%d", &i);

//     for (int a = 0; a <= i; a++)
//     {
//         printf("::--> %d \n ", a);
//         printf(" \n ");
//     }
//     return 0;
// }

// return 0;
// }
