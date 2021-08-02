#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int t_len = t.length();
    for (int i = t_len - 1; i >= s.length(); i--)
    {
        if (t[i] == 'A')
            t.pop_back();
        else if (t[i] == 'B')
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (s.compare(t) == 0)
        cout << "1";
    else
        cout << "0";
}