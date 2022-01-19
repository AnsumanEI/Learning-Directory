#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str="ansuman";
//append add new content to the string
str.append(" is a good boy");
cout<<str<<endl;
//insert
str.insert(8," panigrahi ");
cout<<str<<endl;
//replace
str.replace(4,3,"don");
cout<<str<<endl;
//erase
str.erase();
cout<<str<<endl;
str="ansuman";
//pop back and push
str.push_back('p');
cout<<str<<endl;
str.pop_back();
cout<<str<<endl;
//swap
string s1="hello";

str.swap(s1);
cout<<"str = " <<str <<endl;




return 0;
}