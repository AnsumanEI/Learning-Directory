 #include<stdio.h  > 
int factorial (int x); 
int main() { 
int a,x;
printf("enter the value of number \n ");
scanf("%d",&x);
    factorial(3);
    printf("the value of factorial %d is %d \n  "  , x , factorial(x)  );

  
return 0;
}
int factorial(int x){

if (x==1 || x==0){
    return 1;
}

else{

return x * factorial (x-1);

}

}