 #include<stdio.h  > 
 
int main() { 


int num;
    printf("enter any no. to check for prime \n ");
    scanf("%d", &num);

    for (int a = 2; a < num; a++)

    {

        if (num % a == 0)
        {

            printf("the no is not  a prime no. as it is divisible by %d ", a );
            break; }

            else
            {

                printf("the no is prime no.");
            }
        
    }



return 0;
}