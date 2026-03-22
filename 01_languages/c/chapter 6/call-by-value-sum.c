 #include<stdio.h  > 
 
int sum(int a , int b);

int main() { 
int a =1 ;
 int b =2; //yahan se value ki copy jaati hai in call by value function  
printf("the value of 1+2 is : %d \n " , sum(a,b) );



return 0;
}
int sum(int a , int b){ // upar variables ki copy banti hai and is saved here so the value doesnot  change by change iin the function 
//these are the copy and the value that is called by the function 


return a+b;
//if i change the value of variables it will not change as we cant change the value of variaable of main through funtctions
//but we can change the value of the variable through pointers 
}