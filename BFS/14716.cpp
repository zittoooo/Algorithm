// 현수막
#include <iostream>
#include <queue>
using namespace std;
int board[252][252];
int vis[252][252];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int M, N;
int num;
queue<pair<int, int>> Q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M ; i++)
		for (int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	for (int i = 0; i < M; i++){
		for (int j = 0; j< N; j++){
			if (vis[i][j] == 0 && board[i][j] == 1){
				num++;
				vis[i][j] = 1;
				Q.push({i,j});
				while (!Q.empty()){
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 8; dir++){
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= M*2 || ny < 0 || ny >= N*2) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;
						vis[nx][ny] = 1;
						Q.push({nx,ny});
					}
				}
			}
		}
	}
	cout << num;
}
