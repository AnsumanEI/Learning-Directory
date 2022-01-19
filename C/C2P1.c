 #include<stdio.h  > 
 
int main() { 
// int a ; b = a ; //it is invalid question 1
int v = 3^3 ; //it is  valid  and called bitwise xor but to give 3 to the power 3 pow(3,3) is used instead of ^ question 2
float z = (3.0/8 -2 );
printf("the value of  %f \n " ,z) ;
int num;

//tocheck the divisibility of a no . with 97
printf("enter the no. \n");
scanf("%d" , &num );
printf("divisibilty test returns: %d \n ",  num%97);

int a =2;
int b =3;
int c =3;
int d =1;
printf(" the value of the given expresssion is %d \n " , 3*a/b-c+d);


return 0;
}