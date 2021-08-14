#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
int n, a, b, ans;
int d[505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        d[i] = 1;
        int cur = v[i].second;
        for (int j = 0; j < i; j++)
        {
            if (cur > v[j].second)
                d[i] = max(d[i], d[j] + 1);
        }
        ans = max(ans, d[i]);
    }
    cout << n - ans;
}

// 8 2 9 1 4 6 7 10