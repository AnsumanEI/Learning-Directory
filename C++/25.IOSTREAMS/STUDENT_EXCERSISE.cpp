#include <bits/stdc++.h>
#include <fstream>

using namespace std;
class item
{
private:
    string name;
    float price;
    int quantity;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }

    friend ofstream &operator<<(ofstream &ofs, item &i);
    friend ifstream &operator>>(ifstream &ifs, item &i);
    friend ostream &operator<<(ostream &o, item &i);
};
ofstream &operator<<(ofstream &ofs, item &i)
{
    ofs << i.name << endl;
    ofs << i.price << endl;
    ofs << i.quantity << endl;
    return ofs;
}
ifstream &operator>>(ifstream &ifs, item &i)
{
    ifs >> i.name >> i.price >> i.quantity;
    return ifs;
}
ostream &operator<<(ostream &o, item &i)
{
    o << i.name << endl;
    o << i.price << endl;
    o << i.quantity << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream ofs("grocery.txt", ios::trunc);
    ifstream ifs("grocery.txt", ios::app);
    item i1;
    i1.setName("carrot");
    i1.setPrice(100);
    i1.setQuantity(200);
    item i2;
    i2.setName("tomato");
    i2.setPrice(150);
    i2.setQuantity(20);
    item i3;
    i3.setName("brinjal");
    i3.setPrice(140);
    i3.setQuantity(7);
    item i4;
    i4.setName("potato");
    i4.setPrice(60);
    i4.setQuantity(50);
    item i5;
    i5.setName("beans");
    i5.setPrice(60);
    i5.setQuantity(30);
    // ofs << i1;
    ifs >> i1;

    ofs << i2;
    ifs >> i2;

    ofs << i3;
    ifs >> i3;

    ofs << i4;
    ifs >> i4;

    ofs << i5;
    ifs >> i5;
    // only cout reads the value given in the session like if we modify the grocery text file the cout will not change if ifs is not done
    // thats the difference in normal cout and after ifs here
    cout << i1;

    cout << endl;
    cout << i2;

    cout << endl;
    cout << i3;

    cout << endl;
    cout << i4;

    cout << endl;
    cout << i5;

    cout << endl;
    return 0;
}