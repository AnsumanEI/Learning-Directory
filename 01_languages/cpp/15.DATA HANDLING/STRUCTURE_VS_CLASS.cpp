#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

struct functions
{

  string name;
  int roll;
  int pmarks;
  int cmarks;
  int bmarks;
  int total;
  int totalmarks();
  char grade();
  string pcheck();
};
int functions::totalmarks()
{

  total = pmarks + cmarks + bmarks;
}
char functions::grade()
{
  return total < 50 ? 'D' : total < 70 ? 'C'
                        : total < 80   ? 'B'
                        : total >= 90  ? 'A'
                                       : 'E';
}
string functions::pcheck()
{
  return total > 33 ? "passed" : total <= 33 ? "failed"
                             : total > 100   ? "invalid"
                                             : "cpp";
}
functions a[100];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // the only difference between a class and a structure is that structure is public and class is private until declared

  cout << "enter your name " << endl;
  cin >> a->name;
  cout << "enter your roll number " << endl;
  cin >> a->roll;
  cout << "enter your physics marks " << endl;
  cin >> a->pmarks;
  cout << "enter your chemistry marks " << endl;
  cin >> a->cmarks;
  cout << "enter your biology marks " << endl;
  cin >> a->bmarks;
  a->totalmarks();
  cout << "your total marks are " << a->total << " you are " << a->pcheck() << " with grade " << a->grade() << endl;

  return 0;
}