#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[100][100];
int vis[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N;

int BFS() {
	int cnt = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] == 0) {
				q.push({ i, j });
				vis[i][j] = 1;
				cnt++;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						if (board[nx][ny] == board[cur.first][cur.second] && vis[nx][ny] == 0) {
							vis[nx][ny] = 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	cout << BFS() << ' ';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
	fill(&vis[0][0], &vis[N - 1][N], 0);
	memset(vis, 0, sizeof(vis));

	cout << BFS();
}