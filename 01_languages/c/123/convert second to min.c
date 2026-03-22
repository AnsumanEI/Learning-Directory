 #include<stdio.h  > 
 
int main() { 
    int h,s,m,a ;
printf("enter the value in second \n %d");
scanf("%d", &s);
h=s/3600;
m=s/60;
s=s;
printf("%d hours %dmins %dseconds \n" , h , m  , s );

return 0;
}