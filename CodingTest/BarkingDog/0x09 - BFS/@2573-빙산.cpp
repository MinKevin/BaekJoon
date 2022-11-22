#include <iostream>
#include <queue>

using namespace std;

int board[300][300];
int vis[300][300];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N, M, cnt, year;

int BFS() {
	queue<pair<int, int>> iceberg;

	do {
		cnt = 0;
		fill(&vis[0][0], &vis[N - 1][M], 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] != 0 && vis[i][j] == 0) {
					vis[i][j] = 1;
					iceberg.push({ i, j });
					cnt++;

					while (!iceberg.empty()) {
						pair<int, int> cur = iceberg.front();
						iceberg.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M)
								continue;

							if (board[nx][ny] == 0 && vis[nx][ny] == 0) {
								if (board[cur.first][cur.second] != 0) {
									board[cur.first][cur.second]--;
								}
							}

							else if (board[nx][ny] != 0 && vis[nx][ny] == 0) {
								vis[nx][ny] = 1;
								iceberg.push({ nx, ny });
							}
						}
					}
				}
			}
		}
		if (cnt >= 2)
			return year;
		year++;
	} while (cnt != 0);
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	cout << BFS();
}