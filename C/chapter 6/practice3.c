 #include<stdio.h  > 
 int into(int *a);


int main() { 
int i = 10;
printf("the value of orignal i before calling :: %d \n " , i );
into(&i);
printf("the value of i after calling is  :: %d  \n " , i);

return 0;
}

int into(int *a){

*a = *a*10;
return *a;

}