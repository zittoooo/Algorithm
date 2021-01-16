// 숏다리의 계단 오르기 (Small)
#include <iostream>
using namespace std;
int N, res, tot;
void    func(int tot, int flag)
{
    if (tot > N)
        return ;
    if (tot == N)
    {
        res++;
        return ;
    }
    if (flag == 1)
    {
        func(tot + 1, 2);
        func(tot + 2, 2);
    }
    else if (flag == 2)
    {
        func(tot + 1, 0);
        func(tot + 2, 0);
    }
    else
    {
        func(tot + 1, 0);
        func(tot + 2, 0);
        func(tot + 3, 1);
    }
}

int main()
{
    cin >> N;
    func(0, 0);
    cout << res;
}