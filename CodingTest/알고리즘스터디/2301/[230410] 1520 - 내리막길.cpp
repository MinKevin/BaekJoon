#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> board;
vector<vector<int>> dp;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int recur(int x, int y) {
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

		if (board[nx][ny] < board[x][y]) {
			dp[x][y] += recur(nx, ny);
		}
	}
	return dp[x][y];
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	board.resize(M, vector<int>(N, 0));
	dp.resize(M, vector<int>(N, -1));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	cout << recur(0, 0);
}