// 팩토리얼
#include <iostream>
using namespace std;
int res;

int    fac(int N)
{
    if (N <= 1)
        return 1;
    return (N * fac(N-1));
}

int main()
{
    int N;
    cin >> N;
    if(N == 0 || N == 1)
        cout << 1;
    else
        cout  << N * fac(N - 1);
}