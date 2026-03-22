 #include<stdio.h  > 
 
int main() { 

int i=8;
int *j = &i; // value at adress operator
int *k = &*j;
//and so on we can add as many pointers as we want in a code or a command


printf("the value of i :: %d \n " , i );
printf("the value of *j :: %d \n " , *j );
printf("the adress of i is :: %d \n " , &i );

printf("we can see that both printed the same numbers \n");

printf("now the adress of the adress storing variable is  :: %d  \n" , &*j);
//we can print  the variable in more complicated codes such as

printf("the value of i is :: %d" , *k );
printf("the adress of *k is :: %d" , &*k );

//pointer to pointer


return 0;
}

//* it can be called as value of -- for example *I it is the value at adress of j
//also called as value at adress operator
 