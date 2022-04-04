#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class items
{
public:
    string name;
    float price;
    int qty;
    int number;
    int count = 1;
    items(string name, float price, int qty)
    {
        this->name = name;
        this->price = price;
        this->qty = qty;
        number = count;
        count++;
    }
    friend ofstream &operator<<(ofstream &ofs, items &obj);
    friend ifstream &operator>>(ifstream &ifs, items &obj);
    friend ostream &operator<<(ostream &o, items &it);
};
ofstream &operator<<(ofstream &ofs, items &obj)
{
    ofs << "item number - " << obj.number << endl;
    ofs << "name::" << obj.name << endl;
    ofs << "price::" << obj.price << endl;
    ofs << "quantity::" << obj.qty << endl;
}
ifstream &operator>>(ifstream &ifs, items &obj)
{
    ifs >> obj.number;
    ifs >> obj.name;
    ifs >> obj.price;
    ifs >> obj.qty;
}
ostream &operator<<(ostream &o, items &it)
{
    cout << "item list number " << it.number + 1 << endl;
    o << "name::" << it.name << endl;
    o << "price::" << it.price << endl;
    o << "quantity::" << it.qty << endl;
}
int main()
{
    int n;
    cout << "enter the number of data " << endl;
    cin >> n;
    string mainname;
    float mainprice;
    int mainqty;
    vector<items *> v;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the data for item " << i + 1 << endl;
        cout << "name,price,quantity ->";
        cin >> mainname >> mainprice >> mainqty;
        v.push_back(new items(mainname, mainprice, mainqty));
    }
    ofstream ofs("grocery.txt");
    ifstream ifs("grocery.txt");
    vector<items *>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        ofs << **itr << endl;
        ifs >> **itr;
        cout << **itr << endl;
    }

    return 0;
}