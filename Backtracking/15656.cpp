// N과 M (7)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 7
using namespace std;

int N, M;
int arr[MAX];
vector<int> v;

void    input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
}

void    solve(int k)
{
    if (k == M)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        v.push_back(arr[i]);
        solve(k+1);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve(0);
    return (0);
}

/*
입력
4 2
9 8 7 1

출력
1 1
1 7
1 8
1 9
7 1
7 7
7 8
7 9
8 1
8 7
8 8
8 9
9 1
9 7
9 8
9 9
*/