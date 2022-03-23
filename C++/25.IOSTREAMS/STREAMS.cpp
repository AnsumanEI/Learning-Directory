#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream df("demo.txt");
    // if u have some data in the file from before then we can use
    // ofstream outfile("demo.txt", ios::app);
    // ios :: app means here to append
    // to write content in it
    df << "ansuman panigrahi" << endl;
    df << "2111100497" << endl;
    df << "electronics and instrumentation" << endl;

    df << "test subject 1" << endl;
    df << "2111100500" << endl;
    df << "computer science " << endl;

    df << "test subject 2" << endl;
    df << "2111100505" << endl;
    df << "mechanical " << endl;

    df << "test subject 3" << endl;
    df << "2111100507" << endl;
    df << "civil engineering " << endl;

    df << "test subject 4" << endl;
    df << "2111100508" << endl;
    df << "communication s engineering" << endl;
    df.close();

    return 0;
}