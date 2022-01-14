#include <iostream>
using namespace std;
#define ll long long
int board[1000002];

int main(void){
    int n, k, g, x, end = 0;
    
    cin >> n >> k;
    for (int i = 0; i < n ;i++)
    {
        cin >> g >> x;
        board[x] = g;
        end = max(end, x);
    }
    if (k >= end)
    {
        int ans = 0;
        for (int i = 0; i <= end; i++)
            ans += board[i];
        cout << ans;
        return 0;
    }
    
    ll window = 2*k + 1;
    ll ice = 0;
    for (int i = 0; i < window; i++)
        ice += board[i];
        
    ll ans = ice;
    for (int i = window; i <= end; i++)
    {
        ice += board[i];
        ice -= board[i - window];
        ans = max(ice, ans);
    }
    cout << ans;
}
