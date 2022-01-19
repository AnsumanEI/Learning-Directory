 #include<stdio.h  > 
 
int main() { 
    //multiplication table of a given no 
    int table;
printf("enter the no whose table is needed \n");
scanf("%d" , &table );

for (int a = 1; table ; a++ ){
if (a>10){break;}


printf(" %d X %d = %d \n " , table , a , table*a );

printf("\n");

}

return 0;
}