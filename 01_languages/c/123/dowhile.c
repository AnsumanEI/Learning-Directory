//write first n natural numbers 
 #include<stdio.h  > 
 
int main() { 
    int i = 0 ;
    int n;
printf("enter the first the number \n");
scanf("%d" , &n );

do{
    printf(" ::--> %d \n " , i );
    i++;
}
while(i<=n);

return 0;
}