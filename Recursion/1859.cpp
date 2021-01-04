// 별 삼각형 출력하기
#include <iostream>
using namespace std;

void    g(int k)
{
    if (k == 0)
        return ;
    g(k-1);         // k-1개의 별을 출력하는 함수
    cout << '*';
}
void    func(int k)
{
    if (k == 0)
        return;
    func(k-1);
    g(k);           // k개의 별을 출력하는 재귀 함수
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    func(k);  // k 층의 별 삼각형을 출력한 결과
}