#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int L, C;
char tmp;
vector<char> v;
vector<char> pw;

void pwd(int cur)
{
    if (pw.size() == L)
    {
        int m = 0; int j = 0;
        for (int i = 0; i < L; i++)
        {
            char t = pw[i];
            if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
                ++m;
            else
                ++j;
        }
        if (m >= 1 && j >= 2)
        {
            for (int i = 0; i < L; i++)
                cout << pw[i];
            cout << "\n";
        }
        return ;
    }
    for (int i = cur; i < C; i++)
    {
            pw.push_back(v[i]);
            pwd(i + 1);
            pw.pop_back();
    }
}

int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    pwd(0);
}