#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,T=0,sum=0;
	cin>>t;
	while(T<t){
		T++;
		int n,a;
		cin>>n;
	       while(n>0){
	        a=n%10;
	       sum=a+sum;
	       n=n/10;
	    }
	    cout<<sum;
	}
	
	return 0;
}
