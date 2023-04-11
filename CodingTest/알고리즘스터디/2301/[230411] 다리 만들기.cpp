#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

int board[100][100];
int vis[100][100];
int vis_buf[100][100];
int N;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };



int bfs(int x, int y) {
	deque<pair<int, int>> dq;
	dq.push_back({ x, y });
	vis[x][y] = 1;
	vis_buf[x][y] = 0;
	bool isSea = false;
	while (!dq.empty()) {
		pair<int, int> cur = dq.front();
		dq.pop_front();

		if (board[cur.first][cur.second] == 0) {
			isSea = true;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (vis_buf[nx][ny] == -1 && board[nx][ny] == 1) {
				if (isSea == true) 
					return vis_buf[cur.first][cur.second];
				
				vis[nx][ny] = 1;
				vis_buf[nx][ny] = 0;
				dq.push_front({ nx, ny });
			}

			else if (vis_buf[nx][ny] == -1 && board[nx][ny] == 0) {
				vis_buf[nx][ny] = vis_buf[cur.first][cur.second] + 1;
				dq.push_back({ nx, ny });
			}

		}
	}

	return 0;
}

void solution() {
	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				fill(&vis_buf[0][0], &vis_buf[N - 1][N], -1);
				ans = min(ans, bfs(i, j));
			}
		}
	}
	cout << ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	solution();
}