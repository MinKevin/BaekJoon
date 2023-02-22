#include <iostream>
#include <queue>

using namespace std;

const int MX = 501;
#define X first
#define Y second

int board[MX][MX];
int vis[MX][MX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
void BFS() {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				vis[i][j] = 1;
				q.push(make_pair(i, j));
				
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || ny < 0 || nx >= n || ny >= m)
							continue;
						if (vis[nx][ny] || board[nx][ny] != 1)
							continue;
						q.push(make_pair(nx, ny));
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	BFS();
}