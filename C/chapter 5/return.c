 #include<stdio.h  > 
 int sum(int a,int b);

int main() { 

    int a,b,c;

    c = sum(2,3); //arguments are actual

    printf("the sum is :: %d \n",c);

return 0;
}

int sum(int a, int b){

printf("enter the value of a \n");
scanf("%d",&a);
printf("enter the value of b \n");
scanf("%d",&b);

int c;

c= a+b; //parametere are place holders
return c;


}