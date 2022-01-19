 #include<stdio.h  > 
 
int main() { 
    int i;

int *ptr = &i;

printf("the value of ptr is : %u \n " , ptr );
ptr++;
ptr ++; // as we can see that the adress is being added by 4 

printf("the value of ptr is : %u \n " , ptr );

return 0;
}