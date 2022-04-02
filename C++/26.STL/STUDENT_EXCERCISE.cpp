#include <bits/stdc++.h>

using namespace std;
class items
{
public:
    string name;
    float price;
    int quantity;
    items(string name, float price, int quantity)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    float price;
    int quantity;
    vector<items *> v;
    cout << "enter the number of entries -> ";
    int size;
    cin >> size;
    cout << "enter the data -> " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "enter the " << i + 1 << " data :: " << endl;
        cout << "name -> ";
        cin >> name;
        cout << "price -> ";
        cin >> price;
        cout << "quantity ->";
        cin >> quantity;
        v.push_back(new items(name, price, quantity));
    }
    return 0;
}