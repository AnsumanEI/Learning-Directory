 #include<stdio.h  > 
 
int main() { 
int a = 14; //type declartion function
int b = 4;
printf("the value of a + b %d /n " , a + b) ; // arithmetic declartion function
printf("the value of a - b %d /n " , a - b) ;//operands means the no. used by operators
printf("the value of a * b %d /n " , a * b) ;
printf("the value of a / b %d /n " , a / b) ;

//z = a + b; //legal
// a + b = z; //illegal
printf("the remainder when a is divide b %d \n   " , a%b );

// 5%2 = 1 
// -5%2 = -1
// 5%-2 = 1


return 0;
}