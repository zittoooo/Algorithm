#include <iostream>
#include <algorithm>

/*
m[4][i]

m[4][0] = a4 & a0
= 11 & 1 -> 1011 & 0001 = 0001

m[4][1] = a4 & a1
= 11 & 2 -> 1011 & 0010 = 0010

...

a[i] = m[i][j] | a[i] 

*/

using namespace std;
int a[1005];

int main()
{
    int N, x;
    cin >> N;

    for (int i = 0 ;i < N; i++)
    {
        for (int j = 0 ; j < N; j++)
        {
            cin >> x;
            if (i == j) continue ; // 주대각선
            a[i] = a[i] | x;
        }
    }
    for (int i = 0 ; i < N; i++)
        cout << a[i] << " ";
}