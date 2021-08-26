//가장 큰 증가 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int arr[1001];

int main()
{
    int N, mx;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    d[0] = arr[0];

    for (int i = 1; i < N; i++)
    {
        mx = 0;
        for (int j = 0; j < i ; j++)
        {
            if (arr[j] < arr[i])
                mx = max(mx, d[j]);
        }
        d[i] = mx + arr[i];
    }

    mx = 0;
    for (int i = 0; i < N; i++)
        mx = max(mx, d[i]);
    cout << mx;
}