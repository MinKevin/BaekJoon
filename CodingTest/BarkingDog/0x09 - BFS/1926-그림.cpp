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
	{
		int count = 0, maxWidth = 0, countWidth = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {

					vis[i][j] = 1;
					q.push(make_pair(i, j));

					count += 1;
					countWidth = 0;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						countWidth++;

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
}