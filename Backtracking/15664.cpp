// N과 M (10)
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int N, M;
bool    isused[10];
int     arr[10];
int     input[10];

void    func(int cur)
{
    if (cur == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    int before = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!isused[i] && (input[i] != before) && input[i] >= arr[cur-1])
        {
            arr[cur] = input[i];
            before = arr[cur];
            isused[i] = 1;
            func(cur+1);
            isused[i]= 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    sort(input+1, input + N+1);
    func(0);
}