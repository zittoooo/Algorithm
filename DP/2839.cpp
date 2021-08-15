#include <iostream>
#include <algorithm>
using namespace std;
int d[5005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    fill_n(d, 5005, -1);
    
    d[3] = 1;
    d[5] = 1;

    for (int i = 6 ; i <= N; i++)
    {
        if (d[i-3] == -1 && d[i-5] == -1)
            continue ;
        if (d[i-3] == -1 && d[i-5] != -1)
        {
            d[i] = d[i-5] + 1;
            continue ;
        }
        if (d[i-3] != -1 && d[i-5] == -1)
        {
            d[i] = d[i-3] + 1;
            continue;
        }
        d[i] = min(d[i-3], d[i-5] ) + 1;
    }
    cout << d[N];
}