#include <iostream>
#include <queue>

using namespace std;

int n, m;
int cnt, area;
int board[500][500];
int kindsCnt[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && kindsCnt[i][j] == 0) {
				kindsCnt[i][j] = 1;
				q.push({ i, j });
				cnt++;
				int bufArea = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;

						if (board[nx][ny] == 1 && kindsCnt[nx][ny] == 0) {
							kindsCnt[nx][ny] = 1;
							q.push({ nx, ny });
							bufArea++;
						}
					}
				}
				if (bufArea > area)
					area = bufArea;
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

	bfs();

	cout << cnt << '\n' << area;
}