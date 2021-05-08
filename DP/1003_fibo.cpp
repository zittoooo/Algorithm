#include <iostream>
using namespace std;
int T, N;
long long d[45];

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        d[n] = n;
        return (n);
    }
    else if (d[n] != 0)
        return (d[n]);
    else
    {
        return d[n] = fibonacci(n-1) + fibonacci(n-2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        if (N == 0)
            cout << "1 0" << '\n';
        else if (N == 1)
            cout << "0 1" << '\n';
        else
        {
            fibonacci(N);
            cout << d[N-1] << " " << d[N] << '\n';
        }
    }
    return (0);
}