//피보나치 수 5 (재귀)
#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibo(n - 1) + fibo(n-2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
    {
        int res = 0;
        res = fibo(n - 1) + fibo(n - 2);
        cout << res;
    }
}