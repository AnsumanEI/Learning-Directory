 #include<stdio.h  > 
 float temp(  float celcius , float fhr );

int main() { 

float celcius , fhr;

    printf("enter the value in celcius :: \n ");
scanf("%f" , &celcius);

    temp(180 , 356 );

    printf("the value of celcius in fahreniet is :: %f \n" , temp( celcius ,fhr));

return 0;
}

float temp( float celcius , float fhr){


fhr = celcius*1.8 + 32;

return fhr;

}
