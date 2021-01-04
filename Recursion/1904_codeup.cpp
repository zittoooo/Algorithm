// 두 수 사이의 홀수 출력하기
#include <iostream>
using namespace std;
void    func(int a, int b, int c)
{
    if (b == c)
    {
        if (c % 2 != 0)
            cout << c << " ";
        return ;
    }
    if (c % 2 != 0)
        cout << c << " ";
    func(a, b, c + 1);
}


int main()
{
    int a, b, c;
    cin >> a >> b;
    func(a, b, a);
}