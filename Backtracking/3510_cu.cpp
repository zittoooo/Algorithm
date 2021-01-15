// 예산 관리
#include <iostream>
using namespace std;
int B, N;
int arr[21];
int mx;

void    func(int cur, int tot)
{
    if (cur == N)
    {
        if (tot < B)
        {
            mx = max(mx, tot);
        }
        return ;
    }
    func(cur+1, tot);
    func(cur+1, tot + arr[cur]);
}

int main()
{
    cin >> B;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    func(0,0);
    cout << mx;
}
