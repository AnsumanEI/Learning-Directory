#include <stdio.h  >

int main()
{

    int x = 4;

    int y = 3;

    int z = 2;
    printf("the value of 3x-8y is %d \n " , 3*x - 8*y);

    //operator priority 
    //  1st * / %
    //  2nd + - 
    //  3rd =
    // the answer here comes -12

    //if 
     printf("the value of  8x/3y is %d \n " , 8*x/3*y) ; // answer is coming 30 
     //so associativity  of the operators is used
     //if the priority of the opertaors is same the the compilation follows left to right order
     //the answer of the above is 30 as 
    //  8*4=32
    //  32/3 is 10
    //  10*3 is 30 
    // so brackets are used 
    // x*y/z = (x*Y)/z 
    // x/y*z = (x/y)*z



    return 0;
}