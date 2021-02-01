// 구간 합 구하기 4
#include <iostream>
using namespace std;
int d[100005];
int a[100005];
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);    // 없으면 시간 초과
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1 ; i <= N; i++)
    {
        d[i] = d[i-1] + a[i];
    }
    while (M--)
    {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << '\n';
    }
}