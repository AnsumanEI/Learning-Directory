#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
//overloading of insertion and extraction operators using friend funtion
class complex
{
	public:
	int real;
	int img;
public:
	complex(int real = 0, int img = 0)
	{
		this->real = real;
		this->img = img;
	}
	void display()
	{
		cout<<real<<" + i"<<img<<endl;
	}
	friend ostream& operator<<(ostream& o, complex& c1);

};
ostream &operator<<(ostream& o, complex& c1)
{
	o << c1.real << " + i" << c1.img << endl;
	

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	complex test(a, b);
	complex test1;
	cout << test << endl;
	test.display();
	return 0;
}