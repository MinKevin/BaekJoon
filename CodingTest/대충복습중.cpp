#include <iostream>

using namespace std;

int M, N;
int board[500][500];
int dp[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int func(int x, int y) {
	if (x == M - 1 && y == N - 1)
		return 1;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;

		if (board[x][y] > board[nx][ny])
		dp[x][y] += func(nx, ny);
	}

	return dp[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	fill(&dp[0][0], &dp[499][500], -1);
	func(0, 0);
	cout << dp[0][0];
}