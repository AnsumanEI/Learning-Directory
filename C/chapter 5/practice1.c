 #include<stdio.h  > 
 
float avg(int a, int b,int c);

int main() { 
int a,b,c;
float result;
    printf("enter number a :: \n");
scanf("%d",&a);

printf("enter number b :: \n");
scanf("%d",&b);

printf("enter number c :: \n");
scanf("%d",&c);

result = avg(a,b,c);

printf("the average of three numbers is :: %f \n" , avg(a,b,c) );


    
    

return 0;
}

float avg(int a, int b,int c){
    
float result ;
    result = (a+b+c)/3 ;
   
    return result;

}




