#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
int N, M;
map<string, bool> a;
set<string> res;
int main()
{
    cin >> N >> M;
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        a.insert({name, 1});
    }
    for (int j = 0; j < M; j++)
    {
        cin >> name;
        if (a.find(name) != a.end())
            res.insert(name);
    }
    cout << res.size() << "\n";
    for (set<string>::iterator it = res.begin(); it != res.end(); it++)
        cout << *it << "\n";
}