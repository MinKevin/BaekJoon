#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;
int rawTomato, result;
queue<pair<int, int>> q;

int BFS() {
	if (rawTomato == 0)
		return 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (board[nx][ny] == 0) {
				board[nx][ny] = board[cur.first][cur.second] + 1;
				q.push({ nx, ny });
				rawTomato--;
				if (rawTomato == 0) {
					return board[nx][ny] - 1;
				}
			}
		}
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i, j });
			}
			else if (board[i][j] == 0) {
				rawTomato++;
			}
		}
	}

	cout << BFS();
}