 #include<stdio.h  > 
 #include<time.h>
 #include<stdlib.h>
int main() { 
int variable;
srand(time(0));
variable = rand()%100 + 1;
int *i = &variable;
printf("your random number is : %d \n " , variable);


printf("calling the adress of the variable : %d \n " , &variable);

printf("calling the value of variable through adress : %d  \n " ,   *i );
return 0;
}