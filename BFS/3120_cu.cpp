// 리모컨 https://www.codeup.kr/problem.php?id=3120
#include <iostream>
#include <queue>
using namespace std;
queue<int> Q;
int dist[100];

int a, b, cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    fill(dist, dist + 100, -1);
    Q.push(a);
    dist[a] = 0;
    while (dist[b] == -1)
    {
        int cur = Q.front(); Q.pop();
        for (int nxt : {cur+1, cur-1, cur+5, cur-5, cur+10, cur-10})
        {
            if (nxt < 0 || nxt > 100) continue;
            if (dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur]+1;
            Q.push(nxt);
        }
    }
    cout << dist[b];
}