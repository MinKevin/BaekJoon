#include <iostream>
#include <queue>

using namespace std;

int board[100][100];
int vis[100][100];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int N, answer;

int BFS(int height) {
	fill(&vis[0][0], &vis[N - 1][N], 0);
	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > height && vis[i][j] == 0) {
				vis[i][j] = 1;
				q.push({ i, j });
				cnt++;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						if (board[nx][ny] > height && vis[nx][ny] == 0) {
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

	int min = 101;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] < min)
				min = board[i][j];
			if (board[i][j] > max)
				max = board[i][j];
		}
	}
	int maxSafeZone = 1;
	for (int i = min; i < max; i++) {
		int safeZone = BFS(i);
		if (maxSafeZone < safeZone)
			maxSafeZone = safeZone;
	}
	cout << maxSafeZone;
}