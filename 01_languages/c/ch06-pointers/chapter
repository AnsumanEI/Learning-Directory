 #include<stdio.h  > //same as call by value but adresses are passed 
 int wrong_swap(int a ,int b); // it doesnot works as it only works if the arguments are give in adress
int swap(int *a , int *b);


int main() { 

int a=3,b=4;

printf("the value of a and b before swap is %d and %d \n" , a,b);

swap(&a,&b);

printf("the value of a and b after swap is %d and %d \n" , a,b);

return 0;
}

int swap(int *a ,int *b){

int temp;
temp = *a;
*a=*b;
*b= temp;



}