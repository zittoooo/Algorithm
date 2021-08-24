#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, area;
string map[26];
int    done[26][26];
stack <pair<int,int> > s;
vector<int> res;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> map[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '1' && done[i][j] == 0)
            {
                s.push({i,j});
                done[i][j] = 1;
                while (!s.empty())
                {
                    pair<int, int> cur = s.top(); s.pop();
                    area++;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N|| ny < 0 || ny >= N) continue ;
                        if (map[nx][ny] == '0' || done[nx][ny]) continue ;
                        s.push({nx,ny});
                        done[nx][ny] = 1;
                    }
                }
                res.push_back(area);
                area = 0;
            }
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";
}