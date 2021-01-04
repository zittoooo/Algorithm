// z
#include <iostream>
using namespace std;

int func(int n, int r, int c)
{
    if (n == 0) return 0;
    int half = 1 << (n-1);  // 한변 길이의 절반 2^(n-1)
    if (r < half && c < half) return func(n-1, r, c);  // 1번 사각형일 때
    if (r < half && c >= half) return half*half + func(n-1, r, c - half);  // 2번 사각형 일 때
    if (r >= half && c < half) return 2*half*half + func(n-1, r-half, c); // 3번 사각형 일 때
    return 3*half*half + func(n-1, r-half, c-half); // 4번 사각형일 때
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, r, c;
    cin >> N >> r >> c;  // 1 ≤ N ≤ 15

    cout << func(N, r, c);  // 3 7 7  -> 63
}