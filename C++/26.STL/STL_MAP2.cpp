#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, string> m;
    // input can be given by
    m.insert(pair<string, string>("1", "ansuman"));
    m.insert({"2", "panigrahi"});
    m["3"] = "hello";
    m.erase(m.begin()); // the first one was deleted

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    map<string, string> m1(m);

    for (auto i : m1)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << m.at("2"); // returns ansuman
    cout << endl;
    map<string, string>::iterator itr = m.find("2");
    cout << itr->first << itr->second << " it is the value of the iterator finding 1 " << endl;
    cout << m.count("2"); // checking for 1 if it finds then will return boolean true

    return 0;
}