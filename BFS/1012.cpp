#include <iostream>
#include <queue>
using namespace std;
int board[2500][2500];
int vis[2500][2500];
int T, M, N , K , x, y;
int num;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--){
		cin >> N >> M >> K;  // 가로 세로 배추몇개
		for (int i = 0; i< N; i++)
			for (int j = 0; j < M; j++){
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		for (int i = 0 ; i < K; i++){
			cin >> x >> y;
			board[x][y] = 1;
		}
		num = 0;
		queue<pair<int,int>> Q;
		for (int i = 0; i < N; i ++){
			for (int j = 0; j < M; j++){
				if (board[i][j] == 1 && vis[i][j] == 0){
					num++;
					vis[i][j] = 1;
					Q.push({i,j});
					while (!Q.empty()){
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++){
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
							if (vis[nx][ny] || board[nx][ny] == 0) continue;
							vis[nx][ny] = 1;
							Q.push({nx,ny});
						}
					}
				}
			}
		}
		cout << num << '\n';
	}
}
