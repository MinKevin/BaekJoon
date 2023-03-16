#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char board[51][51];
bool vis[51][51];
int dp[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	//cout << x << ' ' << y << '\n';

	if (dp[x][y] != 0) {
		return dp[x][y];
	}

	vis[x][y] = true;
	dp[x][y] = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir] * (board[x][y] - '0');
		int ny = y + dy[dir] * (board[x][y] - '0');

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 'H')
			continue;

		if (vis[nx][ny] == true) {
			cout << -1;
			exit(0);
		}

		int result = dfs(nx, ny) + 1;

		dp[x][y] = dp[x][y] > result ? dp[x][y] : result;
	}
	vis[x][y] = false;

	return dp[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char test[3];
	cin >> test;
	cout << test;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	cout << dfs(0, 0);
}