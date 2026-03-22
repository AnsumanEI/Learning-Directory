 #include<stdio.h  > 
 void sumavg(int a, int b , int *sum , float  *avg);

int main() { 

int i=4,j=6;
int sum;
float avg;
sumavg(i,j,&sum,&avg);

printf("the sum is : %d \n " , sum);
printf("the average is : %f \n " , avg);

return 0;
}
void sumavg(int a, int b , int *sum , float  *avg){

*sum = a + b;
*avg = (a+b)/2;

}