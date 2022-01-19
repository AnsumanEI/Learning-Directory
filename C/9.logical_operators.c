 #include<stdio.h >
 #include<conio.h>
 
int main() { 
int age;
int vipPass ;
vipPass = 1;

printf("enter your age ? \n");
scanf("%d " , &age );

if ((age>18 && age<70) ||vipPass==0) //enable it to give vip acess to drive so tha every age group can drive

{
    printf("you are capable of driving now \n");
    

}
else if( age== 007){
    printf("this no is a code no. so u can drive");
}
else if(age==966){
    printf("this is a lucky no. u get cash reward and u can drive");
}

else{
    
    printf("you cannot  drive \n ");
}
return 0;
}   