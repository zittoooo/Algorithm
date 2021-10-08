#include<iostream>
using namespace std;
int N, M;
int arr[10];

void func(int depth, int cur)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return ;
    }

    for (int i = cur; i <= N; i++)
    {
        arr[depth] = i;
        func(depth+1, i);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func(0, 1);
    return 0;
}