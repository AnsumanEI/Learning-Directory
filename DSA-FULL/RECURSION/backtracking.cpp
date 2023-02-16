#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int func(int n)
{
    if(n==0)
    {return 0;}
    func(n-1);
    cout<<n<<endl;
}
int main()
{
func(10);
return 0;
}