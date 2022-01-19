#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int call(int x,int y)
{
   int count=0,count1=0,count2=0;
   //count
   if(x>=1&&x<=774){count++;}
   //count1
   for(int i=0;i<x;i++)
        {
            if(x%(pow(2,i))==0)
            {
                count1++;                
            }
        }
   //count2
   if(y>=1&&y<=1000000000){count2++}

   if((count==1)&&(count1>0)&&(count2==1)){return 1;}
   else{return 0;}
     

}

int riffle(int x,int y)
{
  
  string odd;
  string even;
  string res;
  string sum="";
  int m[x];
  
  while (x>0)
  {
    for(int j=0;j<m;j++)
    {
        res+=x%10;
        x/=10;
    }
  }
  
  string::iterator it;
  for(it=res.begin();it!=res.end();it++)
  {
      if(*it%2!==0)
      {
         sum+=*it;
      }
      
  }

  string::iterator bt;
  for(bt=res.begin();bt!=res.end();bt++)
  {
      if(*bt%2==0)
      {
         sum+=*bt;
      }
      
  }

  return sum;
  
}


int main()

{

int t;
cin>>t;
while(t--&&t<=100)
{
    int n,k,res;
    cin>>n>>k;
    res=call(n,k);
    if(res==1)
    {
      while(k--)
      {
          
      }
    }
    
}
return 0;
}