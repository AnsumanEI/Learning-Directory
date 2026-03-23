#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    unordered_map<string, string> store;
    string command;
    cout << "Key-Value Store. Commands: SET key value | GET key | DELETE key | EXIT" << endl;

    while (true)
    {
        cout << ">";
        cin >> command;

        if (command == "EXIT")
        {
            cout << "Bye!!" << endl;
            break;
        }

        else if (command == "SET")
        {
            string key, value;
            cin >> key >> value;
            store[key] = value;
            cout << "stored" << endl;
        }
        else if (command == "GET")
        {
            string key;
            cin >> key;
            if (store.find(key) != store.end())
            {
                cout << store[key] << endl;
            }
            else
            {
                cout << "Key not Found!" << endl;
            }
        }
        else if (command == "DELETE")
        {
            string key;
            cin >> key;

            if (store.find(key) != store.end())
            {
                store.erase(key);
                cout << "Deleted" << endl;
            }
            else
            {
                cout << "Key not Found!";
            }
        }
        else
        {
            cout << "Enter a valid Function!" << endl;
        }
    }
    return 0;
}