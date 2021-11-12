#include <iostream>
#include <cstring>
using namespace std;
long long d[35][65]; // 약 한조각 w개 반조각이 h개 남았을 때 만들 수 있는 개수

// w == 0 -> h만 남은경우 d[w][h] = 1
// h == 0 -> w개가 1개 줄고 h 1개 d[w][0] = d[w-1][1];
// 나머지
// w가 나오면 w가 1개 줄고 h가 1개 생김.
// h가 나오면 hrk 1개 준다.
// d[w][h] = d[w-1][h+1] + d[w][h-1];

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(0);

    while(1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break ;
        memset(d, 0, sizeof(d));
        for(int h = 0; h <= 30; h++)
            d[0][h] = 1;
        for(int w = 1; w <= 30; w++)
        {
            for(int h = 0; h <= 30; h++)
            {
                if(h == 0)
                    d[w][0] = d[w-1][1];
                else
                    d[w][h] = d[w-1][h+1] + d[w][h-1];
            }
        }
        cout << d[n][0] << "\n";
    }
}