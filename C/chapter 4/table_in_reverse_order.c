 #include<stdio.h  > 
 
int main() { 

int num;

printf("enter the no. whose table is needed \n");
scanf("%d", &num);

for(int a=num ; num ; a-- ){

if (a<0 || a>10){break;}

printf("%d X %d = %d \n " , num , a , num*a );
printf("\n");
}

return 0;
}