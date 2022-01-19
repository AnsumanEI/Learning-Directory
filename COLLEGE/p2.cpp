#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int max(int x,int y,int z)
{
  
  return x>y&&x>z?x:y>z?y:z;

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout<<"enter three numbers" <<endl;
int a,b,c;
cin>>a>>b>>c;
cout<<"the greatest number is ";
cout<<max(a,b,c)<<endl;
return 0;
}