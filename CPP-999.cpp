#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s("CBA");
    string::iterator p = find(s.begin(), s.end(), 'B');
    if (p != s.end())
    {
        cout << p - s.begin() << endl;
    }
    sort(s.begin(), s.end());
    cout << s << endl;
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout << s << endl;
    return 0;
}