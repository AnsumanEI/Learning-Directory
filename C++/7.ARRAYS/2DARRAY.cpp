#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int B[2][3] = {01, 2, 33, 45, 4, 3};
    int A[4][3] = {
        {2, 3, 4}, {4, 6, 8}, {27, 33, 14}, {54, 16, 18}};
    // cout<<A[1][3] <<endl;
    // for(int i=0;i<6;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<setw(2)<<A[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }

    for (auto &x : B) // this divides array into smaller ones like one array assigned first then nxt one
    {
        for (auto &y : x) // holds on to elements of the smaller array
        {
            cout << setw(2) << y << " ";
        }
        cout << endl;
    }
    return 0;
}