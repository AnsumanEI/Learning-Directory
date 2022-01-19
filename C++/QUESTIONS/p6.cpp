#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n,ans=0;
	    cin>>n;
	    ans+=n%10;
	    while(n>0){
	        n/=10;
	    }
		 cout<<n<<ans;
	    ans=ans+n;
	    cout<<ans;
	    
	}
	return 0;
}
