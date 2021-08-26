#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

priority_queue<int> pq;
string map[51];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N ; i++)
        cin >> map[i];
    int NMmin = min(N, M);
    for (int len = NMmin; len >= 1; len--)
    {
        for (int i = 0; i <= N - len; i++)
        {
            for (int j = 0; j <= M - len; j++)
            {
                if (map[i][j] == map[i+len-1][j] && map[i][j] == map[i+len-1][j+len-1] && map[i][j] == map[i][j+len-1])
                    pq.push(len);
            }
        }
    }
    int mx = pq.top();
    cout << mx *mx;
}