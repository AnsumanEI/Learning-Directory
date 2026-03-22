 #include<stdio.h  > 
 int into(int a);
int main() { 

int b=10;

printf("the value before the body funttion is executed : %d  \n " , b);

into (b);

printf("the value after the body funttion is executed : %d \n " , b);

return 0;
}
int into(int a){

a=a*10;
return a;

//it is verified that the value doesnot change while using call by value function 

}