// 극장 좌석 배치 1
#include <iostream>
using namespace std;
int k, n;
int res;
void    func(int cur, int tot)
{
    if (cur == n)
    {
        if (tot == k)
            res++;
        return ;
    }
    func(cur + 1, tot);
    func(cur + 1, tot + 1);
}

int main()
{
    cin >> n >> k;
    func(0,0);
    cout << res;
}

/*
극장에 n개의 빈 좌석이 있다. 
k명의 관객들이 영화를 보기 위해서 왔다. 

이 관객들이 n개의 좌석에 앉을 수 있는 서로 다른 방법의 수를 구하는 프로그램을 작성하시오. 
(단, k명의 사람을 서로 구분되지 않는다.)
*/