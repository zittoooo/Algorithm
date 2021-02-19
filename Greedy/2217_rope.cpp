#include <iostream>
#include <algorithm>
using namespace std;
int n, rope[100005], res[100005];

bool    desc(int a, int b)
{
    return a < b;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> rope[i];
    sort(rope, rope+n, greater<int>());
    // for (int i = 0; i < n ; i++)
    //     cout << rope[i] << ' ';
    // cout <<'\n';

    for (int i = 1; i <= n ; i++)
    {
        res[i-1] = rope[i-1] * i;
    }
    cout << *max_element(res, res+n);
}