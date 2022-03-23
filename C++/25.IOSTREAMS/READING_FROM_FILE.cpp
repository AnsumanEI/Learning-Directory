#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream infile;
    infile.open("demo.txt");
    if (!infile.is_open())
    {
        cout << "no such file exist" << endl;
    }

    string name;
    int rollno;
    string branch;
    int i = 1;
    while (!infile.eof() && i < 6)
    {

        infile >> name;
        infile >> rollno;
        infile >> branch;

        cout << "student number " << i << endl;
        cout << name << endl;
        cout << rollno << endl;
        cout << branch << endl;
        cout << endl;
        cout << endl;
        i++;
    }
    return 0;
}