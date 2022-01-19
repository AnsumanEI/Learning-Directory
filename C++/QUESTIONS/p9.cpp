#include <iostream>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int p,steps=0,pr;
	    cin>>p;
	    
	    for(int j=11;j>=0;j--){
	        pr=pow(2,j);
	        while(p>=pr){
	        p-=pr;
	        steps++;
	        }
	        
	    }
	    cout<<steps<<endl;
	}
	return 0;
}
