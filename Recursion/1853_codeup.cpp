// 재귀로 1부터 n까지 합 리턴하기
#include <iostream>
using namespace std;
long long    func(long long n)
{
    if (n <= 1) return 1;
    return func(n-1) + n;
}

int main()
{
    long long n;
    cin >> n;
    cout << func(n);
}