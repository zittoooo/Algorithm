// N과 M (6)
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int isused[10];
int input[10];
int n, m;

void    func(int k)
{
    if (k == m)
    {
        for (int i=0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i] && input[i] > arr[k-1])
        {
            arr[k] = input[i];
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    sort(input + 1, input+n+1);
    func(0);
}