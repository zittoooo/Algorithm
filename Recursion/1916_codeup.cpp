// 피보나치 수열 (Large)
#include <iostream>
using namespace std;
int arr[201];
long long    fibo(long long N)
{
    if (N <= 2)
    {
        return arr[N] = 1;
    }
    if (arr[N] != 0) return arr[N];
    return arr[N] = (fibo(N-1) + fibo(N-2)) % 10009;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;
    cout << fibo(N) % 10009;
}