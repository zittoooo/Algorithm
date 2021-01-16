// 규칙에 맞는 이진수 만들기 (Small) 
#include <iostream>
using namespace std;
int n, res;

void    func(int k, int cnt)
{
    if (k == n)
    {
        res++;
        return ;
    }
    if (cnt == 0)
        func(k+1, 1);
    else
    {
        func(k+1, 0);
        func(k+1, 1);
    }
}

int main()
{
    cin >> n;
    func(0, 1);
    cout << res;
}