#include<iostream>
using namespace std;
int main()
{
int a[]={-1,-12,-34,-23,6,-54,-23,12,-98,67,143,-45};
int neg=0,pos=0;
for(int i=0;i<13;i++){
    if(a[i]>=0){
        pos++;
    }
    else{
        neg++;
    }
}
cout<<"the number of  positve and negative integers are as follows" <<endl;
cout<<"negative = " <<neg <<endl;
cout<<"positive = " <<pos <<endl;

return 0;
}