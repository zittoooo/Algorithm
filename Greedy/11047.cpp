// 동전 0
#include <iostream>
using namespace std;
int n, k;
int a[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int num = k / a[i];
        res += num;
        k = k - num *a[i];
    }
    cout << res;
}