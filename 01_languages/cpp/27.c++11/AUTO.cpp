#include <bits/stdc++.h>

using namespace std;
string testcase()
{
    return "hello is returned ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto test = 3 * 7.9 + 'a';
    cout << test << endl;
    auto test1 = testcase();
    cout << test1 << endl;
    decltype(test1) test2;
    test2 = "hello this is test 2";
    cout << test2 << endl;
    return 0;
}