// 극장 좌석 배치 2
#include <iostream>
using namespace std;
int k, n, res;

void    func(int cur, int tot, int flag)
{
    if (cur == n)
    {
        if (tot == k)
            res++;
        return ;
    }
    if (flag == 1) // 앉으면 다음자리는 앉지 못함
    {
        func(cur+1, tot, 0);
    }
    else  // 안 앉았으면 마음대로 
    {
        func(cur+1, tot, 0);
        func(cur+1,tot+1, 1);
    }
}

int main()
{
    cin >> n >> k;
    func(0,0,0);
    cout << res;
}