// N과 M (1)
#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void    func(int k) // 현재 k개까지 수를 택했음.
{
    if (k == m) // m개를 무도 택했으면
    {
        for (int  i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!isused[i]) // 아직 i가 사용되지 않았으면
        {
            arr[k] = i;  // k번째 수를 i로 정함
            isused[i] = 1; //i를 사용했다고 표시
            func(k+1); // 다음 수를 정하러 한단계 더 들어감
            isused[i] = 0;  // k번째 수를 i로 정한 모든 경우에 대해 다 확인 했으니 이제 사용되지 않았다고 명시함
        }
    }
}

int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}