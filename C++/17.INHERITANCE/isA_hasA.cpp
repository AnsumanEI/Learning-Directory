#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
class rectangle
{
private:
  int length;
  int breadth;

public:
  int area();
};
class cuboid : public rectangle // so its an example of isA inheritance (cuboid is a rectangle ot can be said that it uses its functions)
{
private:
  int height;

public:
  int volume();
};
class table
{
private:
  int height;
  int width;

public:
  rectangle top; // its a hasA inheritance as and object of another class is used for inheritance
  int weight();
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}