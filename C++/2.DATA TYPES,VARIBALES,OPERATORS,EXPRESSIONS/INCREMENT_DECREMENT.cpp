#include<iostream>
using namespace std;
int a =10 , b=15 ;
int main(){
    //some special arithmetic operators 
   
std::cout<<"* type of special arithmetic operators: " ;
    std::cout<<endl;
    std::cout<< "the value of a++ is " <<a++ <<" \nafter operation the value of a is :" <<a <<std::endl; //a++ means fist print value of a then add 1 to it 
    std::cout<< "the value of a-- is " <<a-- <<" \nafter operation the value of a is :" <<a <<std::endl;
    std::cout<< "the value of ++a is " <<++a <<" \nafter operation the value of a is :" <<a <<std::endl; //++a means first add 1 to the value then print
    std::cout<< "the value of --a is " <<--a <<" \nafter operation the value of a is :" <<a <<std::endl;
    std::cout<<"_____________________________________________________________________________________" <<std::endl;
    std::cout<<endl;

//************************************************************************************************************************

std::cout<<"* type of comparison operators:" ;
    std::cout<<endl;
    std::cout<<"the value of a==b --> {"<<(a==b) <<"}" << std::endl ;
    std::cout<<"the value of a!=b --> {"<<(a!=b) <<"}" << std::endl ;
    std::cout<<"the value of a>=b --> {"<<(a>=b) <<"}" << std::endl ;
    std::cout<<"the value of a<=b --> {"<<(a<=b) <<"}" << std::endl ;
    std::cout<<"the value of a>b  --> {"<<(a>b) <<"}" << std::endl ;
    std::cout<<"the value of a<b  --> {"<<(a<b) <<"}" << std::endl ;
    std::cout<<"_____________________________________________________________________________________" <<std::endl;
    std::cout<<endl;

//************************************************************************************************************************
    std::cout<<"* types of logical operators:";
    std::cout<<endl;
    std::cout<<"the value will be printed true if both the values are true in 'and' logical operator (a==b)&&(a>=b) --> {"<<((a==b)&&(a>=b)) <<"}" << std::endl ;
    std::cout<<"the value will be printed true if anyone of the values are true in 'or' logical operator (a==b)||(a<=b) --> {"<<((a==b)||(a<=b)) <<"}" << std::endl ;
    std::cout<<"the value will be printed the negative of the real value in  'not' logical operator (!a==b) --> {"<<(!(a==b)) <<"}" << std::endl ;
    std::cout<<"_____________________________________________________________________________________" <<std::endl;

    

    return 0;
}