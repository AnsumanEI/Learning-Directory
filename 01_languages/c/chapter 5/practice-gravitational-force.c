 #include<stdio.h  > 
#include<math.h>
 float force(float grvt , float m1 ,float m2 , float r ) ;

int main() { 

    float m1, m2 ,r,grvt;

    printf("enter the mass of first body \n");
    scanf("%f", &m1);

    printf("enter the mass of second body \n");
    scanf("%f",&m2);

    printf("enter the  distance between the two  masses \n ");
    scanf("%f" , &r);

    force(1,2,3,4);

    printf("the value of the gravitational attraction between the two masses is %f",force( grvt ,m1,m2,r));



return 0;
}

float force(float grvt ,float m1 ,float m2 , float r ){

float result ;

 grvt= 6.67430*pow(10, -11) ;

result =  (m1*m2)/(r*r) ;
return result ;


}