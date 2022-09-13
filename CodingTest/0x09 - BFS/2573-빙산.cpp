#include <iostream>
#include <queue>

using namespace std;

//{높이, 0이된 해}
pair<int, int> board[300][300];
int vis[300][300];

queue<pair<int, int>> iceberg;
queue<pair<pair<int, int>, int>> height;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M, year = 1;

int BFS() {
	int cnt = 0;
	while (!height.empty()) {
		cnt = 0;
		fill(&vis[0][0], &vis[N - 1][M], 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j].first != 0 && vis[i][j] == 0) {
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

							if (board[nx][ny].first != 0 && vis[nx][ny] == 0) {
								vis[nx][ny] = 1;
								iceberg.push({ nx, ny });
							}
						}
					}
				}
			}
		}
		if (cnt >= 2)
			return year - 1; 

		while (!height.empty() && height.front().second == year) {
			pair<int, int> cur = height.front().first;
			height.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				if (board[nx][ny].first == 0 && board[nx][ny].second < year) {
					board[cur.first][cur.second].first--;
					if (board[cur.first][cur.second].first == 0) {
						board[cur.first][cur.second].second = year;
						break;
					}
				}
			}
			if (board[cur.first][cur.second].first != 0) {
				height.push({ {cur.first, cur.second}, year + 1 });
			}
		}
		year++;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int buf;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			if (buf != 0) {
				board[i][j] = { buf, 1 };
				height.push({ {i, j}, 1 });
			}
		}
	}

	cout << BFS();
}