#include <iostream>
#include <queue>

using namespace std;

int board[100][100][100];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int M, N, H;
int countZero = 0;
queue<pair<pair<int, int>, int>> q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				cin >> board[i][j][k];

				if (board[i][j][k] == -1)
					countZero++;

				else if (board[i][j][k] == 1)
					q.push({ {i, j}, k });
			}
		}
	}

	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.first.first + dx[dir];
			int ny = cur.first.second + dy[dir];
			int nz = cur.second + dz[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
				continue;

			if (board[nx][ny][nz] == 0) {
				board[nx][ny][nz] = board[cur.first.first][cur.first.second][cur.second] + 1;
				q.push({ {nx, ny}, nz });
			}
		}
	}

	if (countZero == 0)
}