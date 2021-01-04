//우박수 (3n+1)
#include <iostream>
using namespace std;

void     func(int N)
{
    if (N == 1)
    {
        cout << 1 << "\n";
        return ;
    }
    cout << N << '\n';
    if (N % 2 == 0)
    {
        N = N/2;
        return func(N);
    }
    else
    {
        N = 3*N+1;
        return func(N);
    }
    
}

int main()
{
    int N;
    cin >> N;
    func(N);
}