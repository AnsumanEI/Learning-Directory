#include<iostream>
using namespace std;
int main()
{
//is else statement 
//if (abcd){
//     fucntion 
// }
// else{
//     funtion 2 
// }

// *************************************
// switch case (expression){
//     case1:{
//         abcd
//     }
//     default:{

//     }
// }

int income,tax;
cout<<"what is your is your is monthly income : " <<endl;
cin>>income;
tax=0.08*income;
if(income>=200000){
    cout<<"you have to pay the tax of amount : " <<tax <<" and additional bill for your income tax of : " <<income*0.02  <<endl;
}
else if(income>=100000){
    cout<<"you have to pay tax of amount : " <<tax <<endl;
}
else{
    cout<<"you do not have any tax to pay thank you" <<endl;

}
switch (income)
{
case 200000:
    cout<<"you are eligible to pay 2 taxes" <<endl;
    break;
case 100000:
    cout<<"you are eligible to pay 1 tax" <<endl;
    break;
case 10000:
    cout<<"you are not eligble to pay any taxes"<<endl;
    break;


default:cout<<"go away prick" <<endl;
    break;
}
return 0;
}