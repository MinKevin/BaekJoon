#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

char board[100][100];
int kindsCnt[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;

int BFS() {
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));
	kindsCnt[0][0] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] == '1' && kindsCnt[nx][ny] == 0) {
				q.push({ nx, ny });
				kindsCnt[nx][ny] = kindsCnt[cur.X][cur.Y] + 1;
				if (nx == n - 1 && ny == m - 1) {
					return kindsCnt[nx][ny];
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
		cin >> board[i];
	}

	cout << BFS();
}