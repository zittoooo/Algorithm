// 곱셈
#include <iostream>
using namespace std;
using ll = long long;
ll val;

ll  POW(ll a, ll b, ll mod)
{
    if (b == 1) return a % mod;
    val = POW(a, b/2, mod);
    val = val * val % mod;
    if (b % 2 == 0) return val;
    return val * a % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c;
    cin >> a >> b >> c;
    cout << POW(a,b,c);
}