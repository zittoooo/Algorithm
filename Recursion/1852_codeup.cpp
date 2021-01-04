// 재귀로 1부터 n까지 한 줄로 출력하기
#include <iostream>
using namespace std;
int n;
void    func(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return ;
    }
    func(n-1);
    cout << n << " ";
}

int main()
{
    cin >> n;
    func(n);
}