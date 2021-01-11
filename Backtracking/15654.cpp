#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int isused[10];
int input[10];
int n, m;

void    func(int k)
{
    if (k == m)
    {
        for (int i=0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i])
        {
            arr[k] = input[i];
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    sort(input + 1, input+n+1);
    func(0);
}
/*
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
4 2
9 8 7 1

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며,
각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
1 7
1 8
1 9
7 1
7 8
7 9
8 1
8 7
8 9
9 1
9 7
9 8

*/
