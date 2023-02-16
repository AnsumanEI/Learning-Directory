#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class solution
{
    void combfinder(vector<vector<int>> &ans, vector<int> &nums , vector <int> &ds , int &target , int &index)
    {

    }
    vector <vector<int>> helper ( vector <int> &nums , int &target)
    {
        vector<vector<int>> ans ;
        vector<int> ds;
        combfinder(ans,nums,ds,target,0);
        return ans;
    }  
};
int main()
{
    
    vector<vector<int>>  ans = helper(nums,target);
return 0;
}