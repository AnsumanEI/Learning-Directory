 #include<stdio.h  > 
 //to find factorial of given n numbers

int main() { 

    int a=0,i, mum = 1;

    printf("enter the no. \n");
    scanf("%d", &i);

    for (int a =1 ; a<=i ; a++)
    {

mum *= a;


    }

    printf("the value of factorial is :: %d \n " , mum);

return 0;
}