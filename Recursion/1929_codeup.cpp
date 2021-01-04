// 우박수 (reverse)
#include <iostream>
using namespace std;

void     func(int N)
{
    if (N == 1)
        return ;
    if (N % 2 == 0)
    {
        N = N/2;
        func(N);
        cout << N << '\n';
    }
    else
    {
        N = 3*N+1;
        func(N);
        cout << N << '\n';
    }
}

int main()
{
    int N;
    cin >> N;
    func(N);
    cout << N;
}