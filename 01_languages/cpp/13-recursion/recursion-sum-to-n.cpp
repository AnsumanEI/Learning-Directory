#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int sum(int x)
{
   if(x==0)
   {
       return 0;
   }
   else
   {
       return sum(x-1)+x;
       
   }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cout<<sum(5);

return 0;
}