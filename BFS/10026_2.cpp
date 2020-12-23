// 적록색약
#include <iostream>
#include <queue>
using namespace std;
int N, num;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int bfs1(int N){
	char board[102][102];
	int vis[102][102];
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)
		for(int j = 0; j < N ; j++)
			cin >> board[i][j];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (vis[i][j] == 0 && (board[i][j] == 'R' ||board[i][j] == 'G' || board[i][j] == 'B')){
				num++;
				vis[i][j] = 1;
				Q.push({i,j});
				while (!Q.empty()){
					pair<int,int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++){
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
						if (board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny]) continue ;
						vis[nx][ny] = 1;
						Q.push({nx,ny});
					}
				}
			}
		}
	}
	return (num);
}
int bfs2(int N){  // 적록색약
	char board[102][102];
	int vis[102][102];
	num = 0;
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)
		for(int j = 0; j < N ; j++){
			vis[i][j] = 0;
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (vis[i][j] == 0 && (board[i][j] == 'R' || board[i][j] == 'B')){
				num++;
				vis[i][j] = 1;
				Q.push({i,j});
				while (!Q.empty()){
					pair<int,int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++){
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
						if (board[nx][ny] != board[cur.first][cur.second]|| vis[nx][ny]) continue ;
						vis[nx][ny] = 1;
						Q.push({nx,ny});
					}
				}
			}
		}
	}
	return (num);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	cout << bfs1(N) << ' ';
	cout << bfs2(N);
}
