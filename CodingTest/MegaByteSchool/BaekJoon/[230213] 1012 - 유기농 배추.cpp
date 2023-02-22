#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[50][50];
int vis[50][50];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int M, N, T, K;

int BFS() {
	int cnt = 0;
	cin >> M >> N >> K;
	memset(board, 0, sizeof(board));
	fill(&vis[0][0], &vis[49][50], 0);

	while (K--) {
		int X, Y;
		cin >> X >> Y;
		board[Y][X] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				vis[i][j] = 1;
				cnt++;
				queue<pair<int, int>> q;
				q.push({ i, j });

				while (!q.empty()) {
					pair<int, int> cur;
					cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;

						if (board[nx][ny] == 1 && vis[nx][ny] == 0) {
							q.push({ nx, ny });
							vis[nx][ny] = 1;
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

	//int vis[50][50];

	//cout << sizeof(vis) << '\n' << sizeof(vis[0]) << '\n' << sizeof(**vis) << '\n';
	//cout << vis;
	// sizeof(vis) => 50 * 50 * 4 = 10000
	// sizeof(vis[0]) => 50 * 4 = 200
	// sizeof(**vis) => 4;

	cin >> T;

	while (T--) {
		cout << BFS() << '\n';
	}
}