// 보물
#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int a[50], b[50];

int main()
{
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> a[i];
    for (int j = 0; j < n ; j++)
        cin >> b[j];
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    for (int i = 0; i < n  ; i++)
    {
        s += a[i] * b[i];
    }
    cout << s;
}