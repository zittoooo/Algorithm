#include<iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, arr[100002], s, dol, vis[100002];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n; i++)
        cin >> arr[i];
    cin >> s;
    vis[s] = 1;
    dol++;
    q.push(s);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        int nx1 = cur + arr[cur];
        int nx2 = cur - arr[cur];

        if(nx1 <= n && nx1 >= 1 && !vis[nx1])
        {
            dol++;
            vis[nx1] = 1;
            q.push(nx1);
        }
        if(nx2 <= n && nx2 >= 1 && !vis[nx2])
        {
            dol++;
            vis[nx2] = 1;
            q.push(nx2);
        }
    }
    cout << dol;
    return 0;
}