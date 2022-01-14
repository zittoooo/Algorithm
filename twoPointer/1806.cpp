#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[100001];

int main(void){
    int n, s;
    
    cin >> n >> s;
    vector<int> v(n+1);
    for (int i = 1; i <= n ; i++)
    {
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
    }

    int i = 0, j = 1;
    
    int mn = 1e9;      // 가장 짧은 길이 저장
    while (j <= n && i <= n)
    {
        if (sum[j] - sum[i] >= s)
        {
            mn = min(mn, j-i);
            i++;
        }
        else if (sum[j] - sum[i] < s)
            j++;
    }
    if (mn == 1e9)
        cout << 0;
    else
        cout << mn;
}
