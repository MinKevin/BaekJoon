#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int vis[1000][1000][11];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

//{{i, j}, º® ºÎ¼ø È½¼ö}
queue<pair<pair<int, int>, int>> q;

int N, M, K;

int BFS() {
	if (N == 1 && M == 1)
		return 1;

	q.push({ { 0, 0 }, 0 });
	vis[0][0][0] = 1;

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first.first + dx[dir];
			int ny = cur.first.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (nx == N - 1 && ny == M - 1) {
				return vis[cur.first.first][cur.first.second][cur.second] + 1;
			}

			if (board[nx][ny] == 0 && vis[nx][ny][cur.second] == 0) {
				vis[nx][ny][cur.second] = vis[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({{ nx, ny }, cur.second});
			}
			if (board[nx][ny] == 1 && cur.second + 1 <= K && vis[nx][ny][cur.second + 1] == 0) {
				vis[nx][ny][cur.second + 1] = vis[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ {nx, ny}, cur.second + 1 });
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string buf;
		cin >> buf;
		for (int j = 0; j < M; j++) {
			board[i][j] = buf[j] - '0';
		}
	}

	cout << BFS();
}