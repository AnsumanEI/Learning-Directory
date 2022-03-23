#include <bits/stdc++.h>
#include <vector>
// vector is dynamic and it can adjust its size accordingly , as array is not size specific
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v; // at start the size eos the vector is 0
    cout << "capacity ->" << v.capacity() << endl;
    // when the vector is full and another element is inserted then the capacity of the vector doubles in size
    v.push_back(1);
    cout << "capacity ->" << v.capacity() << endl;

    v.push_back(2);
    cout << "capacity ->" << v.capacity() << endl;

    v.push_back(3);
    cout << "capacity ->" << v.capacity() << endl;

    v.push_back(4);
    cout << "capacity ->" << v.capacity() << endl;

    v.push_back(5);
    cout << "capacity ->" << v.capacity() << endl;
    // as after 4 element size is full so the vector doubles its size to 8
    v.shrink_to_fit();
    cout << "capacity ->" << v.capacity() << endl; // the capacity becomes size
    cout << v.at(3) << endl;
    v.clear(); // capacity remains the same but the elements are deleted
    cout << "capacity ->" << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "capacity ->" << v.capacity() << endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "elements before pop ->";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << "\n";
    v.pop_back();
    cout << "elements after pop ->";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    // iterator at begin
    // v.begin();
    // iterator at end
    // v.end();
    cout << "iterator " << endl;
    vector<int>::reverse_iterator it;
    for (it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it;
    }
    cout << endl;
    cout << "vector b =" << endl;
    // intialising vector with elements and particular size
    vector<int>
        b(5, 10); // it means capacity is 5 and is filled with number 10
    for (int i : b)
    {
        cout << i << " ";
    }
    // now to copy a vector into a new vector
    vector<int> last(b); // now b is copied in the vector last
    b.swap(v);
    for (int i : b)
    {
        cout << i << " ";
    }
    cout << b.empty();

    return 0;
}