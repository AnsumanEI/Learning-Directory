 #include<stdio.h  > 
 
int main() { 
int marks[5];

for (int i =1 ;   i<6 ; i++)
{

printf("enter the value of marks for the student %d : " , i );
scanf("%d" , &marks[i]);

}
return 0;
}