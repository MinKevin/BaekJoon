#include <iostream>

using namespace std;

int N;
int board[500][500];
int cnt[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	int max = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		if (board[nx][ny] > board[x][y]) {
			if (cnt[nx][ny] == 0) {
				int result = dfs(nx, ny);
				max = max > result ? max : result;
			}
			else {
				max = max > cnt[nx][ny] ? max : cnt[nx][ny];
			}
		}
	}
	cnt[x][y] = max + 1;
	return cnt[x][y];
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

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cnt[i][j] == 0) {
				int result = dfs(i, j);
				if (result > ans)
					ans = result;
			}
		}
	}

	cout << ans;
}