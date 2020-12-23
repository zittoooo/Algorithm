//양 한마리... 양 두마리...
#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0 , -1, 0};
int num; // 무리
int T, H, W;
string board[102];
int vis[102][102];
int main(){
	cin >> T;
	while (T--){
		queue<pair<int, int>> Q;
		cin >> H >> W;
		for(int i = 0; i<H; i++)
			for (int j = 0; j < W; j++)
				vis[i][j] = 0;
		for(int i = 0; i < H; i++)
			cin >> board[i];
		num = 0;
		for(int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (board[i][j] == '#' && vis[i][j] == 0){
					num++;
					vis[i][j] = 1;
					Q.push({i,j});
					while (!Q.empty()){
						pair<int ,int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++){
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
							if (board[nx][ny] == '.' || vis[nx][ny]) continue;
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
