// 상자넣기
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1005];
int d[1005];

int main()
{
    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> a[i];
    d[0] = 1;

    for (int i = 1; i < n ; i++)
    {
        d[i] = 1;
        for (int j = 0 ; j < i ; j++)
        {
            if (a[i] > a[j])
                d[i] = max(d[i], d[j]+1);
        }
    }
    cout << *max_element(d, d+n);
}