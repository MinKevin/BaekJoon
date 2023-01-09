#include <iostream>
#include <algorithm>

using namespace std;

int board[501][501];
int dp[501][501];

int N, M, answer;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int curX, int curY) {
	if (curX == M - 1 && curY == N - 1) {
		return 1;
	}

	if (dp[curX][curY] != -1)
		return dp[curX][curY];

	dp[curX][curY] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = curX + dx[dir];
		int ny = curY + dy[dir];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
			continue;
		}

		if (board[nx][ny] < board[curX][curY]) {
			dp[curX][curY] += dfs(nx, ny);
		}
	}
	return dp[curX][curY];
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
	//-1로 초기화해주는 이유 :
	//dp배열의 값은 해당 위치에서 도착지점에 도착할 수 있는 경우의 수를 의미
	//0일 경우 도착지점에 도착할 수 있는 경우의 수가 없음을 의미하므로,
	//탐색을 하지 않은 지점은 -1로 초기화하여 이를 분별
	fill(&dp[0][0], &dp[500][501], -1);
	cout << dfs(0, 0);
}