#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{

int T=0;
cin>>T;
while(T!=0){
    int A,B;
    cin>>A>>B;
    int rem=A%B;
    cout<<rem;
    T--;
    }
return 0;
}