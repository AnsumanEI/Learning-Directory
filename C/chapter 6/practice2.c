 #include<stdio.h  > 
 int func(int i);
int main() { 

int i=4;

printf("the adress of i is %u \n" , &i);

func(i);

printf("the adress in the last step : %d \n ", func(&i));

return 0;
}

 int func(int i){
     printf("the adress on 1st step : %d \n " , &i );
     return i;
 }