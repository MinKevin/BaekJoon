#include <iostream>
#include <queue>

using namespace std;

int board[200][200];
int vis[200][200][31];

int dx[12] = { 1, 1, 2, 2, -1, -1, -2, -2, 1, -1, 0, 0 };
int dy[12] = { 2, -2, 1, -1, 2, -2, 1, -1, 0, 0, 1, -1 };

int H, W, K;

//{{i, j}, 말처럼 이동한 횟수}
queue<pair<pair<int, int>, int>> q;

int BFS() {
	if (W == 1 && H == 1)
		return 0;

	q.push({ {0, 0}, 0 });
	vis[0][0][0] = 1;

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 12; dir++) {
			if (cur.second >= K && dir < 8) {
				dir = 7;
				continue;
			}
			int nx = cur.first.first + dx[dir];
			int ny = cur.first.second + dy[dir];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W)
				continue;

			if (nx == H - 1 && ny == W - 1) {
				return vis[cur.first.first][cur.first.second][cur.second];
			}

			if (dir < 8) {
				if (board[nx][ny] == 0 && vis[nx][ny][cur.second + 1] == 0) {
					vis[nx][ny][cur.second + 1] = vis[cur.first.first][cur.first.second][cur.second] + 1;
					q.push( { {nx, ny}, cur.second + 1 });
				}
			}
			else {
				if (board[nx][ny] == 0 && vis[nx][ny][cur.second] == 0) {
					vis[nx][ny][cur.second] = vis[cur.first.first][cur.first.second][cur.second] + 1;
					q.push({ {nx, ny}, cur.second });
				}
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}

	cout << BFS();
}