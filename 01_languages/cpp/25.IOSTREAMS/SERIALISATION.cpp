#include <bits/stdc++.h>

using namespace std;
class student
{
public:
    string name;
    int rollno;
    string branch;

    friend ofstream &operator<<(ofstream &ofs, student &std);
    friend ifstream &operator>>(ofstream &ifs, student &std);
    friend ostream &operator<<(ostream &o, student &std);
};
ofstream &operator<<(ofstream &ofs, student &std)
{
    ofs << std.name << endl;
    ofs << std.rollno << endl;
    ofs << std.branch << endl;
    return ofs;
}
ifstream &operator>>(ifstream &ifs, student &std)
{
    ifs >> std.name >> std.rollno >> std.branch;
    return ifs;
}
ostream &operator<<(ostream &o, student &std)
{
    o << std.name << endl;
    o << std.rollno << endl;
    o << std.branch << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    student s1;
    s1.name = "ansuman";
    s1.rollno = 21092932;
    s1.branch = "electronics";
    ofstream ofs1("demo.txt", ios::trunc);
    ifstream ifs1("demo.txt");
    ofs1 << s1;
    ifs1 >> s1;
    cout << s1;

    return 0;
}