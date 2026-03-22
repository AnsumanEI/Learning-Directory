 #include<stdio.h  > 
 
int main() { 

int i =3;
int *poi;
int **poi2;

poi=&i;
poi2= &poi;

printf("the value of the double pointer is :: %d \n " , **poi2);
return 0;
}