// N과 M (2)
#include <iostream>
using namespace std;
int arr[8];
bool isused[8];
int n, m;

void    func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i] && i >= arr[k-1])
        {
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int     main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}

/*
입력
4 2

출력
1 2
1 3
1 4
2 3
2 4
3 4

*/