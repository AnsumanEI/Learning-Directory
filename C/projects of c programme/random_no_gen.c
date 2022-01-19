#include<stdio.h  > 
#include <stdlib.h> 
#include<time.h>

int main() { 

int num ;

srand(time(0));

num = rand()%100 + 1; //generate random number between 1 to 100


printf("the no. to guess is %d", num);

return 0;
}