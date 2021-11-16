#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int R, C, T;
int map[51][51], after[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int up = 0, down = 0, dust = 0;

void spread()
{
	memset(after, 0, sizeof(after));
	for(int i = 0; i < R ;i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(map[i][j])
			{
				dust = map[i][j] / 5;
				for(int dir = 0; dir < 4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if(map[nx][ny] == -1) continue ;
					after[nx][ny] += dust;
					after[i][j] -= dust;
				}
			}
		}
	}

	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			map[i][j] += after[i][j];
}

void air()
{
    //up
    for(int i = up-1; i > 0; i--)
        map[i][0] = map[i-1][0];
    for(int i = 0; i < C-1; i++)
        map[0][i] = map[0][i+1];
    for(int i = 0; i < up; i++)
        map[i][C-1] = map[i+1][C-1];
    for(int i = C-1; i >= 2; i--)
        map[up][i] = map[up][i-1]; 
    map[up][1] = 0;

    // down
    for(int i = down+1; i < R-1; i++)
        map[i][0] = map[i+1][0];
    for(int i = 0; i < C-1; i++)
        map[R-1][i] = map[R-1][i+1];
    for(int i = R-1; i > down; i--)
        map[i][C-1] = map[i-1][C-1];
    for(int i = C-1; i >= 2; i--)
        map[down][i] = map[down][i-1];
    map[down][1] = 0;
}

void printmap()
{
	cout << "\n";
	for(int i = 0; i < R ;i++)
	{
		for(int j =0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin >> R >> C >> T;
	for(int i = 0; i < R ;i++)
	{
		for(int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == -1 && !up) // 공기 청정기 위
				up = i;
			else if(map[i][j] == -1 && up) // 공기 청정기 아래
				down = i;
		}
	}
	while(T--)
	{
		spread();
		air();
	}
    int sum = 0;
    for(int i = 0; i < R ;i++)
		for(int j = 0; j < C; j++)
            sum += map[i][j];
 
    cout << sum + 2;
	return 0;
}