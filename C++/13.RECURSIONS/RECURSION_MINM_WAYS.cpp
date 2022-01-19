#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
template <class t>
t call(t x ,t y)
{
   if(y==1||x==1)
   {
       return 1;
   }
   else
   {
       return call(x,y-1) + call(x-1,y);
   }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout<<call(3,3);

return 0;
}